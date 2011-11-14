#ifndef __Data_h
#define __Data_h

#include <boost/multi_array.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Config.h"
#include "Coordinates.h"

typedef boost::multi_array<double, 4> DataArray;


/**
 * Data.h
 * @author MENO Daisuke
 * @version developping
 */
class Data{
  
public:
  Data(Config* config,Coordinates* coord);
  ~Data();
  DataArray* getData();
  Coordinates* getCoord();
  
private:
  int dimension;
  std::string label;
  std::vector<std::string> path;
  DataArray *data;

  Coordinates* coord;
  
  void loadData();
  
  
  
  
};

#endif
