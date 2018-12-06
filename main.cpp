//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

// http://citforum.ru/programming/opengl/opengl_06.shtml

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
	dx=0.1f, dy=.0, dz = -10.0f, 
	spec[] = {0.6f,0.6f,0.6f},
	colorSun[] = {1,1,0,1},
	colorEarth[] = {0,0,1,.5},
	colorMoon[] = {0.5,0.5,0.5,1},
	colorEndl[] = {0,0,0,1},
	speed = .1;
	
short posX, posY,deep; 
bool leftButton, twoSide, normale=1,deepType=0,normaleLine=0, sunRun,dayRun,yaerRun,moonRun; 
int maxDeep = 6;
float speedTest = 1;
// Lighting values
float  whiteLight1[] = { 0.1f, 0.1f, 0.1f, 1.0f };
float  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };

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
 
	
	glPushMatrix();
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
	glRotatef(sun, 0,1,0);	// Вращаем систему координат
	 
	glMaterialfv(GL_FRONT, GL_EMISSION, colorSun);
	glutSolidSphere(1,30,30);	// Рисуем Солнце
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
	glMaterialfv(GL_FRONT, GL_EMISSION, colorEndl); 
	
	//////
	
	
	//////
	glPopMatrix();
        // sun end
        
        
        // earth
	glPushMatrix();
	 
	glRotatef(year, 0, 1, 0);
	glTranslatef(4, 0, 0); 
	glPushMatrix(); 
	 
	glRotatef(day, 0, 1, 0);
	
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorEarth);
	glutSolidSphere(0.3,20,20); // Рисуем Землю
	
	glPopMatrix();	
	 
	glRotatef(moon, 0, 1, 0);
	glTranslatef(1, 0,  0); 
	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, colorMoon);
	glutSolidSphere(0.08,20,20);
	glPopMatrix();
	// end moon
	
	glPopMatrix();
	// earth end 
	
	
	
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
       
	glShadeModel(GL_SMOOTH); //
	 
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	   
 
        glEnable(GL_DEPTH_TEST); 

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
 
        glLightfv(GL_LIGHT0,GL_DIFFUSE,whiteLight1);
    
        glLightfv(GL_LIGHT1,GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);



        glMaterialfv(GL_FRONT, GL_SPECULAR, spec); //Добавьте блеск всем телам:
        glMaterialf(GL_FRONT, GL_SHININESS, 30.0);


	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
       
        DrawScene();
}
 

 

 //
void onIdle() {
        //addRotation(speedY * .1, 0, 1, 0);
        //addRotation(speedX * .1, 1, 0, 0);
        
        if(sunRun) sun += 0.1; 
        if(moonRun) moon += 1;
        if(dayRun) day += 0.3;
        if(yaerRun) year += 0.5;
        glutPostRedisplay(); 
}


//
void onKeyboardFunc(byte key, int x, int y )
{       

        switch(key){
                case 's':
                        sunRun = !sunRun;
                break;
                case 'd':
                        dayRun = !dayRun;
                break;
                case 'm':
                        moonRun = !moonRun;
                break;
                case 'y':
                        yaerRun = !yaerRun;
                break;
                case 'z':
                        dz -= speed;
                break;
                case 'x':
                        dz += speed;
                break;
        }
        
        if(sunRun || dayRun || moonRun || yaerRun) {
                glutIdleFunc(onIdle);
        } else {
        
        }
         
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
        glutIdleFunc(onIdle);
        glutMainLoop();
        return 0;
}
