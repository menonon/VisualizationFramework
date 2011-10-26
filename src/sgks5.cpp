#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(){

  using namespace std;

  ifstream ifs("../data/ABC/flow_energy");
  vector<double> dbl;
  double dbl_temp;

  /*
  if(ifs.is_open()){
    ifs.seekg(4,ios_base::beg);
    
    for(;!ifs.eof();){

      ifs.read((char*)&dbl_temp, sizeof(double));  
      dbl.push_back(dbl_temp);
      
    }

    int i=0;
    for(vector<double>::iterator it = dbl.begin();it != dbl.end();it++){
      cout << i  << ":" <<(*it) << endl;
      i++;
    }


    ifs.close();
    cout << "TRUE" << endl;

  }
  */



  /*
  unsigned long long  num = 1000 * 1000 * 1000 * 10;
  double *largeArray;
  largeArray = (double*)malloc(sizeof(double)*num);
  if(largeArray == NULL)cout << "no malloc" << endl;
  for(unsigned long long i=0;i<num;i+=100){
    largeArray[i] = i;
  }
  cout << largeArray[i] << endl;  
  cin >> num;
  */

  return 0;
}
