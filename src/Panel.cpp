#include "Panel.h"

Panel::Panel(double x, double y, double z, double h, double w, double d){
    std::string n = "No Name";

    init(x,y,z,h,w,d,n);
}

Panel::Panel(double x, double y, double z, double h, double w, double d, std::string n){
    init(x,y,z,h,w,d,n);
}

void Panel::init(double x, double y, double z, double h, double w, double d, std::string n){  

  pos[0] = x;
  pos[1] = y;
  pos[2] = z;
  
  height = h;
  width = w;
  depth = d;

  gmtl::Point3d min(x-w*0.5, y-h*0.5, z-d);
  gmtl::Point3d max(x+w*0.5, y+h*0.5, z);

  std::cout << __FILE__ << ":min,max:" << min << ":" << max <<std::endl; 

  testBox.setMin(min);
  testBox.setMax(max);
  testBox.setEmpty(false);

  on=false;
  hitTestPrevious = false;

  name = n;


  createNamePanel();

}

void Panel::contextInit(){

    glGenTextures(1, &(*textureId));
}


void Panel::createNamePanel(){

    std::cout << __FILE__ << "createNamePanel : " << name << std::endl;

    cr_width = static_cast<int>(width*1000);
    cr_height = static_cast<int>(height*1000);

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, cr_width, cr_height);
    cr = cairo_create(surface);

    cairo_text_extents_t te;
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);

    cairo_set_line_width(cr, 10);
    cairo_rectangle(cr, 0.0,0.0,cr_width,cr_height);
    cairo_stroke(cr);
    cairo_set_line_width(cr, 0);
    cairo_select_font_face(cr, "Gerorgia", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 100);
    cairo_text_extents(cr, name.c_str(), &te);
    cairo_move_to(cr, cr_width*0.5 - te.width*0.5 - te.x_bearing, cr_height*0.5 - te.height*0.5 - te.y_bearing);
    cairo_show_text(cr, name.c_str());

    cairo_surface_flush(surface);

//    cairo_surface_write_to_png(surface, name.c_str());
    textureImage = cairo_image_surface_get_data(surface);

}


Panel::~Panel(){}


void Panel::draw(){

    glBindTexture(GL_TEXTURE_RECTANGLE, (*textureId));
    glTexImage2D(GL_TEXTURE_RECTANGLE, 0, GL_RGBA, cr_width, cr_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureImage);

    glEnable(GL_BLEND);

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_RECTANGLE);

    if(on) glColor3d(0,1,0);
    else glColor3d(1,0,0);

    glBegin(GL_POLYGON);
    glTexCoord2f(cr_width,0.0);
    glVertex3d(pos[0]+width*0.5, pos[1]+height*0.5, pos[2]);
    glTexCoord2f(0.0,0.0);
    glVertex3d(pos[0]-width*0.5, pos[1]+height*0.5, pos[2]);
    glTexCoord2f(0.0,cr_height);
    glVertex3d(pos[0]-width*0.5, pos[1]-height*0.5, pos[2]);
    glTexCoord2f(cr_width,cr_height);
    glVertex3d(pos[0]+width*0.5, pos[1]-height*0.5, pos[2]);
    glEnd();


    glDisable(GL_TEXTURE_RECTANGLE);
    glBindTexture(GL_TEXTURE_RECTANGLE, 0);
    glEnable(GL_LIGHTING);
    


/*
  if(on) glColor3d(0,1,1);
  else glColor3d(1,1,0);
*/
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT1);
//  glDisable(GL_LIGHTING);
//  glDisable(GL_LIGHT0);
}

void Panel::preFrame(){
/* update */

}

bool Panel::hitTest(gmtl::Point3d point){

  bool present = gmtl::isInVolume(testBox,point);
//  return present;
  

  //when in->out ,recognizing "TOUCH"
  std::cout << __FILE__ << ":Previous,Present:" << hitTestPrevious << present << std::endl;
  if(hitTestPrevious == true && present == false){
    hitTestPrevious = present;
    return true;
  }
  hitTestPrevious = present;
  std::cout << __FILE__ << "no hit" << std::endl;
  return false;

}

void Panel::toggleState(){
  if(on == true)on=false;
  else on=true;
}

bool Panel::getState(){
  return on;
}
