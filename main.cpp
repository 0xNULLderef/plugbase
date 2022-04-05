#include "main.hpp"

// global instance of class required for EXPOSE_SINGLE_INTERFACE_GLOBALVAR macro
Plugin plugin;
EXPOSE_SINGLE_INTERFACE_GLOBALVAR(Plugin, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, plugin);

// most useful plugin callbacks, recommend to dynamically VMT hook others

bool Plugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory) {
	return true;
}

void Plugin::Unload() { }

const char* Plugin::GetPluginDescription() {
	return "Example Plugin";
}

// unused callbacks that have to be defined anyway

void Plugin::Pause() { }
void Plugin::UnPause() { }
void Plugin::LevelInit(char const* pMapName) { }
void Plugin::ServerActivate(void* pEdictList, int edictCount, int clientMax) { }
void Plugin::GameFrame(bool simulating) { }
void Plugin::LevelShutdown() { }
void Plugin::ClientFullyConnect(void* pEdict) { }
void Plugin::ClientActive(void* pEntity) { }
void Plugin::ClientDisconnect(void* pEntity) { }
void Plugin::ClientPutInServer(void* pEntity, char const* playername) { }
void Plugin::SetCommandClient(int index) { }
void Plugin::ClientSettingsChanged(void* pEdict) { }
int Plugin::ClientConnect(bool* bAllowConnect, void* pEntity, const char* pszName, const char* pszAddress, char* reject, int maxrejectlen) { return 0; }
int Plugin::ClientCommand(void* pEntity, const void*& args) { return 0; }
int Plugin::NetworkIDValidated(const char* pszUserName, const char* pszNetworkID) { return 0; }
void Plugin::OnQueryCvarValueFinished(int iCookie, void* pPlayerEntity, int eStatus, const char* pCvarName, const char* pCvarValue) { }
void Plugin::OnEdictAllocated(void* edict) { }
void Plugin::OnEdictFreed(const void* edict) { }

