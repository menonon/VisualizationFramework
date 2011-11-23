/**
* UserInterface
* @author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
* @version developping
*/

#ifndef __UserInterfaces_h
#define __UserInterfaces_h


#include <gadget/Type/PositionInterface.h>
#include <gadget/Type/AnalogInterface.h>
#include <gadget/Type/DigitalInterface.h>
#include <gmtl/Matrix.h>


class UserInterfaces{
  
 public:
  UserInterfaces();
  ~UserInterfaces();

  void init();
  void preFrame();
  void draw();

  gmtl::Matrix44f wand;
  gmtl::Matrix44f navWand;
  gmtl::Matrix44f head;
  float joyStick0X;
  float joyStick0Y;
  int button0;
  int button1;
  int button2;

  

 private:
  gadget::PositionInterface gWand;
  gadget::PositionInterface gHead;
  
  gadget::DigitalInterface gButton0;
  gadget::DigitalInterface gButton1;
  gadget::DigitalInterface gButton2;

  gadget::AnalogInterface gJoyStick0X;
  gadget::AnalogInterface gJoyStick0Y;

  gmtl::Matrix44f navMat;

};
#endif
