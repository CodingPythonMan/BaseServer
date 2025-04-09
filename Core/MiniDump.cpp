#include "MiniDump.h"
#include <WS2tcpip.h>
#include <windows.h>
#include <filesystem>
#include <minidumpapiset.h>
#include "BugTrap.h"

#define CATCH_UNHANDELED_EXCEPTION_V1

#pragma comment(lib, "BugTrapU-x64.lib")

bool	mIsLive = false;

void MiniDump::SetExceptionHandler(bool autoRestart)
{
	// ���� �������� �̸�
	WCHAR appName[MAX_PATH] = {};
	GetModuleFileNameW(nullptr, appName, MAX_PATH);

	std::filesystem::path fullPath(appName);

	DWORD dumpType = MiniDumpWithFullMemory // ��� ���� �� �ִ� ���μ��� �� �������� ������ ����
		| MiniDumpWithHandleData // �ڵ� ���̺� �ִ� ��� �ڵ� ������ ����
		| MiniDumpWithThreadInfo // ������ ����, ���� �ּ� ����
		| MiniDumpWithProcessThreadData // TEB(Thread Environment Blocks), PEB ����
		| MiniDumpWithFullMemoryInfo // �����ּ� ���� ���̾ƿ�
		| MiniDumpWithUnloadedModules // OS���� �����Ǵ� �ֱ� ���� ����
		| MiniDumpWithFullAuxiliaryState // ���� �� �׵��� ���¸� ���� Aux ������ 
		| MiniDumpIgnoreInaccessibleMemory // �޸� �б� ���� ����
		| MiniDumpWithTokenInformation // �����ִ� ���� ��ū ����
		;

	// BugTrap ���
	BT_InstallSehFilter();
	BT_SetAppName(fullPath.stem().c_str());

	// autoRestart ����
	if (true == autoRestart)
		// ũ���� ���ڸ��� ������ϴ� �ɼ�
		BT_SetFlags(BTF_DETAILEDMODE | BTF_RESTARTAPP);
	else
		BT_SetFlags(BTF_DETAILEDMODE);

	BT_SetActivityType(BTA_SAVEREPORT);
	BT_SetDumpType(dumpType);

	// Dump Path ���
	std::wstring dumpPath = fullPath.parent_path().c_str();
	dumpPath.append(L".\\Dump\\");

	BT_SetReportFilePath(dumpPath.c_str());

	BT_SetReportFormat(BTRF_XML);
}

void MiniDump::SetDestroyMode(bool onoff)
{
	mIsLive = onoff;
}
