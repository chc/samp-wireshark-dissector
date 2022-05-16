
#include "rak_minimal/DS_RangeList.h"

extern "C" {
    #include "main.h"
    #include "msgids.h"
    #include "rpc_def.h"
    extern int player_sync_leftright_keys;
    extern int player_sync_updown_keys;
    extern int player_sync_keys;
    extern int player_sync_pos_x;
    extern int player_sync_pos_y;
    extern int player_sync_pos_z;
    extern int player_sync_quat_x;
    extern int player_sync_quat_y;
    extern int player_sync_quat_z;
    extern int player_sync_quat_w;
    extern int player_sync_health;
    extern int player_sync_armour;
    extern int player_sync_weapon;
    extern int player_sync_specialaction;
    extern int player_sync_move_speed_x;
    extern int player_sync_move_speed_y;
    extern int player_sync_move_speed_z;
    extern int player_sync_surf_offset_x;
    extern int player_sync_surf_offset_y;
    extern int player_sync_surf_offset_z;
    extern int player_sync_surf_flags;
    extern int player_sync_anim;
	void dissect_samprpc_message_raknet_player_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
        int offset = 1; //skip sync id
        guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
        char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

        RakNet::BitStream bs;
        bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();


        bool is_server = pinfo->srcport == SAMP_SERVER_PORT;

        uint8_t u8_val;
        uint16_t u16_val;
        uint32_t u32_val;
        float f_val;
        bool b_val;

        if(!is_server) {
            bs.Read(u16_val); //leftright keys
            proto_tree_add_uint(tree, player_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(u16_val); //updown keys
            proto_tree_add_uint(tree, player_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(u16_val); //keys
            proto_tree_add_uint(tree, player_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(f_val); //pos x
            proto_tree_add_float(tree, player_sync_pos_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //pos y
            proto_tree_add_float(tree, player_sync_pos_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //pos z
            proto_tree_add_float(tree, player_sync_pos_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //quat x
            proto_tree_add_float(tree, player_sync_quat_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //quat y
            proto_tree_add_float(tree, player_sync_quat_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //quat z
            proto_tree_add_float(tree, player_sync_quat_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //quat w
            proto_tree_add_float(tree, player_sync_quat_w, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(u8_val); //health
            proto_tree_add_uint(tree, player_sync_health, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.Read(u8_val); //armour
            proto_tree_add_uint(tree, player_sync_armour, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.Read(u8_val); //weapon
            proto_tree_add_uint(tree, player_sync_weapon, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.Read(u8_val); //special item
            proto_tree_add_uint(tree, player_sync_specialaction, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.Read(f_val); //vel x
            proto_tree_add_float(tree, player_sync_move_speed_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //vel y
            proto_tree_add_float(tree, player_sync_move_speed_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //vel z
            proto_tree_add_float(tree, player_sync_move_speed_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //surf offset x
            proto_tree_add_float(tree, player_sync_surf_offset_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //surf offset y
            proto_tree_add_float(tree, player_sync_surf_offset_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val); //surf offset z
            proto_tree_add_float(tree, player_sync_surf_offset_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(u16_val); //surf flags
            proto_tree_add_uint(tree, player_sync_surf_flags, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(u32_val); //anim
            proto_tree_add_uint(tree, player_sync_anim, tvb, offset, sizeof(uint32_t), u16_val); offset += sizeof(uint32_t);

            
        }
    }
}