#include "PacketHandler.h"

void PacketHandler::Push(std::shared_ptr<Packet> packet)
{
	if (nullptr == packet.get())
	{
		return;
	}

	mPacketQueue.Push(packet);
}

void PacketHandler::_ProcessPacket()
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
	for (auto packet : mWorkingQueue)
	{
		if (false == _HandlePacket(*packet))
		{
			printf("Wrong Dispatch!\n");
		}
	}
}

bool PacketHandler::_HandlePacket(const Packet& packet)
{
	int msgID = packet.GetMessageID();

	auto iter = mPacketHandler.find(msgID);
	if (iter == mPacketHandler.end())
	{
		return false;
	}

	return iter->second(packet);
}