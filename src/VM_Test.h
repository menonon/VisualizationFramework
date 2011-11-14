

#ifndef __VM_TEST_H
#define __VM_TEST_H

#include "VisualizeMethods.h"


class VM_Test : public VisualizeMethods{

 public:
  VM_Test(UserInterfaces* ui, Data* data);
  ~VM_Test();

  void draw();
  void init();
  void contextInit();
  void preFrame();
  void intraFrame();
  void postFrame();


 private:
  


};
#endif
