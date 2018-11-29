#pragma once

#include "all.h"

const float GOLD_R = (1 + sqrt(5)) / 2;
const float GOLD_D = sqrt(1 + GOLD_R * GOLD_R);
const float PI = acos(-1.);
const float ToRad = PI / 180;

 
//
void Cube();

//
void Ikosaeder(int normType, int deep);

//
void DrawScene();

//
void DrawPoints();

//
void DrawPlane();

//
void DrawObjects();

//
class Point3D
{
public:
	float x, y, z;

	Point3D() { x = y = z = 0.; }
	Point3D(float xx, float yy, float zz) { x = xx; y = yy; z = zz; }
	Point3D(float v[3]) { x = v[0]; y = v[1]; z = v[2]; }
	Point3D operator+ (Point3D& p) { return Point3D(x + p.x, y + p.y, z + p.z); }
	Point3D operator- (Point3D& p) { return Point3D(x - p.x, y - p.y, z - p.z); }
	void operator+= (Point3D& p) { x += p.x;	y += p.y;	z += p.z; }
	void operator-= (Point3D& p) { x -= p.x;	y -= p.y;	z -= p.z; }
	float operator! () { return sqrt(x*x + y*y + z*z); }
	Point3D operator* (float d) { return Point3D(x*d, y*d, z*d); }
	Point3D operator* (Point3D& p) { return Point3D(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }
	void operator*= (float d) { x *= d; y *= d, z *= d; }
	Point3D ToUnit() { float r = !*this; return Point3D(x / r, y / r, z / r); }
	float Dist(Point3D& p) { return !Point3D(*this - p); }
	void Update(Point3D& p) { this->x= p.x; this->y= p.y; this->z= p.z; }

	Point3D& Rotate(Point3D& p, float a) {
		a *= ToRad;
		p.ToUnit();
		float
			ca = cos(a),
			sa = sin(a),
			c = 1 - cos(a),
			xs = p.x * sa,
			ys = p.y * sa,
			zs = p.z * sa,
			xy = p.x * p.y * c,
			xz = p.x * p.z * c,
			yz = p.y * p.z * c,

			xn = (p.x * p.x * c + ca) * x + (xy - zs) * y + (xz + ys) * z,
			yn = (xy + zs) * x + (p.y * p.y * c + ca) * y + (yz - xs) * z,
			zn = (xz - ys) * x + (yz + xs) * y + (p.z * p.z * c + ca) * z;
		x = xn;  y = yn;  z = zn;
		return *this; 
	}
};


