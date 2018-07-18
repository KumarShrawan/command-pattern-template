#include <iostream>
#include <memory>

#include "CCSMCore.h"

using namespace std;
//using namespace Hello;

int main(int argc, char *argv[]) {
  
  std::shared_ptr<CCSMCore> core(new CCSMCore);

  
  while(1)
  {
	core->run();
  }  
}
