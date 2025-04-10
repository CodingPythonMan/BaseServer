#pragma once
#include "Service.h"
#include "RefSingleton.h"

class GameService : public Service, public RefSingleton<GameService>
{
public:
	GameService();
	virtual ~GameService() = default;

	bool	Start();

private:
	void	_RegisterHandler();

private:
	bool	mIsStart = false;
};