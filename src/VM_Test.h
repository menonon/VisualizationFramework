

#ifndef __VM_TEST_H
#define __VM_TEST_H

#include "VisualizeMethods.h"


class VM_Test:public VisualizeMethods{

 public:
  VM_Test();
  VM_Test(UserInterfaces* _ui, Data* _data);
  ~VM_Test();

  void draw();
  void init();
  void contextInit();
  void preFrame();
  void intraFrame();
  void postFrame();


 private:
  std::vector<double> vertex;
  std::vector<double> color;


};
#endif
