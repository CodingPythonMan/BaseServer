#include "MiniDump.h"
#include "BaseServer.h"

int main()
{
    MiniDump::InitExceptionHandler();

    BaseServer server;
    server.Initialize();

}