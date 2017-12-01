/*
 * Shape.hpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */

#ifndef SHAPE_HPP_
#define SHAPE_HPP_

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "Matrix.hpp"

using namespace peb;

class Shape {
protected:
	Matrix MC;
	GLfloat s;
public:
	Shape();
	virtual ~Shape();
	Matrix getMC();
	void ctm_multiply();
	void scale_change(GLfloat x);
	void translate(GLfloat tx, GLfloat ty, GLfloat t);
	void rotate_mc(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	void rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
	virtual void draw() = 0;
	void reset();
};



#endif /* SHAPE_HPP_ */
