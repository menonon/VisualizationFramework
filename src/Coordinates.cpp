#include "Coordinates.h"
#include <fstream>
#include <iostream>

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
