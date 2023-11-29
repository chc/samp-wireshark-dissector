#ifndef _RPC_DEF_H
#define _RPC_DEF_H
extern "C" {
void init_standard_fields(int dissector);
enum EVariableType {
    EVariableType_NoInit = 0,
    EVariableType_Uint32,
    EVariableType_Uint16,
    EVariableType_Uint8,
    EVariableType_Int32,
    EVariableType_Int16,
    EVariableType_Int8,
    EVariableType_Float,
    EVariableType_NormQuat,
    EVariableType_NormVec,
    EVariableType_LenStr,
    EVariableType_LenU16Str,
    EVariableType_LenU32Str,
    EVariableType_LenStr_Compressed,
    EVariableType_CompressedBool,
    EVariableType_Custom,
};
enum ESAMPRPC {
ESAMPRPC_SetPlayerName = 11,
		ESAMPRPC_SetPlayerPos = 12,	
		ESAMPRPC_SetPlayerPosFindZ = 13,	
		ESAMPRPC_SetPlayerHealth = 14,
		ESAMPRPC_TogglePlayerControllable = 15,
		ESAMPRPC_PlaySound = 16,
		ESAMPRPC_SetWorldBounds = 17,
		ESAMPRPC_GiveMoney = 18,
		ESAMPRPC_SetPlayerFacingAngle = 19,
		ESAMPRPC_ResetMoney = 20,	
		ESAMPRPC_ResetPlayerWeapons = 21,
		ESAMPRPC_GivePlayerWeapon = 22,
		ESAMPRPC_ScoreboardSelectPlayer = 23,
		ESAMPRPC_SetVehicleParams = 24,
		ESAMPRPC_ClientJoin = 25,
		ESAMPRPC_EnterVehicle = 26,
		ESAMPRPC_SelectObject = 27,
		ESAMPRPC_CancelEdit = 28,
		ESAMPRPC_SetPlayerTime = 29,
		ESAMPRPC_ToggleClock = 30,
		ESAMPRPC_AddPlayerToWorld = 32,
		ESAMPRPC_SetPlayerSkillLevel = 34,
		ESAMPRPC_SetPlayerDrunkLevel = 35,
		ESAMPRPC_Create3DTextLabel = 36,
		ESAMPRPC_DisableCheckpoint = 37,
		ESAMPRPC_SetRaceCheckpoint = 38,
		ESAMPRPC_DisableRaceCheckpoint = 39,
		ESAMPRPC_Death = 53,
		ESAMPRPC_PlayAudioStream = 41, 
		ESAMPRPC_StopAudioStream = 42, 
		ESAMPRPC_RemoveBuilding = 43,
		ESAMPRPC_CreateObject = 44,
		ESAMPRPC_SetObjectPos = 45,
		ESAMPRPC_SetObjectRot = 46,
		ESAMPRPC_DeleteObject = 47,
		ESAMPRPC_ClientCommand = 50,
		ESAMPRPC_ClientSpawned = 52,
		ESAMPRPC_NPCJoin = 54,
		ESAMPRPC_DeathMessage = 55,
		ESAMPRPC_SetMapIcon = 56,
		ESAMPRPC_Delete3DTextLabel = 58,
		ESAMPRPC_PlayerChatBubble = 59,
		ESAMPRPC_PlayerUpdate = 60,
		ESAMPRPC_SendPlayerDialog = 61,
		ESAMPRPC_DialogResponse = 62,
		ESAMPRPC_DestroyPickup = 63,
		ESAMPRPC_LinkVehicleToInterior = 65,
		ESAMPRPC_SetPlayerArmour = 66,
		ESAMPRPC_SetPlayerHoldingWeapon = 67,
		ESAMPRPC_SetPlayerSpawnInfo = 68,
		ESAMPRPC_SetPlayerTeam = 69,
		ESAMPRPC_PutPlayerInVehicle = 70,
		ESAMPRPC_RemovePlayerFromVehicle = 71,
		ESAMPRPC_SetPlayerColor = 72,
		ESAMPRPC_ShowGameText = 73,
		ESAMPRPC_ForceClassSelection = 74,
		ESAMPRPC_ShowMenu = 76,
		ESAMPRPC_CreateExplosion = 79,
		ESAMPRPC_ShowNameTag = 80,
		ESAMPRPC_InterpolateCamera = 82,
		ESAMPRPC_SelectTextDraw = 83,
		ESAMPRPC_SetObjectMaterialText = 84,
		ESAMPRPC_GangZoneStopFlash = 85,
		ESAMPRPC_ApplyAnimation = 86,
		ESAMPRPC_ClearAnimations = 87,
		ESAMPRPC_SetPlayerSpecialAction = 88,
		ESAMPRPC_SetPlayerFightingStyle = 89,
		ESAMPRPC_SetPlayerVelocity = 90,
		ESAMPRPC_SetVehicleVelocity = 91,
		ESAMPRPC_WorldTime = 94,
		ESAMPRPC_CreatePickup = 95,
		ESAMPRPC_ScmEvent = 96,
		ESAMPRPC_MoveObject = 99,
		ESAMPRPC_SendClientMessage = 93,
		ESAMPRPC_ChatMessage = 101,
		ESAMPRPC_ClientCheck = 103,
		ESAMPRPC_EditTextDraw = 105,
		ESAMPRPC_OnVehicleDamage = 106,
		ESAMPRPC_SetPlayerCheckpoint = 107,
		ESAMPRPC_AddGangZone = 108,
		ESAMPRPC_PlayCrimeReport = 112,
		ESAMPRPC_SetPlayerAttachedObject = 113,
		ESAMPRPC_GiveTakeDamage = 115,
		ESAMPRPC_EditAttachedObject = 116,
		ESAMPRPC_EditObject = 117,
		ESAMPRPC_SetInterior = 118,
		ESAMPRPC_MapMarker = 119,
		ESAMPRPC_GangZoneDestroy = 120,
		ESAMPRPC_GangZoneFlash = 121,
		ESAMPRPC_StopObject = 122,
		ESAMPRPC_SetCarPlate = 123,
		ESAMPRPC_TogglePlayerSpectating = 124,
		ESAMPRPC_PlayerSpectatePlayer = 126,
		ESAMPRPC_PlayerSpectateVehicle = 127,
		ESAMPRPC_RequestClass = 128,
		ESAMPRPC_RequestSpawn = 129,
		ESAMPRPC_ShowTextDraw = 134,
		ESAMPRPC_ConnectionRejected = 130,
		ESAMPRPC_PickupPickup = 131,
		ESAMPRPC_SetPlayerWantedLevel = 133,
		ESAMPRPC_HideTextDraw = 135,
		ESAMPRPC_VehicleDestroyed = 136,
		ESAMPRPC_ServerJoin = 137,
		ESAMPRPC_ServerQuit = 138,
		ESAMPRPC_InitGame = 139,
		ESAMPRPC_RemoveMapIcon = 144,
		ESAMPRPC_SetGravity = 146,
		ESAMPRPC_SetVehicleHealth = 147,
		ESAMPRPC_AttachTrailerToVehicle = 148,
		ESAMPRPC_DetachTrailerFromVehicle = 149,
		ESAMPRPC_SetPlayerWeather = 152,
		ESAMPRPC_SetPlayerSkin = 153,
		ESAMPRPC_ExitVehicle = 154,
		ESAMPRPC_UpdateScoresPingsIP = 155,
		ESAMPRPC_ScrSetInterior = 156,
		ESAMPRPC_SetCameraPos = 157,
		ESAMPRPC_SetCameraLookAt = 158,
		ESAMPRPC_SetVehiclePos = 159,
		ESAMPRPC_SetVehicleZAngle = 160,
		ESAMPRPC_SetVehicleParamsForPlayer = 161, //doesn't make logical sense... 
		ESAMPRPC_SetCameraBehindPlayer = 162,
		ESAMPRPC_DeletePlayerFromWorld = 163,
		ESAMPRPC_VehicleCreate = 164,
		ESAMPRPC_VehicleDelete = 165,
		ESAMPRPC_PlayerDeath = 166,
		ESAMPRPC_DisableRemoteVehicleCollisions = 167,
		ESAMPRPC_CameraTargetData = 168,
		ESAMPRPC_EnablePlayerCameraTarget = 170,
		ESAMPRPC_CreateActor = 171,
		ESAMPRPC_DestroyActor = 172,
		ESAMPRPC_ApplyActorAnim = 173,
		ESAMPRPC_SetActorVulnerability = 174,
		ESAMPRPC_SetActorPos = 176,
		ESAMPRPC_OnDamageActor = 177,
};


	struct _RPCNameMap;
	typedef struct {
		const char *name;
		EVariableType type;
		bool client_var;
		bool server_var;
	    hf_register_info wireshark_field;
    	int wireshark_field_id;
	} RPCVariableDesc;
	#define MAX_RPC_VARIABLES 50
	typedef struct _RPCNameMap {
		const char *name;
		uint32_t rpc_id; 
		RPCVariableDesc mp_rpc_var_desc[MAX_RPC_VARIABLES];
		void (*mp_cust_dissect)(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree _U_, void *data _U_, struct _RPCNameMap *rpc_map);
	} RPCNameMap;

	RPCNameMap *GetRPCMapByID(uint8_t msgid);

	void dissect_game_init(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map);
	void dissect_create_object(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map);
	void dissect_scoreboard_pings(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map);
	void dissect_set_player_attached_object(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map);
	void dissect_set_object_material_text(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree _U_, void* data _U_, struct _RPCNameMap* rpc_map);
}
#endif //_RPC_DEF_H