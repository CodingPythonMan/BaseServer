#include "MiniDump.h"
#include "BaseServer.h"

int main()
{
    MiniDump::InitExceptionHandler();

    BaseServer server;
    
    if (false == server.Initialize())
    {
        return -1;
    }
        
    if (false == server.Run())
    {
        return -2;
    }

    return 0;
}