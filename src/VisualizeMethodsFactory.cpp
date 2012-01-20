#include "VisualizeMethodsFactory.h"

VisualizeMethodFactory::VisualizeMethodFactory(){
  VisualizeMethods* temp;
  int i=0;
    while(){
      switch (i){
      case 0:temp = new LocalArrows();break;
      case 1:temp = new ParticleTracer();break;
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
