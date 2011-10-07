/**
 *App.h
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 *@version developping
*/


#include <vrj/vrjConfig.h>
#include <vrj/Draw/OpenGL/App.h>
#include <gadget/Type/PositionInterface.h>
#include <gadget/Type/DigitalInterface.h>


class App : public opengl::App{

 public:
  gadget::PositionInterface Wand;
  gadget::PositionInterface Head;
  gadget::DigitalInterface Button0;
  gadget::DigitalInterface Button1;

};

