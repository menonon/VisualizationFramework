#include "VisualizeMethods.h"

VisualizeMethods::VisualizeMethods(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
}

VisualizeMethods::VisualizeMethods(){}

VisualizeMethods::~VisualizeMethods(){}

void VisualizeMethods::draw(){}
void VisualizeMethods::init(){}
void VisualizeMethods::contextInit(){}
void VisualizeMethods::preFrame(){}
void VisualizeMethods::intraFrame(){}
void VisualizeMethods::postFrame(){}
