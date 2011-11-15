#include <vector>
#include <iostream>


void func(double* arr){
  using namespace std;  
  for(int i=0;i<10;++i)cout << i << ":" <<arr[i] << endl;
  
}

int main(){
  using namespace std;
  
  vector<double> arr;
  
  for(int i=0;i<10;++i)arr.push_back(i);



  func(&arr[0]);


  return 0;

}
