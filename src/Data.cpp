/**
 *Data.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

#include "Data.h"
#include <fstream>
#include <ostream>

Data::Data(Config* config,Coordinates* coord_){

  std::cout << __FILE__ << std::endl;

  dimension = config->getDimension();
  label = config->getLabel();
  path = config->getPath();
  coord = coord_;


  data = new DataArray(boost::extents[dimension][coord->getZnum()][coord->getYnum()][coord->getXnum()]);


  loadData();

}


void Data::loadData(){
  
  std::cout << __FILE__ << ":loadData" <<std::endl;

  int n=0;
  double temp=0.0;
  std::ifstream ifs;  

  for(std::vector<std::string>::iterator it = path.begin();it!=path.end();it++){
    std::cout << (*it).c_str() << std::endl;
    ifs.open((*it).c_str(),std::ios::binary);
    std::cout << (*it).c_str() << std::endl;
    ifs.seekg(4,std::ios::beg);
    std::cout << (*it).c_str() << std::endl;


    std::cout << coord->getZnum() <<  coord->getYnum() <<  coord->getXnum() << std::endl;


    for(int i=0; i<coord->getZnum(); i++){
      for(int j=0; j<coord->getYnum(); j++){
	for(int k=0; k<coord->getXnum(); k++){
	  ifs.read((char*)&temp,sizeof(double));
	  //std::cout << n << ":" <<i << ":" << j << ":" << k << "::" << temp << std::endl;
	  (*data)[n][i][j][k] = temp;
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
