/**
 *Palette.h
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

#ifndef __Palette_h
#define __Palette_h

#include "Data.h"
#include "VisualizeMethods.h"


class Palette{
 public:
  Palette();
  ~Palette();

  void setData(Data* data);
  void setVisualizeMethods(VisualizeMethods* vm);

  void removeData();
  void removeVisualizeMethods();

  bool isFull();

  void draw();
  void preFrame();
  void intraFrame();
  void contextPreDraw();


 private:
  Data* data;
  VisualizeMethods* vm;  

  
};

#endif
