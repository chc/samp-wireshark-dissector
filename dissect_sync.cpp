
#include "rak_minimal/DS_RangeList.h"

extern "C" {
    #include "main.h"
    #include "msgids.h"
    #include "rpc_def.h"
    extern int player_sync_playerid;
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

    extern int stats_update_money;
    extern int stats_update_drunk;

	extern int marker_update_num_items;
	extern int marker_update_playerid;
	extern int marker_update_active;
	extern int marker_update_x;
	extern int marker_update_y;
	extern int marker_update_z;

    //aim sync update
    extern int aim_sync_playerid;
    extern int aim_sync_cam_mode;
    extern int aim_sync_angle_x;
    extern int aim_sync_angle_y;
    extern int aim_sync_angle_z;
    extern int aim_sync_pos_x;
    extern int aim_sync_pos_y;
    extern int aim_sync_pos_z;
    extern int aim_sync_z;
    extern int aim_sync_cam_zoom;
    extern int aim_sync_weapon_state;
    extern int aim_sync_unknown;

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
        } else {
            float f_vals[4];
            bs.Read(u16_val); //playerid
            proto_tree_add_uint(tree, player_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(b_val);
            if(b_val) {
                bs.Read(u16_val);
                proto_tree_add_uint(tree, player_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);
            }

            bs.Read(b_val);
            if(b_val) {
                bs.Read(u16_val);
                proto_tree_add_uint(tree, player_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);
            }
            bs.Read(u16_val);
            proto_tree_add_uint(tree, player_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

            bs.Read(f_val);
            proto_tree_add_float(tree, player_sync_pos_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val);
            proto_tree_add_float(tree, player_sync_pos_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

            bs.Read(f_val);
            proto_tree_add_float(tree, player_sync_pos_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);            

            bs.ReadNormQuat(f_vals[0], f_vals[1], f_vals[2], f_vals[3]);
            proto_tree_add_float(tree, player_sync_quat_x, tvb, offset, sizeof(float), f_vals[0]); offset += sizeof(float);
            proto_tree_add_float(tree, player_sync_quat_y, tvb, offset, sizeof(float), f_vals[1]); offset += sizeof(float);
            proto_tree_add_float(tree, player_sync_quat_z, tvb, offset, sizeof(float), f_vals[2]); offset += sizeof(float);
            proto_tree_add_float(tree, player_sync_quat_w, tvb, offset, sizeof(float), f_vals[3]); offset += sizeof(float);

            uint8_t health_val = 0, armour_val = 0;
            bs.ReadBits(&health_val, 4);
            proto_tree_add_uint(tree, player_sync_health, tvb, offset, sizeof(uint8_t), health_val);
            bs.ReadBits(&armour_val, 4);
            proto_tree_add_uint(tree, player_sync_armour, tvb, offset, sizeof(uint8_t), armour_val); offset += sizeof(uint8_t);

            bs.Read(u8_val);
            proto_tree_add_uint(tree, player_sync_weapon, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.Read(u8_val);
            proto_tree_add_uint(tree, player_sync_specialaction, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

            bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
            proto_tree_add_float(tree, player_sync_move_speed_x, tvb, offset, sizeof(float), f_vals[0]); offset += sizeof(float);
            proto_tree_add_float(tree, player_sync_move_speed_y, tvb, offset, sizeof(float), f_vals[1]); offset += sizeof(float);
            proto_tree_add_float(tree, player_sync_move_speed_z, tvb, offset, sizeof(float), f_vals[2]); offset += sizeof(float);

            bs.Read(b_val);
            if(b_val) {
                bs.Read(u16_val);
                proto_tree_add_uint(tree, player_sync_surf_flags, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

                bs.Read(f_val);
                proto_tree_add_float(tree, player_sync_surf_offset_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

                bs.Read(f_val);
                proto_tree_add_float(tree, player_sync_surf_offset_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

                bs.Read(f_val);
                proto_tree_add_float(tree, player_sync_surf_offset_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);    
            }
            bs.Read(b_val);
            if(b_val) {
                proto_tree_add_uint(tree, player_sync_anim, tvb, offset, sizeof(uint32_t), u16_val); offset += sizeof(uint32_t);
            }
        }
    }

    void dissect_samprpc_message_raknet_stats_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
        int offset = 1; //skip sync id
        guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
        char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

        RakNet::BitStream bs;
        bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();

        bool is_server = pinfo->srcport == SAMP_SERVER_PORT;

        uint32_t u32_val;

        if(!is_server) {
            bs.Read(u32_val); //money
            proto_tree_add_uint(tree, stats_update_money, tvb, offset, sizeof(uint32_t), u32_val); offset += sizeof(uint32_t);

            bs.Read(u32_val); //drunk
            proto_tree_add_uint(tree, stats_update_drunk, tvb, offset, sizeof(uint32_t), u32_val); offset += sizeof(uint32_t);
        }
    }
    void dissect_samprpc_message_raknet_marker_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
        int offset = 1; //skip sync id
        guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
        char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

        RakNet::BitStream bs;
        bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();

        bool is_server = pinfo->srcport == SAMP_SERVER_PORT;
        if(is_server) {
            uint32_t num_items = 0;
            bs.Read(num_items);
            proto_tree_add_uint(tree, marker_update_num_items, tvb, offset, sizeof(uint32_t), num_items); offset += sizeof(uint32_t);
            for(int i=0;i<num_items;i++) {
                uint16_t playerid;
                int16_t x, y, z;
                bool active;
                bs.Read(playerid);
                proto_tree_add_uint(tree, marker_update_playerid, tvb, offset, sizeof(uint16_t), playerid); offset += sizeof(uint16_t);
                bs.Read(active);
                proto_tree_add_uint(tree, marker_update_active, tvb, offset, sizeof(uint8_t), playerid); offset += sizeof(uint8_t);
                if(active) {
                    bs.Read(x);
                    proto_tree_add_uint(tree, marker_update_x, tvb, offset, sizeof(uint8_t), x); offset += sizeof(uint8_t);
                    bs.Read(y);
                    proto_tree_add_uint(tree, marker_update_y, tvb, offset, sizeof(uint8_t), y); offset += sizeof(uint8_t);
                    bs.Read(z);
                    proto_tree_add_uint(tree, marker_update_z, tvb, offset, sizeof(uint8_t), z); offset += sizeof(uint8_t);
                }

            }
        }
    }
    void dissect_samprpc_message_raknet_aim_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
        int offset = 1; //skip sync id
        guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
        char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

        RakNet::BitStream bs;
        bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();

        uint16_t u16_val;
        uint8_t u8_val;
        float f_val;

        bool is_server = pinfo->srcport == SAMP_SERVER_PORT;
        if(is_server) {
            bs.Read(u16_val);
            proto_tree_add_uint(tree, aim_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);
        }

        bs.Read(u8_val);
        proto_tree_add_uint(tree, aim_sync_cam_mode, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_angle_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_angle_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_angle_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_pos_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_pos_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_pos_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(f_val);
        proto_tree_add_float(tree, aim_sync_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

        bs.Read(u8_val);
        proto_tree_add_uint(tree, aim_sync_cam_zoom, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

        bs.Read(u8_val);
        proto_tree_add_uint(tree, aim_sync_weapon_state, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

        bs.Read(u8_val);
        proto_tree_add_uint(tree, aim_sync_unknown, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    }
}