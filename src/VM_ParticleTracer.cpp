#include "VM_ParticleTracer.h"
#include <gadget/Type/DigitalInterface.h>
#include <gmtl/Matrix.h>
#include <gmtl/Vec.h>
#include <GL/gl.h>

VM_ParticleTracer::VM_ParticleTracer(){}
VM_ParticleTracer::VM_ParticleTracer(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
}
VM_ParticleTracer::~VM_ParticleTracer(){}

void VM_ParticleTracer::draw(){
  /* draw points and lines*/
  
  
  glEnableClientState(GL_VERTEX_ARRAY);

  for(std::vector<std::vector<double> >::iterator vvdit=tracers.begin();vvdit!=tracers.end();++vvdit){
    //    glColor3f(0,0,0);
    glColor3f(1,1,1);
    glVertexPointer(3,GL_DOUBLE,0,&((*vvdit)[0]));
    glDisable(GL_LIGHTING);
    glDrawArrays(GL_LINE_STRIP,0,((*vvdit).size())/3);
    glEnable(GL_LIGHTING);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}
void VM_ParticleTracer::init(){}
void VM_ParticleTracer::contextPreDraw(){}

void VM_ParticleTracer::preFrame(){
  /* set initial points from device info */
    
  if(ui->button1 == gadget::Digital::TOGGLE_OFF){
    double pos[3];
    double posw[3];
//    for(int i=0;i<3;++i) pos[i] = ui->wand[i][3];
    for(int i=0;i<3;++i) posw[i] = ui->navWand[i][3];
//    std::cout << "wand pos:" << pos[0] <<"," << pos[1] << "," << pos[2] << std::endl;
    std::cout << "wand pos:" << posw[0] <<"," << posw[1] << "," << posw[2] << std::endl;
    
    std::vector<double> vd;
    for(int i=0;i<3;++i) vd.push_back(posw[i]);
    
    tracers.push_back(vd);
  }
  if(ui->button2 == gadget::Digital::ON)tracers.clear();
}
void VM_ParticleTracer::intraFrame(){
  /* integrate trace lines */
  integrate();
}
void VM_ParticleTracer::postFrame(){}

void VM_ParticleTracer::integrate(){
  
  for(std::vector<std::vector<double> >::iterator vvdit=tracers.begin();vvdit!=tracers.end();vvdit++){
    std::vector<double>::iterator vdit = (*vvdit).end();

    double curt[3];
    for(int i=2;i>=0;--i){
      vdit--;
      curt[i] = (*vdit);
    }
    
    const double dt = 0.01;
    bool exit_status=false;

    double k1[3];
    for(int i=0;i<3;++i){
      exit_status = !data->getValue(i,curt[0],curt[1],curt[2], k1[i]);
      if(exit_status)break;
      k1[i]*=dt;
    }
    if(exit_status)continue;

    double k2[3];
    for(int i=0;i<3;++i){
      exit_status = !data->getValue(i, curt[0]+k1[0]*0.5, curt[1]+k1[1]*0.5, curt[2]+k1[2]*0.5, k2[i]);
      if(exit_status)break;
      k2[i]*=dt;
    }
    if(exit_status)continue;
    
    double k3[3];
    for(int i=0;i<3;++i){
      exit_status = !data->getValue(i, curt[0]+k2[0]*0.5 ,curt[1]+k2[1]*0.5, curt[2]+k2[2]*0.5, k3[i]);
      if(exit_status)break;
      k3[i]*=dt;
    }
    if(exit_status)continue;

    double k4[3];
    for(int i=0;i<3;++i){
      exit_status = !data->getValue(i, curt[0]+k3[0] ,curt[1]+k3[1], curt[2]+k3[2], k4[i]);
      if(exit_status)break;
      k4[i]*=dt;
    }
    if(exit_status)continue;

    double next[3];
    const double one_sixth = 1.0/6.0;
    for(int i=0;i<3;++i){
      next[i] = curt[i] + one_sixth * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
      (*vvdit).push_back(next[i]);
      std::cout << next[i] << ",";
    }
    std::cout << std::endl;
  }
}
