
#include "CCommandQueue.h"
using namespace SvcIpc;
class CCSMCore
{
public:
	CCSMCore();
   ~CCSMCore();
	bool run();
private:
    SvcIpc::CCommandQueue commandQueue;
	
};
