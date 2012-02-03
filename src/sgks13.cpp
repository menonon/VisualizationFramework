#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>

#include "Panel.h"

void draw(){
  static Panel* panel = new Panel(0,0,-3,3,3,3);

  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  panel->draw();
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
}

void idle(){
  glutPostRedisplay();
}

void timer(int t){
  glutPostRedisplay();
  glutTimerFunc(t,timer,10);
}

void reshape(int width, int height){
  glViewport(0,0,width,height);
  glLoadIdentity();
  gluPerspective(30.0, (double)width / (double)height, 1.0, 100.0);
}

int main (int argc, char* argv[]){

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);

  glutDisplayFunc(draw);
  glutTimerFunc(0,timer,10);
  glutReshapeFunc(reshape);

  glutMainLoop();

  return 0;


}
