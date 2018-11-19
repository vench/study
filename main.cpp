//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float
        speedX, speedY,
        rotMatrix[16] = { 
                1, 0, 0, 0, 
                0, 1, 0, 0, 
                0, 0, 1, 0, 
                0, 0, 0, 1 
                }, // Стираем буфер Матрица, Стираем буфер суммирующая Стираем буфер малые Стираем буфер вращения 
	dx=0.1f, dy=.0, dz = -7.0f,  
	speed = .1;
short posX, posY,deep; // Текущая позиция указателя мыши
bool leftButton, twoSide, normale=1,deepType=2,flat; 


uint nRingsLoc = 10, nSectsLoc = 10;
 
 


float
pos[] = { 0, 0, 5, 0 }, //  
amb[] = { 0.05f, 0.05f, 0.05 }, //  
dif[] = { 0.9f, 0.9f, 0.9 }, // 
spec[] = { 0.8f, 0.8f, 0.8 }; //  
char buf[128]; //  
int shine = 40; // 
 
 
 
//////


///
void Print(float x, float y, const char *format, ...)
{
	va_list args;
	char buffer[200];
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	for (char* p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p); // GLUT_STROKE_MONO_ROMAN // GLUT_STROKE_ROMAN
	glPopMatrix();
}

//
void DrawInfo()
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.7f, 1, 0);
	Print(80, 2800, "Rings: %d", nRingsLoc);
	Print(80, 2650, "Sects: %d", nSectsLoc);
	Print(80, 2500, "Triangles: %d", getNTria());
	Print(80, 200, "Light is: %s", buf);
	Print(80, 60, "Coordinates: (%3.1f, %3.1f, %3.1f)", pos[0], pos[1], pos[2]);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}
//// 
 
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
       /*   
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	
        glPushMatrix();
	glTranslatef(dx, dy, dz);  
        glMultMatrixf(rotMatrix);  
	//glCallList(normale ? 3 : 2);
	Ikosaeder(normale ? 1 : 2, deep);   
        glPopMatrix(); 
	
        */
	 
	DrawInfo(); 
	glPushMatrix();

	

	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix);

	glCallList(1);

	glPopMatrix();
	
	
	glutSwapBuffers(); 
	glFlush(); 
}

//
void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
        
        glMatrixMode(GL_PROJECTION); ///
        glLoadIdentity();
        gluPerspective(45, double(w)/h, 0.6, 100);
            
}

void initOpenGl() {
        if (pos[3] == 0) {
                strcpy(buf, "Directional");
        } else {
                strcpy(buf, "Positional");
        }         
        glClearColor(0, 0, 0, 0);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_CULL_FACE); 
        glShadeModel(flat ? GL_FLAT : GL_SMOOTH);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);  
        glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
        glMaterialf(GL_FRONT, GL_SHININESS, shine);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        
        DrawSphera(nRingsLoc, nSectsLoc);
}

//
void onKeyboardFunc(byte key, int x, int y )
{       
         std::cout << key << std::endl;
        switch(key) 
	{
	case ' ': 
	        flat = !flat;
	        initOpenGl();
	        break;
	case 'n': normale = !normale; break;
	
	case '+': dz += speed; break;
	case '-': dz -= speed; break;
	case 27: exit(0); break;
	case '2': glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, (twoSide = !twoSide)); break;
	case 'a': pos[0] -= speed; break;
	case 'd': pos[0] += speed; break;
	case 's': pos[1] -= speed; break;
	case 'w': pos[1] += speed; break;
	case 'q':  
	                
	           if(nRingsLoc > 100){
	                nRingsLoc -=15; nSectsLoc -=15; 
	           }   else {
	                nRingsLoc --; nSectsLoc --; 
	           }  
	                
	           initOpenGl();     
	break;  
	case 'e':  if(nRingsLoc > 100) {
	                nRingsLoc += 15; nSectsLoc +=15; 
	           } else {
	                nRingsLoc ++; nSectsLoc ++; 
	           }
	           initOpenGl();     
	break;
	case 'z': pos[3] = (pos[3] - 1) * -1; 
                   initOpenGl();
        break;                	
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
