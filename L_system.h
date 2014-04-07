#ifndef _L_SYSTEM_H_
#define _L_SYSTEM_H_

#include <GL/glut.h>
#include <math.h>

class L_system
{
public:
	L_system(double w=.05, double a=0){ width = w; angle = a; }
	void drawline(double r = 0, double g = 1, double b = 0);
	void drawellipse(double, double, double, double);
	void drawcylinder();
	void offset(double, double, double);
	void scale(double);
	void turnright();
	void turnleft();
	void pitchdown();
	void pitchup();
	void rollleft();
	void rollright();
	void turnaround();
	void start(int);
	virtual void rule1(int) = 0;
	virtual void rule2(int) = 0;
	void setlinewidth(double);
protected:
	double width;
	double angle;
};

class Sierpinski : public L_system
{
public:
	Sierpinski(double a = 60){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class Fern : public L_system
{
public:
	Fern(double a = 25){ angle = a; }
	void rule1(int);
	void rule2(int);
private:

};

class Simple_Tree : public L_system
{
public:
	Simple_Tree(double a = 45){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class Tree1 : public L_system
{
public:
	Tree1(double a = 23){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class _3DTree : public L_system
{
public:
	_3DTree(double a = 22.5){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class _3DTree2 : public L_system
{
public:
	_3DTree2(double a = 30){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class _3DTree3 : public L_system
{
public:
	_3DTree3(double a = 30){ angle = a; }
	void rule1(int);
	void rule2(int);
};

class _3DTree4 : public L_system
{
public:
	_3DTree4(double a = 65){ angle = a; }
	void rule1(int);
	void rule2(int);
};

#endif