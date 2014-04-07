#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include "main.h"
#include "L_system.h"

using namespace std;

static Cube cube;

int Window::width = 1024;   // set window width in pixels here
int Window::height = 768;   // set window height in pixels here
double rotateangle = 0;

void lsystem()
{
	_3DTree2 a;
	_3DTree3 b;
	_3DTree c;
	_3DTree4 d;

	c.setlinewidth(.2);
	
	/*
	//regular tree 1
	glPushMatrix();
	glTranslated(-10, -10, 0);
	glScaled(5, 5, 5);
	glRotated(90, 0, 0, 1);
	glRotated(rotateangle++, 1, 0, 0);
	a.start(7);
	glPopMatrix();
	
	//regular tree 2
	glPushMatrix();
	glTranslated(0, -15, 0);
	glScaled(.15, .15, .15);
	glRotated(90, 0, 0, 1);
	glRotated(rotateangle++, 1, 0, 0);
	b.start(5);
	glPopMatrix();
	
	//weed like looking 
	glPushMatrix();
	glTranslated(0, -10, 0);
	glScaled(.4, .4, .4);
	glRotated(90, 0, 0, 1);
	glRotated(rotateangle++, 1, 0, 0);
	c.start(4);
	glPopMatrix();

	*/
	
	//small bush
	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(.4, .4, .4);
	glRotated(90, 0, 0, 1);
	glRotated(rotateangle++, 1, 0, 0);
	d.start(3);
	glPopMatrix();
	

}

//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback(void)
{
	displayCallback();  // call display routine to re-draw cube
}

//----------------------------------------------------------------------------
// Callback method called when window is resized.
void Window::reshapeCallback(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, w, h);  // set new viewport size
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10.0, 10.0, -10.0, 10.0, 10, 1000.0); // set perspective projection viewing frustum
	glTranslatef(0, 0, -20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//----------------------------------------------------------------------------
// Callback method called when window readraw is necessary or
// when glutPostRedisplay() was called.
void Window::displayCallback(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers

	lsystem();

	glFlush();
	glutSwapBuffers();
}

Cube::Cube()
{
}


int main(int argc, char *argv[])
{
	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float shininess[] = { 100.0 };
	float position[] = { 0.0, 10.0, 1.0, 0.0 };	// lightsource position

	glutInit(&argc, argv);      	      	      // initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   // open an OpenGL context with double buffering, RGB colors, and depth buffering
	glutInitWindowSize(Window::width, Window::height);      // set initial window size
	glutCreateWindow("L-System");    	      // open window and set window title

	glEnable(GL_DEPTH_TEST);            	      // enable depth buffering
	glClear(GL_DEPTH_BUFFER_BIT);       	      // clear depth buffer
	glClearColor(0.0, 0.0, 0.0, 0.0);   	      // set clear color to black
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // set polygon drawing mode to fill front and back of each polygon
	glDisable(GL_CULL_FACE);     // disable backface culling to render both sides of polygons
	glShadeModel(GL_SMOOTH);             	      // set shading to smooth
	glMatrixMode(GL_PROJECTION);

	// Generate material properties:
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Generate light source:
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	// Install callback functions:
	glutDisplayFunc(Window::displayCallback);
	glutReshapeFunc(Window::reshapeCallback);
	glutIdleFunc(Window::idleCallback);

	//glDisable(GL_LIGHTING);

	glutMainLoop();
	return 0;
}

