#include "Data.hpp"

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
