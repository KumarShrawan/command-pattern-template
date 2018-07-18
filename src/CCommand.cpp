/*
 * CCommand.h
 *
 *  
 */
 
#include "CCommand.h"
#include <iostream>
using namespace SvcIpc;
using namespace std;

CCmd::FireWallLoad::FireWallLoad()
{

}

void CCmd::FireWallLoad::execute()
{
	cout << __FUNCTION__<< endl;
	
}


