//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
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
         
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
        glPushMatrix();
	glTranslatef(dx, dy, dz);  
        glMultMatrixf(rotMatrix);   
	Ikosaeder(normale ? 1 : 2, deep, normaleLine);   
        glPopMatrix();  
        
	glutSwapBuffers(); 
	glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
        
        glMatrixMode(GL_PROJECTION); ///
        glLoadIdentity();
        gluPerspective(45, double(w)/h, 0.6, 100);
            
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_SMOOTH); //
	glEnable(GL_DEPTH_TEST); // проверка на порядок !
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	/// 
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
        glMateriali(GL_FRONT, GL_SHININESS, 128); //настройка, определяющая блёскость материала,
        
        // толщина линий нормалий
        glEnable( GL_LIGHTING); 
        glLineWidth(3); 
	DrawScene();
}

//
void onKeyboardFunc(byte key, int x, int y )
{       
         std::cout << key << std::endl;
        switch(key) 
	{
	case ' ': 
	        deep += deepType ? -1 : 1; 
	        if(deep > maxDeep) {
	                deep = maxDeep;
	                deepType = !false;
	        } else if(deep < 0) {
	                deep = 0;
	                deepType = false;
	        }
	        break;
	case 'n': normale = !normale; break;
	case 's': normaleLine = !normaleLine; break; 
	
	case '+': dz += speed; break;
	case '-': dz -= speed; break;
	case 27: exit(0); break;
	case '2': glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, (twoSide = !twoSide)); break;
	}
	glutPostRedisplay();
} 

void onIdle()
{
        // Стираем буфер Изменяйте Стираем буфер значения Стираем буфер углов Стираем буфер поворота
        
        addRotation(speedY * .1, 0, 1, 0);
        addRotation(speedX * .1, 1, 0, 0);
        glutPostRedisplay(); 
}

//
void onSpecialKey(int key, int x, int y ){
       // std::cout << key << std::endl;
	 
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
	
	if (state == GLUT_DOWN)
	{
	         
	      speedX = speedY = 0;
	      glutIdleFunc(0);   
	}
	else
	{ 
              if(fabs(speedY) > 1. || fabs(speedX) > 1.) {
                glutIdleFunc(onIdle);
              }       
	      
	}
	posX = x;	// Запоминаем координаты мыши
	posY = y;
}

void onMouseMove(int x, int y)
{       
        speedX = y-posY;
        speedY = x-posX;
        
	if (leftButton)
	{
		addRotation(speedY * .1, 0, 1, 0);
                addRotation(speedX * .1, 1, 0, 0);
		
	}
	else
	{
	        // Вычислите степень удаления или приближения и измените величину dz пропорционально смещению мыши
		dz += (speedY + speedX) / 60.;
	}
	posX = x;	// Запоминаем новые координаты мыши
	posY = y;
	glutPostRedisplay();
}



//
int main(int argc, char** argv) {

        test();
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
