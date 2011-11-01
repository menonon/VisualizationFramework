#include "UserInterfaces.h"
#include <ostream>

UserInterfaces::UserInterfaces(){
  std::cout << __FILE__ << std::endl;
}


void UserInterfaces::init(){

  gWand.init("VJWand");
  gHead.init("VJHead");

  gButton0.init("VJButton0");
  gButton1.init("VJButton1");

  gJoyStick0X.init("VJAnalog0");
  gJoyStick0Y.init("VJAnalog1");

  
}


void UserInterfaces::preFrame(){
  wand = gWand->getData();
  head = gHead->getData();
  
  button0 = gButton0->getData();
  button1 = gButton1->getData();

  joyStick0X = gJoyStick0X->getData();
  joyStick0Y = gJoyStick0Y->getData();

  if((button0 == gadget::Digital::ON) && (button1 == gadget::Digital::ON)){
    button0 = button1 = gadget::Digital::OFF;
    button2 = gadget::Digital::ON;
  }
  else if((button0 == gadget::Digital::OFF) || (button1 == gadget::Digital::OFF)){
    button2 = gadget::Digital::OFF;
  }
}
