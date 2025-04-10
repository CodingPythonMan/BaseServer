#include "InternalPacketHandler.h"
#include <WS2tcpip.h>
#include <windows.h>

void InternalPacketHandler::_ProcessInternalPacket()
{
	mWorkingQueue.clear();

	mPacketQueue.Get(mWorkingQueue, ONCE_GET_PACKET_COUNT);
	if (true == mWorkingQueue.empty())
	{
		::Sleep(1);
		return;
	}

	std::vector<int> messageList;
	messageList.reserve(ONCE_GET_PACKET_COUNT);
	//if (true == mWorkingQueue)
	//{

	//}
}