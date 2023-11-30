#include "main.h"
#include "encryption.h"
#include "rak_minimal/StringCompressor.h"

void init_rpc_fields(int dissector);

extern int samp_query_magic;
extern int samp_query_ipv4_addr;
extern int samp_query_port;
extern int samp_query_opcode;

extern int samp_query_info_resp_password;
extern int samp_query_info_resp_numplayers;
extern int samp_query_info_resp_maxplayers;
extern int samp_query_info_resp_hostname;
extern int samp_query_info_resp_gamemode;
extern int samp_query_info_resp_language;

//samp query rules
extern int samp_query_rules_resp_count;
extern int samp_query_rules_resp_rulename;
extern int samp_query_rules_resp_rulevalue;

//samp query clients
extern int samp_query_clients_playercount;
extern int samp_query_clients_nick;
extern int samp_query_clients_score;

//samp query detailed
extern int samp_query_detailed_playercount;
extern int samp_query_detailed_nick;
extern int samp_query_detailed_score;
extern int samp_query_detailed_ping;

//samp query ping
extern int samp_query_ping_identifier;

//samp rcon
extern int samp_query_rcon_password;
extern int samp_query_rcon_message;


extern "C" {

    #include <epan/reassemble.h>

    static gint ett_samp_fragment = -1;
    static gint ett_samp_fragments = -1;

    gint hf_samp_fragments = -1;
    gint hf_samp_fragment = -1;
    gint hf_samp_fragment_overlap = -1;
    gint hf_samp_fragment_overlap_conflicts = -1;
    gint hf_samp_fragment_multiple_tails = -1;
    gint hf_samp_fragment_too_long_fragment = -1;
    gint hf_samp_fragment_error = -1;
    gint hf_samp_fragment_count = -1;
    gint hf_samp_reassembled_in = -1;
    gint hf_samp_reassembled_length = -1;
    gint hf_samp_reassembled_data = -1;

    fragment_items samp_msg_frag_items = {
        /* Fragment subtrees */
        &ett_samp_fragment,
        &ett_samp_fragments,
        /* Fragment fields */
        &hf_samp_fragments,                  /* FT_NONE     */
        &hf_samp_fragment,                   /* FT_FRAMENUM */
        &hf_samp_fragment_overlap,           /* FT_BOOLEAN  */
        &hf_samp_fragment_overlap_conflicts, /* FT_BOOLEAN  */
        &hf_samp_fragment_multiple_tails,    /* FT_BOOLEAN  */
        &hf_samp_fragment_too_long_fragment, /* FT_BOOLEAN  */
        &hf_samp_fragment_error,
        &hf_samp_fragment_count,
        /* Reassembled in field */
        &hf_samp_reassembled_in,
        /* Reassembled length field */
        &hf_samp_reassembled_length,
        &hf_samp_reassembled_data,
        /* Tag */
        "Message fragments" };

    WS_DLL_PUBLIC void plugin_register(void);

    reassembly_table msg_reassembly_table;



    int proto_samprpc = -1;
    gint samp_ett_foo = -1;
    static gint* samp_ett[] = {
        &samp_ett_foo,
        &ett_samp_fragment,
        &ett_samp_fragments
    };

    static int
        dissect_samprpc(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_)
    {
        col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAMP");

        char decrypted_buffer[MAX_INCOMING_BUFFER];
        guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
        char* original_buffer = (char*)tvb_get_ptr(tvb, 0, orig_size);
        memcpy((char*)&decrypted_buffer, original_buffer, orig_size);

        samp_conv_t* samp_conv = (samp_conv_t*)get_samp_conversation_data(pinfo);

        int decrypted_length = orig_size;
        if (samp_conv->server_port == pinfo->destport) {
            if (sampDecrypt((uint8_t*)&decrypted_buffer, orig_size, pinfo->destport, 0)) {
                decrypted_length--;
                if (decrypted_length > 0) {
                    guchar* decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, decrypted_length);
                    memcpy(decrypted_heap_buffer, decrypted_buffer, decrypted_length);

                    tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, decrypted_length, decrypted_length);
                    add_new_data_source(pinfo, next_tvb, "Decrypted Data");
                    dissect_samprpc_message(next_tvb, pinfo, tree, data);
                }
            }
            else { //corrupt data

            }
        }
        else {
            dissect_samprpc_message(tvb, pinfo, tree, data);
        }
        return tvb_captured_length(tvb);
    }

    void handle_samp_query_info(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            proto_tree_add_item(tree, samp_query_info_resp_password, tvb, offset, sizeof(uint8_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint8_t);
            proto_tree_add_item(tree, samp_query_info_resp_numplayers, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);
            proto_tree_add_item(tree, samp_query_info_resp_maxplayers, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);

            guint32 len = tvb_get_guint32(tvb, offset, ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
            proto_tree_add_item(tree, samp_query_info_resp_hostname, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;

            len = tvb_get_guint32(tvb, offset, ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
            proto_tree_add_item(tree, samp_query_info_resp_gamemode, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;

            len = tvb_get_guint32(tvb, offset, ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
            proto_tree_add_item(tree, samp_query_info_resp_language, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
        }        
    }
    void handle_samp_query_clients(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            guint32 player_count;
            proto_tree_add_item_ret_uint(tree, samp_query_clients_playercount, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN, &player_count); offset += sizeof(uint16_t);
            for (int i = 0; i < player_count && tvb_reported_length_remaining(tvb, offset) > 0; i++) {
                guint8 len = tvb_get_guint8(tvb, offset); offset += sizeof(uint8_t);
                proto_tree_add_item(tree, samp_query_clients_nick, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
                proto_tree_add_item(tree, samp_query_clients_score, tvb, offset, sizeof(uint32_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
            }
        }
    }
    void handle_samp_query_detailed(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            guint32 player_count;
            proto_tree_add_item_ret_uint(tree, samp_query_detailed_playercount, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN, &player_count); offset += sizeof(uint16_t);
            for (int i = 0; i < player_count && tvb_reported_length_remaining(tvb, offset) > 0; i++) {
                guint8 len = tvb_get_guint8(tvb, offset); offset += sizeof(uint8_t);
                proto_tree_add_item(tree, samp_query_detailed_nick, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
                proto_tree_add_item(tree, samp_query_detailed_score, tvb, offset, sizeof(uint32_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
                proto_tree_add_item(tree, samp_query_detailed_ping, tvb, offset, sizeof(uint32_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint32_t);
            }
        }
    }
    void handle_samp_query_rules(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            guint32 rule_count;
            proto_tree_add_item_ret_uint(tree, samp_query_rules_resp_count, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN, &rule_count); offset += sizeof(uint16_t);
            for (int i = 0; i < rule_count && tvb_reported_length_remaining(tvb, offset) > 0; i++) {
                guint8 len = tvb_get_guint8(tvb, offset); offset += sizeof(uint8_t);
                proto_tree_add_item(tree, samp_query_rules_resp_rulename, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;

                len = tvb_get_guint8(tvb, offset); offset += sizeof(uint8_t);
                proto_tree_add_item(tree, samp_query_rules_resp_rulevalue, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
            }
        }
    }
    void handle_samp_query_ping(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            proto_tree_add_item(tree, samp_query_ping_identifier, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);
        }
    }
    void handle_samp_query_rcon(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, int offset) {
        if (tvb_reported_length_remaining(tvb, offset) > 0) {
            guint16 len = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);
            bool is_server_response = tvb_reported_length_remaining(tvb, offset + sizeof(uint16_t) + len) == 0;
            if (is_server_response) {
                proto_tree_add_item(tree, samp_query_rcon_message, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
            }
            else {
                proto_tree_add_item(tree, samp_query_rcon_password, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;

                len = tvb_get_guint16(tvb, offset, ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);
                proto_tree_add_item(tree, samp_query_rcon_message, tvb, offset, len, ENC_LITTLE_ENDIAN); offset += len;
            }
        }
    }
    
    static int
        dissect_samp_query(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_)
    {
        guint32 opcode;

        col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAMP Query");

        int offset = 0;
        proto_tree_add_item(tree, samp_query_magic, tvb, offset, sizeof(uint32_t), ENC_BIG_ENDIAN); offset += sizeof(uint32_t);
        proto_tree_add_item(tree, samp_query_ipv4_addr, tvb, offset, sizeof(uint32_t), ENC_BIG_ENDIAN); offset += sizeof(uint32_t);
        proto_tree_add_item(tree, samp_query_port, tvb, offset, sizeof(uint16_t), ENC_LITTLE_ENDIAN); offset += sizeof(uint16_t);
        proto_tree_add_item_ret_uint(tree, samp_query_opcode, tvb, offset, sizeof(uint8_t), ENC_BIG_ENDIAN, &opcode); offset += sizeof(uint8_t);

        switch ((char)opcode) {
        case 'i':
            handle_samp_query_info(tvb, pinfo, tree, data, offset);
            break;
        case 'r':
            handle_samp_query_rules(tvb, pinfo, tree, data, offset);
            break;
        case 'c':
            handle_samp_query_clients(tvb, pinfo, tree, data, offset);
            break;
        case 'd':
            handle_samp_query_detailed(tvb, pinfo, tree, data, offset);
            break;
        case 'p':
            handle_samp_query_ping(tvb, pinfo, tree, data, offset);
            break;
        case 'x':
            handle_samp_query_rcon(tvb, pinfo, tree, data, offset);
            break;
        }
        return tvb_captured_length(tvb);
    }

    void
        proto_register_samprpc(void)
    {
        proto_samprpc = proto_register_protocol(
            "SAMP",          /* name        */
            "samp",          /* short name  */
            "samp"           /* filter_name */
        );
        init_rpc_fields(proto_samprpc);
        proto_register_subtree_array(samp_ett, array_length(samp_ett));
    }

    static gboolean
        dissect_samp_heur_udp(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data)
    {
        samp_conv_t* samp_conv = (samp_conv_t*)get_samp_conversation_data(pinfo);
        if (samp_conv->server_port != 0) {
            dissect_samprpc(tvb, pinfo, tree, data);
            return TRUE;
        }

        char decrypted_buffer[MAX_INCOMING_BUFFER];
        guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
        char* original_buffer = (char*)tvb_get_ptr(tvb, 0, orig_size);
        memcpy((char*)&decrypted_buffer, original_buffer, orig_size);

        if (sampDecrypt((uint8_t*)&decrypted_buffer, orig_size, pinfo->destport, 0)) {
            samp_conv->server_port = pinfo->destport;
            dissect_samprpc(tvb, pinfo, tree, data);
            return TRUE;
        }

        return FALSE;
    }

    static gboolean
        dissect_samp_query_heur_udp(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data)
    {
        if (tvb_captured_length_remaining(tvb, 0) >= 4) {
            guint32 samp_magic = tvb_get_guint32(tvb, 0, ENC_BIG_ENDIAN);
            if (samp_magic == SAMP_QUERY_MAGIC) {
                dissect_samp_query(tvb, pinfo, tree, data);
                return TRUE;
            }
        }
        return FALSE;
    }


    void
        proto_reg_handoff_samprpc(void)
    {
        static dissector_handle_t samprpc_handle;

        samprpc_handle = create_dissector_handle(dissect_samprpc, proto_samprpc);
        heur_dissector_add("udp", dissect_samp_heur_udp, "SA:MP",
            "samp", proto_samprpc, HEURISTIC_ENABLE);

        heur_dissector_add("udp", dissect_samp_query_heur_udp, "SA:MP Query",
            "samp_query", proto_samprpc, HEURISTIC_ENABLE);
    }


    void plugin_register(void)
    {
        StringCompressor::AddReference();

        reassembly_table_register(&msg_reassembly_table, &addresses_reassembly_table_functions);

        static proto_plugin plug;

        plug.register_protoinfo = proto_register_samprpc;
        plug.register_handoff = proto_reg_handoff_samprpc; /* or NULL */
        proto_register_plugin(&plug);
    }
}

samp_conv_t* get_samp_conversation_data(packet_info* pinfo)
{
    conversation_t* conversation;
    samp_conv_t* conv_data;

    conversation = find_or_create_conversation(pinfo);

    /* Retrieve information from conversation
     * or add it if it isn't there yet
     */
    conv_data = (samp_conv_t*)conversation_get_proto_data(conversation, proto_samprpc);
    if (!conv_data) {
        /* Setup the conversation structure itself */
        conv_data = (samp_conv_t*)wmem_alloc0(wmem_file_scope(), sizeof(samp_conv_t));

        conversation_add_proto_data(conversation, proto_samprpc,
            conv_data);
    }

    return conv_data;
}
bool is_samp_server(packet_info* pinfo) {
    samp_conv_t* conv = get_samp_conversation_data(pinfo);
    return conv->server_port == pinfo->srcport;
}