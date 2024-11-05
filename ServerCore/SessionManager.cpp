#include "SessionManager.h"

bool SessionManager::ReadyForListen(const std::string& address, const int port)
{
	// ���� Ǯ���� ���� �ʰ�, Session �ϳ� ���� �ش� Session ���� ���� ��������.
	Session* session = new Session();
	if (session == nullptr)
	{
		printf("Create Failed - session");
		return false;
	}

	// �̰� ���� Event ���� ����صθ� ����� �� �ϴ�.
	// ���� ������ �ϴ��� �ľ� �Ϸ� �� �۾�
	//session->SetEventSync();
	session->SetIP(address);
	session->SetPort(port);



	return true;
}
