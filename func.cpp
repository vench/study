#include "func.h"

void test(void) {
        //
        std::cout << "Test..." << std::endl;
}

//

//cube

int 
	id[6][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 3, 5, 4, 7, 6, 2, 1, 0, 4, 7, 1, 5, 3, 2, 6, }
	//filter = GL_NEAREST,
	//wrap = GL_REPEAT
	;

float v[8][3] = { -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1 },
	norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 };
	
void DrawScene()
{ 
        float t[4][2] = {0,1,0,0,1,0,1,1};
        glNewList(1, GL_COMPILE);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++){
	        glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++){
			glTexCoord2fv(t[j]);
			glVertex3fv(v[id[i][j]]);
		}
	}
	glEnd();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEndList();
}	

 
 
