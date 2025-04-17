#include "NetworkHandler.h"
#include "IOContext.h"
#include "TimeUtil.h"
#include "NetworkHost.h"

bool NetworkHandler::CreateThread()
{
	HANDLE handle = reinterpret_cast<HANDLE>(::_beginthreadex(nullptr, 0, _ExecuteThread, this, 0, nullptr));
	if (handle == nullptr || handle == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	mHandle = handle;

	return true;
}

bool NetworkHandler::PushThread(IOContext* context)
{
	if (context == nullptr)
	{
		return false;
	}

	mContextQueue.Push(context);

	return true;
}

void NetworkHandler::_ProcessThread()
{
	while (true)
	{
		Update();

		std::unordered_map<int, bool> mapList;
		{
			std::lock_guard<std::mutex> guard(mRecvLock);
			mapList.swap(mRecvCheckMap);
		}

		for (const auto& [hostID, check] : mapList)
		{
			auto host = _FindHost(hostID);

		}

		auto context = mContextQueue.Pop();
		if (context == nullptr)
		{
			::Sleep(1);
			continue;
		}

		switch (context->GetType())
		{
		case EContextType::CONNECT:
			_ProcessConnect(*context);
			break;
		case EContextType::LISTEN:
			_ProcessListen(*context);
			break;
		case EContextType::JOIN:
			_ProcessJoin(*context);
			break;
		case EContextType::DISCONNECT:
			_ProcessDisconnect(*context);
			break;
		default:
			printf("failed! -GetType:%d", context->GetType());
			break;
		}

		delete context;
	}
}

void NetworkHandler::UpdateHost()
{
	int64_t tick = TimeUtil::GetTick64();

	// IsAlive 가 패킷을 몇 초 이내로 주고 받았는지 체크해야 한다.
	auto iter = mHostMap.begin();
	while (iter != mHostMap.end())
	{
		auto host = iter->second;
		if (nullptr != host)
		{
			if (true == host->IsAlive())
			{
				host->Update(tick);
				iter++;
				continue;
			}

			host->OnDisconnect();
			delete host;
		}

		_RemoveHost(iter->first);

		iter = mHostMap.erase(iter);
	}
}

void NetworkHandler::_RemoveHost(const int hostID)
{

}

NetworkHost* NetworkHandler::_FindHost(const int hostID)
{
	std::lock_guard<std::mutex> lock(mHostIDLock);

	auto iter = mHostMap.find(hostID);
	if (iter == mHostMap.end())
	{
		return nullptr;
	}

	return iter->second;
}

unsigned int __stdcall NetworkHandler::_ExecuteThread(void* arg)
{
	auto& handler = *static_cast<NetworkHandler*>(arg);
	handler._ProcessThread();
	return 0;
}
