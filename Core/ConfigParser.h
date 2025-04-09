#pragma once
#include <WS2tcpip.h>
#include <windows.h>

#include <string>

#include "RefSingleton.h"
#include "Language.h"

struct ServerInfo 
{
	std::string		Name;
	int				ServerID;
	std::string		BindAddress;
	int				BindPort;
	bool			Nagle;
	int				MaxConnection;
};

class ConfigParser : public RefSingleton<ConfigParser>
{
public:
	bool					LoadConfig(const std::wstring& configFile);

	const ServerInfo&		GetServerInfo() const;
	const Language			GetLanguage() const;

private:
	bool					LoadJson(const std::wstring& configFile, size_t fileSize);
	void					LoadCPUInfo();

private:
	std::wstring			m_fileName;

	// Parser ตฅภฬลอ
	ServerInfo				m_serverInfo;
	Language				m_language;

	// CPU Count
	int						m_processorCount;
};