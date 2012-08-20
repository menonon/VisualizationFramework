#pragma once

#include <vlGraphics/OpenGLContext.hpp>

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <iostream>

class emptyVLOpenGLContext: public vl::OpenGLContext{
public:  
  virtual void swapBuffers(){}
  virtual void makeCurrent(){}
  virtual void update(){}
  
  void setHandle(int aHandle){mHandle = aHandle;}
  int mHandle;
};
