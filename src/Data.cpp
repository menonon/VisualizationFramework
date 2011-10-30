/**
 *Data.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

#include "Data.h"
#include <fstream>

Data::Data(Config &config,Coordinates &coord){

  this.dimension = config.getDimension();
  this.label = config.getLabel();
  this.path = config.getPath();
  this.coord = coord;


  this.data = new DataArray(boost::extents[dimension][this.coord.getZnum()][this.coord.getYnum()][this.coord.getXnum()]);


  loadData();

}


void Data::loadData(){
  
  int n=0;
  double temp=0.0;
  std::ifstream ifs;  

  for(vector<std::string>::iterator it = path.begin();it!=path.end();it++){
    ifs.open((*it).c_str());
    ifs.seekg(4,std::ios_base::beg);

    for(int i=0; i<coord.getZnum(); i++){
      for(int j=0; j<coord.getYnum(); j++){
	for(int k=0; k<coord.getXnum(); k++){
	  ifs.read((char*)&temp,sizeof(double));
	  data[n][i][j][k] = temp;
	}
      }
    }
    n++;
    ifs.close();
  }
}

DataArray* Data::getData(){
  return data;
}
