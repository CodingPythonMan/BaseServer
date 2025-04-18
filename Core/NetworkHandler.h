#pragma once
#include "TickRunner.h"
#include "BlockingQueue.h"
#include <WS2tcpip.h>
#include <windows.h>

class NetworkHost;
class IOContext;

class NetworkHandler : public TickRunner
{
public:
	NetworkHandler() = default;
	virtual ~NetworkHandler() = default;

	bool						CreateThread();
	bool						PushThread(IOContext* context);

	void						UpdateHost();

private:
	void						_RemoveHost(const int hostID);
	NetworkHost*				_FindHost(const int hostID);
	bool						_AddHost(NetworkHost* host);
	void						_AddServerHost(NetworkHost* host);

	static unsigned int WINAPI	_ExecuteThread(void* arg);

	void						_ProcessThread();
	void						_ProcessConnect(IOContext& context);
	void						_ProcessListen(IOContext& context);
	void						_ProcessJoin(IOContext& context);
	void						_ProcessDisconnect(IOContext& context);

private:
	BlockingQueue<IOContext*>				mContextQueue;

	// u_map<hostID, NetworkHost*>
	std::unordered_map<int, NetworkHost*>	mHostMap;
	HANDLE									mHandle;

	std::mutex								mRecvLock;
	std::unordered_map<int, bool>			mRecvCheckMap;

	std::mutex								mHostIDLock;
};