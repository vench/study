//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
#include "func.h"
 

float
	speedX, speedY,
        rotMatrix[16] = { 
                1, 0, 0, 0, 
                0, 1, 0, 0, 
                0, 0, 1, 0, 
                0, 0, 0, 1 
                },  
	dx=0.1f, dy=.0, dz = -7.0f,  
        speed = .01,  dist = 14,
	spec[] = { 1, 1, 1 },
	pos0[] = { -3, 3, 3, 0 },
	pos1[] = { 3, 3, -3, 0 },
	amb[] = { 0.3f, 0.3f, 0.3f };
 
Point3D center, eye, up; 

int move  = 0;

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
	glPushMatrix();
	gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z); 
	glCallList(1); 
	glPopMatrix();
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
        glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
	DrawScene();
}

//
void Go(bool fwrd)
{
	Point3D pt((eye - center) * speed);
	if (fwrd)
	{
		eye -= pt;
		center -= pt;
	}
	else
	{
		eye += pt;
		center += pt;
	}
}

//
void Roll(float angle) {
        Point3D V = center - eye;
        up.Rotate(V, angle);
}

//
void Pitch(float angle) {
      Point3D 
        v = center - eye,
        n = v * up;
      center = eye + v.Rotate(n, angle); 
      up.Rotate(n, angle); 
}

// by Y
void Yaw(float angle) { 
        Point3D V = center - eye;
        V.Rotate(up, angle);
        Point3D tmp = V + eye;
        center.Update(tmp);
}

//
void onKeyboardFunc(byte key, int x, int y )
{       
        switch(key)
	{
	case '7': Roll(0.1);	break;
	case '9': Roll(-0.1); break;
	case '8': Pitch(0.1); break;
	case '2': Pitch(-0.1); break;
	case '4': Yaw(1); break;
	case '6': Yaw(-1); break;
	case '5': Go(true); break;
	case '3': Go(false); break;
	case '0': // Возврат в исходное состояние
		eye = Point3D(0, 1.5, dist);
		center = Point3D(0, 1.5, 0);
		up = Point3D(0, 1, 0);
		break;
	case '1': // Помещаем глаз в симметричную позицию и поворачиваем его на 180 градусов
		eye = Point3D(0, 1.5, -2 * dist);
		center = Point3D(0, 1.5, 0);
		up = Point3D(0, 1, 0);
		break;
	case 't': // Телепортируем глаз в удаленную позицию, чтобы оценить звездный кластер издалека
		eye = Point3D(0, 1.5, 20 * dist);
		center = Point3D(0, 1.5, 19 * dist);
		up = Point3D(0, 1, 0);
		break;
	case 'w': move ++; break;
	case 's': move --; break;
	case 'a': Yaw(1); break;
	case 'd': Yaw(-1); break;
	case 'e': Pitch(0.1); break;
	case 'q': Pitch(-0.1); break;
	case ' ':
		std::cout << "\nE = (" << eye.x << ", " << eye.y << ", " << eye.z << ')'
			<< "\nC = (" << center.x << ", " << center.y << ", " << center.z << ')'
			<< "\nU = (" << up.x << ", " << up.y << ", " << up.z << ")\n";
		break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
} 

void onIdle()
{
        // Стираем буфер Изменяйте Стираем буфер значения Стираем буфер углов Стираем буфер поворота
        
        if(move > 0) {
                Go(true);
        } else if(move < 0) {
                Go(false);
        }
        
       // addRotation(speedY * .1, 0, 1, 0);
       // addRotation(speedX * .1, 1, 0, 0);
        glutPostRedisplay(); 
}

//
void onSpecialKey(int key, int x, int y ){
       Point3D pt;
	switch(key)
	{
	case GLUT_KEY_LEFT: pt = Point3D(-0.1, 0, 0); break;
	case GLUT_KEY_RIGHT: pt = Point3D(0.1, 0, 0); break;
	case GLUT_KEY_DOWN: pt = Point3D(0, -0.1, 0); break;
	case GLUT_KEY_UP: pt = Point3D(0, 0.1, 0); break;
	}
	eye += pt; center += pt;
	glutPostRedisplay(); 
}

//
void onMouse(int button, int state, int x, int y){ 
}

//
void onMouseMove(int x, int y)
{         
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
	glutIdleFunc(onIdle);
        glutReshapeFunc(reshapeMe);
        glutDisplayFunc(displayMe);
        glutMainLoop();
        return 0;
}
