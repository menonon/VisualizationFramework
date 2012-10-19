
/**
 *Amaterasu.h
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 *@version developping
*/


#ifndef __Amaterasu_h
#define __Amaterasu_h


#include <string>
#include <vector>
#include <vrj/vrjConfig.h>
#include <vrj/Draw/OpenGL/App.h>

#include "UserInterfaces.h"
#include "Config.h"
#include "Data.h"
#include "VisualizeMethods.h"
#include "Menu.h"
#include "Coordinates.h"

class Amaterasu : public vrj::opengl::App{

 public:
  Amaterasu(std::string path);
  ~Amaterasu();

  virtual void draw();
  virtual void init();
  virtual void preFrame();
  virtual void intraFrame();
  virtual void postFrame();
  virtual void contextInit();
  virtual void bufferPreDraw();
  virtual void contextPreDraw();

 private:
  UserInterfaces* ui;
  Menu* menu;
  Coordinates* coord;

  std::string configPath;
  std::vector<Config*> conf_arr;
  std::vector<Data*> data_arr;
  std::vector<VisualizeMethods*> vm_arr;
  

  void parseConfigFile();
};

#endif
