#ifndef _MAIN_H
#define _MAIN_H
#define HAVE_PLUGINS
#include <epan/packet.h>
#include <epan/proto.h>
#include <epan/conversation.h>

#include <ws_attributes.h>
#include <ws_symbol_export.h>

#include <stdint.h>

#ifndef _WIN32
#include <arpa/inet.h>
#endif

#define MAX_INCOMING_BUFFER 1492

#define SAMP_QUERY_MAGIC 0x53414d50

extern gint list_req_ett_foo;

extern int proto_samprpc;

typedef struct {
	int seq_id;
	int seq_group;
	int msg_len;
} MessageContext;

typedef struct _samp_conv_t {
	guint32	raknet_frame;
	uint16_t server_port;
} samp_conv_t;


samp_conv_t* get_samp_conversation_data(packet_info* pinfo);


void dissect_samprpc_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);

void dissect_samprpc_message_raknet_inner(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);

void dissect_samprpc_message_raknet_player_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_vehicle_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_stats_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_marker_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_aim_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_bullet_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_unoccupied_veh_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_spectator_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_passenger_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_trailer_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_weapons_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
extern gint samp_ett_foo;

bool is_samp_server(packet_info* pinfo);
#endif //_MAIN_H
