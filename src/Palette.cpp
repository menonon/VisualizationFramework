#include "Palette.h"

Palette::Palette(){
  data = NULL;
  vm = NULL;
}
Palette::~Palette(){}

void Palette::setData(Data* data_){
  data = data_;
}
void Palette::setVisualizeMethods(VisualizeMethods* vm_){
  vm = vm_;
}

void Palette::removeData(){
  data = NULL;
}
void Palette::removeVisualizeMethods(){
  vm = NULL;
}

bool Palette::isFull(){
  if((data!=NULL)&&(vm!=NULL))return true;
  else return false;
}

void Palette::draw(){
  vm->draw();
}

void Palette::preFrame(){
  vm->preFrame();
}

void Palette::intraFrame(){
  vm->intraFrame();
}

void Palette::contextPreDraw(){
  vm->contextPreDraw();
}

