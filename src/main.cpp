/**
* main.cpp
* @author MENO Daisuke (menonon@vislab.cs.kobe-u.ac.jp)
* @version developping
*/

#include <cstdlib>
#include <string>
#include <vrj/Kernel/Kernel.h>


int main(int argc, char* argv){

  Kernel* kernel = Kernel::instance();

  /**
     argument of config file for app.
  */
  std::string ConfigFilePath = argv[argc];  
  App* app = new App(ConfigFilePath);
  argc--;

  kernel->init(argc, argv);
  for(int i=1;i<argc;1++){
    kernel->loadConfigFile(argv[i]);
  }

  kernel->start();
  kernel->setApplication(app);
  kernel->waitForKernelStop();

  delete app;
  return EXIT_SUCCESS


}
