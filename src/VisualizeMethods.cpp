#include "VisualizeMethods.h"

VisualizeMethods::VisualizeMethods(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
}

VisualizeMethods* VisualizeMethods::getInstance(){}
VisualizeMethods* VisualizeMethods::getInstance(UserInterfaces* _ui, Data* _data){}
void VisualizeMethods::initName(){}

VisualizeMethods::VisualizeMethods(){}
VisualizeMethods::~VisualizeMethods(){}

void VisualizeMethods::draw(){}
void VisualizeMethods::init(){}
void VisualizeMethods::contextInit(){}
void VisualizeMethods::contextPreDraw(){}
void VisualizeMethods::preFrame(){}
void VisualizeMethods::intraFrame(){}
void VisualizeMethods::postFrame(){}
