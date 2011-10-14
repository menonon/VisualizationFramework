#include "Palette.h"

Palette::Palette(){
  this.data = NULL;
  this.vm = NULL;
}
Palette::~Palette(){}

void Palette::setData(Data* data){
  this.data = data;
}
void Palette::setVisualizeMethods(VisualizeMethods* vm){
  this.vm = vm;
}

void Palette::removeData(){
  this.data = NULL;
}
void Palette::removeVisualizeMethods(){
  this.vm = NULL;
}

bool Palette::isEmpty(){
  if((this.data==NULL)&&(this.vm==NULL))return true;
  else return false;
}
