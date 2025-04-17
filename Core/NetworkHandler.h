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
	void						_ProcessThread();

	void						UpdateHost();

private:
	void						_RemoveHost(const int hostID);
	NetworkHost*				_FindHost(const int hostID);
	
	static unsigned int WINAPI	_ExecuteThread(void* arg);

private:
	BlockingQueue<IOContext*>				mContextQueue;

	// u_map<hostID, NetworkHost*>
	std::unordered_map<int, NetworkHost*>	mHostMap;
	HANDLE									mHandle;

	std::mutex								mRecvLock;
	std::unordered_map<int, bool>			mRecvCheckMap;

	std::mutex								mHostIDLock;
};