#pragma once
// ServerCore �� ���� �˸��� ���� �ȴ�.
#include "ControllService.h"
#include "WorkService.h"
#include "Singleton.h"
#include "ConfigParser.h"

class BaseServer
{
public:
	BaseServer();
	virtual ~BaseServer();

	bool					Start();

private:
	// Has - a ����� NetworkController �� NetworkWorker �� ���� �Ѵ�.
	// �ֱ� �����ǵ� m_ �̷��� ��� �Լ� ���� �� ���� ���п� ������ �ִ� �� �ϴ�.
	ControllService*			m_controllService;
	WorkService*				m_workService;

	bool						m_running;
};