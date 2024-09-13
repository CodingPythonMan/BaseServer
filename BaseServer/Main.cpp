#include "MiniDump.h"
#include "ElasticServer.h"

int main()
{
    MiniDump::InitExceptionHandler();

    ElasticServer server;
    
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