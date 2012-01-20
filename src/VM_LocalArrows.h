

#ifndef __VM_LOCALARROWS_H
#define __VM_LOCALARROWS_H

#include <GL/gl.h>
#include "VisualizeMethods.h"
#include <vector>
#include <gmtl/Matrix.h>
#include <gmtl/Vec.h>


class VM_LocalArrows:public VisualizeMethods{

 public:
  VM_LocalArrows();
  VM_LocalArrows(UserInterfaces* _ui, Data* _data);
  ~VM_LocalArrows();

  VisualizeMethods* getInstance();
  VisualizeMethods* getInstance(UserInterfaces* _ui, Data* _data);
  void initName();
  

  void draw();
  void init();
  void contextPreDraw();
  void preFrame();
  void intraFrame();
  void postFrame();

 private:

  std::vector<gmtl::Vec3f> arrowPosition;
  std::vector<gmtl::Matrix44f> arrowPositionInWorld;
  std::vector<double> arrowLength;

  double norm;
  double normh;
};
#endif
