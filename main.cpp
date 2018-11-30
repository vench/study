//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
#include "func.h"
 
float sun, year, day, moon;		// Углы вращения
float
        speedX, speedY,
        rotMatrix[16] = { 
                1, 0, 0, 0, 
                0, 1, 0, 0, 
                0, 0, 1, 0, 
                0, 0, 0, 1 
                },  
	dx=0.1f, dy=.0, dz = -4.0f, 
	spec[] = {0.9f,0.9f,0.9f},
	speed = .1;
short posX, posY,deep; // Текущая позиция указателя мыши
bool leftButton, twoSide, normale=1,deepType=0,normaleLine=0; 
int maxDeep = 6;

//
void addRotation(float angle, float x, float y, float z)
{
        glPushMatrix();
        glLoadIdentity();
        glRotatef(angle, x, y, z);
        glMultMatrixf(rotMatrix);
        glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
        glPopMatrix();
}

//
void displayMe(void) {
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();	// Запоминаем единичное значение ММ в стеке
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix); // Изменяем ММ

	glColor3f(1, 1, 1);
	glRotatef(sun, 1, 1, 1);	// Вращаем систему координат
	glutWireSphere(1,20,20);	// Рисуем Солнце

	// Операция со стеком (Ваш код)
	glRotatef(year, 0, 1, 0);	// Вращаем систему координат
	glTranslatef(2, 0, 0);	// Смещаем вправо (Землю)

	// Операция со стеком (Ваш код)
	glRotatef(day, 0, 0, 1);	// Вращаем в смещенной системе

	glutWireSphere(0.3,20,20); // Рисуем Землю

	// Операция со стеком (Ваш код)
	glRotatef(moon, 1, 0, 0);	// Вращаем систему координат
	glTranslatef(0, 0.45, 0);		// Смещаем вверх (луну)

	glutWireSphere(0.08,20,20);  // Рисуем Луну
	glPopMatrix();		// Восстанавливаем единичное значение из стека
	glutSwapBuffers(); 
}

//
void reshapeMe(int w, int h) {
        glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35, float(w) / h, .1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
}

void initOpenGl() {
glClearColor(1, 1, 1, 0);
	glShadeModel(GL_SMOOTH); //
	glEnable(GL_DEPTH_TEST);  
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL); 
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
        glMateriali(GL_FRONT, GL_SHININESS, 128); 
        glEnable( GL_LIGHTING); 
        glLineWidth(3); 
        DrawScene();
}
 

 

 

//
void onKeyboardFunc(byte key, int x, int y )
{       
         
	glutPostRedisplay();
} 

//
void onIdle() {
        addRotation(speedY * .1, 0, 1, 0);
        addRotation(speedX * .1, 1, 0, 0);
        
        
        
        glutPostRedisplay(); 
}

//
void onSpecialKey(int key, int x, int y ){
        switch(key) {
	        case 102:
	                dx += speed;
	        break;
	        case 100:
	                dx -= speed;
	        break;   
	        case 101:
	                dy += speed;
	        break;
	        case 103:
	                dy -= speed;
	        break;     
        } 
	glutPostRedisplay(); 
}

//
void onMouse(int button, int state, int x, int y){ 
        leftButton = button == GLUT_LEFT_BUTTON;
	
	if (state == GLUT_DOWN)	{	         
	      speedX = speedY = 0;
	      glutIdleFunc(0);   
	}	else { 
              if(fabs(speedY) > 1. || fabs(speedX) > 1.) {
                glutIdleFunc(onIdle);
              }      	      
	}
	posX = x;	// Запоминаем координаты мыши
        posY = y;
}

//
void onMouseMove(int x, int y)
{  
        speedX = y-posY;
        speedY = x-posX;
        
	if (leftButton) {
		addRotation(speedY * .1, 0, 1, 0);
                addRotation(speedX * .1, 1, 0, 0);
	}	else	{ 
		dz += (speedY + speedX) / 60.;
	}
	posX = x;
	posY = y;
        glutPostRedisplay();       
}



//
int main(int argc, char** argv) {
 
        std::cout << "Start" << std::endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH  );
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Hello world");
        
        initOpenGl();
        glutKeyboardFunc(onKeyboardFunc);
        glutSpecialFunc(onSpecialKey);
        glutMouseFunc(onMouse);
	glutMotionFunc(onMouseMove);
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
