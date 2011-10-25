
/**
 *Amaterasu.h
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 *@version developping
*/


#ifndef __Amaterasu_h
#define __Amaterasu_h


#include <vrj/vrjConfig.h>
#include <vrj/Draw/OpenGL/App.h>
#include <gadget/Type/PositionInterface.h>
#include <gadget/Type/DigitalInterface.h>


class Amaterasu : public vrj::opengl::App{

 public:
  Amaterasu(string path);

 private:
  UserInterfaces ui;

};

#endif
