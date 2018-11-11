//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
 
 
float
	ax=.1, ay=.2, // Углы поворота изображения вокруг осей X и Y
	dx=0, dy=0, dz = -.10, // Сдвиги вдоль координат
	speed = 1,
	color[] = { 0.1f, 0.6f, 0.1f };
short posX, posY; // Текущая позиция указателя мыши
bool leftButton, twoSide; // Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)


//cube
float v[8][3] = { -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1 };
float norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 };
int id[6][4] =
	{
		0, 1, 2, 3,	// Rear (CCW - counterclockwise)
		4, 5, 6, 7,	// Front
		0, 3, 5, 4,	// Left
		7, 6, 2, 1,	// Right
		0, 4, 7, 1,	// Top
		5, 3, 2, 6,	// Bottom
	};
//
void displayMe(void) {
 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 	// Будем пользоваться услугами MM
	glLoadIdentity();
	glTranslatef(dx, dy, dz); // Смещение координат точек будущих примитивов
	glRotatef(ay, 0, 1, 0); 	// Вращение координат точек примитивов
	glRotatef(ax, 1, 0, 0);
	
	glColor3fv(color);
	/*glBegin(GL_QUADS);		// Выбор типа примитива
	for (int i = 0; i < 6; i++)	// Долго готовились - быстро рисуем
	{
		glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++)
			glVertex3fv(v[id[i][j]]);
	}
	glEnd();
	*/
	meSolidCube(.6);
	
	glutSwapBuffers();
}

void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
        gluPerspective(45, double(w)/h, 0.6, 100);
}

void initOpenGl() {
        glClearColor(1, 1, 1, 0);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_LIGHTING);	// "Рубильник в подвале"
	glEnable(GL_LIGHT0);		// Источник света, размещенный в точке z = ∞
	int nLights;
	glGetIntegerv(GL_MAX_LIGHTS, &nLights);
	std::cout << nLights << std::endl;
	glEnable(GL_COLOR_MATERIAL);
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
		ay += speed * (x > posX ? -1 : 1);// Измените углы поворота пропорционально смещению мыши (разностей x – posX и y – posY)
		ax += speed * (y > posY ? -1 : 1);
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
