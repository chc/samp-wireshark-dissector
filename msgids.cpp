#include "main.h"
#include "msgids.h"
MessageTable msgTable[] = {
    {ID_DETECT_LOST_CONNECTIONS, "DETECT_LOST_CONNECTIONS"},
    {ID_RPC, "RPC"},
    {ID_PING, "PING"},
    {ID_INTERNAL_PING, "INTERNAL_PING"},
    {ID_PING_OPEN_CONNECTIONS, "PING_OPEN_CONNECTIONS"},
    {ID_CONNECTED_PONG, "CONNECTED_PONG"},
    {ID_OPEN_CONNECTION_REQUEST, "OPEN_CONNECTION_REQUEST"},
    {ID_OPEN_CONNECTION_REPLY, "OPEN_CONNECTION_REPLY"},
    {ID_OPEN_CONNECTION_COOKIE, "OPEN_CONNECTION_COOKIE"},
    {ID_TIMESTAMP, "TIMESTAMP"},
    {ID_CONNECTION_REQUEST, "CONNECTION_REQUEST"},
    {ID_CONNECTION_REQUEST_ACCEPTED, "CONNECTION_REQUEST_ACCEPTED"},    
    {ID_AUTH_KEY, "AUTH_KEY"},
    {ID_RECEIVED_STATIC_DATA, "RECEIVED_STATIC_DATA"},
    {ID_NEW_INCOMING_CONNECTION, "NEW_INCOMING_CONNECTION"},
    {ID_DISCONNECTION_NOTIFICATION, "DISCONNECTION_NOTIFICATION"},
    {ID_PLAYER_SYNC, "PLAYER_SYNC"},
    {ID_MARKERS_SYNC, "MARKERS_SYNC"},
    {ID_UNOCCUPIED_SYNC, "UNOCCUPIED_SYNC"},
    {ID_TRAILER_SYNC, "TRAILER_SYNC"},
    {ID_PASSENGER_SYNC, "PASSENGER_SYNC"},
    {ID_SPECTATOR_SYNC, "SPECTATOR_SYNC"},
    {ID_AIM_SYNC, "AIM_SYNC"},
    {ID_VEHICLE_SYNC, "VEHICLE_SYNC"},
    {ID_RCON_COMMAND, "RCON_COMMAND"},
    {ID_RCON_RESPONCE, "RCON_RESPONCE"},
    {ID_WEAPONS_UPDATE, "WEAPONS_UPDATE"},
    {ID_STATS_UPDATE, "STATS_UPDATE"},
    {ID_BULLET_SYNC, "BULLET_SYNC"}
        
};
MessageTable *FindMessageInfoById(uint8_t msgid) {
    for(int i=0;i<sizeof(msgTable)/sizeof(MessageTable);i++) {
        if (msgTable[i].msgid == msgid) {
            return &msgTable[i];
        }
    }
    return NULL;
}