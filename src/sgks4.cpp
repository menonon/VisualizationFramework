
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base{
public:
  Base(){using namespace std;cout << "Base Constr" << endl;var=100;}
  Base(int num){std::cout << "Base COnstr(num)" << std::endl;}
  virtual ~Base(){using namespace std;cout << "Base Destr" << endl;}
  virtual void Func(){std::cout<<"BaseFunc"<< var <<std::endl;}
  virtual std::string getName(){return name;}
  int var;
  static std::string name;
  virtual Base* getInstance(){Base* ret = new Base();return ret;};
};

std::string Base::name = "Basename";

class Sub:public Base{
public:
  Sub(){using namespace std;cout << "Sub Constr" << endl;var=200;}
  Sub(int num){using namespace std;cout << "Sub COnstr(num)"<<endl;}
  ~Sub(){using namespace std;cout << "Sub Destr" << endl;}
  virtual void Func(){std::cout<<"SubFunc"<< var <<std::endl;}
  const static std::string subname;
  virtual std::string getName(){return subname;}
  virtual Base* getInstance(){Sub* ret=new Sub();return ret;}
};

const std::string Sub::subname = "Subname";

class Subb:public Base{
public:
  Subb(){using namespace std;cout << "Subb Constr" << endl;var=200;}
  Subb(int num){using namespace std;cout << "Subb COnstr(num)"<<endl;}
  ~Subb(){using namespace std;cout << "Subb Destr" << endl;}
  virtual void Func(){std::cout<<"SubbFunc"<< var <<std::endl;}
  const static std::string subname;
  virtual std::string getName(){return subname;}
};

const std::string Subb::subname = "Subbname";


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


  cout << base->name << "," << Base::name << endl;
  cout << sub1->name << "," << Sub::name << endl;
  sub1->name = "Sub";
  cout << base->name << "," << Base::name << endl;
  cout << sub1->name << "," << Sub::name << endl << endl;

  cout << Sub::subname << "," << Subb::subname << endl;
  for(vector<Base*>::iterator it = baseArray.begin(); it!=baseArray.end();it++){
    cout << (*it)->getName() << endl;
  }
  
  Base* base2 = base->getInstance();
  cout << "getInstance:" << base2->name << endl;


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
