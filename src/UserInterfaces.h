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
  void init();
  void preFrame();

  gmtl::Matrix44f wand;
  gmtl::Matrix44f head;

  

 private:
  gadget::PositionInterface gWand;
  gadget::PositionInterface gHead;
  
  gadget::DigitalInterface gButton0;
  gadget::DigitalInterface gButton1;

  gadget::AnalogInterface gJoyStick0X;
  gadget::AnalogInterface gJoyStick0Y;

  


};
