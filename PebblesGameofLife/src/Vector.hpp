/*
 * Vector.hpp
 *
 *  Created on: Nov 26, 2017
 *      Author: malus
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <GL/glut.h>
#include "Vertex.hpp"

using namespace peb;

class Vector {
public:
	GLfloat x, y, z;
	Vector();
	Vector(GLfloat newX, GLfloat newY, GLfloat newZ);
	void setVector(GLfloat newX, GLfloat newY, GLfloat newZ);
	void setVector(Vector& v);
	void setDifference(Vertex & a, Vertex & b);
	void flip();
	void normalize();
	Vector crossProduct(Vector& b);
	GLfloat dotProduct(Vector& b);
	void build4tuple(GLfloat v[]);
	void printVector();
};



#endif /* VECTOR_HPP_ */
