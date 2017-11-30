/*
 * Dougnut.h
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */

#ifndef TORUS_HPP_
#define TORUS_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Torus: public Shape {
protected:
	GLfloat C;
	GLfloat A;
	GLdouble x;
	GLdouble y;
	GLdouble z;
	int grid_size;
public:
	Torus();
	void draw();
	void reset();
};

#endif /* TORUS_HPP_ */
