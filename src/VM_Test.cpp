#include "VM_Test.h"


void VM_Test::draw(){
  DataArray* dataarr= data->getData();
  Coordinates* coord = data->getCoord();

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(/**/);
  glColorPointer(/**/);

  glDrawArrays(/**/);
  
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  

}
void VM_Test::init(){
  /* create vertex array and color array */
}
void VM_Test::contextInit(){}
void VM_Test::preFrame(){}
void VM_Test::intraFrame(){}
void VM_Test::postFrame(){}
