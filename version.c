#ifndef VERSION
#define VERSION "0.1"
#endif

#define WS_BUILD_DLL
#include <ws_attributes.h>
#include <ws_symbol_export.h>
#include <glib.h>
#include <ws_version.h>


WS_DLL_PUBLIC_DEF const gchar plugin_version[] = VERSION;
WS_DLL_PUBLIC_DEF const int plugin_want_major = WIRESHARK_VERSION_MAJOR;
WS_DLL_PUBLIC_DEF const int plugin_want_minor = WIRESHARK_VERSION_MINOR;