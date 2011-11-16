
#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
  Base(){using namespace std;cout << "Base Constr" << endl;var=100;}
  Base(int num){std::cout << "Base COnstr(num)" << std::endl;}
  virtual ~Base(){using namespace std;cout << "Base Destr" << endl;}
  virtual void Func(){std::cout<<"BaseFunc"<< var <<std::endl;}
  int var;
};

class Sub:public Base{
public:
  Sub(){using namespace std;cout << "Sub Constr" << endl;var=200;}
  Sub(int num){using namespace std;cout << "Sub COnstr(num)"<<endl;}
  ~Sub(){using namespace std;cout << "Sub Destr" << endl;}
  virtual void Func(){std::cout<<"SubFunc"<< var <<std::endl;}
};


void reference(vector<Base*> &basearray){
  using namespace std;

  vector<Base*>::iterator it = basearray.begin();
  while(it != basearray.end()){
    (*it)->Func();
    std::cout << "--- ---" << std::endl;
    it++;
  }

  vector<Base*> basepoint = basearray;
  vector<Base*>::iterator itt = basepoint.begin();
  while(itt != basepoint.end()){
    (*itt)->Func();
    std::cout << "--- ---" << std::endl;
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
  Base* sub3 = new Sub(5);
  cout << "---" <<endl;

  /* inheritance test */
  std::vector<Base*> baseArray;
  baseArray.push_back(base);
  baseArray.push_back(sub1);
  baseArray.push_back(sub2);
  baseArray.push_back(sub3);

  cout << "!!!!!!!!" << endl;
  vector<Base*>::iterator it = baseArray.begin();
  while(it != baseArray.end()){
    (*it)->Func();
    it++;
  }
  cout << "!!!!!!!!" << endl;


  reference(baseArray);

  cout << "---" <<endl;
  delete base;
  cout << "---" <<endl;
  delete sub1;
  cout << "---" <<endl;
  delete sub2;
  cout << "---" <<endl;
  delete sub3;
  cout << "---" <<endl;


  return 0;
}
