#include "rak_minimal/DS_RangeList.h"


#include "main.h"
#include "msgids.h"

extern "C" {
    #include <epan/reassemble.h>
    extern reassembly_table msg_reassembly_table;
    extern fragment_items samp_msg_frag_items;
}

void dissect_samprpc_message_raknet_rpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_, RakNet::BitStream &bs);
extern int msgid_field;
extern int ack_field;
extern int seqid_field;
extern int reliability_field;
extern int orderingChannel_field;
extern int orderingIndexType_field;

extern int has_split_packet_field;
extern int split_packet_id_field;
extern int split_packet_index_field;
extern int split_packet_count_field;
extern int data_len_field;

/*
    enum PacketReliability
    {
        UNRELIABLE = 6,   /// Same as regular UDP, except that it will also discard duplicate datagrams.  RakNet adds (6 to 17) + 21 bits of overhead, 16 of which is used to detect duplicate packets and 6 to 17 of which is used for message length.
        UNRELIABLE_SEQUENCED,  /// Regular UDP with a sequence counter.  Out of order messages will be discarded.  This adds an additional 13 bits on top what is used for UNRELIABLE.
        RELIABLE,   /// The message is sent reliably, but not necessarily in any order.  Same overhead as UNRELIABLE.
        RELIABLE_ORDERED,   /// This message is reliable and will arrive in the order you sent it.  Messages will be delayed while waiting for out of order messages.  Same overhead as UNRELIABLE_SEQUENCED.
        RELIABLE_SEQUENCED /// This message is reliable and will arrive in the sequence you sent it.  Out or order messages will be dropped.  Same overhead as UNRELIABLE_SEQUENCED.
    };
*/

const value_string reliability_vals[] = {
    { UNRELIABLE,             "UNRELIABLE" },
    { UNRELIABLE_SEQUENCED,  "UNRELIABLE_SEQUENCED" },
    { RELIABLE,              "RELIABLE" },
    { RELIABLE_ORDERED,      "RELIABLE_ORDERED" },
    { RELIABLE_SEQUENCED,    "RELIABLE_SEQUENCED" },
    { 0, NULL }
};

void dissect_samprpc_message_raknet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    int offset = 0;
    guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
    char *original_buffer = (char *)tvb_get_ptr(tvb, 0, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

    DataStructures::RangeList<uint16_t> acknowlegements;

    bool has_acks = false;
    bs.Read(has_acks);

	if(has_acks) {
        if (acknowlegements.Deserialize(&bs)) {
            uint16_t messageNumber;
            for (int i = 0; i < acknowlegements.ranges.Size(); i++)
            {
                if (acknowlegements.ranges[i].minIndex > acknowlegements.ranges[i].maxIndex)
                {
                    break;
                }

                for (messageNumber = acknowlegements.ranges[i].minIndex; messageNumber >= acknowlegements.ranges[i].minIndex && messageNumber <= acknowlegements.ranges[i].maxIndex; messageNumber++)
                {
                    //printf("\t ======= ack msgid: %d\n", messageNumber);
                    proto_tree_add_uint(tree, ack_field, tvb, offset, sizeof(uint16_t), messageNumber);
                    offset += sizeof(uint16_t);
                }
            }
        }
	}

    int remaining = BITS_TO_BYTES(bs.GetNumberOfUnreadBits());
    while((remaining = BITS_TO_BYTES(bs.GetNumberOfUnreadBits())) > 0) {
        proto_item *ti = proto_tree_add_item(tree, proto_samprpc, tvb, 0, -1, ENC_NA);
        proto_tree* sub_msg_tree = proto_item_add_subtree(ti, samp_ett_foo);

        uint8_t reliability = 0;
        uint16_t seqid = 0;
        uint8_t orderingChannel = 0;
        uint16_t orderingIndexType = 0;

        bool has_split_packet = false;
        uint16_t split_packet_id = 0;
        uint32_t split_packet_index = 0;
        uint32_t split_packet_count = 0;

        if (!bs.Read(seqid)) {
            break;
        }
        proto_tree_add_uint(sub_msg_tree, seqid_field, tvb, offset, sizeof(uint16_t), seqid); offset += sizeof(uint16_t);
        if (!bs.ReadBits(&reliability, 4)) {
            break;
        }
        proto_tree_add_uint_format_value(sub_msg_tree, reliability_field, tvb, offset, sizeof(reliability), reliability, "%s - %d", val_to_str_const(reliability, reliability_vals, "Unknown"), reliability); offset += sizeof(reliability);
        //
        if(reliability == UNRELIABLE_SEQUENCED || reliability == RELIABLE_SEQUENCED || reliability == RELIABLE_ORDERED ) {
            if (!bs.ReadBits(&orderingChannel, 5)) {
                break;
            }
            proto_tree_add_uint(sub_msg_tree, orderingChannel_field, tvb, offset, sizeof(uint16_t), orderingChannel);
            if (!bs.Read(orderingIndexType)) {
                break;
            }
            proto_tree_add_uint(sub_msg_tree, orderingIndexType_field, tvb, offset, sizeof(uint16_t), orderingIndexType); offset += sizeof(uint16_t);
        }

        if (!bs.Read(has_split_packet)) {
            break;
        }
        proto_tree_add_uint(sub_msg_tree, has_split_packet_field, tvb, offset, sizeof(has_split_packet), has_split_packet);
        if(has_split_packet) {
            bs.Read(split_packet_id);
            proto_tree_add_uint(sub_msg_tree, split_packet_id_field, tvb, offset, sizeof(split_packet_id), split_packet_id); offset += sizeof(split_packet_id);
            bs.ReadCompressed(split_packet_index);
            proto_tree_add_uint(sub_msg_tree, split_packet_index_field, tvb, offset, sizeof(split_packet_index), split_packet_index); offset += sizeof(split_packet_index);
            bs.ReadCompressed(split_packet_count);
            proto_tree_add_uint(sub_msg_tree, split_packet_count_field, tvb, offset, sizeof(split_packet_count), split_packet_count); offset += sizeof(split_packet_count);
        }
        uint16_t data_bit_len = 0;
            
            
        if (!bs.ReadCompressed(data_bit_len)) {
            break;
        }
        uint16_t data_byte_len = BITS_TO_BYTES(data_bit_len);

        proto_tree_add_uint(sub_msg_tree, data_len_field, tvb, offset, sizeof(split_packet_count), data_bit_len); offset += sizeof(data_bit_len);

        if (data_byte_len > 0) {
            guchar* decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, data_byte_len);
            memset(decrypted_heap_buffer, 0, data_byte_len);

            //bs.AlignReadToByteBoundary();
            //bs.ReadBits((unsigned char*)decrypted_heap_buffer, data_bit_len);
            //bs.AlignReadToByteBoundary();

            bs.ReadAlignedBytes(decrypted_heap_buffer, data_byte_len);

            tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, data_byte_len, data_byte_len);

            offset += data_byte_len;

            add_new_data_source(pinfo, next_tvb, "SAMP Msg Data");

            if (!has_split_packet) {
                dissect_samprpc_message_raknet_inner(next_tvb, pinfo, sub_msg_tree, data);
            }
            else {
                pinfo->fragmented = true;
                fragment_head* frag_msg = fragment_add_seq_check(&msg_reassembly_table, next_tvb, 0, pinfo, split_packet_id, NULL, split_packet_index, data_byte_len, split_packet_index != (split_packet_count - 1));
                if (frag_msg) {
                    tvbuff_t* new_tvb = process_reassembled_data(tvb, 0, pinfo,
                        "Reassembled Message", frag_msg, &samp_msg_frag_items,
                        NULL, sub_msg_tree);
                    if (new_tvb) {
                        dissect_samprpc_message_raknet_inner(new_tvb, pinfo, sub_msg_tree, data);
                    }
                }
            }
        }
    }
    //if (BITS_TO_BYTES(bs.GetNumberOfUnreadBits()) > 0) {
    //    add_new_data_source(pinfo, tvb, "SAMP Aborted msg");
    //    col_set_str(pinfo->cinfo, COL_INFO, "SAMP Aborted msg");
    //}
}
void dissect_samprpc_message_raknet_inner(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    proto_item *ti = proto_tree_add_item(tree, proto_samprpc, tvb, 0, -1, ENC_NA);
    proto_tree* msg_tree = proto_item_add_subtree(ti, samp_ett_foo);
        
    uint8_t msgid = 0;

    int offset = 0;
    guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
    char *original_buffer = (char *)tvb_get_ptr(tvb, 0, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

    bs.Read(msgid);
    proto_tree_add_uint(msg_tree, msgid_field, tvb, offset, sizeof(uint8_t), msgid); offset += sizeof(uint8_t);


    MessageTable *msgEntry = FindMessageInfoById(msgid);


    proto_item *s_ti = proto_tree_add_item(msg_tree, proto_samprpc, tvb, 0, -1, ENC_NA);
    proto_tree* sub_msg_tree = proto_item_add_subtree(s_ti, samp_ett_foo);
    if (msgEntry != NULL) {
        col_set_str(pinfo->cinfo, COL_INFO, msgEntry->name);
        proto_item_set_text(sub_msg_tree, msgEntry->name);
        proto_item_set_text(msg_tree, msgEntry->name);
        proto_item_set_text(tree, msgEntry->name);
    }

/*
	ID_RCON_COMMAND = 201,
	ID_RCON_RESPONCE = 202,
*/
    switch(msgid) {
        case ID_RPC:
            dissect_samprpc_message_raknet_rpc(tvb, pinfo, sub_msg_tree, data, bs);
        break;
        case ID_PLAYER_SYNC:
            dissect_samprpc_message_raknet_player_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_VEHICLE_SYNC:
            dissect_samprpc_message_raknet_vehicle_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_AIM_SYNC:
            dissect_samprpc_message_raknet_aim_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_STATS_UPDATE:
            dissect_samprpc_message_raknet_stats_update(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_MARKERS_SYNC:
            dissect_samprpc_message_raknet_marker_update(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_UNOCCUPIED_SYNC:
            dissect_samprpc_message_raknet_unoccupied_veh_update(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_BULLET_SYNC:
            dissect_samprpc_message_raknet_bullet_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_SPECTATOR_SYNC:
            dissect_samprpc_message_raknet_spectator_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_PASSENGER_SYNC:
            dissect_samprpc_message_raknet_passenger_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_TRAILER_SYNC:
            dissect_samprpc_message_raknet_trailer_sync(tvb, pinfo, sub_msg_tree, data);
        break;
        case ID_WEAPONS_UPDATE:
            dissect_samprpc_message_raknet_weapons_update(tvb, pinfo, sub_msg_tree, data);
        break;
    }
}