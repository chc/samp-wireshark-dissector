extern "C" {
	#include "main.h"
	#include "rpc_def.h"


	int msgid_field = -1;
	int rpcid_field = -1;
	int ack_field = -1;

	int seqid_field = -1;
	int reliability_field = -1;
	int orderingChannel_field = -1;
	int orderingIndexType_field = -1;

	int has_split_packet_field = -1;
	int split_packet_id_field = -1;
	int split_packet_index_field = -1;
	int split_packet_count_field = -1;
	int data_len_field = -1;

	//player sync (client to server)
	int player_sync_playerid = -1;
	int player_sync_leftright_keys = -1;
	int player_sync_updown_keys = -1;
	int player_sync_keys = -1;
	int player_sync_pos_x = -1;
	int player_sync_pos_y = -1;
	int player_sync_pos_z = -1;
	int player_sync_quat_x = -1;
	int player_sync_quat_y = -1;
	int player_sync_quat_z = -1;
	int player_sync_quat_w = -1;
	int player_sync_health = -1;
	int player_sync_armour = -1;
	int player_sync_weapon = -1;
	int player_sync_specialaction = -1;
	int player_sync_move_speed_x = -1;
	int player_sync_move_speed_y = -1;
	int player_sync_move_speed_z = -1;
	int player_sync_surf_offset_x = -1;
	int player_sync_surf_offset_y = -1;
	int player_sync_surf_offset_z = -1;
	int player_sync_surf_flags = -1;
	int player_sync_anim = -1;

	//stats update
	int stats_update_money = -1;
	int stats_update_drunk = -1;

	//marker update
	int marker_update_num_items = -1;
	int marker_update_playerid = -1;
	int marker_update_active = -1;
	int marker_update_x = -1;
	int marker_update_y = -1;
	int marker_update_z = -1;

	//aim sync update
	int aim_sync_playerid = -1;
	int aim_sync_cam_mode = -1;
	int aim_sync_angle_x = -1;
	int aim_sync_angle_y = -1;
	int aim_sync_angle_z = -1;
	int aim_sync_pos_x = -1;
	int aim_sync_pos_y = -1;
	int aim_sync_pos_z = -1;
	int aim_sync_z = -1;
	int aim_sync_cam_zoom = -1;
	int aim_sync_weapon_state = -1;
	int aim_sync_aspect_ratio = -1;

	//vehicle sync update
	int vehicle_sync_playerid = -1;
	int vehicle_sync_vehicleid = -1;
	int vehicle_sync_leftright_keys = -1;
	int vehicle_sync_updown_keys = -1;
	int vehicle_sync_keys = -1;
	int vehicle_sync_quat_x = -1;
	int vehicle_sync_quat_y = -1;
	int vehicle_sync_quat_z = -1;
	int vehicle_sync_quat_w = -1;
	int vehicle_sync_pos_x = -1;
	int vehicle_sync_pos_y = -1;
	int vehicle_sync_pos_z = -1;
	int vehicle_sync_vel_x = -1;
	int vehicle_sync_vel_y = -1;
	int vehicle_sync_vel_z = -1;
	int vehicle_sync_vehhealth = -1;
	int vehicle_sync_stoc_vehhealth = -1;	
	int vehicle_sync_player_health = -1;
	int vehicle_sync_player_armour = -1;
	int vehicle_sync_weapon = -1;
	int vehicle_sync_siren = -1;
	int vehicle_sync_angle = -1;
	int vehicle_sync_train_speed = -1;
	int vehicle_sync_landinggear_state = -1;
    int vehicle_sync_hydra = -1;
    int vehicle_sync_trailer = -1;
	int vehicle_sync_stos_train_speed = -1;

	//bullet sync
	int bullet_sync_type = -1;
	int bullet_sync_playerid = -1;
	int bullet_sync_id = -1;
	int bullet_sync_origin_x = -1;
	int bullet_sync_origin_y = -1;
	int bullet_sync_origin_z = -1;
	int bullet_sync_target_x = -1;
	int bullet_sync_target_y = -1;
	int bullet_sync_target_z = -1;
	int bullet_sync_center_x = -1;
	int bullet_sync_center_y = -1;
	int bullet_sync_center_z = -1;
	int bullet_sync_weapon = -1;
	
	//unoccupied veh sync
	int unoccupied_veh_sync_playerid = -1;
	int unoccupied_veh_sync_vehicle_id = -1;
	int unoccupied_veh_sync_roll_x = -1;
	int unoccupied_veh_sync_roll_y = -1;
	int unoccupied_veh_sync_roll_z = -1;
	int unoccupied_veh_sync_direction_x = -1;
	int unoccupied_veh_sync_direction_y = -1;
	int unoccupied_veh_sync_direction_z = -1;
	int unoccupied_veh_sync_seatid = -1;
	int unoccupied_veh_sync_pos_x = -1;
	int unoccupied_veh_sync_pos_y = -1;
	int unoccupied_veh_sync_pos_z = -1;
	int unoccupied_veh_sync_vel_x = -1;
	int unoccupied_veh_sync_vel_y = -1;
	int unoccupied_veh_sync_vel_z = -1;
	int unoccupied_veh_sync_turning_speed_x = -1;
	int unoccupied_veh_sync_turning_speed_y = -1;
	int unoccupied_veh_sync_turning_speed_z = -1;
	int unoccupied_veh_sync_health = -1;

	//spec sync
	int spec_sync_playerid = -1;
	int spec_sync_leftright_keys = -1;
	int spec_sync_updown_keys = -1;
	int spec_sync_keys = -1;
	int spec_sync_pos_x = -1;
	int spec_sync_pos_y = -1;
	int spec_sync_pos_z = -1;

	//passenger sync
	int passenger_sync_playerid = -1;
	int passenger_sync_vehicleid = -1;
	int passenger_sync_seat_flags = -1;
	int passenger_sync_driveby = -1;
	int passenger_sync_currentweapon = -1;
	int passenger_sync_health = -1;
	int passenger_sync_armour = -1;
	int passenger_sync_leftright_keys = -1;
	int passenger_sync_updown_keys = -1;
	int passenger_sync_keys = -1;
	int passenger_sync_pos_x = -1;
	int passenger_sync_pos_y = -1;
	int passenger_sync_pos_z = -1;

	static hf_register_info standard_fields_hf[] = {
		{ &msgid_field,
			{ "msgid", "samprpc.msgid",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &rpcid_field,
			{ "rpcid", "samprpc.rpcid",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &ack_field,
			{ "ackid", "samprpc.ackid",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &seqid_field,
			{ "seqid", "samprpc.seqid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &reliability_field,
			{ "reliability", "samprpc.reliability",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &orderingChannel_field,
			{ "orderingChannel", "samprpc.orderingChannel",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &orderingIndexType_field,
			{ "orderingIndexType", "samprpc.orderingIndexType",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &has_split_packet_field,
			{ "has_split_packet", "samprpc.has_split_packet",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		
		{ &split_packet_id_field,
			{ "split_packet_id", "samprpc.split_packet_id",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &split_packet_index_field,
			{ "split_packet_index", "samprpc.split_packet_index",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &split_packet_count_field,
			{ "split_packet_count", "samprpc.split_packet_count",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &data_len_field,
			{ "data_len_field", "samprpc.data_len_field",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},


		//player sync		
		{ &player_sync_playerid,
			{ "playerid", "samprpc.player_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_leftright_keys,
			{ "leftright_keys", "samprpc.player_sync.leftright_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_updown_keys,
			{ "updown_keys", "samprpc.player_sync.updown_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_keys,
			{ "keys", "samprpc.player_sync.keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_pos_x,
			{ "x", "samprpc.player_sync.x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_pos_y,
			{ "y", "samprpc.player_sync.y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_pos_z,
			{ "z", "samprpc.player_sync.z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_quat_x,
			{ "quat_x", "samprpc.player_sync.quat_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_quat_y,
			{ "quat_x", "samprpc.player_sync.quat_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_quat_z,
			{ "quat_x", "samprpc.player_sync.quat_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_quat_w,
			{ "quat_x", "samprpc.player_sync.quat_w",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_health,
			{ "health", "samprpc.player_sync.health",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_armour,
			{ "armour", "samprpc.player_sync.armour",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_weapon,
			{ "weapon", "samprpc.player_sync.weapon",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_specialaction,
			{ "specialaction", "samprpc.player_sync.specialaction",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_move_speed_x,
			{ "move_speed_x", "samprpc.player_sync.move_speed_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_move_speed_y,
			{ "move_speed_y", "samprpc.player_sync.move_speed_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_move_speed_z,
			{ "move_speed_z", "samprpc.player_sync.move_speed_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_surf_offset_x,
			{ "surf_offset_x", "samprpc.player_sync.surf_offset_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_surf_offset_y,
			{ "surf_offset_y", "samprpc.player_sync.surf_offset_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_surf_offset_z,
			{ "surf_offset_z", "samprpc.player_sync.surf_offset_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_surf_flags,
			{ "surf_flags", "samprpc.player_sync.surf_flags",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &player_sync_anim,
			{ "anim", "samprpc.player_sync.anim",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		//
		{ &stats_update_money,
			{ "money", "samprpc.stats_update.money",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &stats_update_drunk,
			{ "drunk", "samprpc.stats_update.drunk",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},

		//marker update
		{ &marker_update_num_items,
			{ "num_items", "samprpc.marker_update.num_items",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &marker_update_playerid,
			{ "playerid", "samprpc.marker_update.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &marker_update_active,
			{ "active", "samprpc.marker_update.active",
			FT_BOOLEAN, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &marker_update_x,
			{ "x", "samprpc.marker_update.x",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &marker_update_y,
			{ "y", "samprpc.marker_update.y",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &marker_update_z,
			{ "z", "samprpc.marker_update.z",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},	
		{ &aim_sync_playerid,
			{ "playerid", "samprpc.aim_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},	
		{ &aim_sync_cam_mode,
			{ "cam_mode", "samprpc.aim_sync.cam_mode",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_angle_x,
			{ "angle_x", "samprpc.aim_sync.angle_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_angle_y,
			{ "angle_x", "samprpc.aim_sync.angle_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_angle_z,
			{ "angle_z", "samprpc.aim_sync.angle_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},

		{ &aim_sync_pos_x,
			{ "pos_x", "samprpc.aim_sync.pos_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_pos_y,
			{ "pos_y", "samprpc.aim_sync.pos_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_pos_z,
			{ "pos_z", "samprpc.aim_sync.pos_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_z,
			{ "z", "samprpc.aim_sync.z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_cam_zoom,
			{ "cam_zoom", "samprpc.aim_sync.cam_zoom",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_weapon_state,
			{ "weapon_state", "samprpc.aim_sync.weapon_state",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &aim_sync_aspect_ratio,
			{ "aspect_ratio", "samprpc.aim_sync.aspect_ratio",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_playerid,
			{ "playerid", "samprpc.veh_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_vehicleid,
			{ "vehicleid", "samprpc.veh_sync.vehicleid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_stoc_vehhealth,
			{ "vehhealth", "samprpc.veh_sync.stoc_vehhealth",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		
		{ &vehicle_sync_leftright_keys,
			{ "leftright_keys", "samprpc.veh_sync.leftright_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_updown_keys,
			{ "updown_keys", "samprpc.veh_sync.updown_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_keys,
			{ "keys", "samprpc.veh_sync.keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_quat_x,
			{ "quat_x", "samprpc.veh_sync.quat_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_quat_y,
			{ "quat_y", "samprpc.veh_sync.quat_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_quat_z,
			{ "quat_z", "samprpc.veh_sync.quat_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_quat_w,
			{ "quat_w", "samprpc.veh_sync.quat_w",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_pos_x,
			{ "pos_x", "samprpc.veh_sync.pos_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_pos_y,
			{ "pos_y", "samprpc.veh_sync.pos_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_pos_z,
			{ "pos_z", "samprpc.veh_sync.pos_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_vel_x,
			{ "vel_x", "samprpc.veh_sync.vel_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_vel_y,
			{ "vel_y", "samprpc.veh_sync.vel_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_vel_z,
			{ "vel_z", "samprpc.veh_sync.vel_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_vehhealth,
			{ "veh_health", "samprpc.veh_sync.veh_health",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_player_health,
			{ "player_health", "samprpc.veh_sync.player_health",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_player_armour,
			{ "player_armour", "samprpc.veh_sync.player_armour",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_weapon,
			{ "weapon", "samprpc.veh_sync.weapon",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_siren,
			{ "siren", "samprpc.veh_sync.siren",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_angle,
			{ "angle", "samprpc.veh_sync.angle",
			FT_UINT32, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_train_speed,
			{ "train_speed", "samprpc.veh_sync.train_speed",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_stos_train_speed,
			{ "train_speed", "samprpc.veh_sync.stos_train_speed",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_landinggear_state,
			{ "landinggear_state", "samprpc.veh_sync.landinggear_state",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_hydra,
			{ "hydra", "samprpc.veh_sync.hydra",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &vehicle_sync_trailer,
			{ "trailer", "samprpc.veh_sync.trailer",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},


		{ &bullet_sync_type,
			{ "type", "samprpc.bullet_sync.type",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_playerid,
			{ "playerid", "samprpc.bullet_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_id,
			{ "id", "samprpc.bullet_sync.id",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_origin_x,
			{ "origin_x", "samprpc.bullet_sync.origin_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_origin_y,
			{ "origin_y", "samprpc.bullet_sync.origin_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_origin_z,
			{ "origin_z", "samprpc.bullet_sync.origin_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_target_x,
			{ "target_x", "samprpc.bullet_sync.target_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_target_y,
			{ "target_y", "samprpc.bullet_sync.target_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_target_z,
			{ "target_z", "samprpc.bullet_sync.target_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_center_x,
			{ "center_x", "samprpc.bullet_sync.center_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_center_y,
			{ "center_y", "samprpc.bullet_sync.center_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_center_z,
			{ "center_z", "samprpc.bullet_sync.center_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &bullet_sync_weapon,
			{ "weapon", "samprpc.bullet_sync.weapon",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_playerid,
			{ "playerid", "samprpc.unoccupied_veh_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_vehicle_id,
			{ "vehicleid", "samprpc.unoccupied_veh_sync.vehicleid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_roll_x,
			{ "roll_x", "samprpc.unoccupied_veh_sync.roll_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_roll_y,
			{ "roll_y", "samprpc.unoccupied_veh_sync.roll_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_roll_z,
			{ "roll_z", "samprpc.unoccupied_veh_sync.roll_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_direction_x,
			{ "direction_x", "samprpc.unoccupied_veh_sync.direction_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_direction_y,
			{ "direction_y", "samprpc.unoccupied_veh_sync.direction_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_direction_z,
			{ "direction_z", "samprpc.unoccupied_veh_sync.direction_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_seatid,
			{ "seatid", "samprpc.unoccupied_veh_sync.seatid",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		
		{ &unoccupied_veh_sync_pos_x,
			{ "pos_x", "samprpc.unoccupied_veh_sync.pos_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_pos_y,
			{ "pos_y", "samprpc.unoccupied_veh_sync.pos_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_pos_z,
			{ "pos_z", "samprpc.unoccupied_veh_sync.pos_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_vel_x,
			{ "vel_x", "samprpc.unoccupied_veh_sync.vel_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_vel_y,
			{ "vel_y", "samprpc.unoccupied_veh_sync.vel_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_vel_z,
			{ "vel_z", "samprpc.unoccupied_veh_sync.vel_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_turning_speed_x,
			{ "turning_speed_x", "samprpc.unoccupied_veh_sync.turning_speed_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_turning_speed_y,
			{ "turning_speed_y", "samprpc.unoccupied_veh_sync.turning_speed_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_turning_speed_z,
			{ "turning_speed_z", "samprpc.unoccupied_veh_sync.turning_speed_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &unoccupied_veh_sync_health,
			{ "health", "samprpc.unoccupied_veh_sync.health",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},

		{ &spec_sync_playerid,
			{ "playerid", "samprpc.spec_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_leftright_keys,
			{ "leftright_keys", "samprpc.spec_sync.leftright_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_updown_keys,
			{ "updown_keys", "samprpc.spec_sync.updown_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_keys,
			{ "keys", "samprpc.spec_sync.keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_pos_x,
			{ "pos_x", "samprpc.spec_sync.pos_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_pos_y,
			{ "pos_y", "samprpc.spec_sync.pos_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &spec_sync_pos_z,
			{ "pos_z", "samprpc.spec_sync.pos_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},

		{ &passenger_sync_playerid,
			{ "playerid", "samprpc.passenger_sync.playerid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_vehicleid,
			{ "vehicleid", "samprpc.passenger_sync.vehicleid",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_seat_flags,
			{ "seat_flags", "samprpc.passenger_sync.seat_flags",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_driveby,
			{ "driveby", "samprpc.passenger_sync.driveby",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_currentweapon,
			{ "currentweapon", "samprpc.passenger_sync.currentweapon",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_health,
			{ "health", "samprpc.passenger_sync.health",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_armour,
			{ "armour", "samprpc.passenger_sync.armour",
			FT_UINT8, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_leftright_keys,
			{ "leftright_keys", "samprpc.passenger_sync.leftright_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_updown_keys,
			{ "updown_keys", "samprpc.passenger_sync.updown_keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_keys,
			{ "keys", "samprpc.passenger_sync.keys",
			FT_UINT16, BASE_DEC,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_pos_x,
			{ "pos_x", "samprpc.passenger_sync.pos_x",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_pos_y,
			{ "pos_y", "samprpc.passenger_sync.pos_y",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
		{ &passenger_sync_pos_z,
			{ "pos_z", "samprpc.passenger_sync.pos_z",
			FT_FLOAT, BASE_NONE,
			NULL, 0x0,
			NULL, HFILL }
		},
	};

	RPCNameMap mp_rpc_map[] = {
		{"SetPlayerPos", ESAMPRPC_SetPlayerPos, {{"x", EVariableType_Float,true, true}, 
													{"y", EVariableType_Float,true, true}, 
													{"z", EVariableType_Float,true, true}, 
													{NULL, EVariableType_NoInit}}},
		{"SetPlayerPosFindZ", ESAMPRPC_SetPlayerPosFindZ, {{"x", EVariableType_Float,true, true}, 
													{"y", EVariableType_Float,true, true}, 
													{"z", EVariableType_Float,true, true}, 
													{NULL, EVariableType_NoInit}}},
		{"ScoreboardSelectPlayer", ESAMPRPC_ScoreboardSelectPlayer, {{"id", EVariableType_Uint16,true, false}, 
													{"unk", EVariableType_Uint16,true, false}, 
													{NULL, EVariableType_NoInit}}},
											
		{"SetPlayerArmour", ESAMPRPC_SetPlayerArmour, {
														{"Armour", EVariableType_Float,true, true}, 
														{NULL, EVariableType_NoInit}}},
		{"SetPlayerSkin", ESAMPRPC_SetPlayerSkin, {		{"ID", EVariableType_Uint32,true, true}, 
														{"Skin", EVariableType_Uint32,true, true}, 
														{NULL, EVariableType_NoInit}}},
		{"SetPlayerHealth", ESAMPRPC_SetPlayerHealth, {		{"Health", EVariableType_Float,true, true},  
														{NULL, EVariableType_NoInit}}},
		{"ClientJoin", ESAMPRPC_ClientJoin, {{"NetCodeVer", EVariableType_Uint32,true, true}, 
														{"Mod", EVariableType_Uint8,true, true}, 
														{"Name", EVariableType_LenStr,true, true}, 
														{"Challenge", EVariableType_Uint32,true, true}, 
														{"GPCI", EVariableType_LenStr,true, true}, 
														{"Version", EVariableType_LenStr,true, true}, 
														{"Unknown", EVariableType_Uint32,true, true}, 
														{NULL, EVariableType_NoInit}}},
		{"NPCJoin", ESAMPRPC_NPCJoin, {{"NetCodeVer", EVariableType_Uint32,true, true}, 
														{"Mod", EVariableType_Uint8,true, true}, 
														{"Name", EVariableType_LenStr,true, true}, 
														{"Unknown", EVariableType_Uint32,true, true}, 
														{NULL, EVariableType_NoInit}}},
		{"EnterVehicle", ESAMPRPC_EnterVehicle, {
														{"playerid", EVariableType_Uint16,false, true}, 
														{"vehicleid", EVariableType_Uint16,true, true}, 
														{"seat", EVariableType_Uint8,true, true},
														{NULL, EVariableType_NoInit},
												},
		},
		{"SelectObject", ESAMPRPC_SelectObject, {
														

														//client
														{"unk", EVariableType_Uint32,true, false}, 
														{"id", EVariableType_Uint16,true, false}, 
														{"model", EVariableType_Uint32,true, false}, 
														{"x", EVariableType_Float,true, false}, 
														{"y", EVariableType_Float,true, false}, 
														{"z", EVariableType_Float,true, false}, 

														//both
														{"unk", EVariableType_Uint8,true, true}, 
														{NULL, EVariableType_NoInit}
												},
		},
		
		{"CancelEdit", ESAMPRPC_CancelEdit, {
														{"unk", EVariableType_Uint8,true, true},  //possibly padding
														{NULL, EVariableType_NoInit}}},
		{"SetPlayerTime", ESAMPRPC_SetPlayerTime, {
														{"hour", EVariableType_Uint8,false, true}, 
														{"minute", EVariableType_Uint8,false, true}, 
														{"unk", EVariableType_Uint8,false, true},  //possibly padding
														{NULL, EVariableType_NoInit}}},

		{"ToggleClock", ESAMPRPC_ToggleClock, {
														{"status", EVariableType_Uint8,false, true}, 
														{NULL, EVariableType_NoInit}}},

														
		
		{"AddPlayerToWorld", ESAMPRPC_AddPlayerToWorld,  {{"id", EVariableType_Uint16,false, true},
														{"team", EVariableType_Uint8,false, true},
														{"skin", EVariableType_Uint32,false, true},
														{"x", EVariableType_Float,false, true},
														{"y", EVariableType_Float,false, true},
														{"z", EVariableType_Float,false, true},
														{"z_angle", EVariableType_Float,false, true},
														{"colour", EVariableType_Uint32,false, true},
														{"fightstyle", EVariableType_Uint8,false, true},
														{NULL, EVariableType_NoInit}}},
		{"Death", ESAMPRPC_Death, {
									{"reason", EVariableType_Uint8,true, true}, 
									{"killerid", EVariableType_Uint16,true, true}, 
									{NULL, EVariableType_NoInit}}},
		{"DeletePlayerFromWorld", ESAMPRPC_DeletePlayerFromWorld, {
									{"id", EVariableType_Uint16,false, true}, 
									{NULL, EVariableType_NoInit}}},
		{"Create3DTextLabel", ESAMPRPC_Create3DTextLabel, {
												{"id", EVariableType_Uint16,true, true}, 
												{"colour", EVariableType_Uint32,true, true}, 
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"z", EVariableType_Float,true, true}, 
												{"drawdist", EVariableType_Float,true, true}, 
												{"test_los", EVariableType_Uint8,true, true}, 
												{"playerid", EVariableType_Uint16,true, true}, 
												{"vehicle", EVariableType_Uint16,true, true}, 
												{"text", EVariableType_LenStr_Compressed,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"DisableCheckpoint", ESAMPRPC_DisableCheckpoint, {
												{"flag", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"DisableRaceCheckpoint", ESAMPRPC_DisableRaceCheckpoint, {
												{"flag", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"Destroy3DTextLabel", ESAMPRPC_Delete3DTextLabel, {
												{"id", EVariableType_Uint16,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
												
		{"ClientCmd", ESAMPRPC_ClientCommand, {
												{"Command", EVariableType_LenU32Str,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ClientSpawn", ESAMPRPC_ClientSpawned, {
												{"unk", EVariableType_Uint8,true, false}, 
												{NULL, EVariableType_NoInit}
											}},
		{"DeathMessage", ESAMPRPC_DeathMessage, {
														{"playerid", EVariableType_Uint16,true, true}, 
														{"killerid", EVariableType_Uint16,true, true}, 
														{"reason", EVariableType_Uint8,true, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"Delete3DTextLabel", ESAMPRPC_Delete3DTextLabel, {
														{"id", EVariableType_Uint16,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"SendPlayerDialog", ESAMPRPC_SendPlayerDialog, {
														{"id", EVariableType_Uint16,true, true}, 
														{"type", EVariableType_Uint8,true, true}, 
														{"title", EVariableType_LenStr,true, true}, 
														{"button_1", EVariableType_LenStr,true, true}, 
														{"button_2", EVariableType_LenStr,true, true}, 
														{"msg", EVariableType_LenStr_Compressed,true, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"DialogResponse", ESAMPRPC_DialogResponse, {
														{"id", EVariableType_Uint16,true, true}, 
														{"button", EVariableType_Uint8,true, true}, 
														{"selected_item", EVariableType_Uint16,true, true}, 
														{"response", EVariableType_LenStr,true, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"DestroyPickup", ESAMPRPC_DestroyPickup, {
														{"id", EVariableType_Uint32,false, true}, 
														{"unk", EVariableType_Uint8,false, true}, 
														{NULL, EVariableType_NoInit}}
														},

		{"LinkVehicleToInterior", ESAMPRPC_LinkVehicleToInterior, {
														{"vehicleid", EVariableType_Uint16,false, true}, 
														{"interiorid", EVariableType_Uint8,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
															
		{"ShowGameText", ESAMPRPC_ShowGameText, {
														{"style", EVariableType_Uint32,false, true}, 
														{"time", EVariableType_Uint32,false, true}, 
														{"message", EVariableType_LenU32Str,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"ForceClassSelection", ESAMPRPC_ForceClassSelection, {
														{"unk", EVariableType_Uint8,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
															
		{"CreateExplosion", ESAMPRPC_CreateExplosion, {
														{"x", EVariableType_Float,false, true}, 
														{"y", EVariableType_Float,false, true}, 
														{"z", EVariableType_Float,false, true}, 
														{"type", EVariableType_Uint16,false, true}, 
														{"radius", EVariableType_Float,false, true}, 
														{"unknown", EVariableType_Uint8,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"SetInterior", ESAMPRPC_SetInterior, {
														{"id", EVariableType_Uint8,true, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"MapMarker", ESAMPRPC_MapMarker, {
														{"x", EVariableType_Float,true, false}, 
														{"y", EVariableType_Float,true, false}, 
														{"z", EVariableType_Float,true, false}, 
														{"pad", EVariableType_Uint8,true, false}, 
														{NULL, EVariableType_NoInit}}
														},
															
		{"TogglePlayerSpectating", ESAMPRPC_TogglePlayerSpectating, {
														{"status", EVariableType_Uint8,false, true}, 
														{"playerid", EVariableType_Uint16,false, true}, 
														{"unk", EVariableType_Uint16,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"PlayerSpectatePlayer", ESAMPRPC_PlayerSpectatePlayer, {
														{"playerid", EVariableType_Uint16,false, true}, 
														{"unk", EVariableType_Uint16,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"PlayerSpectateVehicle", ESAMPRPC_PlayerSpectateVehicle, {
														{"vehicleid", EVariableType_Uint16,false, true}, 
														{"unk", EVariableType_Uint16,false, true}, 
														{NULL, EVariableType_NoInit}}
														},
		{"RequestClass", ESAMPRPC_RequestClass, {
														{"class_id", EVariableType_Uint32,true, false}, 
														{"unknown", EVariableType_Uint8,false, true}, 

														{"team", EVariableType_Uint8,false, true}, 
														{"skin", EVariableType_Uint32,false, true}, 
														{"unknown2", EVariableType_Uint8,false, true}, 
														{"x", EVariableType_Float,false, true}, 
														{"y", EVariableType_Float,false, true}, 
														{"z", EVariableType_Float,false, true}, 
														{"z_angle", EVariableType_Float,false, true}, 

														{"weapon_1", EVariableType_Int32,false, true},
														{"weapon_2", EVariableType_Int32,false, true},
														{"weapon_3", EVariableType_Int32,false, true},

														{"ammo_1", EVariableType_Int32,false, true},
														{"ammo_2", EVariableType_Int32,false, true},
														{"ammo_3", EVariableType_Int32,false, true},
														{NULL, EVariableType_NoInit}}
														},
		{"RequestSpawn", ESAMPRPC_RequestSpawn, {
														{"unknown", EVariableType_Uint8,true, false},
														{"unknown2", EVariableType_Uint32,false, true},
														{"unknown3", EVariableType_Uint32,false, true},
														{NULL, EVariableType_NoInit}}
														},
		{"ConnectionRejected", ESAMPRPC_ConnectionRejected, {
														{"reason", EVariableType_Uint8,false, true}, 
															/*
																reason = 0 - unknown
																reason 1 = invalid version
																reason 2 = invalid nick
																reason 3 = bad mod version
																reason 4 = unable to allocate player slot
															*/
														{NULL, EVariableType_NoInit}}
														},
		{"SetVehiclePos", ESAMPRPC_SetVehiclePos, {
														{"id", EVariableType_Uint16,false, true}, 
														{"x", EVariableType_Float,false, true}, 
														{"y", EVariableType_Float,false, true}, 
														{"z", EVariableType_Float,false, true}, 
														{NULL, EVariableType_NoInit}},
		},
		{"SetVehicleZAngle", ESAMPRPC_SetVehicleZAngle, {
														{"id", EVariableType_Uint16,false, true}, 
														{"angle", EVariableType_Float,false, true}, 
														{NULL, EVariableType_NoInit}},
		},
		{"VehicleCreate", ESAMPRPC_VehicleCreate, {
													{"id", EVariableType_Uint16,true, true}, 
													{"modelid", EVariableType_Uint32,true, true}, 
													{"x", EVariableType_Float,true, true}, 
													{"y", EVariableType_Float,true, true}, 
													{"z", EVariableType_Float,true, true}, 
													
													{"zrot", EVariableType_Float,true, true}, 
													
													{"col1", EVariableType_Uint8,true, true}, 
													{"col2", EVariableType_Uint8,true, true}, 
													{"health", EVariableType_Float,true, true}, 
													{"interior", EVariableType_Uint8,true, true}, 
													{"door_damage", EVariableType_Uint32,true, true}, 
													{"panel_damage", EVariableType_Uint32,true, true}, 
													{"light_damage", EVariableType_Uint8,true, true}, 
													{"tire_damage", EVariableType_Uint8,true, true}, 
													{"siren", EVariableType_Uint8,true, true}, 												
													//lame
													{"comp1", EVariableType_Uint8,true, true}, 
													{"comp2", EVariableType_Uint8,true, true}, 
													{"comp3", EVariableType_Uint8,true, true}, 
													{"comp4", EVariableType_Uint8,true, true}, 
													{"comp5", EVariableType_Uint8,true, true}, 
													{"comp6", EVariableType_Uint8,true, true}, 
													{"comp7", EVariableType_Uint8,true, true}, 
													{"comp8", EVariableType_Uint8,true, true}, 
													{"comp9", EVariableType_Uint8,true, true}, 
													{"comp10", EVariableType_Uint8,true, true}, 
													{"comp11", EVariableType_Uint8,true, true}, 
													{"comp12", EVariableType_Uint8,true, true}, 
													{"comp13", EVariableType_Uint8,true, true}, 
													{"comp14", EVariableType_Uint8,true, true}, 
													{"col32_1", EVariableType_Uint32,true, true}, 
													{"col32_2", EVariableType_Uint32,true, true}, 
													{"unknown", EVariableType_Uint8,true, true}, 
													{NULL, EVariableType_NoInit}
												}},
		{"VehicleDestroy", ESAMPRPC_VehicleDelete, {
												{"id", EVariableType_Uint16,false, true}, 
												{"unknown1", EVariableType_Uint32,false, true}, //literally just an uninitalized integer from SAMP server, possibly from alignment
												{NULL, EVariableType_NoInit}
											}},
		{"ExitVehicle", ESAMPRPC_ExitVehicle, {
												{"playerid", EVariableType_Uint16,false, true}, 
												{"vehicleid", EVariableType_Uint16,true, true}, 
												{"pad", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"SendClientMessage", ESAMPRPC_SendClientMessage, {
												{"Colour", EVariableType_Uint32,true, true}, 
												{"Message", EVariableType_LenU32Str,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ShowTextDraw", ESAMPRPC_ShowTextDraw, {
												{"id", EVariableType_Uint16,true, true}, 
												{"flags", EVariableType_Uint8,true, true}, 
												{"font_width", EVariableType_Float,true, true}, 
												{"font_height", EVariableType_Float,true, true}, 
												{"font_colour", EVariableType_Uint32,true, true}, 
												{"box_width", EVariableType_Float,true, true}, 
												{"box_height", EVariableType_Float,true, true}, 
												{"box_colour", EVariableType_Uint32,true, true}, 
												{"shadow", EVariableType_Uint8,true, true}, 
												{"outline", EVariableType_Uint8,true, true}, 
												{"background_colour", EVariableType_Uint32,true, true}, 
												{"style", EVariableType_Uint8,true, true}, 
												{"selectable", EVariableType_Uint8,true, true}, 
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"model", EVariableType_Uint16,true, true}, 
												{"rx", EVariableType_Float,true, true}, 
												{"ry", EVariableType_Float,true, true}, 
												{"rz", EVariableType_Float,true, true}, 
												{"zoom", EVariableType_Float,true, true}, 
												{"model_col1", EVariableType_Uint16,true, true}, 
												{"model_col2", EVariableType_Uint16,true, true}, 
												{"msg", EVariableType_LenU16Str,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"EditTextDraw", ESAMPRPC_EditTextDraw, {
												{"id", EVariableType_Uint16,false, true}, 
												{"message", EVariableType_LenU16Str,false, true}, 
												{"pad", EVariableType_Uint8,false, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"OnVehicleDamage", ESAMPRPC_OnVehicleDamage, {
												{"vehicleid", EVariableType_Uint16,true, true}, 
												{"flags1", EVariableType_Uint32,true, true}, 
												{"flags2", EVariableType_Uint32,true, true}, 
												{"tire_flags", EVariableType_Uint16,true, true}, 
												{"pad", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"SetPlayerCheckpoint", ESAMPRPC_SetPlayerCheckpoint, {
												{"x", EVariableType_Float,false, true}, 
												{"y", EVariableType_Float,false, true}, 
												{"z", EVariableType_Float,false, true}, 
												{"size", EVariableType_Float,false, true}, 
												{"unk", EVariableType_Uint8,false, true}, 
												{NULL, EVariableType_NoInit}
											}},

		{"SetRaceCheckpoint", ESAMPRPC_SetRaceCheckpoint, {
												{"type", EVariableType_Uint8,false, true}, 
												{"x", EVariableType_Float,false, true}, 
												{"y", EVariableType_Float,false, true}, 
												{"z", EVariableType_Float,false, true}, 
												{"next_x", EVariableType_Float,false, true}, 
												{"next_y", EVariableType_Float,false, true}, 
												{"next_z", EVariableType_Float,false, true}, 
												{"size", EVariableType_Float,false, true}, 
												{"unk", EVariableType_Uint8,false, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ChatMessage", ESAMPRPC_ChatMessage, {
												{"id", EVariableType_Uint16,false, true}, 
												{"Message", EVariableType_LenStr,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ClientCheck", ESAMPRPC_ClientCheck, {
												{"type", EVariableType_Uint8,true, true}, 
												{"action", EVariableType_Uint32,false, true}, 
												{"offset", EVariableType_Uint16,false, true}, 
												{"bytes", EVariableType_Uint16,false, true}, 

												{"flags", EVariableType_Uint16,true, false}, 
												{"response", EVariableType_Uint8,true, false}, 
												{"unk", EVariableType_Uint32,true, false}, 

												{NULL, EVariableType_NoInit}
											}},
		{"RemovePlayerFromVehicle", ESAMPRPC_RemovePlayerFromVehicle, {NULL, EVariableType_NoInit}},
		{"SetPlayerColour", ESAMPRPC_SetPlayerColor, {
												{"id", EVariableType_Uint16,true, true}, 
												{"colour", EVariableType_Uint32,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ShowNameTag", ESAMPRPC_ShowNameTag, {
												{"playerid", EVariableType_Uint16,true, true}, 
												{"state", EVariableType_Uint8,true, true}, 
												{"pad", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
												
		{"InterpolateCamera", ESAMPRPC_InterpolateCamera, {
												{"sx", EVariableType_Float,false, true}, 
												{"sy", EVariableType_Float,false, true}, 
												{"sz", EVariableType_Float,false, true}, 
												{"tox", EVariableType_Float,false, true}, 
												{"toy", EVariableType_Float,false, true}, 
												{"toz", EVariableType_Float,false, true}, 
												{"time_ms", EVariableType_Uint32,false, true}, 
												{"cut", EVariableType_Uint8,false, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"SelectTextDraw", ESAMPRPC_SelectTextDraw, {
			{"sx", EVariableType_Uint16,true, false}, 
			{"unk1", EVariableType_Uint8,false, true}, 
			{"unk2", EVariableType_Uint16,false, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetObjectMaterialText", ESAMPRPC_SetObjectMaterialText, {
				{"callback", EVariableType_Custom,true, true}
			},
			//SetObjectMaterialRPCToPyDict, SetObjectMaterialPyDictToRPC
		},
		{"GangZoneStopFlash", ESAMPRPC_GangZoneStopFlash, {
			{"id", EVariableType_Uint16,false, true}, 
			{"pad", EVariableType_Uint8,false, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"PlayerUpdate", ESAMPRPC_PlayerUpdate, {
												{"unknown", EVariableType_Uint32,true, true}, 
												{"pad", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"SetMapIcon", ESAMPRPC_SetMapIcon, {
												{"iconid", EVariableType_Uint8,true, true}, 
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"z", EVariableType_Float,true, true},
												{"markertype", EVariableType_Uint8,true, true}, 
												{"colour", EVariableType_Uint32,true, true}, 
												{"style", EVariableType_Uint8,true, true},
												{NULL, EVariableType_NoInit}
												}},
		{"ServerJoin", ESAMPRPC_ServerJoin, {
												{"id", EVariableType_Uint16,true, true}, 
												{"colour", EVariableType_Uint32,true, true}, 
												{"npc", EVariableType_Uint8,true, true}, 
												{"name", EVariableType_LenStr,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"ServerQuit", ESAMPRPC_ServerQuit, {
												{"id", EVariableType_Uint16,true, true}, 
												{"reason", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"PlayerDeath", ESAMPRPC_PlayerDeath, {{"id", EVariableType_Uint16,true, true},{"reason", EVariableType_Uint8,true, true},  {NULL, EVariableType_NoInit}}},
		{"ShowTextDraw", ESAMPRPC_ShowTextDraw, {{"id", EVariableType_Uint16,false, true}, {"pad", EVariableType_Uint8,false, true},  {NULL, EVariableType_NoInit}}},
		{"HideTextDraw", ESAMPRPC_HideTextDraw, {{"id", EVariableType_Uint16,false, true}, {"pad", EVariableType_Uint8,false, true},  {NULL, EVariableType_NoInit}}},
		{"VehicleDestroyed", ESAMPRPC_VehicleDestroyed, {{"id", EVariableType_Uint16,false, true}, {"pad", EVariableType_Uint8,false, true},  {NULL, EVariableType_NoInit}}},	
		{"CreatePickup", ESAMPRPC_CreatePickup, {
												{"id", EVariableType_Uint32,true, true}, 
												{"model", EVariableType_Uint32,true, true}, 
												{"type", EVariableType_Uint32,true, true}, 
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"z", EVariableType_Float,true, true}, 
												{NULL, EVariableType_NoInit}}
											},
		{"SetCarPlate", ESAMPRPC_SetCarPlate, {
												{"vehicleid", EVariableType_Uint16,true, true}, 
												{"plate", EVariableType_LenStr,true, true}, 
												{NULL, EVariableType_NoInit}}
											},
		{"SetPlayerWantedLevel", ESAMPRPC_SetPlayerWantedLevel, {
												{"level", EVariableType_Uint8, true, true}, 
												{NULL, EVariableType_NoInit}}
											},
		{"RemoveBuilding", ESAMPRPC_RemoveBuilding, {
												{"modelid", EVariableType_Uint32,true, true}, 
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"z", EVariableType_Float,true, true}, 
												{"radius", EVariableType_Float,true, true}, 
												{NULL, EVariableType_NoInit}}
											},

		{
			"InitGame",  ESAMPRPC_InitGame, {
				{"callback", EVariableType_Custom,true, true},
				{NULL, EVariableType_NoInit}
			},
			//NULL, GameInitPyDictToRPC
		},


		{"CreateObject", ESAMPRPC_CreateObject, /*{
													{"id", EVariableType_Uint16,true, true}, 
													{"modelid", EVariableType_Uint32,true, true}, 
													{"x", EVariableType_Float,true, true}, 
													{"y", EVariableType_Float,true, true}, 
													{"z", EVariableType_Float,true, true}, 
													{"rx", EVariableType_Float,true, true}, 
													{"ry", EVariableType_Float,true, true}, 
													{"rz", EVariableType_Float,true, true}, 
													{"drawdist", EVariableType_Float,true, true}, 
													{NULL, EVariableType_NoInit}
														}*/
			{
				{"callback", EVariableType_Custom,true, true},
				{NULL, EVariableType_NoInit}
			},
			//CreateObjectRPCToPyDict, CreateObjectPyDictToRPC
		},
		{"SetObjectPos", ESAMPRPC_SetObjectPos, {
			{"id", EVariableType_Uint16,false, true},
			{"x", EVariableType_Float,false, true},
			{"y", EVariableType_Float,false, true},
			{"z", EVariableType_Float,false, true},
			{"unk", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetObjectRot", ESAMPRPC_SetObjectRot, {
			{"id", EVariableType_Uint16,false, true},
			{"rx", EVariableType_Float,false, true},
			{"ry", EVariableType_Float,false, true},
			{"rz", EVariableType_Float,false, true},
			{"unk", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"DeleteObject", ESAMPRPC_DeleteObject, {
			{"id", EVariableType_Uint16,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetCameraPos", ESAMPRPC_SetCameraPos, {
												{"x", EVariableType_Float,true, true}, 
												{"y", EVariableType_Float,true, true}, 
												{"z", EVariableType_Float,true, true},
												{NULL, EVariableType_NoInit}
												}},
		{"SetCameraLookAt", ESAMPRPC_SetCameraLookAt, {
												{"x", EVariableType_Float,false, true}, 
												{"y", EVariableType_Float,false, true}, 
												{"z", EVariableType_Float,false, true},
												{"cut", EVariableType_Uint8,false, true},
												{NULL, EVariableType_NoInit}
												}},
													
		{"ResetMoney", ESAMPRPC_ResetMoney, {
												{"flags", EVariableType_Uint8,false, true},
												{NULL, EVariableType_NoInit}
												}},
		{"ResetPlayerWeapons", ESAMPRPC_ResetPlayerWeapons, {
												{"flags", EVariableType_Uint8,false, true},
												{NULL, EVariableType_NoInit}
												}},
		{"GivePlayerWeapon", ESAMPRPC_GivePlayerWeapon, {
												{"weapon", EVariableType_Uint32,false, true}, 
												{"ammo", EVariableType_Uint32,false, true}, 
												{"flags", EVariableType_Uint8,false, true},
												{NULL, EVariableType_NoInit}
												}},
		//
		{"PlayAudioStream", ESAMPRPC_PlayAudioStream, {
												{"url", EVariableType_LenStr,false, true}, 
												{"x", EVariableType_Float,false, true}, 
												{"y", EVariableType_Float,false, true}, 
												{"z", EVariableType_Float,false, true}, 
												{"distance", EVariableType_Float,false, true}, 
												{"usepos", EVariableType_Uint16,false, true},
												{NULL, EVariableType_NoInit}
												}},
		{"StopAudioStream", ESAMPRPC_StopAudioStream, {
												{"unknown", EVariableType_Uint8,false, true},
												{NULL, EVariableType_NoInit}
												}},
		{"SetInterior", ESAMPRPC_SetInterior, {
												{"id", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
												}},
		{"ScrSetInterior", ESAMPRPC_ScrSetInterior, {
												{"id", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
												}},
		{"SetPlayerName", ESAMPRPC_SetPlayerName, {
												{"id", EVariableType_Uint16,false, true}, 
												{"name", EVariableType_LenStr,false, true}, 
												{"unknown1", EVariableType_Uint8,false, true}, 
												{"unknown2", EVariableType_Uint8,false, true}, 
												{"unknown3", EVariableType_Uint8,false, true}, 
												{"unknown4", EVariableType_Uint8,false, true}, 
												{"unknown5", EVariableType_Uint8,false, true}, 
												{NULL, EVariableType_NoInit}
											}},
		{"GiveMoney", ESAMPRPC_GiveMoney, {
												{"money", EVariableType_Uint32,false, true}, 
												{"pad", EVariableType_Uint8,true, true}, 
												{NULL, EVariableType_NoInit}
												}},
		{"UpdateScoreboardPingIPS", ESAMPRPC_UpdateScoresPingsIP, {
				{"unk", EVariableType_Uint8,true, false}, 
				{"callback", EVariableType_Custom,false, true},
				{NULL, EVariableType_NoInit}
			},
				/*UpdateScoreBoardPingsIPRPCToPyDict, UpdateScoreBoardPingsIPPyDictToRPC*/},
		{"TogglePlayerControllable", ESAMPRPC_TogglePlayerControllable, {
									{"enabled", EVariableType_Uint8,true, true}, 
									{NULL, EVariableType_NoInit}}},
		{"PlaySound", ESAMPRPC_PlaySound, {
									{"sound", EVariableType_Uint32,false, true}, 
									{"x", EVariableType_Float,false, true}, 
									{"y", EVariableType_Float,false, true}, 
									{"z", EVariableType_Float,false, true}, 
									{"pad", EVariableType_Uint8,false, true}, 
									{NULL, EVariableType_NoInit}}},
		{"SetWorldBounds", ESAMPRPC_SetWorldBounds, {
												{"maxx", EVariableType_Float,false, true}, 
												{"minx", EVariableType_Float,false, true}, 
												{"maxy", EVariableType_Float,false, true}, 
												{"miny", EVariableType_Float,false, true}, 
												{NULL, EVariableType_NoInit}
												}},
		{"SetPlayerFacingAngle", ESAMPRPC_SetPlayerFacingAngle, {
									{"angle", EVariableType_Float,true, true}, 
									{"pad", EVariableType_Uint8,true, true}, 
									{NULL, EVariableType_NoInit}}},
		{"PutPlayerInVehicle", ESAMPRPC_PutPlayerInVehicle, {
					{"carid", EVariableType_Uint16,true, true}, 
					{"seat", EVariableType_Uint8,true, true}, 
					{NULL, EVariableType_NoInit}
				}},
		{"SetPlayerSkillLevel", ESAMPRPC_SetPlayerSkillLevel, {
					{"id", EVariableType_Uint16,false, true}, 
					{"weapon", EVariableType_Uint32,false, true}, 
					{"level", EVariableType_Uint16,false, true}, 
					{"unknown", EVariableType_Uint8,false, true}, 
					{NULL, EVariableType_NoInit}
				}},
		{"SetPlayerDrunkLevel", ESAMPRPC_SetPlayerDrunkLevel, {
					{"level", EVariableType_Uint32, false, true},
					{NULL, EVariableType_NoInit}
				}},
		{"OnPickupPickup", ESAMPRPC_PickupPickup, {
										{"id", EVariableType_Uint32,true, true}, 
										{NULL, EVariableType_NoInit}
									}},
		{"ScmEvent", ESAMPRPC_ScmEvent, {
										{"playerid", EVariableType_Uint16,true, true}, 
										{"event", EVariableType_Uint32,true, true}, 
										{"params1", EVariableType_Uint32,true, true}, 
										{"params2", EVariableType_Uint32,true, true}, 
										{"params3", EVariableType_Uint32,true, true}, 
										{NULL, EVariableType_NoInit}
									}},

		{"GiveTakeDamage", ESAMPRPC_GiveTakeDamage, {
										{"issuerid", EVariableType_Uint16,true, false}, 
										{"unk", EVariableType_CompressedBool,true, false}, 
										{"amount", EVariableType_Float,true, false}, 
										{"weapon", EVariableType_Uint32,true, false}, 
										{"bodypart", EVariableType_Uint8,true, false}, 
										{NULL, EVariableType_NoInit}
									}},
		{"EditAttachedObject", ESAMPRPC_EditAttachedObject, {
										{"index", EVariableType_Uint32,false, true}, 
										{"pad", EVariableType_Uint8,false, true}, 

										//{"playerobject", EVariableType_CompressedBool,true, false}, 
										{"response", EVariableType_Uint32,true, false},
										{"unk", EVariableType_Uint32,true, false},
										{"model", EVariableType_Uint32,true, false},
										{"bone", EVariableType_Uint32,true, false},
										//{"unk2", EVariableType_Uint8,true, false}, 
										{"x", EVariableType_Float,true, false}, 
										{"y", EVariableType_Float,true, false}, 
										{"z", EVariableType_Float,true, false}, 
										{"rx", EVariableType_Float,true, false}, 
										{"ry", EVariableType_Float,true, false}, 
										{"rz", EVariableType_Float,true, false}, 
										{"sx", EVariableType_Float,true, false}, 
										{"sy", EVariableType_Float,true, false}, 
										{"sz", EVariableType_Float,true, false}, 
										{"unk1", EVariableType_Uint32,true, false}, 
										{"unk2", EVariableType_Uint32,true, false}, 
										{"unk3", EVariableType_Uint8,true, false}, 
										{NULL, EVariableType_NoInit}
									}},
		{"EditObject", ESAMPRPC_EditObject, {
										{"unk", EVariableType_CompressedBool,false, true}, 
										{"objectid", EVariableType_Uint16,false, true}, 
										{"pad", EVariableType_Uint8,false, true}, 

										{"playerobject", EVariableType_CompressedBool,true, false}, 
										{"objectid", EVariableType_Uint16,true, false}, 
										{"response", EVariableType_Uint32,true, false}, 
										//{"unk2", EVariableType_Uint8,true, false}, 
										{"x", EVariableType_Float,true, false}, 
										{"y", EVariableType_Float,true, false}, 
										{"z", EVariableType_Float,true, false}, 
										{"rx", EVariableType_Float,true, false}, 
										{"ry", EVariableType_Float,true, false}, 
										{"rz", EVariableType_Float,true, false}, 
										{NULL, EVariableType_NoInit}
									}},
		
		{"SetPlayerTeam", ESAMPRPC_SetPlayerTeam, {
										{"id", EVariableType_Uint8,true, true}, 
										{NULL, EVariableType_NoInit}
									}},
										
		{"SetPlayerSpawnInfo", ESAMPRPC_SetPlayerSpawnInfo, {
										{"team", EVariableType_Uint8,false, true}, 
										{"skin", EVariableType_Uint32,false, true}, 
										{"unknown", EVariableType_Uint8,false, true},
										{"x", EVariableType_Float,false, true}, 
										{"y", EVariableType_Float,false, true}, 
										{"z", EVariableType_Float,false, true}, 
										{"z_angle", EVariableType_Float,false, true}, 
										{"weapon_1", EVariableType_Uint32, false, true}, 
										{"weapon_2", EVariableType_Uint32,false, true}, 
										{"weapon_3", EVariableType_Uint32,false, true}, 
										{"ammo_1", EVariableType_Uint32,false, true}, 
										{"ammo_2", EVariableType_Uint32,false, true}, 
										{"ammo_3", EVariableType_Uint32,false, true}, 
										{NULL, EVariableType_NoInit}
									}},
		{"SetPlayerHoldingWeapon", ESAMPRPC_SetPlayerHoldingWeapon, {
										{"weaponid", EVariableType_Uint32,true, true}, 
										{"unk", EVariableType_Uint8,true, true}, 
										{NULL, EVariableType_NoInit}
									}},
		{"SetVehicleParams", ESAMPRPC_SetVehicleParams, {
			{"vehicleid", EVariableType_Uint16,true, true}, 
			{"engine", EVariableType_Uint8,true, true}, 
			{"lights", EVariableType_Uint8,true, true}, 
			{"alarm", EVariableType_Uint8,true, true}, 
			{"locked", EVariableType_Uint8,true, true}, 
			{"bonnet", EVariableType_Uint8, true, true},
			{"boot", EVariableType_Uint8, true, true},
			{"objective", EVariableType_Uint8, true, true},
			{"unk1", EVariableType_Uint8,true, true},
			{"driver_window", EVariableType_Uint8,true, true}, 
			{"passenger_window", EVariableType_Uint8,true, true}, 
			{"backleft_window", EVariableType_Uint8,true, true}, 
			{"backright_window", EVariableType_Uint8,true, true}, 
			{"driver_door_open", EVariableType_Uint8,true, true}, 
			{"passenger_door_open", EVariableType_Uint8,true, true}, 
			{"backleft_door_open", EVariableType_Uint8,true, true},
			{"backright_door_open", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetPlayerSpecialAction", ESAMPRPC_SetPlayerSpecialAction, {
			{"action", EVariableType_Uint8,true, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetPlayerFightingStyle", ESAMPRPC_SetPlayerFightingStyle, {
			{"playerid", EVariableType_Uint16,false, true}, 
			{"action", EVariableType_Uint8,false, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetPlayerVelocity", ESAMPRPC_SetPlayerVelocity, {
			{"x", EVariableType_Float,false, true}, 
			{"y", EVariableType_Float,false, true}, 
			{"z", EVariableType_Float,false, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetVehicleVelocity", ESAMPRPC_SetVehicleVelocity, {
			{"vehicleid", EVariableType_Uint16,false, true}, 
			{"x", EVariableType_Float,false, true}, 
			{"y", EVariableType_Float,false, true}, 
			{"z", EVariableType_Float,false, true}, 
			{NULL, EVariableType_NoInit}
		}},
			
		{"ApplyAnimation", ESAMPRPC_ApplyAnimation, {
			{"playerid", EVariableType_Uint16,true, true}, 
			{"animlib", EVariableType_LenStr,true, true}, 
			{"animname", EVariableType_LenStr,true, true}, 
			{"delta", EVariableType_Float,true, true}, 
			{"unk1", EVariableType_Uint32,true, true}, 
			{"unk2", EVariableType_Uint8,true, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"ClearAnimations", ESAMPRPC_ClearAnimations, {
			{"force_sync", EVariableType_Uint32,true, true}, 
			{"pad", EVariableType_Uint8,true, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetVehicleHealth", ESAMPRPC_SetVehicleHealth, {
			{"id", EVariableType_Uint16,false, true},
			{"health", EVariableType_Float,false, true},
			{"unknown", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},	
		{"AttachTrailerToVehicle", ESAMPRPC_AttachTrailerToVehicle, {
			{"trailerid", EVariableType_Uint16,false, true},
			{"vehicleid", EVariableType_Uint16,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"DetachTrailerFromVehicle", ESAMPRPC_DetachTrailerFromVehicle, {
			{"id", EVariableType_Uint16,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"Weather", ESAMPRPC_SetPlayerWeather, {
			{"id", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"RemovePlayerMapIcon", ESAMPRPC_RemoveMapIcon, {
			{"id", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetGravity", ESAMPRPC_SetGravity, {
			{"gravity", EVariableType_Float,true, true},
			{"pad", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetVehicleParamsForPlayer", ESAMPRPC_SetVehicleParamsForPlayer, {
			{"vehicleid", EVariableType_Uint16,true, true},
			{"objective", EVariableType_Uint8,true, true},
			{"locked", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetCameraBehindPlayer", ESAMPRPC_SetCameraBehindPlayer, {
			{"flags", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
			
		{"CreateActor", ESAMPRPC_CreateActor, {
			{"id", EVariableType_Uint16,true, true},
			{"model", EVariableType_Uint16,true, true},
			{"unknown", EVariableType_Uint16,true, true},
			{"x", EVariableType_Float,true, true},
			{"y", EVariableType_Float,true, true},
			{"z", EVariableType_Float,true, true},
			{"z_angle", EVariableType_Float,true, true},
			{"health", EVariableType_Float,true, true},
			{"unknown", EVariableType_Uint16,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"DestroyActor", ESAMPRPC_DestroyActor, {
			{"id", EVariableType_Uint16,true, true},
			{"unknown", EVariableType_Uint8,true, true},
			{NULL, EVariableType_NoInit}
		}},
		{"ApplyActorAnim", ESAMPRPC_ApplyActorAnim, {
			{"actorid", EVariableType_Uint16,true, true},
			{"animlib", EVariableType_LenStr,true, true}, 
			{"animname", EVariableType_LenStr,true, true}, 
			{"delta", EVariableType_Float,true, true}, 
			{"flags", EVariableType_Uint8,true, true}, 
			{"time", EVariableType_Uint32,true, true}, 
			{NULL, EVariableType_NoInit}
		}},
		{"SetActorVulnerability", ESAMPRPC_SetActorVulnerability, {
			{"actorid", EVariableType_Uint16,false, true},
			{"vulnerable", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"SetActorPos", ESAMPRPC_SetActorPos, {
			{"actorid", EVariableType_Uint16,false, true},
			{"x", EVariableType_Float,false, true},
			{"y", EVariableType_Float,false, true},
			{"z", EVariableType_Float,false, true},
			{"unk", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"DisableRemoteVehicleCollisions", ESAMPRPC_DisableRemoteVehicleCollisions, {
			{"enabled", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{
			"UpdateScoresPingsIP",  ESAMPRPC_UpdateScoresPingsIP, {
				{"flags", EVariableType_Uint8,true, false}, 
				{"callback", EVariableType_Custom,false, true},
				{NULL, EVariableType_NoInit}
			}
		},
		{"EnablePlayerCameraTarget", ESAMPRPC_EnablePlayerCameraTarget, {
			{"enabled", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
			{"MoveObject", ESAMPRPC_MoveObject, {
			{"id", EVariableType_Uint16,false, true},
			{"x", EVariableType_Float,false, true},
			{"y", EVariableType_Float,false, true},
			{"z", EVariableType_Float,false, true},
			{"speed", EVariableType_Float,false, true},
			{"rx", EVariableType_Float,false, true},
			{"ry", EVariableType_Float,false, true},
			{"rz", EVariableType_Float,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"CameraTargetData", ESAMPRPC_CameraTargetData, {
			{"lookat_player", EVariableType_Uint16,true, false}, //-1 if not looking(same for other lookats)
			{"lookat_vehicle", EVariableType_Uint16,true, false},
			{"lookat_object", EVariableType_Uint16,true, false},
			{"lookat_actorid", EVariableType_Uint16,true, false},
			{"pad", EVariableType_Uint8,true, false},
			{NULL, EVariableType_NoInit}
		}},

		{"GetWorldTime", ESAMPRPC_WorldTime, { //probably not
			{"unk", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"AddGangZone", ESAMPRPC_AddGangZone, {
			{"id", EVariableType_Uint16,false, true},
			{"minx", EVariableType_Float,false, true},
			{"miny", EVariableType_Float,false, true},
			{"maxx", EVariableType_Float,false, true},
			{"maxy", EVariableType_Float,false, true},
			{"colour", EVariableType_Uint32,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"PlayCrimeReport", ESAMPRPC_PlayCrimeReport, {
			{"suspectid", EVariableType_Uint16,false, true},
			{"crimeid", EVariableType_Uint8,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
			
		{"SetPlayerAttachedObject", ESAMPRPC_SetPlayerAttachedObject, {
				{"callback", EVariableType_Custom,true, true},
				{NULL, EVariableType_NoInit}
			},
			//SetPlayerAttachedObjectRPCToPyDict, SetPlayerAttachedObjectPyDictToRPC
		},
		{"GangZoneDestroy", ESAMPRPC_GangZoneDestroy, {
			{"id", EVariableType_Uint16,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"GangZoneFlash", ESAMPRPC_GangZoneFlash, {
			{"id", EVariableType_Uint16,false, true},
			{"colour", EVariableType_Uint32,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"StopObject", ESAMPRPC_StopObject, {
			{"id", EVariableType_Uint16,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
			
		{"PlayerChatBubble", ESAMPRPC_PlayerChatBubble, {
			{"id", EVariableType_Uint16,false, true},
			{"colour", EVariableType_Uint32,false, true},
			{"drawdist", EVariableType_Float,false, true},
			{"expiretime", EVariableType_Uint32,false, true},
			{"pad", EVariableType_Uint8,false, true},
			{NULL, EVariableType_NoInit}
		}},
		{"OnDamageActor",ESAMPRPC_OnDamageActor, {
			{"id", EVariableType_Uint16,true, false}, 
			{"unk", EVariableType_CompressedBool,true, false}, 
			{"amount", EVariableType_Float,true, false}, 
			{"weapon", EVariableType_Uint32,true, false}, 
			{"bodypart", EVariableType_Uint8,true, false}, 
			{"unk1", EVariableType_Uint16,true, false},
			{"pad", EVariableType_Uint8,true, false},
			{NULL, EVariableType_NoInit}
		}},	
	};

	void init_standard_fields(int dissector) {
		proto_register_field_array(dissector, standard_fields_hf, array_length(standard_fields_hf));
	}


	void init_rpc_fields(int dissector) {
		init_standard_fields(dissector);
		//RPCNameMap mp_rpc_map
		for(int i=0;i<sizeof(mp_rpc_map) / sizeof(RPCNameMap);i++) {
			int c = 0;
			while(1) {
				header_field_info ws_field =
					{ NULL, NULL,
					FT_INT8, BASE_DEC,
					NULL, 0x0,
					NULL, HFILL };

				RPCVariableDesc *rpc_field = &mp_rpc_map[i].mp_rpc_var_desc[c];
				if(rpc_field->name == NULL) break;
				ws_field.name = rpc_field->name;
				ws_field.abbrev = rpc_field->name;
				switch(rpc_field->type) {
					case EVariableType_Uint32:
						ws_field.type = FT_UINT32;
						ws_field.display = BASE_DEC;
					break;
					case EVariableType_Int32:
						ws_field.type = FT_INT32;
						ws_field.display = BASE_DEC;
					break;
					case EVariableType_Int16:
						ws_field.type = FT_INT16;
						ws_field.display = BASE_DEC;
					break;
					case EVariableType_Uint16:
						ws_field.type = FT_UINT16;
						ws_field.display = BASE_DEC;
					break;
					case EVariableType_Uint8:
						ws_field.type = FT_UINT8;
						ws_field.display = BASE_DEC;
					break;
					case EVariableType_LenStr:
					case EVariableType_LenU16Str:
					case EVariableType_LenU32Str:
					case EVariableType_LenStr_Compressed:
						ws_field.type = FT_STRING;
						ws_field.display = BASE_NONE;
					break;
					case EVariableType_Float:
						ws_field.type = FT_FLOAT;
						ws_field.display = BASE_NONE;
					break;
					/*case FIELD_TYPE_IPV4:
						ws_field.type = FT_IPv4;
						ws_field.display = BASE_NONE;
					break;*/
				}
				rpc_field->wireshark_field.p_id = &rpc_field->wireshark_field_id;
				memcpy(&rpc_field->wireshark_field.hfinfo, &ws_field, sizeof(header_field_info));
				proto_register_field_array(dissector, &rpc_field->wireshark_field, 1);
				c++;
			}
		}
	}

	RPCNameMap *GetRPCMapByID(uint8_t msgid) {
		for(int i=0;i<sizeof(mp_rpc_map)/sizeof(RPCNameMap);i++) {
			if(mp_rpc_map[i].rpc_id == msgid) {
				return &mp_rpc_map[i];
			}		
		}
		return NULL;
	}
}