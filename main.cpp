//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

// http://citforum.ru/programming/opengl/opengl_06.shtml

#include "all.h" 
#include "BmpLoader.h"
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
	dx=0.1f, dy=.0, dz = -40.0f, 
	spec[] = {0.6f,0.6f,0.6f},
	specPos1[] = {0.1f,0.1f,0.1f},
	colorSun[] = {1,1,0,1},
	colorEarth[] = {0,0,1,.5},
	colorMoon[] = {0.5,0.5,0.5,1},
	colorEndl[] = {0,0,0,1},
	
	speed = .1; 
	
short posX, posY,deep; 
bool leftButton, twoSide, normale=1,deepType=0,normaleLine=0, sunRun,dayRun,yaerRun,moonRun; 
//int maxDeep = 6;
float speedTest = 1;
// Lighting values
float  whiteLight1[] = { 0.1f, 0.1f, 0.1f, 1.0f };
float  whiteLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
float  sourceLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
float	 lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };

Point3D center, eye, up;

//
bool LoadTexture(int id, const char *fn) { 
        if (!fn)
		return false;
	BmpLoader* p = new BmpLoader(fn);
	if (!p)
		throw "Error reading texture.\n";
	glBindTexture(GL_TEXTURE_2D, id);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, p->sizeX, p->sizeY, GL_RGB, GL_UNSIGNED_BYTE, p->data);
        std::cout <<  p->sizeX << " " << p->sizeY << std::endl;
        return true;
}

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
        
        // text
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
         
        
        
	glPushMatrix();	
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix); // Изменяем ММ 
	// gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z); 
	
	glPushMatrix();
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos); // TODO change pos
	glRotatef(sun, 0,1,0);	// Вращаем систему координат
	 
	glMaterialfv(GL_FRONT, GL_EMISSION, colorSun);
	//glutWireSphere(1,30,30);	// Рисуем Солнце
	glCallList(1);
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
	glMaterialfv(GL_FRONT, GL_EMISSION, colorEndl); 
	 
	//////
	glPopMatrix();
        // sun end
        
        
        // earth
	glPushMatrix();
	 
	glRotatef(year, 0, 1, 0);
	glTranslatef(14, 0, 0); 
	glPushMatrix(); 
	 
	glRotatef(day, 0, 1, 0);
	
        glMaterialfv(GL_FRONT, GL_DIFFUSE, colorEarth); 
	////gluSphere(sphere, 0.3,20,20);
	//glutWireSphere(0.3,20,20); // Рисуем Землю
	glCallList(2);
	
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
       
	//glShadeModel(GL_SMOOTH); //
	glShadeModel(GL_FLAT);
	 
	glCullFace(GL_BACK);   
        glEnable(GL_DEPTH_TEST);  
        glShadeModel(GL_SMOOTH);
        glEnable(GL_COLOR_MATERIAL);
        glDisable(GL_CULL_FACE);
        glEnable(GL_TEXTURE_2D); 
        
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
 
        glLightfv(GL_LIGHT0,GL_DIFFUSE,whiteLight1);
    
        glLightfv(GL_LIGHT1,GL_DIFFUSE,sourceLight);
	glLightfv(GL_LIGHT1,GL_POSITION,lightPos);
        glLightfv(GL_LIGHT1,GL_SPECULAR,specPos1);


        glMaterialfv(GL_FRONT, GL_SPECULAR, spec); //Добавьте блеск всем телам:
        glMaterialf(GL_FRONT, GL_SHININESS, 30.0);


	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
       
       
        //glClearColor(0, 0, 0, 0);  
        LoadTexture(1, "/home/vench/dev/opengl/tx/sun.bmp");
        LoadTexture(2, "/home/vench/dev/opengl/tx/earth.bmp") ;
        LoadTexture(3, "/home/vench/dev/opengl/tx/moon.bmp") ;
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
