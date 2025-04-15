#pragma once
#include <WS2tcpip.h>
#include <windows.h>

#include <string>

#include "RefSingleton.h"
#include "Language.h"
#include "ServerInfo.h"

class ConfigParser : public RefSingleton<ConfigParser>
{
public:
	bool					LoadConfig(const std::wstring& configFile);

	const ServerInfo&		GetServerInfo() const;
	const ConnectInfo&		GetConnectInfo() const;
	const Language			GetLanguage() const;

private:
	bool					LoadJson(const std::wstring& configFile, size_t fileSize);
	void					LoadCPUInfo();

private:
	std::wstring			mFileName;

	// Parser ตฅภฬลอ
	ServerInfo				mServerInfo;
	ConnectInfo				mConnectInfo;
	Language				mLanguage;

	// CPU Count
	int						mProcessorCount = 0;
};