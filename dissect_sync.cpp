
#include "rak_minimal/DS_RangeList.h"

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
extern int aim_sync_aspect_ratio;

//vehicle sync
extern int vehicle_sync_playerid;
extern int vehicle_sync_vehicleid;
extern int vehicle_sync_leftright_keys;
extern int vehicle_sync_updown_keys;
extern int vehicle_sync_keys;
extern int vehicle_sync_quat_x;
extern int vehicle_sync_quat_y;
extern int vehicle_sync_quat_z;
extern int vehicle_sync_quat_w;
extern int vehicle_sync_pos_x;
extern int vehicle_sync_pos_y;
extern int vehicle_sync_pos_z;
extern int vehicle_sync_vel_x;
extern int vehicle_sync_vel_y;
extern int vehicle_sync_vel_z;
extern int vehicle_sync_stoc_vehhealth;
extern int vehicle_sync_vehhealth;
extern int vehicle_sync_player_health;
extern int vehicle_sync_player_armour;
extern int vehicle_sync_weapon;
extern int vehicle_sync_siren;
extern int vehicle_sync_angle;
extern int vehicle_sync_train_speed;
extern int vehicle_sync_landinggear_state;
extern int vehicle_sync_hydra;
extern int vehicle_sync_trailer;
extern int vehicle_sync_stos_train_speed;

extern int bullet_sync_type;
extern int bullet_sync_playerid;
extern int bullet_sync_id;
extern int bullet_sync_origin_x;
extern int bullet_sync_origin_y;
extern int bullet_sync_origin_z;
extern int bullet_sync_target_x;
extern int bullet_sync_target_y;
extern int bullet_sync_target_z;
extern int bullet_sync_center_x;
extern int bullet_sync_center_y;
extern int bullet_sync_center_z;
extern int bullet_sync_weapon;

extern int unoccupied_veh_sync_playerid;
extern int unoccupied_veh_sync_vehicle_id;
extern int unoccupied_veh_sync_roll_x;
extern int unoccupied_veh_sync_roll_y;
extern int unoccupied_veh_sync_roll_z;
extern int unoccupied_veh_sync_direction_x;
extern int unoccupied_veh_sync_direction_y;
extern int unoccupied_veh_sync_direction_z;
extern int unoccupied_veh_sync_seatid;
extern int unoccupied_veh_sync_pos_x;
extern int unoccupied_veh_sync_pos_y;
extern int unoccupied_veh_sync_pos_z;
extern int unoccupied_veh_sync_vel_x;
extern int unoccupied_veh_sync_vel_y;
extern int unoccupied_veh_sync_vel_z;
extern int unoccupied_veh_sync_turning_speed_x;
extern int unoccupied_veh_sync_turning_speed_y;
extern int unoccupied_veh_sync_turning_speed_z;
extern int unoccupied_veh_sync_health;

extern int spec_sync_playerid;
extern int spec_sync_leftright_keys;
extern int spec_sync_updown_keys;
extern int spec_sync_keys;
extern int spec_sync_pos_x;
extern int spec_sync_pos_y;
extern int spec_sync_pos_z;

extern int passenger_sync_playerid;
extern int passenger_sync_vehicleid;
extern int passenger_sync_seat_flags;
extern int passenger_sync_driveby;
extern int passenger_sync_currentweapon;
extern int passenger_sync_health;
extern int passenger_sync_armour;
extern int passenger_sync_leftright_keys;
extern int passenger_sync_updown_keys;
extern int passenger_sync_keys;
extern int passenger_sync_pos_x;
extern int passenger_sync_pos_y;
extern int passenger_sync_pos_z;


extern int trailer_sync_vehicleid;
extern int trailer_sync_pos_x;
extern int trailer_sync_pos_y;
extern int trailer_sync_pos_z;
extern int trailer_sync_rot_x;
extern int trailer_sync_rot_y;
extern int trailer_sync_rot_z;
extern int trailer_sync_rot_w;
extern int trailer_sync_vel_x;
extern int trailer_sync_vel_y;
extern int trailer_sync_vel_z;
extern int trailer_sync_angular_vel_x;
extern int trailer_sync_angular_vel_y;
extern int trailer_sync_angular_vel_z;

extern int weapons_update_player_target;
extern int weapons_update_actor_target;
extern int weapons_update_slot;
extern int weapons_update_weapon;
extern int weapons_update_ammo;
	    
void dissect_samprpc_message_raknet_player_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();


    bool is_server = is_samp_server(pinfo);

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
        if (health_val == 0xF) {
            health_val = 100;
        }
        else {
            health_val *= 7;
        }
        proto_tree_add_uint(tree, player_sync_health, tvb, offset, sizeof(uint8_t), health_val);
        bs.ReadBits(&armour_val, 4);
        if (armour_val == 0xF) {
            armour_val = 100;
        }
        else {
            armour_val *= 7;
        }
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

    bool is_server = is_samp_server(pinfo);

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

    bool is_server = is_samp_server(pinfo);
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

    bool is_server = is_samp_server(pinfo);
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

    u8_val = 0;
    bs.ReadBits(&u8_val, 2);
    proto_tree_add_uint(tree, aim_sync_weapon_state, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.ReadBits(&u8_val, 6);
    proto_tree_add_uint(tree, aim_sync_cam_zoom, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, aim_sync_aspect_ratio, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

}
void dissect_samprpc_message_raknet_vehicle_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);

    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint32_t u32_val;
    uint16_t u16_val;
    uint8_t u8_val;
    float f_val;
    bool b_val;

    float f_vals[4];

    if(is_server) {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_vehicleid, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.ReadNormQuat(f_vals[0], f_vals[1], f_vals[2], f_vals[3]);
        proto_tree_add_float(tree, vehicle_sync_quat_x, tvb, offset, sizeof(float), f_vals[0]);
        proto_tree_add_float(tree, vehicle_sync_quat_y, tvb, offset, sizeof(float), f_vals[1]);
        proto_tree_add_float(tree, vehicle_sync_quat_z, tvb, offset, sizeof(float), f_vals[2]);
        proto_tree_add_float(tree, vehicle_sync_quat_w, tvb, offset, sizeof(float), f_vals[3]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_x, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_y, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_z, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
        proto_tree_add_float(tree, vehicle_sync_vel_x, tvb, offset, sizeof(float), f_vals[0]);
        proto_tree_add_float(tree, vehicle_sync_vel_y, tvb, offset, sizeof(float), f_vals[1]);
        proto_tree_add_float(tree, vehicle_sync_vel_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_stoc_vehhealth, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        uint8_t health_val, armour_val;
        bs.ReadBits(&health_val, 4);
        if (health_val == 0xF) {
            health_val = 100;
        }
        else {
            health_val *= 7;
        }
        proto_tree_add_uint(tree, vehicle_sync_player_health, tvb, offset, sizeof(uint8_t), health_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
        bs.ReadBits(&armour_val, 4);
        if (armour_val == 0xF) {
            armour_val = 100;
        }
        else {
            armour_val *= 7;
        }
        proto_tree_add_uint(tree, vehicle_sync_player_health, tvb, offset, sizeof(uint8_t), armour_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_weapon, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.ReadCompressed(b_val);
        proto_tree_add_uint(tree, vehicle_sync_siren, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.ReadCompressed(b_val);
        proto_tree_add_uint(tree, vehicle_sync_landinggear_state, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.ReadCompressed(b_val);
        if (b_val) {
            uint32_t hydra_angle;
            bs.Read(hydra_angle);
            proto_tree_add_uint(tree, vehicle_sync_hydra, tvb, offset, sizeof(uint32_t), hydra_angle); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
        }
        

        bs.ReadCompressed(b_val);
        if (b_val) {
            uint16_t trailerId;
            bs.Read(trailerId);
            proto_tree_add_uint(tree, vehicle_sync_trailer, tvb, offset, sizeof(uint16_t), trailerId); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
        }
    } else {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_vehicleid, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_quat_x, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_quat_y, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_quat_z, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_quat_w, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_x, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_y, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_pos_z, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_vel_x, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_vel_y, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_vel_z, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(f_val);
        proto_tree_add_float(tree, vehicle_sync_vehhealth, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_player_health, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_player_armour, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_weapon, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_siren, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u8_val);
        proto_tree_add_uint(tree, vehicle_sync_landinggear_state, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u16_val);
        proto_tree_add_uint(tree, vehicle_sync_trailer, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

        bs.Read(u32_val);
        proto_tree_add_uint(tree, vehicle_sync_hydra, tvb, offset, sizeof(float), u32_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
    }
}

void dissect_samprpc_message_raknet_bullet_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);
    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint32_t u32_val;
    uint16_t u16_val;
    uint8_t u8_val;
    float f_vals[3];
    bool b_val;


    if (is_server) {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, bullet_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
    }

    bs.Read(u8_val);
    proto_tree_add_uint(tree, bullet_sync_type, tvb, offset, sizeof(uint8_t), u8_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.Read(u16_val);
    proto_tree_add_uint(tree, bullet_sync_type, tvb, offset, sizeof(uint16_t), u16_val); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    
    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, bullet_sync_origin_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, bullet_sync_origin_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, bullet_sync_origin_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, bullet_sync_target_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, bullet_sync_target_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, bullet_sync_target_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, bullet_sync_center_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, bullet_sync_center_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, bullet_sync_center_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.Read(u8_val);
    proto_tree_add_uint(tree, bullet_sync_weapon, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);
}
void dissect_samprpc_message_raknet_unoccupied_veh_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);

    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint32_t u32_val;
    uint16_t u16_val;
    uint8_t u8_val;
    float f_vals[4];
    bool b_val;


    if (is_server) {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, unoccupied_veh_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val);  offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
    }  

    bs.Read(u16_val);
    proto_tree_add_uint(tree, unoccupied_veh_sync_vehicle_id, tvb, offset, sizeof(uint16_t), u16_val);  offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.Read(u8_val);
    proto_tree_add_uint(tree, unoccupied_veh_sync_seatid, tvb, offset, sizeof(uint8_t), u8_val);  offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, unoccupied_veh_sync_roll_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, unoccupied_veh_sync_roll_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, unoccupied_veh_sync_roll_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, unoccupied_veh_sync_direction_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, unoccupied_veh_sync_direction_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, unoccupied_veh_sync_direction_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, unoccupied_veh_sync_pos_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, unoccupied_veh_sync_pos_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, unoccupied_veh_sync_pos_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, unoccupied_veh_sync_vel_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, unoccupied_veh_sync_vel_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, unoccupied_veh_sync_vel_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, unoccupied_veh_sync_turning_speed_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, unoccupied_veh_sync_turning_speed_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, unoccupied_veh_sync_turning_speed_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.Read(f_vals[0]); //veh health
    proto_tree_add_float(tree, unoccupied_veh_sync_health, tvb, offset, sizeof(float), f_vals[0]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
}
void dissect_samprpc_message_raknet_spectator_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);

    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint16_t u16_val;
    float f_val;


    if (is_server) {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, spec_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);
    } 
    bs.Read(u16_val);
    proto_tree_add_uint(tree, spec_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(u16_val);
    proto_tree_add_uint(tree, spec_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(u16_val);
    proto_tree_add_uint(tree, spec_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(f_val); //pos x
    proto_tree_add_float(tree, spec_sync_pos_x, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

    bs.Read(f_val); //pos y
    proto_tree_add_float(tree, spec_sync_pos_y, tvb, offset, sizeof(float), f_val); offset += sizeof(float);

    bs.Read(f_val); //pos z
    proto_tree_add_float(tree, spec_sync_pos_z, tvb, offset, sizeof(float), f_val); offset += sizeof(float);
}
void dissect_samprpc_message_raknet_passenger_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);

    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint16_t u16_val;
    uint8_t u8_val;
    float f_val;
    float f_vals[3];

    if (is_server) {
        bs.Read(u16_val);
        proto_tree_add_uint(tree, passenger_sync_playerid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);
    } 
    bs.Read(u16_val);
    proto_tree_add_uint(tree, passenger_sync_vehicleid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, passenger_sync_seat_flags, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, passenger_sync_driveby, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, passenger_sync_currentweapon, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, passenger_sync_health, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u8_val);
    proto_tree_add_uint(tree, passenger_sync_armour, tvb, offset, sizeof(uint8_t), u8_val); offset += sizeof(uint8_t);

    bs.Read(u16_val);
    proto_tree_add_uint(tree, passenger_sync_leftright_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(u16_val);
    proto_tree_add_uint(tree, passenger_sync_updown_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.Read(u16_val);
    proto_tree_add_uint(tree, passenger_sync_keys, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[2]);
    proto_tree_add_float(tree, passenger_sync_pos_x, tvb, offset, sizeof(float), f_vals[0]); offset += sizeof(float);
    proto_tree_add_float(tree, passenger_sync_pos_y, tvb, offset, sizeof(float), f_vals[1]); offset += sizeof(float);
    proto_tree_add_float(tree, passenger_sync_pos_z, tvb, offset, sizeof(float), f_vals[2]); offset += sizeof(float);
}    
void dissect_samprpc_message_raknet_trailer_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    bool is_server = is_samp_server(pinfo);

    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint16_t u16_val;
    float f_vals[4];

    bs.Read(u16_val);
    proto_tree_add_uint(tree, trailer_sync_vehicleid, tvb, offset, sizeof(uint16_t), u16_val); offset += sizeof(uint16_t);

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[3]);
    proto_tree_add_float(tree, trailer_sync_pos_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, trailer_sync_pos_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, trailer_sync_pos_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadNormQuat(f_vals[0], f_vals[1], f_vals[2], f_vals[3]);
    proto_tree_add_float(tree, trailer_sync_rot_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, trailer_sync_rot_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, trailer_sync_rot_z, tvb, offset, sizeof(float), f_vals[2]);
    proto_tree_add_float(tree, trailer_sync_rot_w, tvb, offset, sizeof(float), f_vals[3]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[3]);
    proto_tree_add_float(tree, trailer_sync_vel_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, trailer_sync_vel_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, trailer_sync_vel_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;

    bs.ReadVector(f_vals[0], f_vals[1], f_vals[3]);
    proto_tree_add_float(tree, trailer_sync_angular_vel_x, tvb, offset, sizeof(float), f_vals[0]);
    proto_tree_add_float(tree, trailer_sync_angular_vel_y, tvb, offset, sizeof(float), f_vals[1]);
    proto_tree_add_float(tree, trailer_sync_angular_vel_z, tvb, offset, sizeof(float), f_vals[2]); offset = BITS_TO_BYTES(bs.GetReadOffset()) + 1;
}

void dissect_samprpc_message_raknet_weapons_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_) {
    int offset = 1; //skip sync id
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

    uint16_t playerTarget, actorTarget;
    bs.Read(playerTarget);
    proto_tree_add_uint(tree, weapons_update_player_target, tvb, offset, sizeof(uint16_t), playerTarget); offset += sizeof(uint16_t);

    bs.Read(actorTarget);
    proto_tree_add_uint(tree, weapons_update_actor_target, tvb, offset, sizeof(uint16_t), playerTarget); offset += sizeof(uint16_t);


    uint16_t ammo;
    uint8_t slot, weapon;

    for(int i=0;i<12&&bs.GetNumberOfUnreadBits() > 0;i++) {
        bs.Read(slot);
        proto_tree_add_uint(tree, weapons_update_slot, tvb, offset, sizeof(uint8_t), slot); offset += sizeof(uint8_t);
        bs.Read(weapon);
        proto_tree_add_uint(tree, weapons_update_weapon, tvb, offset, sizeof(uint8_t), weapon); offset += sizeof(uint8_t);
        bs.Read(ammo);
        proto_tree_add_uint(tree, weapons_update_ammo, tvb, offset, sizeof(uint16_t), ammo); offset += sizeof(uint16_t);
    }
}