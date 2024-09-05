#pragma once
// ServerCore �� ���� �˸��� ���� �ȴ�.
#include "NetworkService.h"
#include "ServerService.h"
#include "Singleton.h"

class Listener : public Singleton<Listener>
{
public:
	Listener();
	virtual ~Listener();

	bool					Start();


private:
	// Has - a ����� NetworkController �� NetworkWorker �� ���� �Ѵ�.
	// �ֱ� �����ǵ� m_ �̷��� ��� �Լ� ���� �� ���� ���п� ������ �ִ� �� �ϴ�.
	NetworkService*			m_networkService;
	ServerService*			m_serverService;
};