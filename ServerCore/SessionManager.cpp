#include "SessionManager.h"

bool SessionManager::ReadyForListen(const std::string& address, const int port)
{
	// 굳이 풀까지 쓰지 않고, Session 하나 만들어서 해당 Session 에서 일을 도모하자.
	Session* session = new Session();
	if (session == nullptr)
	{
		printf("Create Failed - session");
		return false;
	}

	// 이게 무슨 Event 인지 기술해두면 깔끔할 듯 하다.
	// 무슨 역할을 하는지 파악 완료 후 작업
	//session->SetEventSync();
	session->SetIP(address);
	session->SetPort(port);



	return true;
}
