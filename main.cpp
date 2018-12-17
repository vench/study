//  g++ testgl.cpp -o testgl -lglut -lGLU -lGL

#include "all.h"  

float   speedY = 2, speedX = 1,
	rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

 
//
void printMatrix(float *M, int r, int c){
        for(int i =0; i < r; i ++) {
                for(int j = 0; j < c; j ++) {
                        int index = i * c + j;
                        std::cout << M[index] << " ";
                }
                
                std::cout << "" << std::endl;
        }

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
int main(int argc, char** argv) {

        
        glutInit(&argc, argv); 
        glutCreateWindow("Hello world"); 
        printMatrix(&rotMatrix[0], 4,4);
        addRotation(speedY * .1, 0, 1, 0);
        addRotation(speedX * .1, 1, 0, 0);
        printMatrix(&rotMatrix[0], 4,4);
        return 0;
}
