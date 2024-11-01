#include "ConfigParser.h"
#include "json.h"

#include <system_error>
#include <filesystem>
#include <fstream>
#include <string>

namespace fsys = std::filesystem;

bool ConfigParser::LoadConfig(const std::wstring& configFile)
{
	if (true == configFile.empty())
		return false;

	std::error_code ec;
	auto currentDir = fsys::current_path(ec);

	// 0 �� �ƴϸ� ������ ��
	if (ec.value() != 0)
		return false;

	std::wstring wstrPath(currentDir.c_str() + std::wstring(L"\\") + configFile);

	fsys::path filePath = fsys::path(wstrPath);
	if (false == fsys::exists(filePath, ec))
		return false;

	if (false == fsys::is_regular_file(filePath, ec))
		return false;

	auto fileSize = fsys::file_size(filePath, ec);
	if (ec.value() != 0)
		return false;

	m_fileName = configFile;

	bool jsonSuccess = LoadJson(wstrPath.c_str(), fileSize);
	LoadCPUInfo();

	return jsonSuccess;
}

const ServerInfo& ConfigParser::GetServerInfo() const
{
	return m_serverInfo;
}

const Language ConfigParser::GetLanguage() const
{
	return m_language;
}

bool ConfigParser::LoadJson(const std::wstring& configFile, size_t fileSize)
{
	if (true == configFile.empty())
		return false;

	if (fileSize == 0 || fileSize == (uintmax_t)~0)
		return false;

	std::ifstream is(configFile);
	if (false == is.is_open())
		return false;

	std::string strBuffer;
	strBuffer.reserve(fileSize);

	std::string strLine;
	while (getline(is, strLine))
		strBuffer.append(strLine);

	is.close();

	// Reader �� �����ϸ� ������ ��Ŀ ������ ����.
	// ��Ŀ ������ ���� ����� �����ϱ�?

	// �˾Ƴ´�. ������ json cpp ������ ���Խ��� ���ƾ� �Ѵ�.
	Json::Reader reader;
	Json::Value root;

	if (false == reader.parse(strBuffer.c_str(), root))
		return false;

	{
		const auto& info = root["Server"];
		if (true == info.isNull())
			return false;

		m_serverInfo.Name = info.get("Name", "Name").asString();
		m_serverInfo.ServerID = info.get("ServerID", "ServerID").asInt();
		m_serverInfo.BindAddress = info.get("BindAddress", "BindAddress").asString();
		m_serverInfo.BindPort = info.get("BindPort", "BindPort").asInt();
		m_serverInfo.Nagle = info.get("Nagle", "Nagle").asBool();
		m_serverInfo.MaxConnection = info.get("MaxConnection", "MaxConnection").asInt();
	}

	{
		const auto& lan = root["Language"];
		std::string strLan = lan.asString();
		if (strLan == "KR")
		{
			m_language = Language::KR;
		}
		else if (strLan == "EN")
		{
			m_language = Language::EN;
		}
	}

	return true;
}

void ConfigParser::LoadCPUInfo()
{
	SYSTEM_INFO info;
	// ���� ��ǻ�� �ý��ۿ� ���� ������ �����Ѵ�.
	GetSystemInfo(&info);

	// ������ �ش� �Լ��� �̿��ؼ� 32bit �� 64bit ���� �ٷ� �� �־���.
	// �̹���, ���μ��� �� ������ ���Ѵ�.
	m_processorCount = (int)info.dwNumberOfProcessors;

	// 0�� ���Ϸ� �α⿣ ������.
	if (m_processorCount <= 0)
	{
		m_processorCount = 1;
	}
}
