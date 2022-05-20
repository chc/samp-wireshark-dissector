#ifndef _MAIN_H
#define _MAIN_H
#define WS_BUILD_DLL
#define HAVE_PLUGINS
#include <epan/packet.h>
#include <epan/proto.h>
#include <epan/conversation.h>

#ifndef VERSION
#define VERSION "0.0.0"
#endif

#include <ws_attributes.h>
#include <ws_symbol_export.h>
//#include <wireshark/config.h>
//#include <wireshark/ws_version.h>

#include <stdint.h>

#include <arpa/inet.h>

#define MAX_INCOMING_BUFFER 1492

#define SAMP_SERVER_PORT 7777

extern gint list_req_ett_foo;

extern int proto_samprpc;

typedef struct {
	int seq_id;
	int seq_group;
	int msg_len;
} MessageContext;

void dissect_samprpc_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);

void dissect_samprpc_message_raknet_inner(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);

void dissect_samprpc_message_raknet_player_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_vehicle_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_stats_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_marker_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_aim_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_bullet_sync(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);
void dissect_samprpc_message_raknet_unoccupied_veh_update(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_);


extern gint samp_ett_foo;

#endif //_MAIN_H
