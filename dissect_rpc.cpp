#include "main.h"
#include "msgids.h"
#include "rak_minimal/DS_RangeList.h"
#include "rak_minimal/StringCompressor.h"
#include "rpc_def.h"
extern int rpcid_field;
void dissect_samprpc_message_raknet_rpc_inner(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_, RPCNameMap *rpc_map) {
    guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
    char *original_buffer = (char *)tvb_get_ptr(tvb, 0, orig_size);

    RakNet::BitStream bs;
    bs.Write(original_buffer, orig_size);

	bs.ResetReadPointer();

	if(rpc_map->mp_cust_dissect != NULL) {
		rpc_map->mp_cust_dissect(tvb, pinfo, tree, data, rpc_map);
		return;
	}

	int offset = 0;

	int c = 0;

	uint32_t i32_val = 0;
	uint16_t i16_val = 0;
	uint8_t i8_val = 0;
	float f_val = 0.0;
	char string_value[4096] = {0};

	bool is_server = is_samp_server(pinfo);
	while(1) {
		RPCVariableDesc *rpc_field = &rpc_map->mp_rpc_var_desc[c++];
		if(rpc_field->name == NULL) break;
			if(is_server) {
				if(!rpc_field->server_var) {
					continue;
				}
			} else {
				if(!rpc_field->client_var) {
					continue;
				}
			}
			switch(rpc_field->type) {
				case EVariableType_Uint32:
				bs.Read(i32_val);
				proto_tree_add_uint(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(uint32_t), i32_val); offset += sizeof(uint32_t);
				break;
				case EVariableType_Int32:
				bs.Read(i32_val);
				proto_tree_add_int(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(uint32_t), i32_val); offset += sizeof(uint32_t);
				break;
				case EVariableType_Int16:
				bs.Read(i16_val);
				proto_tree_add_int(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(uint16_t), i16_val); offset += sizeof(uint16_t);
				break;
				case EVariableType_Uint16:
				bs.Read(i16_val);
				proto_tree_add_uint(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(uint16_t), i16_val); offset += sizeof(uint16_t);
				break;
				case EVariableType_Uint8:
				bs.Read(i8_val);
				proto_tree_add_uint(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(uint8_t), i8_val); offset += sizeof(uint8_t);
				break;
				case EVariableType_LenStr:
				bs.Read(i8_val); offset += sizeof(uint8_t);
				bs.Read(string_value, i8_val);
				string_value[i8_val] = 0;
				proto_tree_add_string(tree, rpc_field->wireshark_field_id, tvb, offset, i8_val, string_value); offset += i8_val;
				break;
				case EVariableType_LenU16Str:
				bs.Read(i16_val); offset += sizeof(uint16_t);
				bs.Read(string_value, i16_val);
				string_value[i16_val] = 0;
				proto_tree_add_string(tree, rpc_field->wireshark_field_id, tvb, offset, i16_val, string_value); offset += i16_val;
				break;
				case EVariableType_LenU32Str:
				bs.Read(i32_val); offset += sizeof(uint32_t);
				bs.Read(string_value, i32_val);
				string_value[i32_val] = 0;
				proto_tree_add_string(tree, rpc_field->wireshark_field_id, tvb, offset, i32_val, string_value); offset += i32_val;
				break;
				case EVariableType_LenStr_Compressed:
				c = bs.GetNumberOfBytesUsed();
				if (StringCompressor::Instance()->DecodeString(string_value, sizeof(string_value), &bs)) {
					proto_tree_add_string(tree, rpc_field->wireshark_field_id, tvb, offset, bs.GetNumberOfBytesUsed() - c, string_value); offset += bs.GetNumberOfBytesUsed() - c;
				}
				break;
				case EVariableType_Float:
				bs.Read(f_val);
				proto_tree_add_float(tree, rpc_field->wireshark_field_id, tvb, offset, sizeof(float), f_val); offset += sizeof(float);
				break;
			}
	}
}
void dissect_samprpc_message_raknet_rpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_, RakNet::BitStream &bs) {
	int offset = 0;
	uint8_t rpc_id;

	uint32_t bits = 0;
	bs.Read(rpc_id);
	proto_tree_add_uint(tree, rpcid_field, tvb, offset, sizeof(uint8_t), rpc_id); offset += sizeof(uint8_t);

		

	bs.ReadCompressed(bits);

	uint16_t data_byte_len = BITS_TO_BYTES(bits);

	if (data_byte_len > 0) {
		guchar* decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, data_byte_len);
		memset(decrypted_heap_buffer, 0, data_byte_len);
		bs.ReadBits(decrypted_heap_buffer, bits);

		tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, data_byte_len, data_byte_len);
		add_new_data_source(pinfo, next_tvb, "RPC Data");

		RPCNameMap* rpc_map = GetRPCMapByID(rpc_id);
		if (rpc_map != NULL) {
			proto_item_set_text(tree, rpc_map->name);
			dissect_samprpc_message_raknet_rpc_inner(next_tvb, pinfo, tree, data, rpc_map);
		}
	}
}