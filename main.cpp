//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float speed = 4.;
float angle = 0;

void displayMe(void) {

        std::cout << "displayMe: " << angle << ", " << speed << std::endl; 
 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //
        glPushMatrix();
        meSolidCube(.1);
        glPopMatrix();
        //
      
        glPushMatrix();  
       // glTranslated(0, 0, -20);
       // glRotated(angle,0,0,1); 
       glRotated(34,0,1,1);
        glRotated(angle,1,0,0);
       // glRotated(angle,0,1,0);
        
        meSolidCube(.3); 
         glPopMatrix();
         
        glutSwapBuffers();
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
        glClearColor(1,1,1,0);
        glShadeModel(GL_SMOOTH); //glShadeModel(GL_FLAT); 
        glPointSize(7);
        glEnable(GL_POINT_SMOOTH);
}

//

void onKeyboardFunc(int key, int x, int y )
{

        if (key == GLUT_KEY_UP) {
                angle+=speed;
                if(angle > 360) {
                        angle = 0;
                        if (speed < 20) speed +=.5;
                } 
        } else if (key == GLUT_KEY_DOWN) {
                angle-=speed;
                if(angle <= 0) {
                        angle = 360;
                        if (speed > 0) speed -=.5;
                }        
        }
    
        
        glutPostRedisplay();
} 

//
int main(int argc, char** argv) {

        test();
        std::cout << "Start" << std::endl;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(800, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Hello world");
        glEnable(GL_DEPTH_TEST); // проверка на порядок !
        initOpenGl();
        //glutKeyboardFunc(onKeyboardFunc);
        glutSpecialFunc(onKeyboardFunc);
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
