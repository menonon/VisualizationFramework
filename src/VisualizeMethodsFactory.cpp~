#include "VisualizeMethodsFactory.h"

VisualizeMethodsFactory::VisualizeMethodsFactory(){
  VisualizeMethods* temp;
  int i=0;
    while(true){
      switch (i){
      case 0:temp = new VM_LocalArrows();break;
      case 1:temp = new VM_ParticleTracer();break;
      default:temp = NULL;break;
      }
      if(temp==NULL)break;
      VM.push_back(temp);
      i++;
    }
}

VisualizeMethods* VisualizeMethodsFactory::getVM(int m, UserInterfaces* _ui, Data* _data){
  if(m<VM.size())return VM[m]->getInstance(_ui,_data);
  else return NULL;
}
