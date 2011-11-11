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

  virtual  void draw();
  virtual  void init();
  virtual  void contextInit();
  virtual  void preFrame();
  virtual  void intraFrame();
  virtual  void postFrame();
  

  
private:
  std::string name;

  UserInterfaces* ui;

  
};

#endif
