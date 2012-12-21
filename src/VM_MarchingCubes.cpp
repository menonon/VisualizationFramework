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

void VM_MarchingCubes::draw(){

  std::cout << __FILE__ << ":Aa" << std::endl;

  int current = vrj::opengl::DrawManager::instance()->getCurrentContext();
  int vp[4];
  std::cout << __FILE__ << ":Ab" << std::endl;
  glGetIntegerv(GL_VIEWPORT, vp);
  std::cout << __FILE__ << ":Ac" << std::endl;
  std::cout << "currentContext:" << current << std::endl;
  
  mRend[current]->camera()->viewport()->set(vp[0], vp[1], vp[2], vp[3]);

  std::cout << __FILE__ << ":B" << std::endl;

  float MVM_array[16];
  glGetFloatv(GL_MODELVIEW_MATRIX, MVM_array);
  //gmtl::Matrix44f MVM_gmtl;
  //MVM_gmtl.set(MVM_array);
  vl::mat4 MVM_vl(MVM_array);
  mRend[current].get()->camera()->setViewMatrix(MVM_vl);
  
  std::cout << __FILE__ << ":C" << std::endl;

  float PM_array[16];
  glGetFloatv(GL_PROJECTION_MATRIX, PM_array);
  vl::mat4 PM_vl(PM_array);
  mRend[current].get()->camera()->setProjectionMatrix(PM_vl, vl::PMT_PerspectiveProjectionFrustum);

  std::cout << __FILE__ << ":D" << std::endl;

  mRend[current]->renderer()->setClearFlags(vl::CF_DO_NOT_CLEAR);

  std::cout << __FILE__ << ":Ea" << std::endl;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  std::cout << __FILE__ << ":Eb" << std::endl;
  mRend[current].get()->render();
  std::cout << __FILE__ << ":Ec" << std::endl;
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();

  std::cout << __FILE__ << ":F" << std::endl;

}
void VM_MarchingCubes::init(){

  std::cout << __FILE__ << ":init:A" << std::endl;
  
  vl::VisualizationLibrary::init();

  mThreshold = 0.0;
  mThreshold = (data->getMaxValue() - data->getMinValue())*0.5;
  
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

  std::cout << __FILE__ << ":conInit:A." << current << std::endl;

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

  mEffect[current] = new vl::Effect;
  mEffect[current]->shader()->enable(vl::EN_DEPTH_TEST);
  mEffect[current]->shader()->setRenderState( new vl::Light, 0);
  mEffect[current]->shader()->enable(vl::EN_LIGHTING);
  mEffect[current]->shader()->gocMaterial()->setDiffuse(vl::gold);
  mEffect[current]->shader()->gocMaterial()->setSpecular(vl::white);
  mEffect[current]->shader()->gocMaterial()->setShininess(60);
  


  mIsosurfGeom[current] = new vl::Geometry;
  mIsosurfGeom[current]->setVertexArray(mMarchingCubes.mVertsArray.get());
  mIsosurfGeom[current]->setNormalArray(mMarchingCubes.mNormsArray.get());
  mIsosurfGeom[current]->drawCalls()->push_back(mMarchingCubes.mDrawElements.get());

  mActor[current] = new vl::Actor(mIsosurfGeom[current].get(), mEffect[current].get(), mTrans[current].get(), 0,0);
  
  
  mScene[current].get()->tree()->addActor(mActor[current].get());

  mRend[current].get()->renderer()->setFramebuffer(mOGLContext.framebuffer());

  std::cout << __FILE__ << "conInit:B" << std::endl;


}


void VM_MarchingCubes::contextPreDraw(){}
void VM_MarchingCubes::preFrame(){
  
}
void VM_MarchingCubes::intraFrame(){}
void VM_MarchingCubes::postFrame(){}
