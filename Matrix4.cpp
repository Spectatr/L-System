#include <math.h>
#include <iostream>
#include "Matrix4.h"

Matrix4::Matrix4()
{
	for (int i = 0; i<4; ++i)
	{
		for (int j = 0; j<4; ++j)
		{
			m[i][j] = 0;
		}
	}
	m[3][3] = 0;
}

Matrix4::Matrix4(
	double m00, double m01, double m02, double m03,
	double m10, double m11, double m12, double m13,
	double m20, double m21, double m22, double m23,
	double m30, double m31, double m32, double m33)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	m[0][3] = m03;
	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
	m[1][3] = m13;
	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
	m[2][3] = m23;
	m[3][0] = m30;
	m[3][1] = m31;
	m[3][2] = m32;
	m[3][3] = m33;
}

void Matrix4::set(int i, int j, double a)
{
	m[i][j] = a;
}

double* Matrix4::getPointer()
{
	return &m[0][0];
}

void Matrix4::identity()
{
	double ident[4][4] = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };
	for (int i = 0; i<4; ++i)
	{
		for (int j = 0; j<4; ++j)
		{
			m[i][j] = ident[i][j];
		}
	}
}

// angle in radians
void Matrix4::rotateY(double angle)
{
	m[0][0] = cos(angle);
	m[0][1] = 0;
	m[0][2] = sin(angle);
	//m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	//m[1][3] = 0;
	m[2][0] = -sin(angle);
	m[2][1] = 0;
	m[2][2] = cos(angle);
	//m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

double Matrix4::get(int x, int y)
{
	return m[x][y];
}

void Matrix4::multiply(Matrix4 &a)
{
	Matrix4 temp;
	for (int row = 0; row<4; row++){
		for (int col = 0; col<4; col++){
			for (int i = 0; i<4; i++){
				temp.m[row][col] += m[row][i] * a.m[i][col];
			}
		}
	}
	for (int row = 0; row<4; row++){
		for (int col = 0; col<4; col++){
			m[row][col] = temp.m[row][col];
		}
	}
}



Vector4 Matrix4::multiply(Vector4 &a)
{
	Vector4 temp;
	double temp2[4] = { 0 };
	for (int row = 0; row<4; row++){
		for (int i = 0; i<4; i++){
			temp2[row] += m[row][i] * a[i];
		}
		temp.set(temp2[0], temp2[1], temp2[2], temp2[3]);
	}
	return temp;
}

void Matrix4::rotateX(double angle)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	//m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = cos(angle);
	m[1][2] = -sin(angle);
	//m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = cos(angle);
	//m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void Matrix4::rotateZ(double angle)
{
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[0][2] = 0;
	//m[0][3] = 0;
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
	m[1][2] = 0;
	//m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	//m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

Matrix4 Matrix4::rotateaxis(double angle, Vector3 a)
{
	Matrix4 b;
	b.m[0][0] = 1 + (1 - cos(angle))*(pow(a[0], 2) - 1);
	b.m[0][1] = -a[2] * sin(angle) + (1 - cos(angle))*a[0] * a[1];
	b.m[0][2] = a[1] * sin(angle) + (1 - cos(angle))*a[0] * a[2];
	b.m[0][3] = 0;
	b.m[1][0] = a[2] * sin(angle) + (1 - cos(angle))*a[1] * a[0];
	b.m[1][1] = 1 + (1 - cos(angle))*(pow(a[1], 2) - 1);
	b.m[1][2] = -a[0] * sin(angle) + (1 - cos(angle))*a[1] * a[2];
	b.m[1][3] = 0;
	b.m[2][0] = -a[1] * sin(angle) + (1 - cos(angle))*a[2] * a[0];
	b.m[2][1] = a[0] * sin(angle) + (1 - cos(angle))*a[2] * a[1];
	b.m[2][2] = 1 + (1 - cos(angle))*(pow(a[2], 2) - 1);
	b.m[2][3] = 0;
	b.m[3][0] = 0;
	b.m[3][1] = 0;
	b.m[3][2] = 0;
	b.m[3][3] = 1;
	return b;
}

void Matrix4::nonuni(Vector3 a)
{
	m[0][0] = a[0];
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = a[1];
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = a[2];
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

void Matrix4::translation(Vector3 a)
{

	/*m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;*/
	m[0][3] += a[0];
	/*m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;*/
	m[1][3] += a[1];
	/*m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;*/
	m[2][3] += a[2];
	/*m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;*/
	m[3][3] = 1;

}

void Matrix4::print()
{
	std::cout << "[";
	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			std::cout << " " << m[i][j];
		}
		std::cout << "\n";
	}
}

void Matrix4::transpose()
{
	double temp;
	for (int row = 0; row<4; row++){
		for (int col = row + 1; col<4; col++){
			temp = m[row][col];
			m[row][col] = m[col][row];
			m[col][row] = temp;
		}
	}
}


/** Rotates the matrix according to a fictitious trackball, placed in
the middle of the given window.
The trackball is approximated by a Gaussian curve.
The trackball coordinate system is: x=right, y=up, z=to viewer<BR>
The origin of the mouse coordinates zero (0,0) is considered to be top left.
@param width, height  window size in pixels
@param fromX, fromY   mouse starting position in pixels
@param toX, toY       mouse end position in pixels
*/
Matrix4 Matrix4::trackballRotation(int width, int height, int fromX, int fromY, int toX, int toY)
{
	const float TRACKBALL_SIZE = 1.3f;              // virtual trackball size (empirical value)
	Matrix4 mInv;                                   // inverse of ObjectView matrix
	Vector3 v1, v2;                                 // mouse drag positions in normalized 3D space
	float smallSize;                                // smaller window size between width and height
	float halfWidth, halfHeight;                    // half window sizes
	float angle;                                    // rotational angle
	float d;                                        // distance

	// Compute mouse coordinates in window and normalized to -1..1
	// ((0,0)=window center, (-1,-1) = bottom left, (1,1) = top right)
	halfWidth = (float)width / 2.0f;
	halfHeight = (float)height / 2.0f;
	smallSize = (halfWidth < halfHeight) ? halfWidth : halfHeight;
	v1.set(((float)fromX - halfWidth) / smallSize, ((float)(height - fromY) - halfHeight) / smallSize, 0);
	v2.set(((float)toX - halfWidth) / smallSize, ((float)(height - toY) - halfHeight) / smallSize, 0);

	// Compute z-coordinates on Gaussian trackball:
	d = sqrtf(v1[0] * v1[0] + v1[1] * v1[1]);
	v1.set(v1[0], v1[1], expf(-TRACKBALL_SIZE * d * d));

	d = sqrtf(v2[0] * v2[0] + v2[1] * v2[1]);
	v2.set(v2[0], v2[1], expf(-TRACKBALL_SIZE * d * d));

	// Compute rotational angle:
	double temp2;
	temp2 = v1.dot(v2);
	temp2 /= (v1.magnitude()*v2.magnitude());
	angle = acos(temp2);                          // angle = angle between v1 and v2

	// Compute rotational axis:
	v2.cross(v2, v1);                                  // v2 = v2 x v1 (cross product)

	// Convert axis coordinates (v2) from WCS to OCS:
	mInv.identity();
	mInv.set(0, 0, m[0][0]);
	mInv.set(0, 1, m[0][1]);
	mInv.set(0, 2, m[0][2]);
	mInv.set(1, 0, m[1][0]);
	mInv.set(1, 1, m[1][1]);
	mInv.set(1, 2, m[1][2]);
	mInv.set(2, 0, m[2][0]);
	mInv.set(2, 1, m[2][1]);
	mInv.set(2, 2, m[2][2]);

	mInv.transpose();                             // invert orthogonal matrix mInv
	int temp3[3] = { 0 };                            // v2 = v2 x mInv (matrix multiplication)
	for (int i = 0; i < 3; i++){
		temp3[i] = v2[0] * mInv.get(0, i) * v2[1] * mInv.get(1, i) * v2[2] * mInv.get(2, i);
	}
	v2.set(temp3[0], temp3[1], temp3[2]);
	v2.normalize();                                 // normalize v2 before rotation

	// Perform acutal model view matrix modification:
	return rotateaxis(-angle, v2);      // rotate model view matrix
}

