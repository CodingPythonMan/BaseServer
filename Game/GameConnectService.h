#pragma once
#include "Service.h"
#include "RefSingleton.h"
#include "ServerInfo.h"

class GameConnectService : public RefSingleton<GameConnectService>, public Service
{
public:
	GameConnectService() = default;
	virtual ~GameConnectService() = default;

	// ���⼭ DB ������ �� �ְԲ� �۾��� �ؾ��Ѵ�.
	// �����尣 ����� ��° ġ����, DB �� ������ �����Ͽ� �����ؾ��Ѵ�.
	bool				Initialize();
	bool				Start();

private:
	void				_TryListen();

private:
	bool				mIsStarted = false;
	ServerInfo			mServerInfo;
};