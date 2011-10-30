#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

int main(){

  using namespace std;

  ifstream ifs("../data/dynamo/dynamo.x");
  vector<double> dbl;
  double dbl_temp;

  
  // Binary numerical data read test
  
  if(ifs.is_open()){
    ifs.seekg(4,ios_base::beg);
    
    for(int i=1;!ifs.eof();i++){

      ifs.read((char*)&dbl_temp, sizeof(double));  
      dbl.push_back(dbl_temp);
      //      if(i>7900000)
      cout << dbl.size() << " : " << dbl.capacity() << " : " << dbl.at(i-1) <<endl;
      
    }

    dbl.pop_back();
    cout << dbl.size() << " : " << dbl.capacity()  <<endl;
    

    /*
    int i=0;
    for(vector<double>::iterator it = dbl.begin();it != dbl.end();it++){
      cout << i  << ":" <<(*it) << endl;
      i++;
    }
    */

    ifs.close();
    cout << "TRUE" << endl;

  }
  


  // Large Memory Alocation Test
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
