#pragma once
#include <windows.h>

#include <string>

#include "Singleton.h"
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

class ConfigParser : public Singleton<ConfigParser>
{
public:
	bool					LoadConfig(const std::wstring& configFile);

	const ServerInfo&		GetServerInfo() const;
	const Language			GetLanguage() const;

private:
	bool					LoadJson(const std::wstring& configFile, size_t fileSize);
	bool					LoadCPUInfo();

private:
	std::wstring			m_fileName;

	ServerInfo				m_serverInfo;
	Language				m_language;
};