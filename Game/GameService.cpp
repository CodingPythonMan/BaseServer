#include "GameService.h"

GameService::GameService()
{
	_RegisterHandler();
}

bool GameService::Start()
{
	mIsStart = CreateThread();

	return false;
}

void GameService::_RegisterHandler()
{
	
}