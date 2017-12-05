/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Omid Ghiyasian
 *      		Nicholas Hallman
 *
 *
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <GL/gl.h>
#include <math.h>

namespace peb {

class Matrix {
public:
	GLfloat matrix[4][4];
	Matrix();
	void matrix_pre_multiply(Matrix *m);
	void transpose();
	void translate(GLfloat x, GLfloat y, GLfloat z);
	void rotate(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
	void multiply_vector(GLfloat* v);
	void normalize();
};

}




#endif /* MATRIX_HPP_ */
