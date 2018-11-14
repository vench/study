#include "func.h"

void test(void) {
        //
        std::cout << "Test..." << std::endl;
}

//

//cube

 

 
	
void DrawScene()
{

        // cube
        glNewList(1,GL_COMPILE);          
        Cube();
	glEndList();
	
	/// ic
	glNewList(2,GL_COMPILE);
        Ikosaeder(0);  
        glEndList();
        
	glNewList(3,GL_COMPILE);
        Ikosaeder(1);  
        glEndList(); 
}

//
void Cube() {
        float color[] = { 0.1f, 0.1f, 0.7f };
        float sz = 1.;
        float v[8][3] = { -sz, sz, -sz, sz, sz, -sz, sz, -sz, -sz, -sz, -sz, -sz, -sz, sz, sz, -sz, -sz,  sz, sz, -sz, sz, sz, sz, sz };
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
	
	
	glColor3fv(color);
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++)
			glVertex3fv(v[id[i][j]]);
	}
	glEnd();
}	


//
void Ikosaeder(int normType) {
	float 
        r = (1 + sqrt(5)) / 2, // Золотое сечение
        v[12][3] =
        {
                0, 1, r, 
                0,-1, r, 
                0, 1,-r, 
                0,-1,-r,
                1, r, 0, 
                -1, r, 0, 
                1,-r, 0, 
                -1,-r, 0,
                r, 0, 1, 
                -r, 0, 1, 
                r, 0,-1, 
                -r, 0,-1
        }, 
        color[] = {0.9f, 0.1f, 0.2f};
        int id[20][3] = // Стираем буфер 20 Стираем буфер triangular Стираем буфер faces
        {
                0, 1, 8, 
                0, 9, 1, 
                0, 8, 4, 
                0, 4, 5, 
                0, 5, 9,
                2, 3, 11, 
                2, 11, 5, 
                2, 5, 4, 
                2, 4, 10, 
                2, 10, 3,
                1, 9, 7, 
                1, 7, 6, 
                1, 6, 8, 
                3, 10, 6, 
                3, 6, 7,
                3, 7, 11, 
                4, 8, 10, 
                5, 11, 9, 
                6, 10, 8, 
                7, 9, 11
        };

        // делаем сдвиг
        float d = sqrt(1 + r * r);
        for (int i = 0; i < 12; i++)
        {
                for (int j = 0; j < 3; j++)
                        v[i][j] /= d;
        }
        
        glColor3fv(color);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 20; i++)
	{ 
	        if(normType == 1) { 
	        // создаем нормалии
	                float norm[3], a[3], b[3];
	                 for (int n = 0; n < 3; n++) {
                                        a[n] = v[id[i][2]][n] - v[id[i][1]][n];
                                        b[n] = v[id[i][0]][n] - v[id[i][1]][n];
                         }
                                
                         norm[0] = a[1] * b[2] - a[2] * b[1];
                         norm[1] = a[2] * b[0] - a[0] * b[2];
                         norm[2] = a[0] * b[1] - a[1] * b[0];      
                         // нормализуем           
                         float dd = sqrt(norm[0] * norm[0] + norm[1] * norm[1] + norm[2] * norm[2]);
                        if (dd != 0) {
                                norm[0] /= dd; norm[1] /= dd; norm[2] /= dd; 
                        }
                      
                        // std::cout << norm[0] << std::endl;       
                        glNormal3fv(norm);   
                }    
                        
		for (int j = 0; j < 3; j++) {
		        if(normType == 0) {
		                glNormal3fv(v[id[i][j]]); //smooth normale 
			}
			glVertex3fv(v[id[i][j]]);
		}	
	}
	glEnd();
} 
