/**
 *Data.cpp
 *@author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
 */

#include "Data.h"
#include <fstream>
#include <ostream>
#include <cstdlib>
#include <cmath>

Data::Data(Config* config,Coordinates* coord_){

  std::cout << __FILE__ << std::endl;

  dimension = config->getDimension();
  label = config->getLabel();
  path = config->getPath();
  coord = coord_;
  maxValue = 0.0;

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
	  if(maxValue < abs(temp))maxValue = temp;
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

Coordinates* Data::getCoord(){
  return coord;
}

bool Data::getValue(int dim, double x_pos,double y_pos,double z_pos,double& ret){
  if(dim>dimension-1)return false;

  int x_index[2]; x_index[0]=coord->getXindex(x_pos); x_index[1]=x_index[0]+1;
  int y_index[2]; y_index[0]=coord->getYindex(y_pos); y_index[1]=y_index[0]+1;
  int z_index[2]; z_index[0]=coord->getZindex(z_pos); z_index[1]=z_index[0]+1;

  if(x_index[0]==-1 || y_index[0]==-1 || z_index[0]==-1){std::cout << "cant get value" << std::endl; return false;}

  double x_coor[2]; x_coor[0]=coord->getX(x_index[0]); x_coor[1]=coord->getX(x_index[1]);
  double y_coor[2]; y_coor[0]=coord->getY(y_index[0]); y_coor[1]=coord->getY(y_index[1]);
  double z_coor[2]; z_coor[0]=coord->getZ(z_index[0]); z_coor[1]=coord->getZ(z_index[1]);

  double volume_all = 1.0/(x_coor[1]-x_coor[0])*(y_coor[1]-y_coor[0])*(z_coor[1]-z_coor[0]);
  double volume_part[2][2][2];
  for(int i=0;i<2;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k)
    volume_part[i][j][k] = 1.0 - volume_all * abs(x_pos-x_coor[i]) * abs(y_pos-y_coor[i]) * abs(z_pos-z_coor[i]);

  double value[2][2][2];
  double ret_=0;
  for(int i=0;i<2;++i)for(int j=0;j<2;++j)for(int k=0;k<2;++k){
    value[i][j][k] = (*data)[dim][z_index[k]][y_index[j]][x_index[i]] * volume_part[i][j][k];
    ret_+=value[i][j][k];
  }

  ret = ret_;
  return true;
}

double Data::getMaxValue(){
  return maxValue;
}
