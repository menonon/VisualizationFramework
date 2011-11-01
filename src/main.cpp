/**
* main.cpp
* @author MENO Daisuke (menonon@vislab.cs.kobe-u.ac.jp)
* @version developping
*/

#include <cstdlib>
#include <string>
#include <vrj/Kernel/Kernel.h>
#include "Amaterasu.h"

int main(int argc, char* argv[]){

  vrj::Kernel* kernel = vrj::Kernel::instance();

  /**
     argument of config file for app.
  */
  std::string ConfigFilePath(argv[argc-1]);  
  Amaterasu* app = new Amaterasu(ConfigFilePath);
  argc--;

  kernel->init(argc, argv);
  for(int i=1;i<argc;i++){
    kernel->loadConfigFile(argv[i]);
  }

  kernel->start();
  kernel->setApplication(app);
  kernel->waitForKernelStop();

  delete app;
  return EXIT_SUCCESS;
}
