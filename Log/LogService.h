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
	// ������ ���� �α׿��� �ǵ����ִ� ���� �ƴϱ� ������ ���� ����
	LogConnectEvent		mEvent;

	// u_map<ServerID, ServerConnectInfo>
	std::unordered_map<int, ServerConnectInfo*> mConnectInfoList;
};