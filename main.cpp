//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float
	ax=.1, ay=.2, // Углы поворота изображения вокруг осей X и Y
	dx=0, dy=0, dz = -2, // Сдвиги вдоль координат
	speed = 1;
short posX, posY; // Текущая позиция указателя мыши
bool leftButton, twoSide; // Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)



//
void displayMe(void) {
 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(dx, dy, dz);
	glRotatef(ay, 0, 1, 0);
	glRotatef(ax, 1, 0, 0);

	glCallList(1); 	// Воспроизводим команды из списка 1

	glutSwapBuffers(); 
	glFlush();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
        gluPerspective(45, double(w)/h, 0.3, 100);
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	DrawScene();
}

//

void onKeyboardFunc(unsigned char key, int x, int y )
{        
	
        switch(key) 
	{
	case 27: exit(0); break;
	case '2': glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, (twoSide = !twoSide)); break;
	}
	glutPostRedisplay();
} 

void onSpecialKey(int key, int x, int y ){
       
	 
	glutPostRedisplay();
}

//
void onMouse(int button, int state, int x, int y){
//d +=0.1;
	leftButton = button == GLUT_LEFT_BUTTON;
	if (state == GLUT_DOWN)
	{
	}
	else
	{
	}
	posX = x;	// Запоминаем координаты мыши
	posY = y;
}

void onMouseMove(int x, int y)
{
        
	if (leftButton)
	{
		ay += x-posX;// Измените углы поворота пропорционально смещению мыши (разностей x – posX и y – posY)
		ax += y-posY;
	}
	else
	{
		// Вычислите степень удаления или приближения и измените величину dz пропорционально смещению мыши
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
        glEnable(GL_DEPTH_TEST); // проверка на порядок !
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
