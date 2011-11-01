#include "Config.h"


Config::Config(){}


int Config::getDimension(){
  return dimension;
}

std::string Config::getLabel(){
  return label;
}

std::vector<std::string> Config::getPath(){
  return path;
}

void Config::setDimension(int dim){
  dimension = dim;
}

void Config::setLabel(std::string lab){
  label = lab;
}
void Config::setPath(std::vector<std::string> path_){
  path = path_;
}
