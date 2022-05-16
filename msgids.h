#ifndef _SAMP_MSGIDS_H
#define _SAMP_MSGIDS_H

	#define SAMP_MAGIC 0x504d4153
	#define SAMP_COOKIE 0x6969
	
	enum PacketEnumeration
	{
		ID_INTERNAL_PING = 6,
		ID_PING,
		ID_PING_OPEN_CONNECTIONS,
		ID_CONNECTED_PONG,
		ID_REQUEST_STATIC_DATA,
		ID_CONNECTION_REQUEST,
		ID_AUTH_KEY,
		ID_BROADCAST_PINGS = 14,
		ID_SECURED_CONNECTION_RESPONSE,
		ID_SECURED_CONNECTION_CONFIRMATION,
		ID_RPC_MAPPING,
		ID_SET_RANDOM_NUMBER_SEED = 19,
		ID_RPC,
		ID_RPC_REPLY,
		ID_DETECT_LOST_CONNECTIONS = 23,
		ID_OPEN_CONNECTION_REQUEST,
		ID_OPEN_CONNECTION_REPLY,
		ID_OPEN_CONNECTION_COOKIE,
		ID_RSA_PUBLIC_KEY_MISMATCH = 28,
		ID_CONNECTION_ATTEMPT_FAILED,
		ID_NEW_INCOMING_CONNECTION = 30,
		ID_NO_FREE_INCOMING_CONNECID_AUTH_KEYTIONS = 31,
		ID_DISCONNECTION_NOTIFICATION,	
		ID_CONNECTION_LOST,
		ID_CONNECTION_REQUEST_ACCEPTED,
		ID_FAILED_INIT_ENCRYPTION,
		ID_CONNECTION_BANNED,
		ID_INVALID_PASS,
		ID_MODIFIED_PACKET,
		ID_PONG,
		ID_TIMESTAMP,
		ID_RECEIVED_STATIC_DATA,
		ID_REMOTE_DISCONNECTION_NOTIFICATION,
		ID_REMOTE_CONNECTION_LOST,
		ID_REMOTE_NEW_INCOMING_CONNECTION,
		ID_REMOTE_EXISTING_CONNECTION,
		ID_REMOTE_STATIC_DATA,
		ID_ADVERTISE_SYSTEM = 55,

		ID_PLAYER_SYNC = 207,
		ID_MARKERS_SYNC = 208,
		ID_UNOCCUPIED_SYNC = 209,
		ID_TRAILER_SYNC = 210,
		ID_PASSENGER_SYNC = 211,
		ID_SPECTATOR_SYNC = 212,
		ID_AIM_SYNC = 203,
		ID_VEHICLE_SYNC = 200,
		ID_RCON_COMMAND = 201,
		ID_RCON_RESPONCE = 202,
		ID_WEAPONS_UPDATE = 204,
		ID_STATS_UPDATE = 205,
		ID_BULLET_SYNC = 206,
	};

	/// These enumerations are used to describe when packets are delivered.
	enum PacketPriority
	{
		SYSTEM_PRIORITY,   /// \internal Used by RakNet to send above-high priority messages.
		HIGH_PRIORITY,   /// High priority messages are send before medium priority messages.
		MEDIUM_PRIORITY,   /// Medium priority messages are send before low priority messages.
		LOW_PRIORITY,   /// Low priority messages are only sent when no other messages are waiting.
		NUMBER_OF_PRIORITIES
	};

	/// These enumerations are used to describe how packets are delivered.
	/// \note  Note to self: I write this with 3 bits in the stream.  If I add more remember to change that
	enum PacketReliability
	{
		UNRELIABLE = 6,   /// Same as regular UDP, except that it will also discard duplicate datagrams.  RakNet adds (6 to 17) + 21 bits of overhead, 16 of which is used to detect duplicate packets and 6 to 17 of which is used for message length.
		UNRELIABLE_SEQUENCED,  /// Regular UDP with a sequence counter.  Out of order messages will be discarded.  This adds an additional 13 bits on top what is used for UNRELIABLE.
		RELIABLE,   /// The message is sent reliably, but not necessarily in any order.  Same overhead as UNRELIABLE.
		RELIABLE_ORDERED,   /// This message is reliable and will arrive in the order you sent it.  Messages will be delayed while waiting for out of order messages.  Same overhead as UNRELIABLE_SEQUENCED.
		RELIABLE_SEQUENCED /// This message is reliable and will arrive in the sequence you sent it.  Out or order messages will be dropped.  Same overhead as UNRELIABLE_SEQUENCED.
	};

	/// Given a number of bits, return how many uint8_ts are needed to represent that.
	#define BITS_TO_BYTES(x) (((x)+7)>>3)
	#define BYTES_TO_BITS(x) ((x)<<3)
	#define ALIGNED_BITS(x) (BYTES_TO_BITS(BITS_TO_BYTES(x)))

	#define NUMBER_OF_ORDERED_STREAMS 32 // 2^5

	typedef struct {
		uint8_t msgid;
		const char *name;
	} MessageTable;

	MessageTable *FindMessageInfoById(uint8_t msgid);

#endif // _SAMP_MSGIDS_H