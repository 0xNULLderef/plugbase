#ifndef SDK_HPP
#define SDK_HPP

#define INTERFACEVERSION_ISERVERPLUGINCALLBACKS "ISERVERPLUGINCALLBACKS002"

#define EXPOSE_SINGLE_INTERFACE_GLOBALVAR(className, interfaceName, versionName, globalVarName) \
	static void* __Create##className##interfaceName##_interface() { return static_cast<interfaceName*>(&globalVarName); } \
	static InterfaceReg __g_Create##className##interfaceName##_reg(__Create##className##interfaceName##_interface, versionName);

typedef void*(*CreateInterfaceFn)(const char* pName, int* pReturnCode);
typedef void*(*InstantiateInterfaceFn)();

struct InterfaceReg {
	InstantiateInterfaceFn m_CreateFn;
	const char* m_pName;
	InterfaceReg* m_pNext;
	static InterfaceReg* s_pInterfaceRegs;

	InterfaceReg(InstantiateInterfaceFn fn, const char* pName) : m_pName(pName) {
		m_CreateFn = fn;
		m_pNext = s_pInterfaceRegs;
		s_pInterfaceRegs = this;
	}
};

class IServerPluginCallbacks {
public:
	virtual bool Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) = 0;
	virtual void Unload() = 0;
	virtual void Pause() = 0;
	virtual void UnPause() = 0;
	virtual const char* GetPluginDescription() = 0;
	virtual void LevelInit(char const* pMapName) = 0;
	virtual void ServerActivate(void* pEdictList, int edictCount, int clientMax) = 0;
	virtual void GameFrame(bool simulating) = 0;
	virtual void LevelShutdown() = 0;
	virtual void ClientFullyConnect(void* pEdict) = 0;
	virtual void ClientActive(void* pEntity) = 0;
	virtual void ClientDisconnect(void* pEntity) = 0;
	virtual void ClientPutInServer(void* pEntity, char const* playername) = 0;
	virtual void SetCommandClient(int index) = 0;
	virtual void ClientSettingsChanged(void* pEdict) = 0;
	virtual int ClientConnect(bool* bAllowConnect, void* pEntity, const char* pszName, const char* pszAddress, char* reject, int maxrejectlen) = 0;
	virtual int ClientCommand(void* pEntity, const void*& args) = 0;
	virtual int NetworkIDValidated(const char* pszUserName, const char* pszNetworkID) = 0;
	virtual void OnQueryCvarValueFinished(int iCookie, void* pPlayerEntity, int eStatus, const char* pCvarName, const char* pCvarValue) = 0;
	virtual void OnEdictAllocated(void* edict) = 0;
	virtual void OnEdictFreed(const void* edict) = 0;
};

#endif // SDK_HPP

