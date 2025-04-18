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
	// ������ ���� �α׿��� �ǵ����ִ� ���� �ƴϱ� ������ ���� ����
	LogServerEvent		mEvent;
};