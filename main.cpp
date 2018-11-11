//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float gx = 0.35f, gy = 0.58f, gw, gh;
int gn = 6; 


float ps = 1.;
float points[3][2] = { {0, ps},{ps, -ps},{-ps, -ps}};

void displayMe(void) {


        std::cout << ((1 << gn)) << std::endl;

        glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
 
	
	glBegin(GL_POINTS);
	glColor3f(0, 0, 1);
	for(int i = 0; i < 3; i ++){
	        glVertex2f(points[i][0], points[i][1]); 
	}
	glEnd();
	
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0); 
	
        float a[2] = {points[2][0],points[2][1]};
        for(int i = 0; i< (1 << gn); i ++) {
                int x = rand() %3; 
                glVertex2f(a[0], a[1]); 
                a[0] = (a[0] + points[x][0]) / 2;
                a[1] = (a[1] + points[x][1]) / 2;
        }

	glEnd();
	
	glutSwapBuffers();
	glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl;
        
        gw = w;
	gh = h; 
        
        glViewport(0,0,w,h); 
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);  
}

//

void onKeyboardFunc(unsigned char key, int x, int y )
{        
	switch(key) {
	        case '+': gn ++; break;
	        case '-': gn --; break;
	}  
	if(gn > 20) {
	        gn = 20;
	}  else if(gn < 1) {
	        gn = 1;
	}
        glutPostRedisplay();
} 

void onSpecialKey(int key, int x, int y ){
        
        switch(key) {
	        case GLUT_KEY_LEFT: gx -= 0.005f; break;
	        case GLUT_KEY_RIGHT: gx += 0.005f; break;
	        case GLUT_KEY_DOWN: gy -= 0.005f; break;
	        case GLUT_KEY_UP:  gy += 0.005f; break;
	}
	 
	glutPostRedisplay();
}

//
int main(int argc, char** argv) {

        test();
        std::cout << "Start" << std::endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE  );
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
