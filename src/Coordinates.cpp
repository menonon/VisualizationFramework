#include "Coordinates.h"
#include <fstream>

Coordinates::Coordinates(std::vector<std::string> path){

  std::ifstream ifs();
  double temp=0;
  int i=0;

  for(std::vector<std::vector>::iterator it = path.begin(); it!=path.end(); it++){
    ifs.open((*it).c_str());
    while(!ifs.eof()){
      ifs.read((char*)&temp,sizeof(double));
      if(i==0)x.push_back(temp);
      else if(i==1)y.push_back(temp);
      else if(i==2)z.push_back(temp);
    }
    i++;
    ifs.close();
  }
  
  x.pop_back();
  y.pop_back();
  z.pop_back();
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
