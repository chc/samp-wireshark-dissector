cmake_minimum_required (VERSION 2.6)

project(samprpc)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file (GLOB MAIN_SRCS "*.c" "*.cpp")
file (GLOB MAIN_HDRS "*.h")

file (GLOB RAKNET_SRCS "rak_minimal/*.cpp")

set (ALL_SRCS ${MAIN_SRCS} ${MAIN_HDRS} ${RAKNET_SRCS})

include_directories (${CMAKE_CURRENT_SOURCE_DIR} /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/wireshark)

source_group("Sources" FILES ${ALL_SRCS})
source_group("Headers" FILES ${MAIN_HDRS})

add_library (samprpc SHARED ${ALL_SRCS})
target_link_libraries(samprpc wireshark)