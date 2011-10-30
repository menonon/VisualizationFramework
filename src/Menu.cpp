
#include "Menu.h"



Menu::Menu(UserInterface* ui){

  selectedPalette =0;
  selectedData =0;
  selectedVM =0;

  this.ui = ui;

}


Menu::~Menu(){}



void Menu::createPalette(){
  
  allPalette.push_back(new Palette());
  
  allPalette.back().setData(allData.at(selectedData));
  allPalette.back().setVisualizeMethods(allVM.at(selectedVM));
  
}


void Menu::deletePalette(){

  allPalette.pop_back();

}




void Menu::preFrame(){

  

}
