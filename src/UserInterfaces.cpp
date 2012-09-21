#include "UserInterfaces.h"
#include <ostream>
#include <gmtl/Vec.h>
#include <gmtl/Generate.h>
#include <GL/gl.h>

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
  glLoadIdentity();
  glMultMatrixf(navMat.mData);
}

void UserInterfaces::preFrame(){
  /* Refresh Devices Data */
  wand = gWand->getData();
  head = gHead->getData();
  
  button0 = gButton0->getData();
  button1 = gButton1->getData();
  button2 = gButton2->getData();

  joyStick0X = (gJoyStick0X->getData() -0.5);
  joyStick0Y = (gJoyStick0Y->getData() -0.5);

  std::cout << joyStick0X<<":"<<joyStick0Y<<std::endl;
  
  std::cout << "wand" << std::endl << wand << std::endl;
  std::cout << "head" << std::endl << head << std::endl;

  /* Navigation */
  gmtl::Vec3f z_dir;
  if(joyStick0Y>0.1 || joyStick0Y<-0.1){
    z_dir = gmtl::Vec3f(0,0,joyStick0Y*0.5);
  }else{
    z_dir = gmtl::Vec3f(0,0,0);
  }
  gmtl::Vec3f dir(wand*z_dir);
  gmtl::preMult(navMat, gmtl::makeTrans<gmtl::Matrix44f>(dir));

  const float rotScale(0.1);
  float yRot;
  if(joyStick0X>0.1 || joyStick0X<-0.1){
    yRot = joyStick0X*0.5;
  }else{
    yRot = 0.0f;
  }
  float rotation = -1.0 * yRot * rotScale;
  gmtl::preMult(navMat, gmtl::makeRot<gmtl::Matrix44f>(gmtl::EulerAngleXYZf(0.0,rotation,0.0)));

  gmtl::Matrix44f vw_M_w;
  gmtl::invert(vw_M_w,navMat);
  navWand = vw_M_w * wand;  
}
