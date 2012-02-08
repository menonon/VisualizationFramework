#include "Panel.h"

Panel::Panel(double x, double y, double z, double h, double w, double d){
  
  pos[0] = x;
  pos[1] = y;
  pos[2] = z;
  
  height = h;
  width = w;
  depth = d;

  gmtl::Point3d min(x-w*0.5, y-h*0.5, z-d);
  gmtl::Point3d max(x+w*0.5, y+h*0.5, z);

  std::cout << __FILE__ << ":min,max:" << min << ":" << max <<std::endl; 

  testBox.setMin(min);
  testBox.setMax(max);
  testBox.setEmpty(false);

  on=false;
  hitTestPrevious = false;
}

Panel::~Panel(){}


void Panel::draw(){
/*
  if(on) glColor3d(0,1,1);
  else glColor3d(1,1,0);
*/
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
  if(on) glColor3d(0,1,0);
  else glColor3d(1,0,0);
  glBegin(GL_POLYGON);
  glVertex3d(pos[0]+width*0.5, pos[1]+height*0.5, pos[2]);
  glVertex3d(pos[0]-width*0.5, pos[1]+height*0.5, pos[2]);
  glVertex3d(pos[0]-width*0.5, pos[1]-height*0.5, pos[2]);
  glVertex3d(pos[0]+width*0.5, pos[1]-height*0.5, pos[2]);
  glEnd();

//  glDisable(GL_LIGHTING);
//  glDisable(GL_LIGHT0);
}

void Panel::preFrame(){
/* update */

}

bool Panel::hitTest(gmtl::Point3d point){

  bool present = gmtl::isInVolume(testBox,point);
//  return present;
  

  //when in->out ,recognizing "TOUCH"
  std::cout << __FILE__ << ":Previous,Present:" << hitTestPrevious << present << std::endl;
  if(hitTestPrevious == true && present == false){
    hitTestPrevious = present;
    return true;
  }
  hitTestPrevious = present;
  std::cout << __FILE__ << "no hit" << std::endl;
  return false;

}

void Panel::toggleState(){
  if(on == true)on=false;
  else on=true;
}

bool Panel::getState(){
  return on;
}
