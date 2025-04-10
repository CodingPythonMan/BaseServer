#include "Packet.h"

void Packet::Reset()
{
	mHostID = 0;
	mMsgID = 0;
	mMsgLen = 0;

	mPayload.SetMessageLength(0);
}

bool Packet::Serialize(int inMsgID, size_t inMsgLen, const uint8_t* inMsgBytes)
{
	size_t maxMsgLen = mPayload.GetMaxMessageLength();
	if (maxMsgLen < inMsgLen)
	{
		return false;
	}

	mMsgID = inMsgID;
	mMsgLen = (int)inMsgLen;
	mPayload.SetMessageLength(inMsgLen);
	mPayload.SetMessageID(inMsgID);
	if (0 < inMsgLen)
	{
		uint8_t* payloadMsgBytes = mPayload.GetMessageBytes();
		memcpy(payloadMsgBytes, inMsgBytes, inMsgLen);
	}
	return true;
}

bool Packet::Serialize(int inMsgID, const google::protobuf::MessageLite& inMsg, char* compBuffer, size_t bufferSize)
{
	size_t inMsgLen = inMsg.ByteSizeLong();
	size_t maxMsgLen = mPayload.GetMaxMessageLength();
	if (maxMsgLen < inMsgLen)
	{
		return false;
	}

	mMsgID = inMsgID;
	mMsgLen = (int)inMsgLen;
	mPayload.SetMessageLength(inMsgLen);
	mPayload.SetMessageID(inMsgID);

	uint8_t* payloadMsgBytes = mPayload.GetMessageBytes();

	return inMsg.SerializeToArray(payloadMsgBytes, (int)inMsgLen);
}

bool Packet::Serialize(const PacketPayload& inPayload)
{
	int inMsgId = inPayload.GetMessageID();
	size_t inMsgLen = inPayload.GetMessageLength();

	size_t maxMsgLen = mPayload.GetMaxMessageLength();
	if (maxMsgLen < inMsgLen)
	{
		return false;
	}

	mMsgID = inMsgId;
	mMsgLen = (int)inMsgLen;
	mPayload.SetMessageLength(inMsgLen);
	mPayload.SetMessageID(inMsgId);
	if (0 < inMsgLen)
	{
		const uint8_t* inMsgBytes = inPayload.GetMessageBytes();
		uint8_t* payloadMsgBytes = mPayload.GetMessageBytes();
		memcpy(payloadMsgBytes, inMsgBytes, inMsgLen);
	}
	return true;
}

bool Packet::Deserialize(google::protobuf::MessageLite& outMsg, char* compBuffer, size_t bufferSize) const
{
	size_t payloadMsgLen = mPayload.GetMessageLength();
	size_t maxMsgLen = mPayload.GetMaxMessageLength();
	if (maxMsgLen < payloadMsgLen)
	{
		return false;
	}

	const uint8_t* payloadMsgBytes = mPayload.GetMessageBytes();

	return outMsg.ParseFromArray(payloadMsgBytes, (int)payloadMsgLen);
}

int Packet::GetMessageID() const
{
	return mMsgID;
}

const std::string& Packet::GetMessageName() const
{
	static std::string empty;
	return empty;
}

size_t Packet::GetMessageLength() const
{
	return mMsgLen;
}

size_t Packet::GetPayloadLength() const
{
	return mPayload.GetPayloadLength();
}

const uint8_t* Packet::GetMessageBytes() const
{
	return mPayload.GetMessageBytes();
}

const uint8_t* Packet::GetPayloadBytes() const
{
	return reinterpret_cast<const uint8_t*>(&mPayload);
}

uint8_t* Packet::GetMessageBytes()
{
	return mPayload.GetMessageBytes();
}

uint8_t* Packet::GetPayloadBytes()
{
	return reinterpret_cast<uint8_t*>(&mPayload);
}