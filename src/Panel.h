#pragma once
#include <vlCore/OpenGLDefs.hpp>
#include <GL/gl.h>
#include <gmtl/gmtl.h>
#include <string>
#include <vrj/Draw/OpenGL/ContextData.h>
#include <cairo.h>

class Panel{

 public:
  Panel(double x, double y, double z, double h, double w, double d);
  Panel(double x, double y, double z, double h, double w, double d, std::string n);

  virtual ~Panel();


  virtual void contextInit();
  virtual void init(double x, double y, double z, double h, double w, double d, std::string n);
  virtual void draw();
  virtual void preFrame();
  virtual bool hitTest(gmtl::Point3d point);
  virtual void createNamePanel();

  
  virtual void toggleState();
  virtual bool getState();

  vrj::opengl::ContextData<GLuint> textureId;

 private:
  bool on;
  double pos[3];
  double height,width,depth;
  gmtl::AABoxd testBox;
  std::string name;
  bool hitTestPrevious;

  cairo_surface_t *surface;
  cairo_t *cr;
  int cr_width;
  int cr_height;


  unsigned char* textureImage;



};
