#include <fstream>
#include <string>
#include <iostream>


/**
   Config file read test :)
 */
int main(){

  using namespace std;

  ifstream ifs("Config.txt");

  string key;
  string lab;
  int dim;
  string path;

  ifs >> key;
  ifs >> lab;
  ifs >> dim;
  ifs >> path;

  cout << key << ":" << lab << ":" << dim << ":" << path << endl;


  if(key.compare("data")==0)cout << "EQ" << endl;
}
