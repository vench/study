#include "func.h"

void test(void) {
        //
        std::cout << "Test..." << std::endl;
}

//

//cube

 
const float GOLD_R = (1 + sqrt(5)) / 2;
const float GOLD_D = sqrt(1 + GOLD_R * GOLD_R);
 
	
void DrawScene()
{

        // cube
        glNewList(1,GL_COMPILE);          
        Cube();
	glEndList();
	
	/// ic
	glNewList(2,GL_COMPILE);
        Ikosaeder(0, 0);  
        glEndList();
        
	glNewList(3,GL_COMPILE);
        Ikosaeder(1,0);  
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
void makeNorm(float *v1, float *v2, float *v3, float * norm) {
        float a[3], b[3];
	for (int n = 0; n < 3; n++) {
                a[n] = v3[n] - v2[n]; 
                b[n] = v1[n] - v2[n]; 
        }
                                
        norm[0] = a[1] * b[2] - a[2] * b[1];
        norm[1] = a[2] * b[0] - a[0] * b[2];
        norm[2] = a[0] * b[1] - a[1] * b[0];      
                         // нормализуем           
        float d = sqrt(norm[0] * norm[0] + norm[1] * norm[1] + norm[2] * norm[2]);
        if (d != 0) {
            norm[0] /= d; norm[1] /= d; norm[2] /= d; 
        }
}


//
void ToUnit(float *v) {
 
  for (int j = 0; j < 3; j++)
          v[j] /= GOLD_D;
                  
}

//
void DrawTriaSmooth(float *v1, float *v2, float *v3) {
        glNormal3fv(v1);  
	glVertex3fv(v1);
	glNormal3fv(v2);  
	glVertex3fv(v2);
	glNormal3fv(v3);  
	glVertex3fv(v3);
}

//
void DrawTriaFlat(float *v1, float *v2, float *v3) {
        float norm[3];
        makeNorm(v1, v2, v3, norm);
        glNormal3fv(norm);  
	glVertex3fv(v1);   
	glVertex3fv(v2);  
	glVertex3fv(v3);
}


//
void DrawRecursive(float *v1, float *v2, float *v3, int depth, int normType)
{
        float v12[3], v23[3], v31[3];
        if (depth <= 0)
        {
                if (normType == 1)
                        DrawTriaFlat(v1, v2, v3);
                else
                        DrawTriaSmooth(v1, v2, v3); 
                return;
        }
        for (int i = 0; i < 3; i++)
        {
                v12[i] = v1[i] + v2[i];
                v23[i] = v2[i] + v3[i];
                v31[i] = v3[i] + v1[i];
        }
        ToUnit(v12); ToUnit(v23); ToUnit(v31);
        DrawRecursive(v1, v12, v31, depth - 1, normType);
        DrawRecursive(v2, v23, v12, depth - 1, normType);
        DrawRecursive(v3, v31, v23, depth - 1, normType);
        DrawRecursive(v12, v23, v31, depth - 1, normType);
}

//
void Ikosaeder(int normType, int deep) {
	float 
        r = GOLD_R, // Золотое сечение
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
        for (int i = 0; i < 12; i++)  { 
              ToUnit(v[i]);    
        }
        
        glColor3fv(color);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 20; i++)
	{  
		DrawRecursive(v[id[i][0]], v[id[i][1]], v[id[i][2]], deep, normType);	
	}
	glEnd();
} 
