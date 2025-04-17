#pragma once
#include <vector>
#include "NetworkHost.h"

class IocpWorker
{
public:
	bool		CreateThread();


private:
	static unsigned int WINAPI _ExecuteThread(void* arg);

	void				_ProcessThread();

	void				_ProcessConnect(NetworkHost& host, IOContext& context, bool result);
	void				_ProcessAccept(NetworkHost& host, IOContext& context, bool result);
	void				_ProcessReceive(NetworkHost& host, IOContext& context, bool result, int transferred);
	void				_ProcessSend(NetworkHost& host, IOContext& context, bool result, int transferred);

private:
	HANDLE				mIocp;
	std::vector<HANDLE>	mHandles;
};