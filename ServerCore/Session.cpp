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

	// Linger �ɼ��� Listen socket ���� ��ӹޱ� ������ ���� ���� �ɼ� �� ä���൵ �ȴ�.
	// ���߿� �־�� ���ɿ� ���� ������ ����.

	closesocket(m_socket);
	// ���⼭�� �ٽñ� �ʱ�ȭ ��ų �ʿ� ����.

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
