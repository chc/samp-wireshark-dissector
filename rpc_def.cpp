#include "rak_minimal/DS_RangeList.h"
#include "main.h"
#include "rpc_def.h"
#include "rak_minimal/StringCompressor.h"

//samp query
int samp_query_magic = -1;
int samp_query_ipv4_addr = -1;
int samp_query_port = -1;
int samp_query_opcode = -1;

//samp query info
int samp_query_info_resp_password = -1;
int samp_query_info_resp_numplayers = -1;
int samp_query_info_resp_maxplayers = -1;
int samp_query_info_resp_hostname = -1;
int samp_query_info_resp_gamemode = -1;
int samp_query_info_resp_language = -1;

//samp query rules
int samp_query_rules_resp_count = -1;
int samp_query_rules_resp_rulename = -1;
int samp_query_rules_resp_rulevalue = -1;

//samp query clients
int samp_query_clients_playercount = -1;
int samp_query_clients_nick = -1;
int samp_query_clients_score = -1;

//samp query detailed
int samp_query_detailed_playercount = -1;
int samp_query_detailed_nick = -1;
int samp_query_detailed_score = -1;
int samp_query_detailed_ping = -1;

//samp query ping
int samp_query_ping_identifier = -1;

//samp rcon
int samp_query_rcon_password = -1;
int samp_query_rcon_message = -1;



//raknet
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

//trailer sync
int trailer_sync_vehicleid = -1;
int trailer_sync_pos_x = -1;
int trailer_sync_pos_y = -1;
int trailer_sync_pos_z = -1;
int trailer_sync_rot_x = -1;
int trailer_sync_rot_y = -1;
int trailer_sync_rot_z = -1;
int trailer_sync_rot_w = -1;
int trailer_sync_vel_x = -1;
int trailer_sync_vel_y = -1;
int trailer_sync_vel_z = -1;
int trailer_sync_angular_vel_x = -1;
int trailer_sync_angular_vel_y = -1;
int trailer_sync_angular_vel_z = -1;


int weapons_update_player_target = -1;
int weapons_update_actor_target = -1;
int weapons_update_slot = -1;
int weapons_update_weapon = -1;
int weapons_update_ammo = -1;

int game_init_zone_names = -1;
int game_init_cj_walk = -1;
int game_init_allow_weapons = -1;
int game_init_limit_chat_radius = -1;
int game_init_chat_radius = -1;
int game_init_stunt_bonus = -1;
int game_init_nametag_dist = -1;
int game_init_disable_enter_exit = -1;
int game_init_nametag_los = -1;
int game_init_manuel_veh_lighting = -1;
int game_init_num_spawn_classes = -1;
int game_init_playerid = -1;
int game_init_show_nametags = -1;
int game_init_show_player_markers = -1;
int game_init_server_hour = -1;
int game_init_server_weather = -1;
int game_init_gravity = -1;
int game_init_lan_mode = -1;
int game_init_instagib = -1;
int game_init_vehicle_friendly_fire = -1;
int game_init_drop_money_on_death = -1;
int game_init_onfoot_sendrate = -1;
int game_init_incar_sendrate = -1;
int game_init_firing_sendrate = -1;
int game_init_send_multiplier = -1;
int game_init_lagcomp = -1;
int game_init_unknown = -1;
int game_init_unknown_2 = -1;
int game_init_unknown_3 = -1;
int game_init_unknown_4 = -1;
int game_init_hostname = -1;
int game_init_preloaded_model = -1;


int scoreboard_ping_playerid = -1;
int scoreboard_ping_score = -1;
int scoreboard_ping_ping = -1;


//create object
int createobject_objectid = -1;
int createobject_modelid = -1;
int createobject_pos_x = -1;
int createobject_pos_y = -1;
int createobject_pos_z = -1;
int createobject_rot_x = -1;
int createobject_rot_y = -1;
int createobject_rot_z = -1;
int createobject_drawdist = -1;
int createobject_cameracollision = -1;
int createobject_vehicleid = -1;
int createobject_playerid = -1;
int createobject_attachoffset_pos_x = -1;
int createobject_attachoffset_pos_y = -1;
int createobject_attachoffset_pos_z = -1;
int createobject_attachoffset_rot_x = -1;
int createobject_attachoffset_rot_y = -1;
int createobject_attachoffset_rot_z = -1;
int createobject_attachoffset_rot_sync = -1;
int createobject_attachoffset_material_count = -1;
int createobject_attachoffset_material_type = -1;
int createobject_attachoffset_material_index = -1;
//createobj attach type 1
int createobject_attachoffset_material_type1_model = -1;
int createobject_attachoffset_material_type1_textOrTXD = -1; //and type2
int createobject_attachoffset_material_type1_fontOrTexture = -1; //and type2
int createobject_attachoffset_material_type1_materialColour = -1;
//createobj attach type 2
int createobject_attachoffset_material_type2_materialSize = -1;
int createobject_attachoffset_material_type2_fontSize = -1;
int createobject_attachoffset_material_type2_bold = -1;
int createobject_attachoffset_material_type2_fontColour = -1;
int createobject_attachoffset_material_type2_backgroundColour = -1;
int createobject_attachoffset_material_type2_alignment = -1;
int createobject_attachoffset_material_type2_textOrTXD = -1; //and type2
int createobject_attachoffset_material_type2_fontOrTexture = -1; //and type2

//SetPlayerObjectMaterial
int setplayerobjectmaterial_objectid = -1;
int setplayerobjectmaterial_material_type = -1;
int setplayerobjectmaterial_material_id = -1;
int setplayerobjectmaterial_material_default_model = -1;
int setplayerobjectmaterial_material_default_textOrTXD = -1;
int setplayerobjectmaterial_material_default_fontOrTexture = -1;
int setplayerobjectmaterial_material_default_materialColour = -1;
int setplayerobjectmaterial_material_text_materialSize = -1;
int setplayerobjectmaterial_material_text_fontOrTexture = -1;
int setplayerobjectmaterial_material_text_fontSize = -1;
int setplayerobjectmaterial_material_text_bold = -1;
int setplayerobjectmaterial_material_text_fontColour = -1;
int setplayerobjectmaterial_material_text_backgroundColour = -1;
int setplayerobjectmaterial_material_text_alignment = -1;
int setplayerobjectmaterial_material_text_textOrTXD = -1;
//

extern "C" {
	extern gint hf_samp_fragments;
	extern gint hf_samp_fragment;
	extern gint hf_samp_fragment_overlap;
	extern gint hf_samp_fragment_overlap_conflicts;
	extern gint hf_samp_fragment_multiple_tails;
	extern gint hf_samp_fragment_too_long_fragment;
	extern gint hf_samp_fragment_error;
	extern gint hf_samp_fragment_count;
	extern gint hf_samp_reassembled_in;
	extern gint hf_samp_reassembled_length;
	extern gint hf_samp_reassembled_data;
}

static hf_register_info standard_fields_hf[] = {
	/* Reassembly fields. */
	{ &hf_samp_fragments,
	  { "Message fragments",              "samp.fragments",
		FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment,
	  { "Message fragment",               "samp.fragment",
		FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_overlap,
	  { "Message fragment overlap",       "samp.fragment.overlap",
		FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_overlap_conflicts,
	  { "Message fragment overlapping with conflicting data", "samp.fragment.overlap.conflicts",
		FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_multiple_tails,
	  { "Message has multiple tail fragments", "samp.fragment.multiple_tails",
		FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_too_long_fragment,
	  { "Message fragment too long",      "samp.fragment.too_long_fragment",
		FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_error,
	  { "Message defragmentation error",  "samp.fragment.error",
		FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_fragment_count,
	  { "Message fragment count",         "samp.fragment.count",
		FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_reassembled_in,
	  { "Reassembled in",                 "samp.reassembled.in",
		FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_reassembled_length,
	  { "Reassembled msg length",     "samp.reassembled.length",
		FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL }},
	{ &hf_samp_reassembled_data,
	  { "Reassembled msg ata",     "samp.reassembled.data",
		FT_BYTES, SEP_SPACE, NULL, 0x00, NULL, HFILL }},

	//samp query
	{ &samp_query_magic,
		{ "magic", "samp_query.magic",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_ipv4_addr,
		{ "ipaddr", "samp_query.ipaddr",
		FT_IPv4, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_port,
		{ "port", "samp_query.port",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_opcode,
		{ "opcode", "samp_query.opcode",
		FT_CHAR, BASE_OCT,
		NULL, 0x0,
		NULL, HFILL }
	},

	//samp query info packet
	{ &samp_query_info_resp_password,
		{ "opcode", "samp_query.info.password",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_info_resp_numplayers,
		{ "numplayers", "samp_query.info.numplayers",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_info_resp_maxplayers,
		{ "maxplayers", "samp_query.info.maxplayers",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_info_resp_hostname,
		{ "hostname", "samp_query.info.hostname",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_info_resp_gamemode,
		{ "gamemode", "samp_query.info.gamemode",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_info_resp_language,
		{ "language", "samp_query.info.language",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	//samp query rules
	{ &samp_query_rules_resp_count,
		{ "count", "samp_query.rules.count",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_rules_resp_rulename,
		{ "name", "samp_query.rules.name",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_rules_resp_rulevalue,
		{ "value", "samp_query.rules.value",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	//samp query clients
	{ &samp_query_clients_playercount,
		{ "playercount", "samp_query.clients.playercount",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_clients_nick,
		{ "nick", "samp_query.clients.nick",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_clients_score,
		{ "score", "samp_query.clients.score",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	//samp query detailed
	{ &samp_query_detailed_playercount,
		{ "playercount", "samp_query.detailed.playercount",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_detailed_nick,
		{ "nick", "samp_query.detailed.nick",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_detailed_score,
		{ "score", "samp_query.detailed.score",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_detailed_ping,
		{ "ping", "samp_query.detailed.ping",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},

	//samp query ping
	{ &samp_query_ping_identifier ,
		{ "identifier", "samp_query.ping.identifier",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},

	//samp rcon
	{ &samp_query_rcon_password,
		{ "password", "samp_query.rcon.password",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &samp_query_rcon_message,
		{ "message", "samp_query.rcon.message",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},


	//samp raknet
	{ &msgid_field,
		{ "msgid", "samp.msgid",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &rpcid_field,
		{ "rpcid", "samp.rpcid",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &ack_field,
		{ "ackid", "samp.ackid",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &seqid_field,
		{ "seqid", "samp.seqid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &reliability_field,
		{ "reliability", "samp.reliability",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &orderingChannel_field,
		{ "orderingChannel", "samp.orderingChannel",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &orderingIndexType_field,
		{ "orderingIndexType", "samp.orderingIndexType",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &has_split_packet_field,
		{ "has_split_packet", "samp.has_split_packet",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
		
	{ &split_packet_id_field,
		{ "split_packet_id", "samp.split_packet_id",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &split_packet_index_field,
		{ "split_packet_index", "samp.split_packet_index",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &split_packet_count_field,
		{ "split_packet_count", "samp.split_packet_count",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &data_len_field,
		{ "data_len_field", "samp.data_len_field",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},


	//player sync		
	{ &player_sync_playerid,
		{ "playerid", "samp.player_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_leftright_keys,
		{ "leftright_keys", "samp.player_sync.leftright_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_updown_keys,
		{ "updown_keys", "samp.player_sync.updown_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_keys,
		{ "keys", "samp.player_sync.keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_pos_x,
		{ "x", "samp.player_sync.x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_pos_y,
		{ "y", "samp.player_sync.y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_pos_z,
		{ "z", "samp.player_sync.z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_quat_x,
		{ "quat_x", "samp.player_sync.quat_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_quat_y,
		{ "quat_y", "samp.player_sync.quat_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_quat_z,
		{ "quat_z", "samp.player_sync.quat_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_quat_w,
		{ "quat_w", "samp.player_sync.quat_w",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_health,
		{ "health", "samp.player_sync.health",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_armour,
		{ "armour", "samp.player_sync.armour",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_weapon,
		{ "weapon", "samp.player_sync.weapon",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_specialaction,
		{ "specialaction", "samp.player_sync.specialaction",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_move_speed_x,
		{ "move_speed_x", "samp.player_sync.move_speed_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_move_speed_y,
		{ "move_speed_y", "samp.player_sync.move_speed_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_move_speed_z,
		{ "move_speed_z", "samp.player_sync.move_speed_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_surf_offset_x,
		{ "surf_offset_x", "samp.player_sync.surf_offset_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_surf_offset_y,
		{ "surf_offset_y", "samp.player_sync.surf_offset_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_surf_offset_z,
		{ "surf_offset_z", "samp.player_sync.surf_offset_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_surf_flags,
		{ "surf_flags", "samp.player_sync.surf_flags",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &player_sync_anim,
		{ "anim", "samp.player_sync.anim",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	//
	{ &stats_update_money,
		{ "money", "samp.stats_update.money",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &stats_update_drunk,
		{ "drunk", "samp.stats_update.drunk",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},

	//marker update
	{ &marker_update_num_items,
		{ "num_items", "samp.marker_update.num_items",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &marker_update_playerid,
		{ "playerid", "samp.marker_update.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &marker_update_active,
		{ "active", "samp.marker_update.active",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &marker_update_x,
		{ "x", "samp.marker_update.x",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &marker_update_y,
		{ "y", "samp.marker_update.y",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &marker_update_z,
		{ "z", "samp.marker_update.z",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},	
	{ &aim_sync_playerid,
		{ "playerid", "samp.aim_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},	
	{ &aim_sync_cam_mode,
		{ "cam_mode", "samp.aim_sync.cam_mode",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_angle_x,
		{ "angle_x", "samp.aim_sync.angle_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_angle_y,
		{ "angle_y", "samp.aim_sync.angle_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_angle_z,
		{ "angle_z", "samp.aim_sync.angle_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	{ &aim_sync_pos_x,
		{ "pos_x", "samp.aim_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_pos_y,
		{ "pos_y", "samp.aim_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_pos_z,
		{ "pos_z", "samp.aim_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_z,
		{ "z", "samp.aim_sync.z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_cam_zoom,
		{ "cam_zoom", "samp.aim_sync.cam_zoom",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_weapon_state,
		{ "weapon_state", "samp.aim_sync.weapon_state",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &aim_sync_aspect_ratio,
		{ "aspect_ratio", "samp.aim_sync.aspect_ratio",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_playerid,
		{ "playerid", "samp.veh_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_vehicleid,
		{ "vehicleid", "samp.veh_sync.vehicleid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_stoc_vehhealth,
		{ "vehhealth", "samp.veh_sync.stoc_vehhealth",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
		
	{ &vehicle_sync_leftright_keys,
		{ "leftright_keys", "samp.veh_sync.leftright_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_updown_keys,
		{ "updown_keys", "samp.veh_sync.updown_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_keys,
		{ "keys", "samp.veh_sync.keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_quat_x,
		{ "quat_x", "samp.veh_sync.quat_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_quat_y,
		{ "quat_y", "samp.veh_sync.quat_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_quat_z,
		{ "quat_z", "samp.veh_sync.quat_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_quat_w,
		{ "quat_w", "samp.veh_sync.quat_w",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_pos_x,
		{ "pos_x", "samp.veh_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_pos_y,
		{ "pos_y", "samp.veh_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_pos_z,
		{ "pos_z", "samp.veh_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_vel_x,
		{ "vel_x", "samp.veh_sync.vel_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_vel_y,
		{ "vel_y", "samp.veh_sync.vel_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_vel_z,
		{ "vel_z", "samp.veh_sync.vel_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_vehhealth,
		{ "veh_health", "samp.veh_sync.veh_health",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_player_health,
		{ "player_health", "samp.veh_sync.player_health",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_player_armour,
		{ "player_armour", "samp.veh_sync.player_armour",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_weapon,
		{ "weapon", "samp.veh_sync.weapon",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_siren,
		{ "siren", "samp.veh_sync.siren",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_angle,
		{ "angle", "samp.veh_sync.angle",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_train_speed,
		{ "train_speed", "samp.veh_sync.train_speed",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_stos_train_speed,
		{ "train_speed", "samp.veh_sync.stos_train_speed",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_landinggear_state,
		{ "landinggear_state", "samp.veh_sync.landinggear_state",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_hydra,
		{ "hydra", "samp.veh_sync.hydra",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &vehicle_sync_trailer,
		{ "trailer", "samp.veh_sync.trailer",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},


	{ &bullet_sync_type,
		{ "type", "samp.bullet_sync.type",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_playerid,
		{ "playerid", "samp.bullet_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_id,
		{ "id", "samp.bullet_sync.id",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_origin_x,
		{ "origin_x", "samp.bullet_sync.origin_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_origin_y,
		{ "origin_y", "samp.bullet_sync.origin_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_origin_z,
		{ "origin_z", "samp.bullet_sync.origin_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_target_x,
		{ "target_x", "samp.bullet_sync.target_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_target_y,
		{ "target_y", "samp.bullet_sync.target_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_target_z,
		{ "target_z", "samp.bullet_sync.target_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_center_x,
		{ "center_x", "samp.bullet_sync.center_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_center_y,
		{ "center_y", "samp.bullet_sync.center_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_center_z,
		{ "center_z", "samp.bullet_sync.center_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &bullet_sync_weapon,
		{ "weapon", "samp.bullet_sync.weapon",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_playerid,
		{ "playerid", "samp.unoccupied_veh_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_vehicle_id,
		{ "vehicleid", "samp.unoccupied_veh_sync.vehicleid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_roll_x,
		{ "roll_x", "samp.unoccupied_veh_sync.roll_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_roll_y,
		{ "roll_y", "samp.unoccupied_veh_sync.roll_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_roll_z,
		{ "roll_z", "samp.unoccupied_veh_sync.roll_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_direction_x,
		{ "direction_x", "samp.unoccupied_veh_sync.direction_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_direction_y,
		{ "direction_y", "samp.unoccupied_veh_sync.direction_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_direction_z,
		{ "direction_z", "samp.unoccupied_veh_sync.direction_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_seatid,
		{ "seatid", "samp.unoccupied_veh_sync.seatid",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
		
	{ &unoccupied_veh_sync_pos_x,
		{ "pos_x", "samp.unoccupied_veh_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_pos_y,
		{ "pos_y", "samp.unoccupied_veh_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_pos_z,
		{ "pos_z", "samp.unoccupied_veh_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_vel_x,
		{ "vel_x", "samp.unoccupied_veh_sync.vel_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_vel_y,
		{ "vel_y", "samp.unoccupied_veh_sync.vel_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_vel_z,
		{ "vel_z", "samp.unoccupied_veh_sync.vel_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_turning_speed_x,
		{ "turning_speed_x", "samp.unoccupied_veh_sync.turning_speed_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_turning_speed_y,
		{ "turning_speed_y", "samp.unoccupied_veh_sync.turning_speed_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_turning_speed_z,
		{ "turning_speed_z", "samp.unoccupied_veh_sync.turning_speed_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &unoccupied_veh_sync_health,
		{ "health", "samp.unoccupied_veh_sync.health",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	{ &spec_sync_playerid,
		{ "playerid", "samp.spec_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_leftright_keys,
		{ "leftright_keys", "samp.spec_sync.leftright_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_updown_keys,
		{ "updown_keys", "samp.spec_sync.updown_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_keys,
		{ "keys", "samp.spec_sync.keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_pos_x,
		{ "pos_x", "samp.spec_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_pos_y,
		{ "pos_y", "samp.spec_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &spec_sync_pos_z,
		{ "pos_z", "samp.spec_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	{ &passenger_sync_playerid,
		{ "playerid", "samp.passenger_sync.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_vehicleid,
		{ "vehicleid", "samp.passenger_sync.vehicleid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_seat_flags,
		{ "seat_flags", "samp.passenger_sync.seat_flags",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_driveby,
		{ "driveby", "samp.passenger_sync.driveby",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_currentweapon,
		{ "currentweapon", "samp.passenger_sync.currentweapon",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_health,
		{ "health", "samp.passenger_sync.health",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_armour,
		{ "armour", "samp.passenger_sync.armour",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_leftright_keys,
		{ "leftright_keys", "samp.passenger_sync.leftright_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_updown_keys,
		{ "updown_keys", "samp.passenger_sync.updown_keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_keys,
		{ "keys", "samp.passenger_sync.keys",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_pos_x,
		{ "pos_x", "samp.passenger_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_pos_y,
		{ "pos_y", "samp.passenger_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &passenger_sync_pos_z,
		{ "pos_z", "samp.passenger_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_vehicleid,
		{ "vehicleid", "samp.trailer_sync.vehicleid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_pos_x,
		{ "pos_x", "samp.trailer_sync.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_pos_y,
		{ "pos_y", "samp.trailer_sync.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_pos_z,
		{ "pos_z", "samp.trailer_sync.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_rot_x,
		{ "rot_x", "samp.trailer_sync.rot_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_rot_y,
		{ "rot_y", "samp.trailer_sync.rot_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_rot_z,
		{ "rot_z", "samp.trailer_sync.rot_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_rot_w,
		{ "rot_w", "samp.trailer_sync.rot_w",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_vel_x,
		{ "vel_x", "samp.trailer_sync.vel_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_vel_y,
		{ "vel_y", "samp.trailer_sync.vel_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_vel_z,
		{ "vel_z", "samp.trailer_sync.vel_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_angular_vel_x,
		{ "angular_vel_x", "samp.trailer_sync.angular_vel_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_angular_vel_y,
		{ "angular_vel_y", "samp.trailer_sync.angular_vel_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &trailer_sync_angular_vel_z,
		{ "angular_vel_z", "samp.trailer_sync.angular_vel_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},

	{ &weapons_update_player_target,
		{ "player_target", "samp.weapons_update.player_target",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &weapons_update_actor_target,
		{ "actor_target", "samp.weapons_update.actor_target",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &weapons_update_slot,
		{ "wep_slot", "samp.weapons_update.slot",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &weapons_update_weapon,
		{ "wep_weaponid", "samp.weapons_update.weaponid",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &weapons_update_ammo,
		{ "wep_ammo", "samp.weapons_update.ammo",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_zone_names,
		{ "zone_names", "samp.rpc.gameinit.zone_names",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_cj_walk,
		{ "cj_walk", "samp.rpc.gameinit.cj_walk",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_allow_weapons,
		{ "allow_weapons", "samp.rpc.gameinit.allow_weapons",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_limit_chat_radius,
		{ "limit_chat_radius", "samp.rpc.gameinit.limit_chat_radius",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_chat_radius,
		{ "chat_radius", "samp.rpc.gameinit.chat_radius",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_nametag_dist,
		{ "nametag_dist", "samp.rpc.gameinit.nametag_dist",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_disable_enter_exit,
		{ "disable_enter_exit", "samp.rpc.gameinit.disable_enter_exit",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_nametag_los,
		{ "nametag_los", "samp.rpc.gameinit.nametag_los",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_manuel_veh_lighting,
		{ "manual_veh_lighting", "samp.rpc.gameinit.manual_veh_lighting",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_num_spawn_classes,
		{ "num_spawn_classes", "samp.rpc.gameinit.num_spawn_classes",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_playerid,
		{ "playerid", "samp.rpc.gameinit.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_stunt_bonus,
		{ "stunt_bonus", "samp.rpc.gameinit.stunt_bonus",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_show_nametags,
		{ "show_nametags", "samp.rpc.gameinit.show_nametags",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_show_player_markers,
		{ "show_player_markers", "samp.rpc.gameinit.show_player_markers",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_server_hour,
		{ "server_hour", "samp.rpc.gameinit.server_hour",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_server_weather,
		{ "server_weather", "samp.rpc.gameinit.server_weather",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_gravity,
		{ "gravity", "samp.rpc.gameinit.gravity",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_lan_mode,
		{ "lan_mode", "samp.rpc.gameinit.lan_mode",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_instagib,
		{ "instagib", "samp.rpc.gameinit.instagib",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_vehicle_friendly_fire,
		{ "vehicle_friendly_fire", "samp.rpc.gameinit.vehicle_friendly_fire",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_drop_money_on_death,
		{ "show_player_markers", "samp.rpc.gameinit.drop_money_on_death",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_unknown,
		{ "unknown", "samp.rpc.gameinit.unknown",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_onfoot_sendrate,
		{ "onfoot_sendrate", "samp.rpc.gameinit.onfoot_sendrate",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_incar_sendrate,
		{ "incar_sendrate", "samp.rpc.gameinit.incar_sendrate",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_send_multiplier,
		{ "send_multiplier", "samp.rpc.gameinit.send_multiplier",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_firing_sendrate,
		{ "firing_sendrate", "samp.rpc.gameinit.firing_sendrate",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},		
	{ &game_init_lagcomp,
		{ "lagcomp", "samp.rpc.gameinit.lagcomp",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_unknown_2,
		{ "unknown_2", "samp.rpc.gameinit.unknown_2",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_unknown_3,
		{ "unknown_3", "samp.rpc.gameinit.unknown_3",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_unknown_4,
		{ "unknown_4", "samp.rpc.gameinit.unknown_4",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_hostname,
		{ "hostname", "samp.rpc.gameinit.hostname",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &game_init_preloaded_model,
		{ "preloaded_model", "samp.rpc.gameinit.preloaded_model",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},

	//scoreboard pings
	{ &scoreboard_ping_playerid,
		{ "playerid", "samp.rpc.scoreboard.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &scoreboard_ping_score,
		{ "score", "samp.rpc.scoreboard.score",
		FT_INT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &scoreboard_ping_ping,
		{ "ping", "samp.rpc.scoreboard.ping",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	//

	//create object
	{ &createobject_objectid,
		{ "objectid", "samp.rpc.createobject.objectid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_modelid,
		{ "modelid", "samp.rpc.createobject.modelid",
		FT_INT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_pos_x,
		{ "pos_x", "samp.rpc.createobject.pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_pos_y,
		{ "pos_y", "samp.rpc.createobject.pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_pos_z,
		{ "pos_z", "samp.rpc.createobject.pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_rot_x,
		{ "rot_x", "samp.rpc.createobject.rot_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_rot_y,
		{ "rot_y", "samp.rpc.createobject.rot_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_rot_z,
		{ "rot_z", "samp.rpc.createobject.rot_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_drawdist,
		{ "drawdist", "samp.rpc.createobject.drawdist",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_cameracollision,
		{ "cameracollision", "samp.rpc.createobject.cameracollision",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_vehicleid,
		{ "vehicleid", "samp.rpc.createobject.vehicleid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_playerid,
		{ "playerid", "samp.rpc.createobject.playerid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},

	{ &createobject_attachoffset_pos_x,
		{ "attach_pos_x", "samp.rpc.createobject.attach_pos_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_pos_y,
		{ "attach_pos_y", "samp.rpc.createobject.attach_pos_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_pos_z,
		{ "attach_pos_z", "samp.rpc.createobject.attach_pos_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_rot_x,
		{ "attach_rot_x", "samp.rpc.createobject.attach_rot_x",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_rot_y,
		{ "attach_rot_y", "samp.rpc.createobject.attach_rot_y",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_rot_z,
		{ "attach_rot_z", "samp.rpc.createobject.attach_rot_z",
		FT_FLOAT, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_rot_sync,
		{ "sync_rotation", "samp.rpc.createobject.attach.sync_rotation",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_count,
		{ "material_count", "samp.rpc.createobject.material_count",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type,
		{ "material_type", "samp.rpc.createobject.material.type",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_index,
		{ "material_index", "samp.rpc.createobject.material.index",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type1_model,
		{ "modelid", "samp.rpc.createobject.type1.modelid",
		FT_INT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type1_textOrTXD,
		{ "textOrTXD", "samp.rpc.createobject.type1.textOrTXD",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type1_fontOrTexture,
		{ "fontOrTexture", "samp.rpc.createobject.type1.fontOrTexture",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type1_materialColour,
		{ "materialColour", "samp.rpc.createobject.type1.materialColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_materialSize,
		{ "materialSize", "samp.rpc.createobject.type2.materialSize",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_fontOrTexture,
		{ "fontOrTexture", "samp.rpc.createobject.type2.fontOrTexture",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_fontSize,
		{ "fontSize", "samp.rpc.createobject.type2.fontSize",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_bold,
		{ "bold", "samp.rpc.createobject.type2.bold",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_fontColour,
		{ "fontColour", "samp.rpc.createobject.type2.fontColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_backgroundColour,
		{ "backgroundColour", "samp.rpc.createobject.type2.backgroundColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_alignment,
		{ "alignment", "samp.rpc.createobject.type2.alignment",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &createobject_attachoffset_material_type2_textOrTXD,
		{ "textOrTXD", "samp.rpc.createobject.type2.textOrTXD",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	//

	//setplayerobjectmaterial
	{ &setplayerobjectmaterial_objectid,
		{ "objectid", "samp.rpc.setplayerobjectmaterial.objectid",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_type,
		{ "material_type", "samp.rpc.setplayerobjectmaterial.material_type",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_id,
		{ "material_id", "samp.rpc.setplayerobjectmaterial.material_id",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_default_model,
		{ "material_model", "samp.rpc.setplayerobjectmaterial.default.model",
		FT_UINT16, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_default_textOrTXD,
		{ "textOrTXD", "samp.rpc.setplayerobjectmaterial.default.textOrTXD",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_default_fontOrTexture,
		{ "fontOrTexture", "samp.rpc.setplayerobjectmaterial.default.fontOrTexture",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_default_materialColour,
		{ "materialColour", "samp.rpc.setplayerobjectmaterial.default.materialColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_materialSize,
		{ "materialSize", "samp.rpc.setplayerobjectmaterial.text.materialSize",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_fontOrTexture,
		{ "fontOrTexture", "samp.rpc.setplayerobjectmaterial.text.fontOrTexture",
		FT_STRING, BASE_NONE,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_fontSize,
		{ "fontSize", "samp.rpc.setplayerobjectmaterial.text.fontSize",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_bold,
		{ "bold", "samp.rpc.setplayerobjectmaterial.text.bold",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_fontColour,
		{ "fontColour", "samp.rpc.setplayerobjectmaterial.text.fontColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_backgroundColour,
		{ "backgroundColour", "samp.rpc.setplayerobjectmaterial.text.backgroundColour",
		FT_UINT32, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_alignment,
		{ "alignment", "samp.rpc.setplayerobjectmaterial.text.alignment",
		FT_UINT8, BASE_DEC,
		NULL, 0x0,
		NULL, HFILL }
	},
	{ &setplayerobjectmaterial_material_text_textOrTXD,
		{ "textOrTXD", "samp.rpc.setplayerobjectmaterial.text.textOrTXD",
		FT_STRING, BASE_NONE,
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
											{"unk", EVariableType_Uint8,true, true}, 
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
											{"id", EVariableType_Uint16,true, false}, 
											//{"unknown1", EVariableType_Uint32,false, false}, //literally just an uninitalized integer from SAMP server, possibly from alignment
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
											//{"type", EVariableType_Uint8,true, true}, 
											//{"address", EVariableType_Uint32,true, true}, 
											//{"offset", EVariableType_Uint16,false, true}, 
											//{"bytes", EVariableType_Uint16,false, true}, 

											//{"offset", EVariableType_Uint16,true, false}, 
											//{"count", EVariableType_Uint16,true, false},

											{"type", EVariableType_Uint8,true, true},
											{"address", EVariableType_Uint32,true, true},
											{"offset", EVariableType_Uint16,false, true},
											{"bytes", EVariableType_Uint16,false, true},

											//
											{"results", EVariableType_Uint8,true, false},

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
			{"callback", EVariableType_Custom,true, true},
			{NULL, EVariableType_NoInit}
		}, dissect_set_object_material_text
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
		}, dissect_game_init
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
		dissect_create_object
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
	{ "UpdateScoreboardPingIPS", ESAMPRPC_UpdateScoresPingsIP, {
			{"unk", EVariableType_Uint8,true, false},
			{"callback", EVariableType_Custom,false, true},
			{NULL, EVariableType_NoInit}
		},
		dissect_scoreboard_pings
	},
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
									{"playerobject", EVariableType_CompressedBool,false, true}, 
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
		{"playerid", EVariableType_Uint16,true, true},
		//{"pad", EVariableType_Uint8,true, true}, 
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
	//{
	//	"UpdateScoresPingsIP",  ESAMPRPC_UpdateScoresPingsIP, {
	//		{"flags", EVariableType_Uint8,true, false}, 
	//		{"callback", EVariableType_Custom,false, true},
	//		{NULL, EVariableType_NoInit}
	//	}
	//},
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
			{"id", EVariableType_Uint16,false, true},
			{"index", EVariableType_Uint32,false, true},
			{"unk1", EVariableType_CompressedBool,false, true},
			{"modelid", EVariableType_Uint32,false, true},
			{"bone", EVariableType_Uint32,false, true},
			{"x", EVariableType_Float,false, true},
			{"y", EVariableType_Float,false, true},
			{"z", EVariableType_Float,false, true},
			{"rx", EVariableType_Float,false, true},
			{"ry", EVariableType_Float,false, true},
			{"rz", EVariableType_Float,false, true},
			{"sx", EVariableType_Float,false, true},
			{"sy", EVariableType_Float,false, true},
			{"sz", EVariableType_Float,false, true},
			{"mat_1", EVariableType_Uint32,false, true},
			{"mat_2", EVariableType_Uint32,false, true},
			{NULL, EVariableType_NoInit}
		}
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


///
void dissect_game_init(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_, struct _RPCNameMap *rpc_map) {
	int offset = 0;
    guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
    char *original_buffer = (char *)tvb_get_ptr(tvb, offset, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

	uint32_t i32_val = 0;
	uint16_t i16_val = 0;
	uint8_t i8_val = 0;
	float f_val = 0.0;
	bool b_val = false;

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_zone_names, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_cj_walk, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_allow_weapons, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_limit_chat_radius, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(f_val);
	proto_tree_add_float(tree, game_init_chat_radius, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_stunt_bonus, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(f_val);
	proto_tree_add_float(tree, game_init_nametag_dist, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_disable_enter_exit, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_nametag_los, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_manuel_veh_lighting, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_num_spawn_classes, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i16_val);
	proto_tree_add_uint(tree, game_init_playerid, tvb, offset, sizeof(uint16_t), i16_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_show_nametags, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_show_player_markers, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i8_val);
	proto_tree_add_uint(tree, game_init_server_hour, tvb, offset, sizeof(uint8_t), i8_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i8_val);
	proto_tree_add_uint(tree, game_init_server_weather, tvb, offset, sizeof(uint8_t), i8_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(f_val);
	proto_tree_add_float(tree, game_init_gravity, tvb, offset, sizeof(float), f_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val);
	proto_tree_add_uint(tree, game_init_lan_mode, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());
		
	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_drop_money_on_death, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.ReadCompressed(b_val); //INSTAGIB??
	proto_tree_add_uint(tree, game_init_instagib, tvb, offset, sizeof(uint8_t), b_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_onfoot_sendrate, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_incar_sendrate, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_firing_sendrate, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_send_multiplier, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_lagcomp, tvb, offset, sizeof(uint8_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());

	bs.Read(i8_val);
	char hostname[256];
	bs.Read((char *)&hostname, i8_val);
	hostname[i8_val] = 0;
	proto_tree_add_string(tree, game_init_hostname, tvb, offset, i8_val, hostname); offset = BITS_TO_BYTES(bs.GetReadOffset());

	for(int i=0;i<212;i++) {
		bs.Read(i8_val);
		proto_tree_add_uint(tree, game_init_preloaded_model, tvb, offset, sizeof(uint8_t), i8_val); offset = BITS_TO_BYTES(bs.GetReadOffset());
	}
	bs.Read(i32_val);
	proto_tree_add_uint(tree, game_init_vehicle_friendly_fire, tvb, offset, sizeof(uint32_t), i32_val); offset = BITS_TO_BYTES(bs.GetReadOffset());
}


void dissect_create_object(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map) {
	if (is_samp_server(pinfo)) {
		int offset = 0;
		guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
		char* original_buffer = (char*)tvb_get_ptr(tvb, offset, orig_size);

		RakNet::BitStream bs;
		bs.Write(original_buffer, orig_size);

		uint16_t objectid;
		int32_t modelid;
		bs.Read(objectid);
		proto_tree_add_uint(tree, createobject_objectid, tvb, offset, sizeof(uint16_t), objectid); offset = BITS_TO_BYTES(bs.GetReadOffset());

		bs.Read(modelid);
		proto_tree_add_int(tree, createobject_modelid, tvb, offset, sizeof(int32_t), modelid); offset = BITS_TO_BYTES(bs.GetReadOffset());

		uint8_t camera_collision;

		float pos[3];
		float rot[3];

		bs.Read(pos[0]);
		proto_tree_add_float(tree, createobject_pos_x, tvb, offset, sizeof(float), pos[0]); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(pos[1]);
		proto_tree_add_float(tree, createobject_pos_y, tvb, offset, sizeof(float), pos[1]); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(pos[2]);
		proto_tree_add_float(tree, createobject_pos_z, tvb, offset, sizeof(float), pos[2]); offset = BITS_TO_BYTES(bs.GetReadOffset());

		bs.Read(rot[0]);
		proto_tree_add_float(tree, createobject_rot_x, tvb, offset, sizeof(float), rot[0]); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(rot[1]);
		proto_tree_add_float(tree, createobject_rot_y, tvb, offset, sizeof(float), rot[1]); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(rot[2]);
		proto_tree_add_float(tree, createobject_rot_z, tvb, offset, sizeof(float), rot[2]); offset = BITS_TO_BYTES(bs.GetReadOffset());

		float draw_dist;
		bs.Read(draw_dist);
		proto_tree_add_float(tree, createobject_drawdist, tvb, offset, sizeof(float), draw_dist); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(camera_collision);
		proto_tree_add_uint(tree, createobject_cameracollision, tvb, offset, sizeof(uint8_t), camera_collision); offset = BITS_TO_BYTES(bs.GetReadOffset());

		uint16_t vehicleid, playerid;
		bs.Read(vehicleid);
		proto_tree_add_uint(tree, createobject_vehicleid, tvb, offset, sizeof(uint16_t), vehicleid); offset = BITS_TO_BYTES(bs.GetReadOffset());
		bs.Read(playerid);
		proto_tree_add_uint(tree, createobject_playerid, tvb, offset, sizeof(uint16_t), playerid); offset = BITS_TO_BYTES(bs.GetReadOffset());

		if (playerid != 0xFFFF || vehicleid != 0xFFFF) {
			float attach_offset[3];
			float attach_rot[3];

			uint8_t syncRotation;

			bs.Read(attach_offset[0]);
			proto_tree_add_float(tree, createobject_attachoffset_pos_x, tvb, offset, sizeof(float), attach_offset[0]); offset = BITS_TO_BYTES(bs.GetReadOffset());
			bs.Read(attach_offset[1]);
			proto_tree_add_float(tree, createobject_attachoffset_pos_y, tvb, offset, sizeof(float), attach_offset[1]); offset = BITS_TO_BYTES(bs.GetReadOffset());
			bs.Read(attach_offset[2]);
			proto_tree_add_float(tree, createobject_attachoffset_pos_z, tvb, offset, sizeof(float), attach_offset[2]); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(attach_rot[0]);
			proto_tree_add_float(tree, createobject_attachoffset_rot_x, tvb, offset, sizeof(float), attach_rot[0]); offset = BITS_TO_BYTES(bs.GetReadOffset());
			bs.Read(attach_rot[1]);
			proto_tree_add_float(tree, createobject_attachoffset_rot_y, tvb, offset, sizeof(float), attach_rot[1]); offset = BITS_TO_BYTES(bs.GetReadOffset());
			bs.Read(attach_rot[2]);
			proto_tree_add_float(tree, createobject_attachoffset_rot_z, tvb, offset, sizeof(float), attach_rot[2]); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(syncRotation);
			proto_tree_add_uint(tree, createobject_attachoffset_rot_sync, tvb, offset, sizeof(uint8_t), vehicleid); offset = BITS_TO_BYTES(bs.GetReadOffset());
		}

		uint8_t materialCount;
		bs.Read(materialCount);
		proto_tree_add_uint(tree, createobject_attachoffset_material_count, tvb, offset, sizeof(uint8_t), materialCount); offset = BITS_TO_BYTES(bs.GetReadOffset());

		for (int i = 0; i < materialCount; i++) {
			uint8_t type;
			uint8_t index;

			bs.Read(type);
			proto_tree_add_uint(tree, createobject_attachoffset_material_count, tvb, offset, sizeof(uint8_t), type); offset = BITS_TO_BYTES(bs.GetReadOffset());
			bs.Read(index);
			proto_tree_add_uint(tree, createobject_attachoffset_material_count, tvb, offset, sizeof(uint8_t), index); offset = BITS_TO_BYTES(bs.GetReadOffset());


			uint8_t text_len;
			char text[4096];
			if (type == 1) { //default
				uint16_t model;
				bs.Read(model);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type1_model, tvb, offset, sizeof(uint16_t), model); offset = BITS_TO_BYTES(bs.GetReadOffset());

				bs.Read(text_len); offset++;
				bs.Read(text, text_len); text[text_len] = 0;
				proto_tree_add_string(tree, createobject_attachoffset_material_type1_textOrTXD, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

				bs.Read(text_len); offset++;
				bs.Read(text, text_len); text[text_len] = 0;
				proto_tree_add_string(tree, createobject_attachoffset_material_type1_fontOrTexture, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

				uint32_t mat_color;
				bs.Read(mat_color);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type1_materialColour, tvb, offset, sizeof(uint32_t), mat_color); offset = BITS_TO_BYTES(bs.GetReadOffset());
			}
			else if (type == 2) { //text
				uint8_t material_size, font_size, bold, alignment;
				uint32_t font_colour, background_colour;
				bs.Read(material_size);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_materialSize, tvb, offset, sizeof(uint8_t), material_size); offset = BITS_TO_BYTES(bs.GetReadOffset());

				bs.Read(text_len);
				bs.Read(text, text_len); text[text_len] = 0;
				proto_tree_add_string(tree, createobject_attachoffset_material_type2_fontOrTexture, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

				bs.Read(font_size);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_fontSize, tvb, offset, sizeof(uint8_t), font_size); offset = BITS_TO_BYTES(bs.GetReadOffset());
				bs.Read(bold);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_bold, tvb, offset, sizeof(uint8_t), bold); offset = BITS_TO_BYTES(bs.GetReadOffset());
				bs.Read(font_colour);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_fontColour, tvb, offset, sizeof(uint32_t), font_colour); offset = BITS_TO_BYTES(bs.GetReadOffset());
				bs.Read(background_colour);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_backgroundColour, tvb, offset, sizeof(uint32_t), background_colour); offset = BITS_TO_BYTES(bs.GetReadOffset());
				bs.Read(alignment);
				proto_tree_add_uint(tree, createobject_attachoffset_material_type2_alignment, tvb, offset, sizeof(uint8_t), alignment); offset = BITS_TO_BYTES(bs.GetReadOffset());

				if (StringCompressor::Instance()->DecodeString(text, sizeof(text), &bs)) {
					proto_tree_add_string(tree, createobject_attachoffset_material_type2_textOrTXD, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());
				}
			}
		}
	}
}


void dissect_scoreboard_pings(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map) {
	if (is_samp_server(pinfo)) {
		int offset = 0;
		guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
		char* original_buffer = (char*)tvb_get_ptr(tvb, offset, orig_size);

		RakNet::BitStream bs;
		bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();

		while (bs.GetNumberOfUnreadBits() > 0) {
			uint16_t playerid;
			int32_t score;
			uint32_t ping;
			proto_item* s_ti = proto_tree_add_item(tree, proto_samprpc, tvb, 0, -1, ENC_NA);
			proto_tree* sub_msg_tree = proto_item_add_subtree(s_ti, samp_ett_foo);

			proto_item_set_text(sub_msg_tree, "Player Score Entry");

			if (!bs.Read(playerid)) {
				proto_item_set_hidden(sub_msg_tree);
				break;
			}
				
			proto_tree_add_uint(sub_msg_tree, scoreboard_ping_playerid, tvb, offset, sizeof(uint16_t), playerid); offset = BITS_TO_BYTES(bs.GetReadOffset());
			if (!bs.Read(score)) {
				proto_item_set_hidden(sub_msg_tree);
				break;
			}

			proto_tree_add_int(sub_msg_tree, scoreboard_ping_score, tvb, offset, sizeof(int32_t), score); offset = BITS_TO_BYTES(bs.GetReadOffset());
			if (!bs.Read(ping)) {
				proto_item_set_hidden(sub_msg_tree);
				break;
			}

			proto_tree_add_uint(sub_msg_tree, scoreboard_ping_ping, tvb, offset, sizeof(uint32_t), ping); offset = BITS_TO_BYTES(bs.GetReadOffset());
		}
	}
}

void dissect_set_object_material_text(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map) {
	if (is_samp_server(pinfo)) {
		int offset = 0;
		guint16 orig_size = tvb_captured_length_remaining(tvb, offset);
		char* original_buffer = (char*)tvb_get_ptr(tvb, offset, orig_size);

		uint8_t text_len;
		char text[4096];

		RakNet::BitStream bs;
		bs.Write(original_buffer, orig_size);

		bs.ResetReadPointer();

		uint16_t objectid, model;
		uint8_t type, materialid, materialSize, fontSize, bold, alignment;
		uint32_t materialColour, fontColour, backgroundColour;

		bs.Read(objectid);
		proto_tree_add_uint(tree, setplayerobjectmaterial_objectid, tvb, offset, sizeof(uint16_t), objectid); offset = BITS_TO_BYTES(bs.GetReadOffset());

		bs.Read(type);
		proto_tree_add_uint(tree, setplayerobjectmaterial_material_type, tvb, offset, sizeof(uint8_t), type); offset = BITS_TO_BYTES(bs.GetReadOffset());

		bs.Read(materialid);
		proto_tree_add_uint(tree, setplayerobjectmaterial_material_id, tvb, offset, sizeof(uint8_t), materialid); offset = BITS_TO_BYTES(bs.GetReadOffset());

		if (type == 1) { //default
			bs.Read(model);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_default_model, tvb, offset, sizeof(uint16_t), model); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(text_len); offset++;
			bs.Read(text, text_len); text[text_len] = 0;
			proto_tree_add_string(tree, setplayerobjectmaterial_material_default_textOrTXD, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(text_len); offset++;
			bs.Read(text, text_len); text[text_len] = 0;
			proto_tree_add_string(tree, setplayerobjectmaterial_material_default_fontOrTexture, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(materialColour);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_default_materialColour, tvb, offset, sizeof(uint32_t), materialColour); offset = BITS_TO_BYTES(bs.GetReadOffset());
		}
		else if (type == 2) { //text
			bs.Read(materialSize);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_materialSize, tvb, offset, sizeof(uint8_t), materialSize); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(text_len); offset++;
			bs.Read(text, text_len); text[text_len] = 0;
			proto_tree_add_string(tree, setplayerobjectmaterial_material_text_fontOrTexture, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(fontSize);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_fontSize, tvb, offset, sizeof(uint8_t), fontSize); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(bold);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_bold, tvb, offset, sizeof(uint8_t), bold); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(fontColour);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_fontColour, tvb, offset, sizeof(uint32_t), fontColour); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(backgroundColour);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_backgroundColour, tvb, offset, sizeof(uint32_t), backgroundColour); offset = BITS_TO_BYTES(bs.GetReadOffset());

			bs.Read(alignment);
			proto_tree_add_uint(tree, setplayerobjectmaterial_material_text_alignment, tvb, offset, sizeof(uint8_t), alignment); offset = BITS_TO_BYTES(bs.GetReadOffset());

			if (StringCompressor::Instance()->DecodeString(text, sizeof(text), &bs)) {
				proto_tree_add_string(tree, setplayerobjectmaterial_material_text_textOrTXD, tvb, offset, text_len, text); offset = BITS_TO_BYTES(bs.GetReadOffset());
			}
		}
	}
}