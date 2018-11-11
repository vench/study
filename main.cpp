//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
#define Line(x1,y1,x2,y2) \
        glBegin(GL_LINES);  \
	glVertex2f((x1),(y1)); \
	glVertex2f((x2),(y2)); \
glEnd();

void displayMe(void) {
 

        glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
 
        glColor3d(0,0,0);
	
	glEnable(GL_LINE_STIPPLE);
	
	
	glColor3d(1,0,0);
	
	// 0
	glLineStipple(10, 0x2727);
	glBegin(GL_LINES); 
	for(float i = -.95; i < 1.; i += 0.5) {
	        glVertex2f(i, -.5 + cos(i*30));
	}
	glEnd();
	//Line(-.95, -.5, .95, -.5);
	
	
	glColor3d(0,0,0);
	
	//======== В 1-м ряду рисуем 3 линии с разной штриховкой (stipple)
	glLineStipple(1, 0x0303);		// dot
	Line(.05, .1, .35, .1);
	glLineStipple(1, 0x00FF);		// dash
	Line(.35, .1, .65, .1);
	glLineStipple(1, 0x2727);		// dash/dot/dash
	Line(.65, .1, .95, .1);
	
	//======== Во 2-м ряду то же, но шире в 6 раз
	glLineWidth(6);
	glLineStipple(1, 0x0303);		// dot
	Line(.05, .2, .35, .2);
	glLineStipple(1, 0x00FF);		// dash
	Line(.35, .2, .65, .2);
	glLineStipple(1, 0x2727);		// dash/dot/dash
	Line(.65, .2, .95, .2);
	
		// В 3-м ряду 19 линий являются частями полосы (strip). Удвоенный узор не прерывается
	glLineStipple(2, 0x2727);
 
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 19; i++)
		glVertex2d(.05*(i+1),.3);
	glEnd();

	// В 4-м ряду 18 независимых, отдельных линий.
	// Тот же узор, но он каждый раз начинается заново
	for (int i = 0;  i < 18; i++)
	{
		Line(0.05*(i+1),.4, 0.05*(i+2), .4);
	}
	//===== В 5-м ряду 1 линия с тем же узором
	glLineStipple(6, 0x2727);
	Line(.05, .5, .95, .5);

	glDisable(GL_LINE_STIPPLE);
	glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);  
}

//

void onKeyboardFunc(unsigned char key, int x, int y )
{        
	
        glutPostRedisplay();
} 

void onSpecialKey(int key, int x, int y ){
       
	 
	glutPostRedisplay();
}

//
int main(int argc, char** argv) {

        test();
        std::cout << "Start" << std::endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE  );
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Hello world");
       // glEnable(GL_DEPTH_TEST); // проверка на порядок !
        initOpenGl();
        glutKeyboardFunc(onKeyboardFunc);
        glutSpecialFunc(onSpecialKey);
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
