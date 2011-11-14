
#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
  Base(){using namespace std;cout << "Base Constr" << endl;var=100;}
  virtual void Func(){std::cout<<"BaseFunc"<< var <<std::endl;}
  int var;
};

class Sub:public Base{
public:
  Sub(){using namespace std;cout << "Sub Constr" << endl;var=200;}
  Sub(int num){using namespace std;cout << "Sub COnstr(num)"<<endl;}
  virtual void Func(){std::cout<<"SubFunc"<< var <<std::endl;}
};


void reference(vector<Base*> &basearray){
  using namespace std;

  vector<Base*>::iterator it = basearray.begin();
  while(it != basearray.end()){
    (*it)->Func();
    it++;
  }

  vector<Base*> basepoint = basearray;
  vector<Base*>::iterator itt = basepoint.begin();
  while(itt != basepoint.end()){
    (*itt)->Func();
    itt++;
  }

  
  
}

int main(){
  using namespace std;

  /* constructor test */
  cout << "---" <<endl;
  Base* base = new Base();
  cout << "---" <<endl;
  Sub* sub1 = new Sub();
  cout << "---" <<endl;
  Sub* sub2 = new Sub(4);
  cout << "---" <<endl;

  /* inheritance test */
  std::vector<Base*> baseArray;
  baseArray.push_back(base);
  baseArray.push_back(sub1);
  baseArray.push_back(sub2);

  vector<Base*>::iterator it = baseArray.begin();
  while(it != baseArray.end()){
    (*it)->Func();
    it++;
  }
  
  reference(baseArray);


  return 0;
}
