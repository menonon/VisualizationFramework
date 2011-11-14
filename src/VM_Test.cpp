#include "VM_Test.h"
#include <GL/gl.h>


VM_Test::VM_Test(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
  
}

void VM_Test::draw(){

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(3,GL_DOUBLE,0,vertex);
  glColorPointer(3,GL_DOUBLE,0,color);

  glDrawArrays(GL_POINTS,0,vertex.size());
  
  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  

}
void VM_Test::init(){
  /* create vertex array and color array */
  Coordinates* coord = data->getCoord();
  DataArray* dataarr= data->getData();
  
  for(int i=0; i<coord->getZnum(); ++i)
    for(int j=0; j<coord->getYnum(); ++j)
      for(int k=0; k<coord->getXnum(); ++k){
	vertex.push_back(coord->getX(k));
	vertex.push_back(coord->getY(j));
	vertex.push_back(coord->getZ(i));
      }
  

  for(int i=0; i<coord->getZnum(); ++i)
    for(int j=0; j<coord->getYnum(); ++j)
      for(int k=0; k<coord->getXnum(); ++k){
	for(int n=0;n<3;++n){
	  color.push_back((*dataarr)[n][i][j][k]);
	}


}
void VM_Test::contextInit(){}
void VM_Test::preFrame(){}
void VM_Test::intraFrame(){}
void VM_Test::postFrame(){}
