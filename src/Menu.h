/**
 *  Menu.h
 * @author MENO Daisuke
 * @version dev
 **/

#ifndef __Menu_h
#define __Menu_h

#include <vector>
#include <algorithm>

#include "Data.h"
#include "VisualizeMethods.h"
#include "Palette.h"
#include "UserInterfaces.h"
#include <gadget/Type/DigitalInterface.h>
#include "Panel.h"
#include "VisualizeMethodsFactory.h"

class Menu{

 public:
  Menu(UserInterfaces* ui);
  ~Menu();

  void createPalette();
  void deletePalette();

  void createPanel();

  //void selectData(int num);
  //void selectVM(int num);

  
  void init(std::vector<Data*> &data, std::vector<VisualizeMethods*> &vm);
  void draw();
  void preFrame();
  void intraFrame();
  void contextInit();
  void contextPreDraw();

  void setDrawPalette(int paletteNnm);
  void unsetDrawPalette(int paletteNum);
  void setPreFramePalette(int paletteNum);
  void unsetPreFramePalette(int paletteNum);
  void setIntraFramePalette(int paletteNum);
  void unsetIntraFramePalette(int paletteNum);
  
 private:
  
  VisualizeMethodsFactory vmf;

  std::vector<int> drawPalette;
  std::vector<int> preFramePalette;
  std::vector<int> intraFramePalette;

  std::vector<Panel*> visiblePanel;
  std::vector<Panel*> preFramePanel;
  std::vector<Panel*> intraFramePanel;

  //deprecated variables
  //int selectedPalette;
  //int selectedData;
  //int selectedVM;

  enum state{ON, OFF};
  state menuState;

  std::vector<Data*> allData;
  std::vector<VisualizeMethods*> allVM;
  std::vector<Palette*> allPalette;

  void preFrameMenu();
  void drawMenu();
  void intraFrameMenu();

  UserInterfaces* ui;

};
#endif
