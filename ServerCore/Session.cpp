#include "Session.h"
#include <iostream>

Session::Session()
{
	m_isRecv = false;
	m_sessionID = 0;
	m_socket = INVALID_SOCKET;
	m_ip = "";
	m_port = 0;
}

Session::~Session()
{
}

bool Session::Close(ESocketClose closeType)
{
	if (m_socket == INVALID_SOCKET)
	{
		return false;
	}

	// Linger 옵션은 Listen socket 에서 상속받기 때문에 굳이 링거 옵션 안 채워줘도 된다.
	// 나중에 넣어보고 성능에 영향 가는지 보자.

	closesocket(m_socket);
	// 여기서도 다시금 초기화 시킬 필요 없다.

	if (ESocketClose::FailInit == closeType)
	{
		printf("Session(%d) Socket Close : %d [%s:%d] \n", m_sessionID, closeType, m_ip.c_str(), m_port);
	}
	else
	{
		printf("[Error] Session(%d) Socket Close : %d [%s:%d] \n", m_sessionID, closeType, m_ip.c_str(), m_port);
	}

	return true;
}
