#pragma once
#include "TickRunner.h"
#include "BlockingQueue.h"

class NetworkHost;
class IOContext;

class NetworkHandler : public TickRunner
{
public:
	NetworkHandler() = default;
	virtual ~NetworkHandler() = default;

	bool		PushThread(IOContext* context);

	void		UpdateHost();

private:
	void		_RemoveHost(const int hostID);

private:
	BlockingQueue<IOContext*>				mContextQueue;

	// u_map<hostID, NetworkHost*>
	std::unordered_map<int, NetworkHost*>	mHostMap;
};