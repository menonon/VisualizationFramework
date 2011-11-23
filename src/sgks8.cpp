#include <iostream>

double func(int a){
  if(a==0)return NULL;
  else return a*0.1;
}


int main(){
  using namespace std;
  
  cout << func(2) << ":" << func(0) << endl;

  return 0;
  
}
