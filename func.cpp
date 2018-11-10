#include "func.h"

void test(void) {
        //
        std::cout << "Test..." << std::endl;
}

//
void meSolidCube(float s) {
  //face
  glBegin(GL_QUADS);
   glColor3d(0,1,0);
   glVertex3d(-s,-s, s);
   glVertex3d(-s, s, s); 
   glVertex3d( s, s, s);
   glVertex3d( s,-s, s);
  glEnd();
  // back
  glBegin(GL_QUADS);
   glColor3d(0,0,1);
   glVertex3d(-s, -s,-s);
   glVertex3d(-s, s, -s);  
   glVertex3d( s, s, -s); 
   glVertex3d( s,-s, -s);
  glEnd();
  //right
  glBegin(GL_QUADS);
   glColor3d(1,1,0);
   glVertex3d(s,-s, s);
   glVertex3d(s, s, s); 
   glVertex3d(s, s, -s);
   glVertex3d(s,-s, -s);
  glEnd();
  
  //left
  glBegin(GL_QUADS);
   glColor3d(1,0,0);
   glVertex3d(-s,-s, s);
   glVertex3d(-s, s, s); 
   glVertex3d(-s, s, -s);
   glVertex3d(-s,-s, -s);
  glEnd(); 
  
  //top
  glBegin(GL_QUADS);
   glColor3d(0,0,0);
   glVertex3d(-s,-s, s);
   glVertex3d( s,-s, s); 
   glVertex3d( s,-s, -s);
   glVertex3d(-s,-s, -s);
  glEnd();
    //bottom
  glBegin(GL_QUADS);
   glColor3d(0,1,1);
   glVertex3d(-s, s, s);
   glVertex3d( s, s, s); 
   glVertex3d( s, s, -s);
   glVertex3d(-s, s, -s);
  glEnd();
  
}

//
void meSolidCube(float left, float top, float right, float bottom) {
  glBegin(GL_QUADS);
   glColor3d(1,0,0);
   glVertex3d(left,top, 0);
   glColor3d(0,1,0);
   glVertex3d(left,bottom, 0); 
   glColor3d(1,1,1);
   glVertex3d(right,bottom, 0);
   glColor3d(0,0,1);
   glVertex3d(right,top,0 );
  glEnd();      
}
