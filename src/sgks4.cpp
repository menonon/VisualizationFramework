
#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
  Base(){using namespace std;cout << "Base Constr" << endl;}
  virtual void Func(){std::cout<<"BaseFunc"<<std::endl;}
};

class Sub:public Base{
public:
  Sub(){using namespace std;cout << "Sub Constr" << endl;}
  Sub(int num){using namespace std;cout << "Sub COnstr(num)"<<endl;}
  virtual void Func(){std::cout<<"SubFunc"<<std::endl;}
};


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
  

  return 0;
}
