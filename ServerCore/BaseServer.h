#pragma once
// ServerCore 에 들어가야 알맞은 값이 된다.
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
	// Has - a 관계로 NetworkController 와 NetworkWorker 를 갖게 한다.
	// 최근 느낀건데 m_ 이렇게 멤버 함수 적는 게 변수 구분에 도움을 주는 듯 하다.
	ControllService*			m_controllService;
	WorkService*				m_workService;

	bool						m_running;

	std::shared_ptr<NetworkEvent>	m_networkEvent;
};