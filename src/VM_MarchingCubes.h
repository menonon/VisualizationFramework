#pragma once

#include "VisualizeMethodsWithVL.h"

class VM_MarchingCubes:public VisualizeMethodsWithVL{



 public:
  VM_MarchingCubes();
  VM_MarchingCubes(UserInterfaces* _ui, Data* _data);
  ~VM_MarchingCubes();

  VisualizeMethods* getInstance();
  VisualizeMethods* getInstance(UserInterfaces* _ui, Data* _data);
  void initName();
  void initDimension();

  void draw();
  void init();
  void contextInit();
  void contextPreDraw();
  void preFrame();
  void intraFrame();
  void postFrame();


 private:
  vl::ref<vl::Image> mImage;
  vl::MarchingCubes mMarchingCubes;
  vl::ref<vl::Volume> mVolume;
  std::map<int, vl::ref<vl::Geometry> > mIsosurfGeom;

  float mThreshold;
};
