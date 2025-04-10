#pragma once
#include "BlockingQueue.h"
#include "InternalPacket.h"
#include <map>
#include <functional>

#define		ONCE_GET_PACKET_COUNT 200

class InternalPacketHandler
{
protected:
	void			_ProcessInternalPacket();


	BlockingQueue<std::shared_ptr<InternalPacket>>	mPacketQueue;
	std::deque<std::shared_ptr<InternalPacket>>		mWorkingQueue;

	BlockingQueue<std::shared_ptr<InternalPacket>>	mRecoverQueue;

	// map<messageID, function>
	std::map<int, std::function<bool(std::shared_ptr<InternalPacket>())>>	mPacketHandler = {};

	template <typename DispatcherType,
		typename = typename std::enable_if<std::is_base_of<InternalPacketHandler, DispatcherType>::value>::type>
	void RegisterInternalHandler(int id, bool (DispatcherType::* handler)(std::shared_ptr<InternalPacket>))
	{
		DispatcherType* derived = static_cast<DispatcherType*>(this);
		auto invoker = [derived, handler](std::shared_ptr<InternalPacket> packet)
			{
				return (derived->*handler)(packet);
			};

		mPacketHandler.insert({ id, invoker });
	}
};