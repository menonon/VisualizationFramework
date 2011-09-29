#include "Config.h"


Config::Config(){}


int Config::getDimension(){
  return this.dimension;
}

std::string Config::getLabel(){
  return this.label;
}

std::vector<std::string> Config::getPath(){
  return this.path;
}

void Config::setDimension(int dimension){
  this.dimension = dimension;
}

void Config::setLabel(std::string label){
  this.label = label;
}
void Config::setPath(std::vector<std::string> path){
  this.path = path;
}
