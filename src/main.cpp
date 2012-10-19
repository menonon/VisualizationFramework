/**
* main.cpp
* @author MENO Daisuke (menonon@vislab.cs.kobe-u.ac.jp)
* @version developping
*/

#include <vlCore/OpenGLDefs.hpp>
#include <cstdlib>
#include <string>
#include <vrj/Kernel/Kernel.h>
#include "Amaterasu.h"
#include <iostream>


int main(int argc, char* argv[]){

  std::cout << __FILE__ << ":A" << std::endl;

  vrj::Kernel* kernel = vrj::Kernel::instance();

  /**
     argument of config file for app.
  */
  std::cout << __FILE__ << ":B" << std::endl;
  std::string ConfigFilePath(argv[argc-1]);  
  Amaterasu* app = new Amaterasu(ConfigFilePath);
  argc--;

  std::cout << __FILE__ << ":C" << std::endl;

  kernel->init(argc, argv);
  for(int i=1;i<argc;i++){
    kernel->loadConfigFile(argv[i]);
  }

  std::cout << __FILE__ << ":D" << std::endl;

  kernel->start();
  kernel->setApplication(app);
  kernel->waitForKernelStop();

  delete app;
  return EXIT_SUCCESS;
}
