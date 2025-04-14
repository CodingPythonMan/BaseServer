#include "GameService.h"
#include "Protocol.pb.h"

GameService::GameService()
{
	_RegisterHandler();
}

bool GameService::Start()
{
	mIsStart = CreateThread();

	return true;
}

void GameService::_RegisterHandler()
{
	RegisterHandler(CS_Log1Req, &GameService::OnCSLog1Req);
}

bool GameService::OnCSLog1Req(int hostID, const CSLog1Req& msg)
{
	// ���Ƿ� ���ν����忡�� ��Ŷ�� �Ѱܹް� ����.
	// hostID �� 0�� ����.
	

	return true;
}