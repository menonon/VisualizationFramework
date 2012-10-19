#include "VM_MarchingCubes.h"

VM_MarchingCubes::VM_MarchingCubes(){
  initName();
  initDimension();
}
VM_MarchingCubes::VM_MarchingCubes(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
  initName();
  initDimension();
}
VM_MarchingCubes::~VM_MarchingCubes(){}

VisualizeMethods* VM_MarchingCubes::getInstance(){
  VisualizeMethods* ret = new VM_MarchingCubes();
  return ret;
}
VisualizeMethods* VM_MarchingCubes::getInstance(UserInterfaces* _ui, Data* _data){
  VisualizeMethods* ret = new VM_MarchingCubes(_ui,_data);
  return ret;
}
void VM_MarchingCubes::initName(){
  name = "Marching Cubes";
}
void VM_MarchingCubes::initDimension(){
  dimension = 1;
}

void VM_MarchingCubes::draw(){}
void VM_MarchingCubes::init(){
  
  mThreshold = 0.0;
  
  /** Data Generation for VL Marching Cubes */
  DataArray* tempData = data->getData();
  int sizeX = data->getCoord()->getXnum();
  int sizeY = data->getCoord()->getYnum();
  int sizeZ = data->getCoord()->getZnum();
  mImage = new vl::Image(sizeX, sizeY, sizeZ, sizeof(float), vl::IF_LUMINANCE,vl::IT_FLOAT); 
  
  unsigned char* tempImage = mImage->pixels();
  float* tempImageFloat = reinterpret_cast<float*>(tempImage);
  
  for(int i=0;i<sizeZ;i++){
    for(int j=0;j<sizeY;j++){
      for(int k=0;k<sizeX;k++){
	tempImageFloat[sizeX*sizeY*i + sizeX*j + k] = static_cast<float>((*tempData)[dimension-1][i][j][k]);
      }
    }
  }
  
  
  /* MerchingCube initialize */
  float minX = data->getCoord()->getX(0);
  float minY = data->getCoord()->getY(0);
  float minZ = data->getCoord()->getZ(0);
  float maxX = data->getCoord()->getX(sizeX-1);
  float maxY = data->getCoord()->getY(sizeY-1);
  float maxZ = data->getCoord()->getZ(sizeZ-1);
  
  
  
  mVolume = new vl::Volume;
  mVolume->setup( reinterpret_cast<float*>(mImage->pixels()), true, false, vl::fvec3(minX,minY,minZ), vl::fvec3(maxX,maxY,maxZ), vl::ivec3(mImage->width(), mImage->height(), mImage->depth()) );

  mMarchingCubes.reset();
  mMarchingCubes.volumeInfo()->push_back( new vl::VolumeInfo(mVolume.get(), mThreshold) );
  mMarchingCubes.run(false);


}
void VM_MarchingCubes::contextInit(){
  int current = vrj::opengl::DrawManager::instance()->getCurrentContext();
  
  vl::initializeOpenGL();
  mOGLContext.initGLContext(true);
  mOGLContext.setContinuousUpdate(false);

  mRend[current] = new vl::Rendering;
  mScene[current] = new vl::SceneManagerActorTree;
  mRend[current]->sceneManagers()->push_back(mScene[current].get());

  mEdgeRend[current] = new vl::EdgeRenderer;
  mEdgeRend[current]->setClearFlags(vl::CF_CLEAR_DEPTH);
  mEdgeRend[current]->setFramebuffer(mOGLContext.framebuffer());

  mRend[current]->renderers().push_back(mEdgeRend[current].get());

  mEdgeRend[current]->setShowHiddenLines(true);
  mEdgeRend[current]->setShowCreases(true);
  mEdgeRend[current]->setDefaultLineColor(vl::white);

  mTrans[current] = new vl::Transform;
  mRend[current].get()->transform()->addChild(mTrans[current].get());

  vl::ref<vl::Effect> effect = new vl::Effect;
  effect->shader()->enable(vl::EN_DEPTH_TEST);
  effect->shader()->setRenderState( new vl::Light, 0);
  effect->shader()->enable(vl::EN_LIGHTING);
  effect->shader()->gocMaterial()->setDiffuse(vl::gold);
  effect->shader()->gocMaterial()->setSpecular(vl::white);
  effect->shader()->gocMaterial()->setShininess(60);
  


  mIsosurfGeom[current] = new vl::Geometry;
  mIsosurfGeom[current]->setVertexArray(mMarchingCubes.mVertsArray.get());
  mIsosurfGeom[current]->setNormalArray(mMarchingCubes.mNormsArray.get());
  mIsosurfGeom[current]->drawCalls()->push_back(mMarchingCubes.mDrawElements.get());

  vl::ref<vl::Actor> actor = new vl::Actor(mIsosurfGeom[current].get(), effect.get(), mTrans[current].get(), 0,0);
  
  
  mScene[current].get()->tree()->addActor(actor.get());

  mRend[current].get()->renderer()->setFramebuffer(mOGLContext.framebuffer());

  


}


void VM_MarchingCubes::contextPreDraw(){}
void VM_MarchingCubes::preFrame(){}
void VM_MarchingCubes::intraFrame(){}
void VM_MarchingCubes::postFrame(){}
