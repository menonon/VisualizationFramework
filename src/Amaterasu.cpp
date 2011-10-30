/**
 * Amaterasu.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 *@version developping
 */

#include <GL/gl.h>
#include "Amaterasu.h"
#include <fstream>
#include <vector>

Amaterasu(std::string path){
  this.configPath = path;
}
~Amaterasu(){}

void Amaterasu::parseConfigFile(){
  
  std::ifstream ifs(configPath.c_str(), std::ios::in);
  
  std::string keyword;
  std::string label;
  int dimension;
  std::vector<std::string> path;
  
  while(!ifs.eof()){
    path.clear();

    ifs >> keyword;
    if(keyword.compare("data")){
      ifs >> label >> dimension;
      for(int i=0;i<dimension;i++){
	std::string temp;
	ifs >> temp;
	path.push_back(temp);
      }
      Config conf = new Config();
      conf.setLabel(label);
      conf.setDimension(dimension);
      conf.setPath(path);
      conf_arr.push_back(conf);
    }
    else if(keyword.compare("coord")){
      for(int i=0;i<3;i++){
	std::string temp;
	ifs >> temp;
	path.push_back(temp);
      }
      coord = new Coordinates(path);
    }
  }
  
}

void Amaterasu::init(){
  parseConfigFile();
  
  for(std::vector<Config>::iterator it = conf_arr.begin();it!=conf_arr.end();it++){
    Data data_temp = new Data((*it), coord);
    data_arr.push_back(data_temp);
  }

  ui = new UserInterfaces();
  ui->init();
  
}

void Amaterasu::contextInit(){}

void Amaterasu::bufferPreDraw(){}
void Amaterasu::draw(){}

void Amaterasu::preFrame(){

  ui->preFrame();
  menu->preFrame();

}
void Amaterasu::intraframe(){}
void Amaterasu::postFrame(){}
