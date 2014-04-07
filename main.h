#ifndef _CUBE_H_
#define _CUBE_H_


class Cube
{
protected:

public:
	Cube();   // Constructor
	void spin(double);      // spin cube [degrees]
};

class Window	  // output window related routines
{
public:
	static int width, height; 	            // window size

	static void idleCallback(void);
	static void reshapeCallback(int, int);
	static void displayCallback(void);
};

#endif

