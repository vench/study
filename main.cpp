//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float gx = 0.35f, gy = 0.58f, gw, gh;

void displayMe(void) {

        glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0, -0.2f);
	glVertex2f(0, -0.1f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0, 0.4f);
	glEnd();
	glEnable(GL_SCISSOR_TEST); // Включаем ножницы
	glClearColor(0.9f, 0.8f, 0.7f, 0); // Меняем цвет фона
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 1);
	glVertex2f(-0.2f, 0.2f);
	glVertex2f(0, 0.2f);
	glVertex2f(0, 0.1f);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(0, -0.4f);
	glEnd();
	glDisable(GL_SCISSOR_TEST); // Выключаем ножницы
	glutSwapBuffers();
	glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl;
        
        gw = w;
	gh = h;
	glScissor((int)(gx * w), (int)(gy * h), (int)(0.3f * w), (int)(0.3f * h));
        
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
        glLoadIdentity();
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_FLAT);
	glPointSize(10);
	glEnable(GL_POINT_SMOOTH);
}

//

void onKeyboardFunc(unsigned char key, int x, int y )
{         
        glutPostRedisplay();
} 

void onSpecialKey(int key, int x, int y ){
        
        switch(key) {
	        case GLUT_KEY_LEFT: gx -= 0.005f; break;
	        case GLUT_KEY_RIGHT: gx += 0.005f; break;
	        case GLUT_KEY_DOWN: gy -= 0.005f; break;
	        case GLUT_KEY_UP:  gy += 0.005f; break;
	}
	
	glScissor((int)(gx * gw), (int)(gy * gh), (int)(0.3f * gw), (int)(0.3f * gh));
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
        //glutKeyboardFunc(onKeyboardFunc);
        glutSpecialFunc(onSpecialKey);
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
