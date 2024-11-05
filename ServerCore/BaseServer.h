#pragma once
// ServerCore �� ���� �˸��� ���� �ȴ�.
#include "ControllService.h"
#include "WorkService.h"
#include "Singleton.h"
#include "ConfigParser.h"
#include "NetworkEvent.h"

class BaseServer
{
public:
	BaseServer();
	virtual ~BaseServer();

	bool					Start();
	void					BindEventSync(std::shared_ptr<NetworkEvent> eventSync);

private:
	// Has - a ����� NetworkController �� NetworkWorker �� ���� �Ѵ�.
	// �ֱ� �����ǵ� m_ �̷��� ��� �Լ� ���� �� ���� ���п� ������ �ִ� �� �ϴ�.
	ControllService*			m_controllService;
	WorkService*				m_workService;

	bool						m_running;

	std::shared_ptr<NetworkEvent>	m_networkEvent;
};