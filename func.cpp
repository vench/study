#include "func.h"





//
uint nRings = 100, 
        nSects = 100,  
        nTria,         nVert; 

 



//
void DrawScene()
{ 
        glNewList(1, GL_COMPILE);
	DrawPoints();
	DrawPlane();
	DrawObjects();
	glEndList();
}
 
//
void DrawPoints()
{
	srand(time(0));
	glPointSize(5);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	for (int i = 0; i < 150; i++)
	{
		int
			x = rand() % 60 - 30,
			y = rand() % 30,
			z = rand() % 200 - 100;
		glVertex3f(x, y, z);
		glVertex3f(x, -y, z);
	}
	glEnd();
	glEnable(GL_LIGHTING);
} 

//
void DrawPlane()
{
	glColor3f(0, 0.5, 0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-5, 0, 5); glVertex3f(5, 0, 5); glVertex3f(5, 0, -15); glVertex3f(-5, 0, -15);
	glEnd();

	glColor3f(1, 1, 1);
	glDisable(GL_LIGHTING);
	glLineWidth(2);
	glBegin(GL_LINES);
	for (float x = -4.4; x < 5.5; x += 0.4)
	{
		glVertex3f(x, 0.02, 5);
		glVertex3f(x, 0.02, -15);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}
 
//
void DrawObjects() {
        glColor3f(0.8,0.6,0.4); 
	glTranslatef(-3,0.25,0); glutSolidCube(0.5);
	glTranslatef(0,0,-5);    glutSolidCube(0.5);	// -3, 0.25, -5
	glTranslatef(6,0,0);     glutSolidCube(0.5);	// 3, 0.25, -5
	glTranslatef(0,0,5);     glutSolidCube(0.5);	// 3, 0.25, 0
	
	glColor3f(0.4,0.2,0.1);
	glTranslatef(0,0.25,0); glRotatef(-90,1,0,0); glutSolidCone(0.28,1,16,16); glRotatef(90,1,0,0); 	// 3, 0.5, 0
	glTranslatef(0,0,-5);   glRotatef(-90,1,0,0); glutSolidCone(0.28,1,16,16); glRotatef(90,1,0,0); // 3, 0.5, -5
	glTranslatef(-6,0,0);   glRotatef(-90,1,0,0); glutSolidCone(0.28,1,16,16); glRotatef(90,1,0,0); // -3, 0.5, -5 
	glTranslatef(0,0,5);    glRotatef(-90,1,0,0); glutSolidCone(0.28,1,16,16); glRotatef(90,1,0,0); // -3, 0.5, 0
	glColor3f(0.6,0,0); 
	glTranslatef(0,-0.23,-9); glRotatef(-90,1,0,0); glutSolidTorus(0.27,0.8,16,16); glRotatef(90,1,0,0);// -3,0.27, -14
	glTranslatef(6,0,0);      glRotatef(-90,1,0,0); glutSolidTorus(0.27,0.8,16,16); glRotatef(90,1,0,0);// 3,0.27,-14
	glColor3f(0,0.2,1);
	
	glTranslatef(0,9,-10);  glutSolidSphere(3, 20, 20); // 3,9.27,-24 
	glColor3f(1,0.2,1);
	glTranslatef(-3,11,-20);  glutSolidSphere(3, 20, 20); // 0,20.27,-44 
	glColor3f(0.7,0.2,0.3);
	glTranslatef(-17,0,-2);  glutSolidSphere(1, 20, 20); // -17,20.27,-46
	glColor3f(0.7,0.8,0.3);
	glTranslatef(-17,0,-500);  glutSolidSphere(1, 20, 20); // -17,20.27,-46
	glTranslatef(-17,0,-1000);  glutSolidSphere(1, 20, 20); // -17,20.27,-46
} 


// 
 
