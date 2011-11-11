#include <ostream>
#include "Menu.h"



Menu::Menu(UserInterfaces* ui_){

  std::cout << __FILE__ << std::endl;

  selectedPalette =0;
  selectedData =0;
  selectedVM =0;

  ui = ui_;

  state =0;
}


Menu::~Menu(){}


void Menu::init(std::vector<Data*> &data, std::vector<VisualizeMethods*> &vm){

  allData = data;
  allVM = vm;

}


void Menu::createPalette(){
  
  allPalette.push_back(new Palette());
  
  allPalette.back()->setData(allData.at(selectedData));
  allPalette.back()->setVisualizeMethods(allVM.at(selectedVM));
  
}


void Menu::deletePalette(){

  allPalette.pop_back();

}

void Menu::draw(){

  if(state==0){
    for(std::vector<Palette*>::iterator it = allPalette.begin();it<allPalette.end();++it){
      (*it)->draw();
    }
  }
  else if(state==1){
    /*Draw Menu*/
  }
}


void Menu::preFrame(){
  if(state==1){
    if(ui->button0 == gadget::Digital::TOGGLE_ON)createPalette();
    if(ui->button1 == gadget::Digital::TOGGLE_ON)deletePalette();
    if(ui->button2 == gadget::Digital::TOGGLE_OFF)state=0;
  }
  else if(state==0){
    if(ui->button2 == gadget::Digital::TOGGLE_ON)state=1;
  }
  


  for(std::vector<Palette*>::iterator it = allPalette.begin();it<allPalette.end();++it){
    (*it)->preFrame();
  }

}

void Menu::intraFrame(){
  for(std::vector<Palette*>::iterator it = allPalette.begin();it<allPalette.end();++it){
    (*it)->intraFrame();
  }
}
