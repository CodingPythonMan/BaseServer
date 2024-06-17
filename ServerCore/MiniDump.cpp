#include "MiniDump.h"
#include <windows.h>
#include <filesystem>
#include <minidumpapiset.h>
#include <BugTrap.h>

#pragma comment(lib, "BugTrapU-x64.lib")

void MiniDump::InitExceptionHandler(bool autoRestart)
{
	// 현재 실행파일 이름
	WCHAR appName[MAX_PATH] = {};
	GetModuleFileNameW(nullptr, appName, MAX_PATH);

	std::filesystem::path fullPath(appName);

	DWORD dumpType = MiniDumpWithFullMemory // 모든 읽을 수 있는 프로세스 내 페이지를 덤프에 포함
		| MiniDumpWithHandleData // 핸들 테이블에 있던 모든 핸들 데이터 포함
		| MiniDumpWithThreadInfo // 스레드 시작, 유연 주소 포함
		| MiniDumpWithProcessThreadData // TEB(Thread Environment Blocks), PEB 포함
		| MiniDumpWithFullMemoryInfo // 가상주소 정보 레이아웃
		| MiniDumpWithUnloadedModules // OS에서 지원되는 최근 빠진 모듈들
		| MiniDumpWithFullAuxiliaryState // 덤프 안 그들의 상태를 담은 Aux 데이터 
		| MiniDumpIgnoreInaccessibleMemory // 메모리 읽기 실패 제외
		| MiniDumpWithTokenInformation // 관계있는 보안 토큰 포함
		;

	// BugTrap 등록
	BT_InstallSehFilter(); 
	BT_SetAppName(fullPath.stem().c_str());

	// autoRestart 쓰기
	if (true == autoRestart)
		// 크래시 나자마자 재시작하는 옵션
		BT_SetFlags(BTF_DETAILEDMODE | BTF_RESTARTAPP);
	else
		BT_SetFlags(BTF_DETAILEDMODE);

	BT_SetActivityType(BTA_SAVEREPORT);
	BT_SetDumpType(dumpType);

	// Dump Path 등록
	std::wstring dumpPath = fullPath.parent_path().c_str();
	dumpPath.append(L".\\Dump\\");

	BT_SetReportFilePath(dumpPath.c_str());

	BT_SetReportFormat(BTRF_XML);
}