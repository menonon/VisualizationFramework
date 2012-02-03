#include <iostream>




class sgks12{

public:

  sgks12(){
    now = OFF;
    previous = OFF;
  }


  void toggleState(){
    previous = now;

    switch(now){
    case ON:now=OFF;break;
    case OFF:now=ONOFF;break;
    case ONOFF:now=OFFON;break;
    case OFFON:now=ON;break;
    }


    /*
    if(now==ON)now=OFF;
    else if(now==OFF)now=ONOFF;
    else if(now==ONOFF)now=OFFON;
    else if(now==OFFON)now=ON;
    */

    std::cout << now << std::endl;
    //    return now;
  };


private:


  enum state{ON, OFF, ONOFF, OFFON};


  state now;
  state previous;


};


int main(){

  sgks12 ins;
  
  for(int i=0; i<10; i++){
    //    std::cout << ins.toggleState() << std::endl;
    ins.toggleState();
  }

  return 0;

}
