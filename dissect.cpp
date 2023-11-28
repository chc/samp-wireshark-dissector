#include "main.h"
#include "msgids.h"

extern int msgid_field;
void dissect_samprpc_message_raknet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    
    //raknet mode = after ID_OPEN_CONNECTION_REPLY
    int offset = 0;
    proto_item *ti = proto_tree_add_item(tree, proto_samprpc, tvb, 0, -1, ENC_NA);
    proto_tree* msg_tree = proto_item_add_subtree(ti, samp_ett_foo);

    guint32 msg_id = 0;

    samp_conv_t* conv_data = get_samp_conversation_data(pinfo);

    int raknet_mode = pinfo->num > conv_data->raknet_frame && conv_data->raknet_frame != 0;

    if(!raknet_mode) {
        proto_tree_add_item_ret_uint(msg_tree, msgid_field, tvb, offset, sizeof(uint8_t), ENC_LITTLE_ENDIAN, &msg_id); offset += sizeof(uint8_t);

        if (msg_id == ID_OPEN_CONNECTION_REPLY) {
            conv_data->raknet_frame = pinfo->num;
        }
    } else {
        dissect_samprpc_message_raknet(tvb, pinfo, msg_tree, data);
    }
}