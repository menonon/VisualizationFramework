
#ifndef __VM_PARTICLETRACER_H
#define __VM_PARTICLETRACER_H

#include "VisualizeMethods.h"
#include <vector>

class VM_ParticleTracer:public VisualizeMethods{
 public:
  VM_ParticleTracer();
  VM_ParticleTracer(UserInterfaces* _ui, Data* _data);
  ~VM_ParticleTracer();

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
  std::vector<std::vector<double> > tracers;
  void integrate();


};
#endif
