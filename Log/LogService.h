#pragma once
#include "LogServerEvent.h"
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
	// 있지만 굳이 로그에서 되돌려주는 값은 아니기 때문에 쓰진 않음
	LogServerEvent		mEvent;
};