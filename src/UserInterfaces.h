/**
* UserInterface
* @author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
* @version developping
*/

#ifndef __UserInterface_h
#define __UserInterface_h


#include <gadget/Type/PositionInterface.h>
#include <gadget/Type/AnalogInterface.h>
#include <gadget/Type/DigitalInterface.h>


class UserInterface{
  
 public:


 private:
  gadget::PositionInterface Wand;
  gadget::PositionInterface Head;
  
  gadget::DigitalInterface Button0;
  gadget::DigitalInterface Button1;

  //  gadget::AnalogInterface JoyStick0X;
  //  gadget::AnalogInterface JoyStick0Y;
};
