#include <ostream>
#include "Menu.h"



Menu::Menu(UserInterfaces* ui_){

  std::cout << __FILE__ << std::endl;

  selectedPalette =0;
  selectedData =0;
  selectedVM =0;

  ui = ui_;

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




void Menu::preFrame(){

  

}
