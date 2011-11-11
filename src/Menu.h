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
#include <gadget/Type/DigitalInterface.h>

class Menu{

 public:
  Menu(UserInterfaces* ui);
  ~Menu();

  void createPalette();
  void deletePalette();

  void selectData(int num);
  void selectVM(int num);

  
  void init(std::vector<Data*> &data, std::vector<VisualizeMethods*> &vm);
  void draw();
  void preFrame();
  void intraFrame();

 private:

  int selectedPalette;
  int selectedData;
  int selectedVM;

  int state;

  std::vector<Data*> allData;
  std::vector<VisualizeMethods*> allVM;
  std::vector<Palette*> allPalette;


  UserInterfaces* ui;

};
#endif
