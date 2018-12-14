//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h" 
#include "BmpLoader.h"
 
 
float
        speedX, speedY, 
	ax=11.1, ay=.2, // Углы поворота изображения вокруг осей X и Y
	angle =0,
	speed = 1;
short posX, posY; // Текущая позиция указателя мыши
bool leftButton, twoSide, lighting, sphereMap, decal, colored; 

float
	rotX = 20, rotY = 30,
	dx, dy, dz = -5, 
	rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	green[] = { 0, 0.6, 0 },
	white[] = { 0.9, 0.9, 0.9 },
	sx, sy,
	texX, texY, texZ;
int  
	filter = GL_NEAREST,
	wrap = GL_REPEAT; 
uint texture;

const int MAX_PATH = 255;

std::string* FileDlg()
{  
        FILE *f = popen("zenity --file-selection", "r");
        if(!f) {
                return 0;
        }
        char *arr = new char[1024];
        fgets(arr, 1024, f);
        fclose(f);   
         
	return new std::string(arr); 
}

//
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v") {
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

//
bool LoadTexture(int id, bool def = true)
{  
	std::string *fn = def ? 
	        new std::string("/home/vench/dev/opengl/image/test.bmp") : FileDlg();  
	//std::cout << "LoadTexture: " << *fn  << fn->length() <<  std::endl; 
	
	if (!fn)
		return false;
	BmpLoader* p = new BmpLoader(rtrim(*fn));
	if (!p)
		throw "Error reading texture.\n";
	glBindTexture(GL_TEXTURE_2D, id);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, p->sizeX, p->sizeY, GL_RGB, GL_UNSIGNED_BYTE, p->data);
	
	//std::cout << "LoadTexture: x: "  << p->sizeX << ", y: "<< p->sizeY <<  std::endl;
	
	return true;
}

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
void Print(float x, float y, const char *format, ...) {
	va_list args;
	char buffer[200];
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	for (char* p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

//
void DrawInfo() {
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.7f, 1, 0);
	Print(80, 2800, "Decal: %d", decal);
	Print(80, 2650, "Colored: %d", colored);
	Print(80, 2500, "Lighting: %d", lighting);
	Print(80, 200, "Wrapping: %s", (wrap == GL_REPEAT ? "Repeat" : "Clamp"));
	Print(80, 60, "Filtering: %s", (filter == GL_LINEAR ? "Linear" : "Nearest"));
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
	glColor3f(1, 1, 1); // base color
}

//
void displayMe(void) {
 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        if(colored) {
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
	        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
	}
	//
	if(decal) {
	        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	} else {
	        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}
	
	//glTexGeni
	if(sphereMap) {
	glEnable(GL_TEXTURE_GEN_S);
 glEnable(GL_TEXTURE_GEN_T);
	        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
                glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
                glDisable(GL_TEXTURE_GEN_S);
 glDisable(GL_TEXTURE_GEN_T);
	} else {}
	//
	
	// x
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
        glTranslatef(0.5, 0.5, 0.0);
        glRotatef(angle, 0.0, 0.0, 1.0);
        glTranslatef(-0.5, -0.5, 0.0);
	glMatrixMode(GL_MODELVIEW);
	// ex
	
	glPushMatrix();
	DrawInfo();
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix);
	glCallList(1);
	glPopMatrix();
	glutSwapBuffers(); 
}

//
void reshapeMe(int w, int h) {
        std::cout << "Reshape" << std::endl; 
        
        glViewport(0,0,w,h); 
        
        glMatrixMode(GL_PROJECTION); ///
        glLoadIdentity();
        gluPerspective(45, double(w)/h, 0.6, 100);
            
}


void SetLight()
{
	if (lighting)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
	}
	else
		glDisable(GL_LIGHTING);
}


//
void initOpenGl() { 
	glClearColor(0, 0, 0, 0);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	SetLight();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	if (LoadTexture(1))
		DrawScene();
}


//
void onKeyboardFunc(unsigned char key, int x, int y )
{  
        switch(key) 
	{
	case 'c': colored = !colored; 
	        /*if(colored) {
	                glEnable(GL_TEXTURE_2D);
	        } else {
	                glDisable(GL_TEXTURE_2D);
	        }  */      
	break;
	case 'd': decal = !decal; break;
	case 's': sphereMap = !sphereMap; break;
	case 'l': lighting = !lighting; SetLight(); break;
	case 'o': LoadTexture(1, false); break;
	case 'w': 
	        if(wrap == GL_REPEAT) {
	                wrap = GL_CLAMP;
	        } else {
	                wrap = GL_REPEAT;
	        }
	 break;
	 case 'f': 
	        if(filter == GL_LINEAR){
	                filter = GL_NEAREST; //Nearest
	        } else {
	                filter = GL_LINEAR;
	        }
	 break;
	
	case 'q': angle += 1; break;
	case 'a': angle -= 1; break;
	
	case '+': dz += 0.1; break;
	case '-': dz -= 0.1; break;
	case 27: exit(0); break;
	case '2': glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, (twoSide = !twoSide)); break;
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
        std::cout << key << std::endl;
	 
	switch(key) {
	        case 102:
	                dx += 0.1;
	        break;
	        case 100:
	                dx -= 0.1;
	        break;   
	        case 101:
	                dy += 0.1;
	        break;
	        case 103:
	                dy -= 0.1;
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
	      
             // std::cout << "bbbbbx: " << speedY << speedX << std::endl;
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
	      dz += (speedY + speedX) / 60.;
	}
	posX = x;
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
