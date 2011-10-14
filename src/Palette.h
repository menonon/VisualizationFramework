/**
 *Palette.h
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

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

  bool isEmpty();

 private:
  Data* data;
  VisualizeMethods* vm;  

  
};
