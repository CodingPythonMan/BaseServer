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
	// 임의로 메인스레드에서 패킷을 넘겨받고 있음.
	// hostID 는 0인 상태.
	

	return true;
}