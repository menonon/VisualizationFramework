#include <boost/multi_array.hpp>


int main(){

  typedef boost::multi_array<double,4> DataArray;

  DataArray *data;

  data = new DataArray(boost::extents[2][3][4][5]);



  



  return 0;

}
