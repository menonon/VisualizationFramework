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
#include "VM_Test.h"

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

void Amaterasu::contextInit(){
  menu->contextInit();
}

void Amaterasu::contextPreDraw(){
  //  std::cout << __FILE__ << ":contextPreDraw" << std::endl;
  //  menu->contextPreDraw();
}

void Amaterasu::bufferPreDraw(){
  glClearColor(0.0,0.0,0.0,0.0);
  //  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  
}

void Amaterasu::draw(){
  glClear(GL_DEPTH_BUFFER_BIT);

  GLfloat mat_diffuse[]  = {1.0, 1.0, 1.0, 1.0};
  GLfloat mat_ambient[]  = {0.1, 0.1, 0.1, 1.0};
  GLfloat mat_specular[] = {0.9, 0.9, 0.9, 1.0};

  GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0};
  GLfloat light_ambient[]  = {0.5, 0.5, 0.5, 1.0};
  GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

  glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
  glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf (GL_FRONT, GL_SHININESS, 64.0);

  glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);

  
  ui->draw();
  menu->draw();
  coord->draw();

}

void Amaterasu::preFrame(){

  ui->preFrame();
  menu->preFrame();

}
void Amaterasu::intraFrame(){

  menu->intraFrame();
}
void Amaterasu::postFrame(){}
