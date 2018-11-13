#include "func.h"

void test(void) {
        //
        std::cout << "Test..." << std::endl;
}

//

//cube

	
void DrawScene()
{
float color[] = { 0.1f, 0.6f, 0.1f };
float sz = 1.;
float v[8][3] = { -sz, sz, -sz, sz, sz, -sz, sz, -sz, -sz, -sz, -sz, -sz, -sz, sz, sz, -sz, -sz, sz, sz, -sz, sz, sz, sz, sz };
float norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 };
int id[6][4] =
	{
		0, 1, 2, 3,	// Rear (CCW - counterclockwise)
		4, 5, 6, 7,	// Front
		0, 3, 5, 4,	// Left
		7, 6, 2, 1,	// Right
		0, 4, 7, 1,	// Top
		5, 3, 2, 6,	// Bottom
	};
	
	glNewList(1,GL_COMPILE); 	// Создаем новый список команд OpenGL
	glColor3fv(color);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++)
			glVertex3fv(v[id[i][j]]);
	}
	glEnd();
	glEndList();
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
