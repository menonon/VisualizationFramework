#include <boost/multi_array.hpp>
#include <iostream>

int main(){

  typedef boost::multi_array<double,4> DataArray;

  DataArray *data;

  data = new DataArray(boost::extents[2][3][4][5]);

  DataArray daaaa(boost::extents[5][5][5][5]);
  daaaa[0][0][0][0] = 1.0;


  (*data)[0][0][0][0] = 1.0;

  std::cout << daaaa[0][0][0][0] << std::endl;
  std::cout << (*data)[0][0][0][0] << std::endl;



  return 0;

}
