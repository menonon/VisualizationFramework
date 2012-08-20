#include <iostream>
#include <string>

/** class inheritace test */

class first{
public:
  first(){f_print();}
  virtual void f_print(){std::cout << "first" << std::endl;}

private:
  int f_a;
};

class second :public first{
public:
  second(){f_print();}
  void f_print(){std::cout << "second" << std::endl;}
private:
  int s_a;
};

class third :public second{
public:
  third(){f_print();}
  void f_print(){std::cout << "third" << std::endl;}
private:
  int t_a;
};


int main(){

  first* t = new third();
  t->f_print();

  int x=3,y=4,z=5;

  for(int i=0;i<z;i++)for(int j=0;j<y;j++)for(int k=0;k<x;k++)std::cout << x*y*i + x*j + k << std::endl;


  return 0;
}
