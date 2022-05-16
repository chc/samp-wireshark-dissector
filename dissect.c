#include "main.h"

extern int msgid_field;
void dissect_samprpc_message_raknet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    int raknet_mode = 1;
    //raknet mode = after ID_OPEN_CONNECTION_REPLY
    int offset = 0;
    proto_item *ti = proto_tree_add_item(tree, proto_samprpc, tvb, 0, -1, ENC_NA);
    proto_tree* msg_tree = proto_item_add_subtree(ti, samp_ett_foo);

    uint8_t msg_id = 0;

    if(!raknet_mode) {
        proto_tree_add_item_ret_uint(msg_tree, msgid_field, tvb, offset, sizeof(uint8_t), ENC_LITTLE_ENDIAN, &msg_id); offset += sizeof(uint8_t);
    } else {
        dissect_samprpc_message_raknet(tvb, pinfo, tree, data);
    }
}

