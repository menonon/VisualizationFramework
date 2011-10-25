/**
* VisualizeMethod
* @author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
* @version developping
*/

#ifndef __VisualizeMethods_h
#define __VisualizeMethods_h

#include <string>
#include "UserInterfaces.h"

class VisualizeMethods{
  
public:
  VisualizeMethods(UserInterfaces* ui);
  ~VisualizeMethods();
  void draw();
  void init();
  void contextInit();
  void preFrame();
  void intraFrame();
  void postFrame();
  

  
private:
  std::string name;
  

  
};

#endif
