#include "VM_LocalArrows.h"
#include <gmtl/gmtl.h>


VM_LocalArrows::VM_LocalArrows(){
  initName();
  initDimension();
}
VM_LocalArrows::VM_LocalArrows(UserInterfaces* _ui, Data* _data){
  ui = _ui;
  data = _data;
  initName();
  initDimension();
}
VM_LocalArrows::~VM_LocalArrows(){}

VisualizeMethods* VM_LocalArrows::getInstance(){
  VisualizeMethods* ret = new VM_LocalArrows();
  return ret;
}
VisualizeMethods* VM_LocalArrows::getInstance(UserInterfaces* _ui, Data* _data){
  VisualizeMethods* ret = new VM_LocalArrows(_ui,_data);
  return ret;
}
void VM_LocalArrows::initName(){
  name = "Local Arrows";
}
void VM_LocalArrows::initDimension(){
  dimension = 3;
}


void VM_LocalArrows::draw(){
  std::cout << __FILE__ << ":draw" << std::endl;
  glDisable(GL_LIGHTING);
  glLineWidth(3);
  std::vector<double>::iterator itvd = arrowLength.begin();
  for(std::vector<gmtl::Matrix44f>::iterator it=arrowPositionInWorld.begin();it!=arrowPositionInWorld.end();++it){
    glPushMatrix();
      glMultMatrixf((*it).mData);
      glBegin(GL_LINES);
      glColor3f(0,1,1);
      glVertex3d(0,0,0);
      glColor3f(1,1,0);
      glVertex3d(0,0,(*itvd));
      glEnd();
    glPopMatrix();
    itvd++;
  }
  glLineWidth(1);
  glEnable(GL_LIGHTING);


}
void VM_LocalArrows::init(){
  /* create seeds for each local arrow position */

  int ndiv = 2;
  double radius = 0.5;
  double ds = radius/ndiv;

  double x,y,z,r;

  for(int i=-ndiv; i<ndiv; i++){
    for(int j=-ndiv; j<ndiv; j++){
      for(int k=-ndiv; k<ndiv; k++){
	x = i*ds;
	y = j*ds;
	z = k*ds;
	r = sqrt(x*x + y*y + z*z);
	if(r<=radius){
	  gmtl::Vec3f pos(x,y,z);
	  arrowPosition.push_back(pos);
	}
      }
    }
  }
  norm = 0.05 / data->getMaxValue();
  normh = norm / 2.0;
}
void VM_LocalArrows::contextPreDraw(){}
void VM_LocalArrows::preFrame(){


  if(ui->button0 == gadget::Digital::ON){
    gmtl::Matrix44f mattemp;
    gmtl::Vec3f vectemp;

    arrowPositionInWorld.clear();
    arrowLength.clear();

    for(std::vector<gmtl::Vec3f>::iterator it = arrowPosition.begin(); it != arrowPosition.end();++it){
      vectemp = (*it) + gmtl::makeTrans<gmtl::Vec3f>(ui->navWand);
      gmtl::setTrans(mattemp,vectemp);
      
      double direction[3];
      bool exit_status=false;
      for(int i=0;i<3;++i){
	exit_status = !data->getValue(i,vectemp[0],vectemp[1],vectemp[2],direction[i]);
	if(exit_status)break;
      }
      if(exit_status)continue;

      
      gmtl::Vec3f st;
      for(int i=0;i<3;++i){
	st[i] = vectemp[i] - normh * direction[i];
      }
      
      //      gmtl::setTrans(mattemp,st);

      double u[3];
      for(int i=0;i<3;++i){
	u[i] = norm * direction[i];
      }

      double nrmdv = norm * sqrt(direction[0]*direction[0]
				 +direction[1]*direction[1]
				 +direction[2]*direction[2]);

      double r2 = sqrt(u[0]*u[0] + u[1]*u[1]);
      //      double phi = gmtl::Math::rad2Deg(gmtl::Math::aTan2(u[1],u[0]));
      //      double tht = gmtl::Math::rad2Deg(gmtl::Math::aTan2(r2,u[2]));

      double phi = gmtl::Math::aTan2(u[1],u[0]);
      double tht = gmtl::Math::aTan2(r2,u[2]);

      gmtl::setRot(mattemp, gmtl::EulerAngleZYXf(phi,tht,0.0f));


      arrowPositionInWorld.push_back(mattemp);
      arrowLength.push_back(nrmdv);
    }
  }
}

void VM_LocalArrows::intraFrame(){}
void VM_LocalArrows::postFrame(){}
