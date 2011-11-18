

#ifndef __VM_TEST_H
#define __VM_TEST_H

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <vrj/Draw/OpenGL/ContextData.h>
#include "VisualizeMethods.h"



class VM_Test:public VisualizeMethods{

 public:
  VM_Test();
  VM_Test(UserInterfaces* _ui, Data* _data);
  ~VM_Test();

  void draw();
  void init();
  void contextPreDraw();
  void preFrame();
  void intraFrame();
  void postFrame();


 private:
  std::vector<double> vertex;
  std::vector<double> color;

  vrj::opengl::ContextData<GLuint> vboVertex;
  vrj::opengl::ContextData<GLuint> vboColor;

};
#endif
