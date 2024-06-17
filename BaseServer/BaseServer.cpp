#include "BaseServer.h"
#include "ConfigParser.h"

BaseServer::BaseServer()
{
	ConfigParser::CreateInstance();
	
}

BaseServer::~BaseServer()
{
}

bool BaseServer::Initialize()
{
	ConfigParser::GetInstance()->LoadConfig(L"GameConfig.json");

	return true;
}

bool BaseServer::Run()
{
	return false;
}