/*
 * Shape.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: Omid Ghiyasian
 *      		Nicholas Hallman
 */

#include "Shape.hpp"

Shape::Shape() {
	MC.matrix[0][0] = 1.0; MC.matrix[0][1] = 0.0; MC.matrix[0][2] = 0.0; MC.matrix[0][3] = 0.0;
	MC.matrix[1][0] = 0.0; MC.matrix[1][1] = 1.0; MC.matrix[1][2] = 0.0; MC.matrix[1][3] = 0.0;
	MC.matrix[2][0] = 0.0; MC.matrix[2][1] = 0.0; MC.matrix[2][2] = 1.0; MC.matrix[2][3] = 0.0;
	MC.matrix[3][0] = 0.0; MC.matrix[3][1] = 0.0; MC.matrix[3][2] = 0.0; MC.matrix[3][3] = 1.0;
	s = 1;
}


Shape::~Shape() {};

Matrix Shape::getMC() {
	return MC;
};

void Shape::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	MC.translate(tx, ty, tz);
}

void Shape::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	MC.rotate(rx, ry, rz, angle);
}

void Shape::rotate_mc(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	GLfloat x0, y0, z0;
	x0 = MC.matrix[0][3];
	y0 = MC.matrix[1][3];
	z0 = MC.matrix[2][3];

	MC.rotate(rx, ry, rz, angle);

	MC.matrix[0][3] = x0;
	MC.matrix[1][3] = y0;
	MC.matrix[2][3] = z0;

	MC.normalize();
}

void Shape::rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix* m = new Matrix();
	m->rotate(rx, ry, rz, angle);
	GLfloat v[4];
	v[0] = MC.matrix[0][3];
	v[1] = MC.matrix[1][3];
	v[2] = MC.matrix[2][3];
	v[3] = MC.matrix[3][3];
	m->multiply_vector(v);
	MC.matrix[0][3] = v[0];
	MC.matrix[1][3] = v[1];
	MC.matrix[2][3] = v[2];
	MC.matrix[3][3] = v[3];
	delete m;
}

void Shape::scale_change(GLfloat x) {
	s += x;
}

void Shape::ctm_multiply() {
	GLfloat M[16];
	M[0] = MC.matrix[0][0];
	M[1] = MC.matrix[1][0];
	M[2] = MC.matrix[2][0];
	M[3] = 0;
	M[4] = MC.matrix[0][1];
	M[5] = MC.matrix[1][1];
	M[6] = MC.matrix[2][1];
	M[7] = 0;
	M[8] = MC.matrix[0][2];
	M[9] = MC.matrix[1][2];
	M[10] = MC.matrix[2][2];
	M[11] = 0;
	M[12] = MC.matrix[0][3];
	M[13] = MC.matrix[1][3];
	M[14] = MC.matrix[2][3];
	M[15] = 1;
	glMultMatrixf(M);
}

void Shape::reset(){
	GLint i, j;
	for (i = 0; i < 4; i ++) {
		for (j = 0; j < 4; j ++) {
			MC.matrix[i][j] = 0.0;
		}
	}
	MC.matrix[0][0] = 1.0;
	MC.matrix[1][1] = 1.0;
	MC.matrix[2][2] = 1.0;
	MC.matrix[3][3] = 1.0;

}


