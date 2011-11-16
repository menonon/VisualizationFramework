#include "VM_Test.h"
#include <GL/gl.h>

VM_Test::VM_Test(){}
VM_Test::VM_Test(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
}
VM_Test::~VM_Test(){}


void VM_Test::draw(){
  std::cout << __FILE__ << ":draw A" << std::endl;

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(3,GL_DOUBLE,0,&vertex[0]);
  glColorPointer(3,GL_DOUBLE,0,&color[0]);

  std::cout << __FILE__ << ":draw B" << std::endl;

  glPointSize(5);
  glDrawArrays(GL_POINTS,0,(vertex.size()+1)/3);
  glPointSize(1);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  
  std::cout << __FILE__ << ":draw C" << std::endl;
}
void VM_Test::init(){

  std::cout << __FILE__ << ":init" << std::endl;  

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
  

  double max,min;
  max = min = (*dataarr)[0][0][0][0];
  for(int n=0;n<3;++n)
    for(int i=0; i<coord->getZnum(); ++i)
      for(int j=0; j<coord->getYnum(); ++j)
	for(int k=0; k<coord->getXnum(); ++k){
	  if((*dataarr)[n][i][j][k]<min)min=(*dataarr)[n][i][j][k];
	  else if((*dataarr)[n][i][j][k]>max)max=(*dataarr)[n][i][j][k];
	}

  double scale = 1.0 / max;

  
  for(int i=0; i<coord->getZnum(); ++i)
    for(int j=0; j<coord->getYnum(); ++j)
      for(int k=0; k<coord->getXnum(); ++k)
	for(int n=0;n<3;++n){
	  color.push_back(((*dataarr)[n][i][j][k]-min)*scale);
	}

  std::cout << __FILE__ << ":init" << (vertex.size()+1)/3 << std::endl;

}

void VM_Test::contextInit(){}
void VM_Test::preFrame(){}
void VM_Test::intraFrame(){}
void VM_Test::postFrame(){}
