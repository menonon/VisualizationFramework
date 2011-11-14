#include "UserInterfaces.h"
#include <ostream>
#include <gmtl/Vec.h>
#include <gmtl/Generate.h>

UserInterfaces::UserInterfaces(){
  std::cout << __FILE__ << std::endl;
}


void UserInterfaces::init(){

  gWand.init("VJWand");
  gHead.init("VJHead");

  gButton0.init("VJButton0");
  gButton1.init("VJButton1");
  gButton2.init("VJButton2");

  gJoyStick0X.init("VJAnalog0");
  gJoyStick0Y.init("VJAnalog1");

  
}


void UserInterfaces::draw(){
  glMultMatrixf(navMat.mData);
}

void UserInterfaces::preFrame(){
  /* Refresh Devices Data */
  wand = gWand->getData();
  head = gHead->getData();
  
  button0 = gButton0->getData();
  button1 = gButton1->getData();
  button2 = gButton2->getData();

  joyStick0X = (gJoyStick0X->getData() -0.5)*2.0;
  joyStick0Y = (gJoyStick0Y->getData() -0.5)*2.0;

  
  /* Navigation */
  gmtl::Vec3f z_dir = gmtl::Vec3f(0,0,joyStick0Y);
  gmtl::Vec3f dir(wand*z_dir);
  gmtl::preMult(navMat, gmtl::makeTrans<gmtl::Matrix44f>(dir));

  const float rotScale(0.01);
  float yRot = joyStick0X;
  float rotation = -1.0 * yRot * rotScale;
  gmtl::preMult(navMat, gmtl::makeRot<gmtl::Matrix44f>(gmtl::EulerAngleXYZf(0.0,rotation,0.0)));
  

}
