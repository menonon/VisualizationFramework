#include <ostream>
#include "Menu.h"
#include "VM_Test.h"
#include "VM_ParticleTracer.h"
#include "VM_LocalArrows.h"

Menu::Menu(UserInterfaces* ui_){

  std::cout << __FILE__ << std::endl;

  //  selectedPalette =0;
  //  selectedData =0;
  //  selectedVM =0;

  ui = ui_;

  menuState =OFF;
}


Menu::~Menu(){}


void Menu::init(std::vector<Data*> &data, std::vector<VisualizeMethods*> &vm){

  allData = data;
  allVM = vm;

  

  createPalette();

  createPanel();

}


void Menu::createPalette(){

  for(std::vector<Data*>::iterator itd=allData.begin(); itd!=allData.end(); itd++){
    for(int i=0; i< vmf.VM.size(); i++){
      VisualizeMethods* vmtemp = vmf.getVM(i,ui,(*itd));
      vmtemp->init();
      allVM.push_back(vmtemp);
      Palette* ptemp = new Palette();
      ptemp->setData((*itd));
      ptemp->setVisualizeMethods(vmtemp);
      allPalette.push_back(ptemp);
    }
  }


}


void Menu::createPanel(){
  
  int dataSize = allData.size();
  int VMSize = vmf.VM.size();

  int halfDataSize = dataSize/2;
  int halfVMSize = VMSize/2;

  for(int d=halfDataSize; d > -halfDataSize; d--){
    for(int v=-halfVMSize; v < halfVMSize; v++){
      
      Panel* vtemp = new Panel(v-0.3, d, 0, 0.3, 0.3, 0.3);
      visiblePanel.push_back(vtemp);

      Panel* pretemp = new Panel(v, d, 0, 0.3, 0.3, 0.3);
      preFramePanel.push_back(pretemp);
      
      Panel* intratemp = new Panel(v+0.3, d, 0, 0.3, 0.3, 0.3);
      intraFramePanel.push_back(intratemp);
    }
  }
  
}


void Menu::deletePalette(){

  allPalette.pop_back();

}

void Menu::draw(){


  if(menuState==OFF){
    for(std::vector<int>::iterator it = drawPalette.begin(); it!=drawPalette.end();it++){
      allPalette.at((*it))->draw();
    }
  }
  else if(menuState==ON){
    /*Draw Menu*/
    drawMenu();
  }
}


void Menu::preFrame(){
  //  std::cout << __FILE__ << ":state:" << state <<std::endl;


  //toggle menu state
  if(ui->button2 == gadget::Digital::TOGGLE_OFF){
    switch(menuState){
    case ON:menuState = OFF;break;
    case OFF:menuState = ON;break;
    }
  }
  
  
  
  if(menuState==ON){
    preFrameMenu();
  }
  else if(menuState==OFF){    
    for(std::vector<int>::iterator it = preFramePalette.begin(); it!=preFramePalette.end();it++){
      allPalette.at((*it))->preFrame();
    }
  }
  
}

void Menu::intraFrame(){

  if(menuState == ON){
    intraFrameMenu();
  }

  else if(menuState == OFF){
    for(std::vector<int>::iterator it = intraFramePalette.begin(); it!=intraFramePalette.end();it++){
      allPalette.at((*it))->intraFrame();
    }
  }
}

void Menu::contextInit(){}

void Menu::contextPreDraw(){
  for(std::vector<Palette*>::iterator it = allPalette.begin();it<allPalette.end();++it){
    (*it)->contextPreDraw();
  }
}


void Menu::preFrameMenu(){
  /* process device input for menu state ON*/

  /* hit test & set or unset preFramePalette*/

  gmtl::Point3d wandpos = gmtl::makeTrans<gmtl::Point3d>(ui->navWand);

  int i=0;
  for(std::vector<Panel*>::iterator it = visiblePanel.begin(); it!=visiblePanel.end();it++){
    if((*it)->hitTest(wandpos)){
      (*it)->toggleState();
      if((*it)->getState())setDrawPalette(i);
      else unsetDrawPalette(i);
    }
    i++;
  }

  i=0;
  for(std::vector<Panel*>::iterator it = preFramePanel.begin(); it!=preFramePanel.end();it++){
    if((*it)->hitTest(wandpos)){
      (*it)->toggleState();
      if((*it)->getState())setPreFramePalette(i);
      else unsetPreFramePalette(i);
    }
    i++;
  }

  i=0;
  for(std::vector<Panel*>::iterator it = intraFramePanel.begin(); it!=intraFramePanel.end();it++){
    if((*it)->hitTest(wandpos)){
      (*it)->toggleState();
      if((*it)->getState())setIntraFramePalette(i);
      else unsetIntraFramePalette(i);
    }
    i++;
  }


}

void Menu::drawMenu(){
  /*draw menu panels*/

  for(std::vector<Panel*>::iterator it = visiblePanel.begin(); it != visiblePanel.end(); it++){
    (*it)->draw();
  }

  for(std::vector<Panel*>::iterator it = preFramePanel.begin(); it != preFramePanel.end(); it++){
    (*it)->draw();
  }

  for(std::vector<Panel*>::iterator it = intraFramePanel.begin(); it != intraFramePanel.end(); it++){
    (*it)->draw();
  }

}


void Menu::setDrawPalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(drawPalette.begin(), drawPalette.end(), paletteNum);
  if(it==drawPalette.end())drawPalette.push_back(paletteNum);
}

void Menu::unsetDrawPalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(drawPalette.begin(), drawPalette.end(), paletteNum);
  if(it!=drawPalette.end())drawPalette.erase(it);
}

void Menu::setPreFramePalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(preFramePalette.begin(), preFramePalette.end(), paletteNum);
  if(it==preFramePalette.end())preFramePalette.push_back(paletteNum);
}

void Menu::unsetPreFramePalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(preFramePalette.begin(), preFramePalette.end(), paletteNum);
  if(it!=preFramePalette.end())preFramePalette.erase(it);
}

void Menu::setIntraFramePalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(intraFramePalette.begin(), intraFramePalette.end(), paletteNum);
  if(it==intraFramePalette.end())intraFramePalette.push_back(paletteNum);
}

void Menu::unsetIntraFramePalette(int paletteNum){
  std::vector<int>::iterator it;
  it = std::find(intraFramePalette.begin(), intraFramePalette.end(), paletteNum);
  if(it!=intraFramePalette.end())intraFramePalette.erase(it);
}


void Menu::intraFrameMenu(){
}
