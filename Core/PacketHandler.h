#pragma once
#include "Packet.h"
#include "BlockingQueue.h"

#define		ONCE_GET_PACKET_COUNT 200

class PacketHandler
{
public:
	void			Push(std::shared_ptr<Packet> packet);

protected:
	void			_ProcessPacket();
	bool			_HandlePacket(const Packet& packet);

	BlockingQueue<std::shared_ptr<Packet>>	mPacketQueue;
	std::deque<std::shared_ptr<Packet>>		mWorkingQueue;

	BlockingQueue<std::shared_ptr<Packet>>	mRecoverQueue;

	// map<messageID, function>
	std::map<int, std::function<bool(const Packet&)>>	mPacketHandler = {};

	template <typename DispatcherType, typename MessageType,
		typename = typename std::enable_if<std::is_base_of<PacketHandler, DispatcherType>::value>::type>
	void RegisterHandler(int msgID, bool (DispatcherType::* handler)(int, const MessageType&))
	{
		DispatcherType* derived = static_cast<DispatcherType*>(this);
		
		auto invoker = [derived, handler, this](const Packet& packet)
			{
				MessageType msg;
				if (false == packet.Deserialize(msg))
				{
					if (packet.mPayload.GetMessageLength() <= packet.mPayload.GetMaxMessageLength())
					{
						// 패킷에 담을 수 있는 양보다 엄청 담겼으니 Socket 에서 Close 필요?
					}

					return false;
				}

				return (derived->*handler)(packet.mHostID, msg);
			};

		mPacketHandler.insert({ msgID, invoker });
	}
};