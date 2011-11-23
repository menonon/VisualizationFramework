#include "Coordinates.h"
#include <fstream>
#include <iostream>
#include <GL/gl.h>

Coordinates::Coordinates(std::vector<std::string> path){

  std::cout << __FILE__ << std::endl;

  std::ifstream ifs;
  double temp=0;
  int i=0;

  for(std::vector<std::string>::iterator it = path.begin(); it!=path.end(); it++){
    std::cout << (*it).c_str() << std::endl;
    ifs.open((*it).c_str(),std::ios::binary);
    ifs.seekg(4,std::ios::beg);
    while(!ifs.eof()){
      ifs.read((char*)&temp,sizeof(double));
      std::cout << temp << std::endl;
      if(i==0)x.push_back(temp);
      else if(i==1)y.push_back(temp);
      else if(i==2)z.push_back(temp);
    }
    i++;
    ifs.close();
  }
  
  std::cout << getZnum() <<  getYnum() <<  getXnum() << std::endl;


  x.pop_back();
  y.pop_back();
  z.pop_back();

  std::cout << getZnum() <<  getYnum() <<  getXnum() << std::endl;


  createBoundingBox();

}


int Coordinates::getXnum(){
  return x.size();
}

int Coordinates::getYnum(){
  return y.size();
}

int Coordinates::getZnum(){
  return z.size();
}

double Coordinates::getX(int at){
  return x.at(at);
}

double Coordinates::getY(int at){
  return y.at(at);
}

double Coordinates::getZ(int at){
  return z.at(at);
}


void Coordinates::draw(){
  drawBoundingBox();
}

void Coordinates::drawBoundingBox(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glVertexPointer(3,GL_DOUBLE,0,&boxVertex[0]);
  glColorPointer(3,GL_DOUBLE,0,&boxColor[0]);

  glDisable(GL_LIGHTING);
  glLineWidth(3);
  glDrawArrays(GL_LINES,0,(boxVertex.size()+1)/3);
  glLineWidth(1);
  glEnable(GL_LIGHTING);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Coordinates::createBoundingBox(){

  /* X */
  for(int j=0; j<getYnum(); j+=getYnum()-1)for(int k=0; k<getZnum(); k+=getZnum()-1){
    boxVertex.push_back(x.front());boxVertex.push_back(y[j]);boxVertex.push_back(z[k]);
    boxVertex.push_back(x.back()); boxVertex.push_back(y[j]);boxVertex.push_back(z[k]);
    
    boxColor.push_back(1);boxColor.push_back(0);boxColor.push_back(0);
    boxColor.push_back(1);boxColor.push_back(0);boxColor.push_back(0);
  }
  
  /* Y */
  for(int i=0; i<getXnum(); i+=getXnum()-1)for(int k=0; k<getZnum(); k+=getZnum()-1){
    boxVertex.push_back(x[i]);boxVertex.push_back(y.front());boxVertex.push_back(z[k]);
    boxVertex.push_back(x[i]);boxVertex.push_back(y.back()); boxVertex.push_back(z[k]);
    
    boxColor.push_back(0);boxColor.push_back(1);boxColor.push_back(0);
    boxColor.push_back(0);boxColor.push_back(1);boxColor.push_back(0);
  }
  
  /* Z */
  for(int i=0; i<getXnum(); i+=getXnum()-1)for(int j=0; j<getYnum(); j+=getYnum()-1){
    boxVertex.push_back(x[i]);boxVertex.push_back(y[j]);boxVertex.push_back(z.front());
    boxVertex.push_back(x[i]);boxVertex.push_back(y[j]);boxVertex.push_back(z.back());
    
    boxColor.push_back(0);boxColor.push_back(0);boxColor.push_back(1);
    boxColor.push_back(0);boxColor.push_back(0);boxColor.push_back(1);
  }

}


int Coordinates::getXindex(double at){
  std::cout << x.front() << "," << x.back() << "," << at << std::endl;
  if(at<x.front())return -1;
  if(x.back()<=at)return -1;

  int i=0;
  for(std::vector<double>::iterator it = x.begin();it!=x.end();++it){
    if(at-(*it)<=0){
      std::cout << "Xindex" << i << std::endl;
      return i-1;
    }
    ++i;
  }
  std::cout << "X out of range" << std::endl;
  return i;
}
int Coordinates::getYindex(double at){
  std::cout << y.front() << "," << y.back() << "," << at << std::endl;
  if(at<y.front())return -1;
  if(y.back()<=at)return -1;

  int i=0;
  for(std::vector<double>::iterator it = y.begin();it!=y.end();++it){
    if(at-(*it)<=0){
      std::cout << "Yindex" << i << std::endl;
      return i-1;
    }
    ++i;
  }
  std::cout << "Y out of range" << std::endl;
  return i;
}
int Coordinates::getZindex(double at){
  std::cout << z.front() << "," << z.back() << "," << at << std::endl;
  if(at<z.front())return -1;
  if(z.back()<=at)return -1;

  int i=0;
  for(std::vector<double>::iterator it = z.begin();it!=z.end();++it){
    if(at-(*it)<=0){
      std::cout << "Zindex" << i << std::endl;
      return i-1;
    }
    ++i;
  }
  std::cout << "Z out of range" << std::endl;
  return i;
}
