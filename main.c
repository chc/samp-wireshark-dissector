#include "main.h"
#define WIRESHARK_VERSION_MAJOR 3
#define WIRESHARK_VERSION_MINOR 2
WS_DLL_PUBLIC_DEF const gchar plugin_version[] = VERSION;
WS_DLL_PUBLIC_DEF const int plugin_want_major = WIRESHARK_VERSION_MAJOR;
WS_DLL_PUBLIC_DEF const int plugin_want_minor = WIRESHARK_VERSION_MINOR;

WS_DLL_PUBLIC void plugin_register(void);

int proto_samprpc = -1;


gint samp_ett_foo = -1;



static gint *samp_ett[] = {
    &samp_ett_foo
};



static int
dissect_samprpc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_)
{
    col_set_str(pinfo->cinfo, COL_PROTOCOL, "SAMP RPC");

    char decrypted_buffer[MAX_INCOMING_BUFFER];
    guint16 orig_size = tvb_captured_length_remaining(tvb, 0);
    char *original_buffer = (char *)tvb_get_ptr(tvb, 0, orig_size);
    memcpy((char *)&decrypted_buffer, original_buffer, orig_size);

    //int decrypted_length = validate_and_copy_stream(original_buffer, &decrypted_buffer, orig_size, 1);

    int decrypted_length = orig_size;

    if(pinfo->srcport != SAMP_SERVER_PORT) {
        sampDecrypt((char *)&decrypted_buffer, orig_size, SAMP_SERVER_PORT, 0);
        decrypted_length--;
        if(decrypted_length > 0) {
            guchar *decrypted_heap_buffer = (guchar*)wmem_alloc(pinfo->pool, decrypted_length);
            memcpy(decrypted_heap_buffer, decrypted_buffer, decrypted_length);
            
            tvbuff_t* next_tvb = tvb_new_child_real_data(tvb, decrypted_heap_buffer, decrypted_length, decrypted_length);
            add_new_data_source(pinfo, next_tvb, "Decrypted Data");
            dissect_samprpc_message(next_tvb, pinfo, tree, data);
        }
    } else {
        dissect_samprpc_message(tvb, pinfo, tree, data);
    }
    

    




    return tvb_captured_length(tvb);
}

void
proto_register_samprpc(void)
{
    proto_samprpc = proto_register_protocol (
        "SAMP RPC",          /* name        */
        "samp_rpc",          /* short name  */
        "samp_rpc"           /* filter_name */
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
    //dissector_add_uint("udp.port", THPS_CLIENT_PORT, samprpc_handle);
}


void plugin_register(void)
 {
     static proto_plugin plug;
 
     plug.register_protoinfo = proto_register_samprpc;
     plug.register_handoff = proto_reg_handoff_samprpc; /* or NULL */
     proto_register_plugin(&plug);
}
