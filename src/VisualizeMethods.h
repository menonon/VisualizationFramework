/**
* VisualizeMethod
* @author MENO Daisuke (menonon@vizlab.cs.kobe-u.ac.jp)
* @version developping
*/

#ifndef __VisualizeMethod_h
#define __VisualizeMethod_h

#include <string>

class VisualizeMethod{
  
public:
  VisualizeMethod();
  ~VisualizeMethod();
  void draw();
  void init();
  void contextInit();
  void preFrame();
  void intraFrame();
  void postFrame();
  

  
private:
  std::string name;
  

  
};
