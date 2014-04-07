#include <math.h>
#include "Vector4.h"
#include <iostream>

Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4::Vector4(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
	w = 1;
}

Vector4::Vector4(double a, double b, double c, double d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

void Vector4::set(double a, double b, double c, double d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}

double Vector4::get(int a){
	switch (a)
	{
	case 0: return x; break;
	case 1: return y; break;
	case 2: return z; break;
	case 3: return w; break;
	default: std::cout << "out of bounds"; break;
	}

}

double Vector4::operator[](int a)
{
	return get(a);
}

void Vector4::add(Vector4 &a)
{
	x += a.x;
	y += a.y;
	z += a.z;
	w += a.w;
}

void Vector4::add(Vector4 &a, Vector4 &b)
{
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
	w = a.w + b.w;
}

Vector4 operator+(Vector4 &a, Vector4 &b)
{
	return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

void Vector4::subtract(Vector4 &a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
	w -= a.w;
}

void Vector4::subtract(Vector4 &a, Vector4 &b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
	w = a.w - b.w;
}

Vector4 operator-(Vector4 &a, Vector4 &b)
{
	return Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

void Vector4::dehomogenize()
{
	x /= w;
	y /= w;
	z /= w;
	w /= w;
}

void Vector4::print()
{
	std::cout << "[" << x << " " << y << " " << z << " " << w << "]";
}