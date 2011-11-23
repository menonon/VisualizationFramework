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

  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  
  glVertexPointer(3,GL_DOUBLE,0,&vertex[0]);
  glColorPointer(4,GL_DOUBLE,0,&color[0]);

  std::cout << __FILE__ << ":draw B" << std::endl;

  glPointSize(10);
  glDrawArrays(GL_POINTS,0,(vertex.size())/3/20);
  glPointSize(1);

  std::cout << __FILE__ << ":draw C" << std::endl;

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  std::cout << __FILE__ << ":draw D" << std::endl;

  glEnable(GL_DEPTH_TEST);
  glDisable(GL_BLEND);

  std::cout << __FILE__ << ":draw E" << std::endl;
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
      for(int k=0; k<coord->getXnum(); ++k){
	for(int n=0;n<3;++n){
	  color.push_back(((*dataarr)[n][i][j][k]-min)*scale);
	}
	color.push_back(0.5);
      }


  std::cout << __FILE__ << ":init:" << (vertex.size()+1)/3 << std::endl;
  std::cout << __FILE__ << ":init:" << (color.size()+1)/4 << std::endl;
}

void VM_Test::contextPreDraw(){
  /* create Vertex Buffer Object */
  static bool once = false;

  once=true;
  if(!once){
    once = true;
  
    std::cout << __FILE__ << ":contextInit A" << std::endl;
    
    glGenBuffers(1,&(*vboVertex));
    glGenBuffers(1,&(*vboColor));
    
    std::cout << __FILE__ << ":contextInit B" << std::endl;
    
    glBindBuffer(GL_ARRAY_BUFFER,(*vboVertex));
    glBufferData(GL_ARRAY_BUFFER,sizeof(&vertex[0]),&vertex[0],GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER,(*vboColor));
    glBufferData(GL_ARRAY_BUFFER,sizeof(&color[0]),&color[0],GL_STATIC_DRAW);
    
    std::cout << __FILE__ << ":contextInit C" << std::endl;
  }
}
void VM_Test::preFrame(){}
void VM_Test::intraFrame(){}
void VM_Test::postFrame(){}
