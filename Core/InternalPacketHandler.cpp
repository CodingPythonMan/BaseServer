#include "InternalPacketHandler.h"
#include <WS2tcpip.h>
#include <windows.h>

void InternalPacketHandler::PushInternal(std::shared_ptr<InternalPacket> packet)
{
	if (nullptr == packet.get())
	{
		return;
	}

	mInternalPacketQueue.Push(packet);
}

void InternalPacketHandler::_ProcessInternalPacket()
{
	mInternalWorkingQueue.clear();

	mInternalPacketQueue.Get(mInternalWorkingQueue, ONCE_GET_PACKET_COUNT);
	if (true == mInternalWorkingQueue.empty())
	{
		::Sleep(1);
		return;
	}

	std::vector<int> messageList;
	messageList.reserve(ONCE_GET_PACKET_COUNT);
	for (auto& packet : mInternalWorkingQueue)
	{
		if (false == _DispatchInternalPacket(packet))
		{
			printf("Wrong Dispatch!\n");
		}
	}
}

bool InternalPacketHandler::_DispatchInternalPacket(std::shared_ptr<InternalPacket> packet)
{
	int msgID = packet->mMsgID;

	auto iter = mInternalPacketHandler.find(msgID);
	if (iter == mInternalPacketHandler.end())
	{
		return false;
	}

	return iter->second(packet);
}