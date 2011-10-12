/**
 *Data.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

#include "Data.h"

Data::Data(Config config){

  this.dimension = config.getDimension();
  this.label = config.getLabel();
  this.path = config.getPath();

  loadData();

}


void Data::loadData(){


}

DataArray Data::getData(){

}
