//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 



void displayMe(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
        glEnd();
        glColor3f(0.1,0.1,1);
        glBegin(GL_POINTS);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, .8);
        glVertex2f(.8, 0.8);
        glEnd(); 
        
        //
        glBegin(GL_QUADS);
        glColor3f(1.,1.,1.);
        glVertex2f(0, -0.8);
        glColor3f(0,0,1.);
        glVertex2f(0, 0);
        glColor3f(0,1.,0);
        glVertex2f(-0.8, 0);
        glColor3f(1.,0,0);
        glVertex2f(-0.8, -0.8);
        glEnd();
        
        glutSwapBuffers();
        glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl;
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, w, 0, h);
        glLoadIdentity();
}

void initOpenGl() {
        glClearColor(1,0.5,1,0);
        glShadeModel(GL_FLAT);
        glPointSize(7);
        glEnable(GL_POINT_SMOOTH);
}

//
int main(int argc, char** argv) {

        test();
        std::cout << "Start" << std::endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Hello world");
        initOpenGl();
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
