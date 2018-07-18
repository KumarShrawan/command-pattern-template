#include "CCSMCore.h"

CCSMCore::CCSMCore() 
{

}

CCSMCore::~CCSMCore()
{

}
bool CCSMCore::run()
{
	ICommand *command = commandQueue.get();

    if( !command )
        return true;

    command->execute();

    delete command;
    return 0;
}

