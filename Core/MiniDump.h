#pragma once
class MiniDump
{
public:
	static void SetExceptionHandler(bool autoRestart = false);
	static void SetDestroyMode(bool onoff);	
};