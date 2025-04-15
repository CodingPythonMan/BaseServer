#include "ServerConnectInfo.h"

bool ServerConnectInfo::IsConnected() const
{
	return mState == EServerConnectState::Connected;
}

bool ServerConnectInfo::IsConnecting()
{
	auto IsConnecting = false;
	if (mState == EServerConnectState::Connecting)
	{
		IsConnecting = true;
	}

	if (true == IsConnecting)
	{
		if (true == mChecker.IsActivated())
		{
			IsConnecting = false;
		}
		else if (false == mChecker.IsAvailable())
		{
			mState = EServerConnectState::Disconnect;
			IsConnecting = false;
		}
	}

	return IsConnecting;
}

void ServerConnectInfo::SetState(EServerConnectState state)
{
	mState = state;
	if (state == EServerConnectState::Connecting)
	{
		mChecker.SetDelayTick(10000);	// 10�� ��ٷ���
	}
	else if (state == EServerConnectState::Connected)
	{
		mChecker.Check();	// ���� �Ϸ�
	}
}