#pragma once

#include <GL/gl.h>
#include <gmtl/gmtl.h>

class Panel{

 public:
  Panel(double x, double y, double z, double h, double w, double d);
  virtual ~Panel();

  virtual void draw();
  virtual bool hitTest(gmtl::Point3d point);
  
  virtual void toggleState();
  virtual bool getState();

 private:
  bool on;
  double pos[3];
  double height,width,depth;
  gmtl::AABoxd testBox;



};
