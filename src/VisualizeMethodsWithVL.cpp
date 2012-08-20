#include "VisualizeMethodsWithVL.h"

VisualizeMethodsWithVL::VisualizeMethodsWithVL(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
}

VisualizeMethods* VisualizeMethodsWithVL::getInstance(){}
VisualizeMethods* VisualizeMethodsWithVL::getInstance(UserInterfaces* _ui, Data* _data){}
void VisualizeMethodsWithVL::initName(){}
void VisualizeMethodsWithVL::initDimension(){}

VisualizeMethodsWithVL::VisualizeMethodsWithVL(){}
VisualizeMethodsWithVL::~VisualizeMethodsWithVL(){}

void VisualizeMethodsWithVL::draw(){}
void VisualizeMethodsWithVL::init(){}
void VisualizeMethodsWithVL::contextInit(){}
void VisualizeMethodsWithVL::contextPreDraw(){}
void VisualizeMethodsWithVL::preFrame(){}
void VisualizeMethodsWithVL::intraFrame(){}
void VisualizeMethodsWithVL::postFrame(){}
