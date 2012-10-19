#pragma once

#include "VisualizeMethods.h"

#include <vrj/Display/Display.h>
#include <vrj/Display/DisplayManager.h>
#include <vrj/Display/Viewport.h>
#include <vrj/vrjConfig.h>
#include <vrj/Draw/OpenGL/App.h>
#include <gmtl/gmtl.h>
#include <gadget/Type/PositionInterface.h>
#include <vrj/Draw/OpenGL/DrawManager.h>

#include <vlGraphics/plugins/ioOBJ.hpp>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlCore/String.hpp>
#include <vlGraphics/Rendering.hpp>
#include <vlGraphics/SceneManagerActorTree.hpp>
#include <vlGraphics/Geometry.hpp>
#include <vlGraphics/GeometryPrimitives.hpp>
#include <vlGraphics/Light.hpp>
#include <vlCore/Time.hpp>
#include <vlCore/GlobalSettings.hpp>
#include <vlGraphics/EdgeRenderer.hpp>

#include <GL/gl.h>

#include <string>
#include <iostream>
#include <map>

#include "emptyVLOpenGLContext.hpp"


class VisualizeMethodsWithVL:public VisualizeMethods{
  
 public:
  VisualizeMethodsWithVL();
  VisualizeMethodsWithVL(UserInterfaces* _ui, Data* _data);
  virtual ~VisualizeMethodsWithVL();

  virtual VisualizeMethods* getInstance();
  virtual VisualizeMethods* getInstance(UserInterfaces* _ui, Data* _data);
  virtual void initName();
  virtual void initDimension();

  virtual  void draw();
  virtual  void init();
  virtual  void contextInit();
  virtual  void contextPreDraw();
  virtual  void preFrame();
  virtual  void intraFrame();
  virtual  void postFrame();

 private:
  vl::ref<vl::ResourceDatabase> mObj;
  std::map<int, vl::ref<vl::Rendering> > mRend;
  std::map<int, vl::ref<vl::SceneManagerActorTree> > mScene;
  std::map<int, vl::ref<vl::Transform> >mTrans;
  emptyVLOpenGLContext mOGLContext;
  
  std::map<int, vl::ref<vl::EdgeRenderer> > mEdgeRend;


};
