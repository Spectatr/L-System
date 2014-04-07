#include <math.h>
#include "Vector3.h"
#include <iostream>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void Vector3::set(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

double Vector3::get(int a){
	switch (a)
	{
	case 0: return x; break;
	case 1: return y; break;
	case 2: return z; break;
	default: std::cout << "out of bounds"; break;
	}

}

double Vector3::operator[](int a)
{
	return get(a);
}

void Vector3::add(Vector3 &a)
{
	x += a.x;
	y += a.y;
	z += a.z;
}

void Vector3::add(Vector3 &a, Vector3 &b)
{
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
}

Vector3 operator+(Vector3 &a, Vector3 &b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

void Vector3::subtract(Vector3 &a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
}

void Vector3::subtract(Vector3 &a, Vector3 &b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
}

Vector3 operator-(Vector3 &a, Vector3 &b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

void Vector3::negate()
{
	x = -x;
	y = -y;
	z = -z;
}

void Vector3::negate(Vector3 &a)
{
	x = -a.x;
	y = -a.y;
	z = -a.z;
}

void Vector3::scale(double a)
{
	x *= a;
	y *= a;
	z *= a;
}

void Vector3::scale(double a, Vector3 &b)
{
	x = a*b.x;
	y = a*b.y;
	z = a*b.z;
}

double Vector3::dot(Vector3 &a)
{
	return x*a.x + y*a.y + z*a.z;
}

void Vector3::cross(Vector3 &a, Vector3 &b)
{
	x = a.y*b.z - a.z*b.y;
	y = a.z*b.x - a.x*b.z;
	z = a.x*b.y - a.y*b.x;
}

double Vector3::magnitude()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::normalize()
{
	scale(1.0 / magnitude());
}

void Vector3::print()
{
	std::cout << "[" << x << " " << y << " " << z << "]";
}