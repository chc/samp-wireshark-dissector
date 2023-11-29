#include "main.h"
#include "encryption.h"
#include "rak_minimal/StringCompressor.h"

void init_rpc_fields(int dissector);

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

        int decrypted_length = orig_size;

        if (pinfo->srcport != SAMP_SERVER_PORT) {
            if (sampDecrypt((uint8_t*)&decrypted_buffer, orig_size, SAMP_SERVER_PORT, 0)) {
                decrypted_length--;
                if (decrypted_length > 0) {
                    guchar* decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, decrypted_length);
                    memcpy(decrypted_heap_buffer, decrypted_buffer, decrypted_length);

                    tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, decrypted_length, decrypted_length);
                    add_new_data_source(pinfo, next_tvb, "Decrypted Data");
                    dissect_samprpc_message(next_tvb, pinfo, tree, data);
                }
            }
        }
        else {
            dissect_samprpc_message(tvb, pinfo, tree, data);
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

    void
        proto_reg_handoff_samprpc(void)
    {
        static dissector_handle_t samprpc_handle;

        samprpc_handle = create_dissector_handle(dissect_samprpc, proto_samprpc);
        dissector_add_uint("udp.port", SAMP_SERVER_PORT, samprpc_handle);
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
