/**
 * Amaterasu.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 *@version developping
 */

#include <GL/gl.h>
#include "Amaterasu.h"
#include <fstream>
#include <vector>
#include <ostream>

Amaterasu::Amaterasu(std::string path){
  std::cout << __FILE__ << std::endl;

  configPath = path;
}
Amaterasu::~Amaterasu(){}

void Amaterasu::parseConfigFile(){
  
  std::ifstream ifs(configPath.c_str(), std::ios::in);
  
  std::string keyword;
  std::string label;
  int dimension;
  std::vector<std::string> path;
  
  while(!ifs.eof()){
    std::cout << "aaa" << std::endl;
    path.clear();

    ifs >> keyword;
    if(keyword.compare("data")==0){
      ifs >> label >> dimension;
      for(int i=0;i<dimension;i++){
	std::string temp;
	ifs >> temp;
	path.push_back(temp);
      }
      Config* conf = new Config();
      conf->setLabel(label);
      conf->setDimension(dimension);
      conf->setPath(path);
      conf_arr.push_back(conf);
      keyword.clear();
    }
    else if(keyword.compare("coord")==0){
      for(int i=0;i<3;i++){
	std::string temp;
	ifs >> temp;
	path.push_back(temp);
      }
      coord = new Coordinates(path);
      keyword.clear();
    }
    else{
      ifs.close();
      return;
    }
  }

  
}

void Amaterasu::init(){
  
  std::cout << __FILE__ << ":init" << std::endl;
  parseConfigFile();
  std::cout << "bbb" << std::endl;
  for(std::vector<Config*>::iterator it = conf_arr.begin();it!=conf_arr.end();it++){
    Data* data_temp = new Data((*it), coord);
    data_arr.push_back(data_temp);
  }

  ui = new UserInterfaces();
  ui->init();

  

  menu = new Menu(ui);
  menu->init(data_arr,vm_arr);

  
  
}

void Amaterasu::contextInit(){}

void Amaterasu::bufferPreDraw(){}
void Amaterasu::draw(){;}

void Amaterasu::preFrame(){

  ui->preFrame();
  menu->preFrame();

}
void Amaterasu::intraFrame(){}
void Amaterasu::postFrame(){}
