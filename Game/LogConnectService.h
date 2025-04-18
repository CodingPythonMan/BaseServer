#pragma once
#include "Service.h"
#include "RefSingleton.h"
#include "ServerConnectInfo.h"
#include "LogConnectEvent.h"

#define CHECK_RECONNECT_TICK 5000

class LogConnectService : public RefSingleton<LogConnectService>, public Service
{
public:
	LogConnectService() = default;
	virtual ~LogConnectService() = default;

	// 여기서 DB 저장할 수 있게끔 작업을 해야한다.
	// 스레드간 통신은 둘째 치더라도, DB 에 빠르게 접근하여 저장해야한다.
	bool				Initialize();
	bool				Start();

private:
	void				_TryConnect();

private:
	bool				mIsStarted = false;

	LogConnectEvent		mEvent;
	ServerConnectInfo*	mServerConnectInfo = nullptr;
};