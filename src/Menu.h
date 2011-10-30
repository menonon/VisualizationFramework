/**
 *  Menu.h
 * @author MENO Daisuke
 * @version dev
 **/

#ifndef __Menu_h
#define __Menu_h

#include <vector>

#include "Data.h"
#include "VisualizeMethods.h"
#include "Palette.h"
#include "UserInterfaces.h"


class Menu{

 public:
  Menu(UserInterfaces* ui);
  ~Menu();

  void createPalette();
  void deletePalette();

  void selectData(int num);
  void selectVM(int num);

  

  void preFrame();

 private:

  int selectedPalette;
  int selectedData;
  int selectedVM;


  std::vector<Data> allData;
  std::vector<VisualizeMethods> allVM;
  std::vector<Palette> allPalette;


  UserInterfaces* ui;

};
#endif
