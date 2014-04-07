#include <iostream>
#include "L_system.h"

#define PI 3.14159

GLUquadric* qobj = gluNewQuadric();

void L_system::scale(double scalenum)
{
	glScaled(scalenum, scalenum, scalenum);

}

void L_system::drawellipse(double x, double y, double xsize, double ysize)
{
	float i;
	float triangleAmount = 40; //# of triangles used to draw circle

	GLfloat radius = 1.5f; //radius
	GLfloat twicePi = 2.0f * 3.14159f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,1,0);

	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + xsize*(radius * cos(i * twicePi / triangleAmount)),
			y + ysize*(radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
}

void L_system::drawcylinder()
{
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glColor3f(.627, .322, .176);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluCylinder(qobj, .2f, .2f, 3.0f, 32, 32);
	glPopMatrix();
	glTranslated(3, 0, 0);

}

void L_system::drawline(double r, double g, double b)
{
	glBegin(GL_QUADS);
	glColor3f(r, g, b);

	glVertex3f(0, width, 0.0);
	glVertex3f(3, width, 0.0);
	glVertex3f(3, -width, 0.0);
	glVertex3f(0, -width, 0.0);

	glEnd();

	glTranslated(3, 0, 0);


}

void L_system::turnright()
{
	glRotated(-angle,0,0,1);
	
}

void L_system::turnleft()
{
	glRotated(angle, 0, 0, 1);
}

void L_system::pitchdown()
{
	glRotated(angle, 0, 1, 0);
}

void L_system::pitchup()
{
	glRotated(-angle, 0, 1, 0);
}

void L_system::rollleft()
{
	glRotated(angle, 1, 0, 0);
}

void L_system::rollright()
{
	glRotated(-angle, 1, 0, 0);
}

void L_system::turnaround()
{
	glRotated(180, 1, 0, 0);
}

void Sierpinski::rule1(int i)
{
	if (i == 0)
		drawline();
	else{
		rule2(i - 1);
		turnright();
		rule1(i - 1);
		turnright();
		rule2(i - 1);

	}
}

void Sierpinski::rule2(int i)
{
	if (i == 0)
		drawline();
	else{
		rule1(i - 1);
		turnleft();
		rule2(i - 1);
		turnleft();
		rule1(i - 1);

	}
}

void L_system::start(int i)
{
	rule1(i);
}

void L_system::offset(double x,double y, double z)
{
	glTranslated(x, y, z);
}

void L_system::setlinewidth(double a)
{
	width = a;
}

void Fern::rule1(int i)
{
	
	if (i == 0)
		;
	else
	{
		rule2(i-1);
		turnleft();
		glPushMatrix();
		glPushMatrix();
		rule1(i-1);
		glPopMatrix();
		turnright();
		rule1(i-1);
		glPopMatrix();
		turnright();
		rule2(i - 1);
		glPushMatrix();
		turnright();
		rule2(i - 1);
		rule1(i - 1);
		glPopMatrix();
		turnleft(); 
		rule1(i - 1);

	}
}

void Fern::rule2(int i)
{
	if (i == 0)
		drawline();
	else
	{
		rule2(i - 1);
		rule2(i - 1);
	}
}

void Simple_Tree::rule1(int i)
{
	if (i == 0)
		drawline();
	else
	{
		rule2(i - 1);
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		turnright();
		rule1(i - 1);
	}
}

void Simple_Tree::rule2(int i)
{
	if (i == 0)
		drawline();
	else
	{
		rule2(i - 1);
		rule2(i - 1);
	}
}

void Tree1::rule1(int i)
{
	if (i == 0)
		drawline();
	else
	{
		rule1(i - 1);
		rule1(i - 1);
		turnright();
		glPushMatrix();
		turnright();
		rule1(i - 1);
		turnleft();
		rule1(i - 1);
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		turnleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		turnright();
		rule1(i - 1);
		turnright();
		rule1(i - 1);
		glPopMatrix();
	}
}

void Tree1::rule2(int i)
{

}

void _3DTree::rule1(int i)
{
	if (i == 0)
		drawline();
	else
	{
		rule1(i - 1);
		glPushMatrix();
		turnright();
		pitchdown();
		rollleft();
		rule1(i - 1);
		glPopMatrix();
		glPushMatrix();
		rollleft();
		turnleft();
		turnleft();
		pitchdown();
		rule1(i - 1);
		glPopMatrix();
		turnaround();
		turnaround();
		rule1(i - 1);
		glPushMatrix();
		turnright();
		turnright();
		pitchdown();
		rollright();
		rule1(i - 1);
		glPopMatrix();
		glPushMatrix();
		turnleft();
		pitchdown();
		rule1(i - 1);
		glPopMatrix();
	}
}

void _3DTree::rule2(int i)
{

}

void _3DTree2::rule1(int i)
{
	if (i == 0)
		drawellipse(5,0,5,2);
	else
	{
		glScaled(.6, .6, .6);
		rule2(i - 1);
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
	}
}

void _3DTree2::rule2(int i)
{
	if (i == 0)
		drawcylinder();
	else
	{
		rule2(i - 1);
	}
}

void _3DTree3::rule1(int i)
{
	if (i == 0)
		drawellipse(2, 0,2,1);
	else
	{
		glScaled(.6, .6, .6);
		rule2(i - 1);
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();

	}
}

void _3DTree3::rule2(int i)
{
	if (i == 0)
		drawcylinder();
	else
	{
		rule2(i - 1);
	}
}
void _3DTree4::rule1(int i)
{
	if (i == 0)
		drawellipse(2, 0, 2, 1);
	else
	{
		glScaled(.9, .9, .9);
		rule2(i - 1);
		rule2(i - 1);
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();

		rollleft();
		rollleft();

		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rule2(i - 1);

		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();

		rollleft();
		rollleft();

		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();
		rollleft();
		rollleft();
		glPushMatrix();
		turnleft();
		rule1(i - 1);
		glPopMatrix();


	}
}

void _3DTree4::rule2(int i)
{
	if (i == 0)
		drawcylinder();
	else
	{
		rule2(i - 1);
	}
}
