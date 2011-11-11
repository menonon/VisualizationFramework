

#ifndef __VM_TEST_H
#define __VM_TEST_H

#include "VisualizeMethods.h"

class VM_Test : public VisualizeMethods{

  void draw();
  void init();
  void contextInit();
  void preFrame();
  void intraFrame();
  void postFrame();


};
#endif
