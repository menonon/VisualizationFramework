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

  testBox.setMin(min);
  testBox.setMax(max);

  on=false;
}

Panel::~Panel(){}


void Panel::draw(){

  if(on) glColor3d(0,1,1);
  else glColor3d(1,1,0);

  glBegin(GL_POLYGON);
  glVertex3d(pos[0]+width*0.5, pos[1]+height*0.5, pos[2]);
  glVertex3d(pos[0]-width*0.5, pos[1]+height*0.5, pos[2]);
  glVertex3d(pos[0]-width*0.5, pos[1]-height*0.5, pos[2]);
  glVertex3d(pos[0]+width*0.5, pos[1]-height*0.5, pos[2]);
  glEnd();

}

bool Panel::hitTest(gmtl::Point3d point){

  return gmtl::isInVolume(testBox,point);

}

void Panel::toggleState(){
  if(on == true)on=false;
  else on=true;
}

bool Panel::getState(){
  return on;
}
