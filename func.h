#pragma once

#include "all.h"


 




//
void test(void);


//
void Cube();

//
void Ikosaeder(int normType, int deep);

//
void DrawScene();

//
class Point3D{
        
public: 
        float x,y,z;
        
        Point3D(){}
        
        Point3D(float x, float y, float z){
                this->x = x;
                this->y = y;
                this->z = z;
        }
        
        Point3D* operator +=(float v) {
                this->x += v;
                this->y += v;
                this->z += v;
                return this;
        }
        
        Point3D* operator +=(Point3D* v) {
                this->x += v->x;
                this->y += v->y;
                this->z += v->z;
                return this;
        }
};

// Координаты вершины и ее цвет
struct VERT { Point3D v, n; uint c; };  

// Индекусы трех вершин 
struct TRIA { int i1, i2, i3; };

//
uint RGB(int r, int g, int b);




//
void Sphere(VERT *v, TRIA* t);

const uint clr1 = RGB(0, 255, 0), clr2 = RGB(0, 0, 255); // цвета сферы


//
void DrawSphera(uint , uint );

uint getNTria();
