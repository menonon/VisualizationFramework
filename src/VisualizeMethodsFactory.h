#include <vlCore/OpenGLDefs.hpp>
#include <iostream>
#include "VM_LocalArrows.h"
#include "VM_ParticleTracer.h"
#include "VM_MarchingCubes.h"

class VisualizeMethodsFactory{
 public:
  VisualizeMethodsFactory();
  VisualizeMethods* getVM(int m,UserInterfaces* _ui,Data* _data);

  std::vector<VisualizeMethods*> VM;

};
