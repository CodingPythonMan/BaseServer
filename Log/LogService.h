#pragma once
#include "LogConnectEvent.h"
#include "RefSingleton.h"
#include <unordered_map>
#include "Service.h"

#define CONNECT_CHECK_TICK 5000

class ServerConnectInfo;

class LogService : public RefSingleton<LogService>, public Service
{
public:
	bool				Initialize();
	bool				Start();

private:
	void				_TryConnect();

private:
	// 있지만 굳이 로그에서 되돌려주는 값은 아니기 때문에 쓰진 않음
	LogConnectEvent		mEvent;

	// u_map<ServerID, ServerConnectInfo>
	std::unordered_map<int, ServerConnectInfo*> mConnectInfoList;
};