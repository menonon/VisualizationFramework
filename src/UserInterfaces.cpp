#include "UserInterfaces.h"

UserInterfaces::init(){

  gWand.init("VJWand");
  gHead.init("VJHead");

  gButton0.init("VJButton0");
  gButton1.init("VJButton1");

  gJoyStick0X.init("VJAnalog0");
  gJoyStick0Y.init("VJAnalog1");
}


UserInterfaces::preFrame(){}
