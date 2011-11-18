/**
* VisualizeMethod
* @author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
* @version developping
*/

#ifndef __VisualizeMethods_h
#define __VisualizeMethods_h

#include <string>
#include "UserInterfaces.h"
#include "Data.h"

class VisualizeMethods{
  
public:
  VisualizeMethods();
  VisualizeMethods(UserInterfaces* _ui, Data* _data);
  virtual ~VisualizeMethods();

  virtual  void draw();
  virtual  void init();
  virtual  void contextInit();
  virtual  void contextPreDraw();
  virtual  void preFrame();
  virtual  void intraFrame();
  virtual  void postFrame();
  

  std::string name;

  UserInterfaces* ui;
  Data* data;
  
};

#endif
