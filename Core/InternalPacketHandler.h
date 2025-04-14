#pragma once
#include "BlockingQueue.h"
#include "InternalPacket.h"
#include <map>
#include <functional>

#define		ONCE_GET_PACKET_COUNT 200

class InternalPacketHandler
{
public:
	void			PushInternal(std::shared_ptr<InternalPacket> packet);

protected:
	void			_ProcessInternalPacket();
	bool			_DispatchInternalPacket(std::shared_ptr<InternalPacket> packet);


	BlockingQueue<std::shared_ptr<InternalPacket>>	mInternalPacketQueue;
	std::deque<std::shared_ptr<InternalPacket>>		mInternalWorkingQueue;

	BlockingQueue<std::shared_ptr<InternalPacket>>	mInternalRecoverQueue;

	// map<messageID, function>
	std::map<int, std::function<bool(std::shared_ptr<InternalPacket>)>>	mInternalPacketHandler = {};

	template <typename DispatcherType,
		typename = typename std::enable_if<std::is_base_of<InternalPacketHandler, DispatcherType>::value>::type>
	void RegisterInternalHandler(int id, bool (DispatcherType::* handler)(std::shared_ptr<InternalPacket>))
	{
		DispatcherType* derived = static_cast<DispatcherType*>(this);
		auto invoker = [derived, handler](std::shared_ptr<InternalPacket> packet)
			{
				return (derived->*handler)(packet);
			};

		mInternalPacketHandler.insert({ id, invoker });
	}
};