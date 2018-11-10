//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 

int    keys[256];      // Массив для процедуры обработки клавиатуры

GLfloat rtri;           // Угол для треугольник
GLfloat rquad;          // Угол для четырехугольника


void displayMe(void) {

        GLUquadricObj *quadObj;
        quadObj = gluNewQuadric(); // создаем новый объект
                            // для создания сфер и цилиндров

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
 
        
        
        //
        glPushMatrix();
 glColor3d(1,0,0);
  gluQuadricDrawStyle(quadObj, GLU_FILL); // устанавливаем
                          // стиль: сплошной
 gluSphere(quadObj, 0.5, 10, 10); // рисуем сферу
                                  // радиусом 0.5
 glTranslated(-2,0,0); // сдвигаемся влево
 glRotated(45, 1,0,0); // поворачиваем
 glColor3d(0,1,0);
 gluQuadricDrawStyle(quadObj, GLU_LINE); // устанавливаем
                          // стиль: проволочный
 gluCylinder(quadObj, 0.5, 0.75, 1, 15, 15);
glPopMatrix();
gluDeleteQuadric(quadObj);
//  
// 
  glBegin(GL_QUADS);
   glColor3d(1,0,0);
   glVertex2d(0,0);
   glColor3d(0,1,0);
   glVertex2d(0,0.3);
   glColor3d(0,0,1);
   glVertex2d(.3,0);
   glColor3d(1,1,1);
   glVertex2d(.3,.3);
  glEnd(); 
        
        glutSwapBuffers();
        
        
       // glFlush();
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
        glShadeModel(GL_SMOOTH); //glShadeModel(GL_FLAT); 
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
