/*
 * CCommand.h
 *
 *  
 */

#ifndef CCOMMAND_H_
#define CCOMMAND_H_

#include <string>

#include "CCommandQueue.h"
#include "IInterface.h"

class CCmd{
public:
	class FireWallLoad : implements SvcIpc::ICommand
	{
	public:
		FireWallLoad();
		void execute();
		
	};

	
};


#endif /* CCOMMAND_H_ */
