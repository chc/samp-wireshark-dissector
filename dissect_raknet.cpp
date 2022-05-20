#include "rak_minimal/DS_RangeList.h"
extern "C" {

#include "main.h"
#include "msgids.h"

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
			acknowlegements.Deserialize(&bs);

            uint16_t messageNumber;
            for (int i=0; i<acknowlegements.ranges.Size();i++)
            {
                if (acknowlegements.ranges[i].minIndex>acknowlegements.ranges[i].maxIndex)
                {
                    break;
                }

                for (messageNumber=acknowlegements.ranges[i].minIndex; messageNumber >= acknowlegements.ranges[i].minIndex && messageNumber <= acknowlegements.ranges[i].maxIndex; messageNumber++)
                {
                    //printf("\t ======= ack msgid: %d\n", messageNumber);
                    proto_tree_add_uint(tree, ack_field, tvb, offset, sizeof(uint16_t), messageNumber);
                    offset += sizeof(uint16_t);
                }
            }

		}
        while(BITS_TO_BYTES(bs.GetNumberOfUnreadBits()) > 0) {
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

            bs.Read(seqid);
            proto_tree_add_uint(sub_msg_tree, seqid_field, tvb, offset, sizeof(uint16_t), seqid); offset += sizeof(uint16_t);
            bs.ReadBits(&reliability, 4);
            proto_tree_add_uint(sub_msg_tree, reliability_field, tvb, offset, sizeof(reliability), reliability); offset += sizeof(reliability);
            if(reliability == UNRELIABLE_SEQUENCED || reliability == RELIABLE_SEQUENCED || reliability == RELIABLE_ORDERED ) {
                bs.ReadBits(&orderingChannel, 5);
                proto_tree_add_uint(sub_msg_tree, orderingChannel_field, tvb, offset, sizeof(uint16_t), orderingChannel);
                bs.Read(orderingIndexType);
                proto_tree_add_uint(sub_msg_tree, orderingIndexType_field, tvb, offset, sizeof(uint16_t), orderingIndexType); offset += sizeof(uint16_t);
            }

            bs.Read(has_split_packet);
            proto_tree_add_uint(sub_msg_tree, has_split_packet_field, tvb, offset, sizeof(has_split_packet), has_split_packet);
            if(has_split_packet) {
                bs.ReadCompressed(split_packet_id);
                proto_tree_add_uint(sub_msg_tree, split_packet_id_field, tvb, offset, sizeof(split_packet_id), split_packet_id); offset += sizeof(split_packet_id);
                bs.ReadCompressed(split_packet_index);
                proto_tree_add_uint(sub_msg_tree, split_packet_index_field, tvb, offset, sizeof(split_packet_index), split_packet_index); offset += sizeof(split_packet_index);
                bs.ReadCompressed(split_packet_count);
                proto_tree_add_uint(sub_msg_tree, split_packet_count_field, tvb, offset, sizeof(split_packet_count), split_packet_count); offset += sizeof(split_packet_count);
            }
            uint16_t data_bit_len = 0;
            
            
            bs.ReadCompressed(data_bit_len);
            proto_tree_add_uint(sub_msg_tree, data_len_field, tvb, offset, sizeof(split_packet_count), data_bit_len); offset += sizeof(data_bit_len);

            uint16_t data_byte_len = BITS_TO_BYTES(data_bit_len);

            guchar *decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, data_byte_len);
            memset(decrypted_heap_buffer, 0, data_byte_len);

            bs.AlignReadToByteBoundary();
            bs.ReadBits((unsigned char *)decrypted_heap_buffer, data_bit_len, false);
            bs.AlignReadToByteBoundary();

            tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, data_byte_len, data_byte_len);           

            add_new_data_source(pinfo, next_tvb, "SAMP Msg Data");            

            dissect_samprpc_message_raknet_inner(next_tvb, pinfo, sub_msg_tree, data);
        }
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
		ID_TRAILER_SYNC = 210,
		ID_RCON_COMMAND = 201,
		ID_RCON_RESPONCE = 202,
		ID_WEAPONS_UPDATE = 204,
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
        }
    }
}
