#pragma once
#include "SharedObject.h"
#include "PacketPayload.h"
#include "Protocol.pb.h"

#define	MakePacket(host, msgID, msg)				std::shared_ptr<Packet> packet = std::make_shared<Packet>();			\
													packet->mHostID = host;													\
													packet->Serialize(msgID, msg);

struct Packet : public SharedObject<Packet>
{
public:
	Packet() = default;
	virtual ~Packet() = default;

	void	Reset();

	bool	Serialize(int inMsgID, size_t inMsgLen, const uint8_t* inMsgBytes);
	bool	Serialize(int inMsgID, const google::protobuf::MessageLite& inMsg, char* compBuffer = nullptr, size_t bufferSize = 0);
	bool	Serialize(const PacketPayload& inPayload);
	bool	Deserialize(google::protobuf::MessageLite& outMsg, char* compBuffer = nullptr, size_t bufferSize = 0) const;

	int GetMessageID() const;
	const std::string& GetMessageName() const;

	size_t GetMessageLength() const;
	size_t GetPayloadLength() const;

	const uint8_t* GetMessageBytes() const;
	const uint8_t* GetPayloadBytes() const;

	uint8_t* GetMessageBytes();
	uint8_t* GetPayloadBytes();

	int		mHostID = 0;
	int		mMsgID = 0;
	int		mMsgLen = 0;

	PacketPayload mPayload;
};