

#ifndef __Coordinates_h
#define __Coordinates_h

#include <vector>
#include <string>

/**
 *Coordinates
 *@author MENO Daisuke
 *@version dev
 */
class Coordinates{

 public:
  Coordinates(std::vector<std::string> path);
  ~Coordinates();

  int getXnum();
  int getYnum();
  int getZnum();

  double getX(int at);
  double getY(int at);
  double getZ(int at);

  void draw();


 private:
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> z;

  void drawBoundingBox();
  void createBoundingBox();
  std::vector<double> boxVertex;
  std::vector<double> boxColor;
};
#endif
