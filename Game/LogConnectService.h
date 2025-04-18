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

	// ���⼭ DB ������ �� �ְԲ� �۾��� �ؾ��Ѵ�.
	// �����尣 ����� ��° ġ����, DB �� ������ �����Ͽ� �����ؾ��Ѵ�.
	bool				Initialize();
	bool				Start();

private:
	void				_TryConnect();

private:
	bool				mIsStarted = false;

	LogConnectEvent		mEvent;
	ServerConnectInfo*	mServerConnectInfo = nullptr;
};