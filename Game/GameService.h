#pragma once
#include "Service.h"
#include "RefSingleton.h"
#include "Packet.h"

class GameService : public Service, public RefSingleton<GameService>
{
public:
	GameService();
	virtual ~GameService() = default;

	bool	Start();

private:
	void	_RegisterHandler();

public:
	bool	OnCSLog1Req(int hostID, const CSLog1Req& msg);

private:
	bool	mIsStart = false;
};