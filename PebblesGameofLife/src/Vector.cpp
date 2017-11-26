/*
 * Vector.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: malus
 */

#include "Vector.hpp"
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace peb;

Vector::Vector() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector::setVector(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Vector::setVector(Vector& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return;
}

void Vector::setDifference(Vertex& a, Vertex& b) {
	this->x = a.x - b.x;
	this->y = a.y - b.y;
	this->z = a.z - b.z;
	return;
}

void Vector::flip() {
	this->x = -x;
	this->y = -y;
	this->z = -z;
	return;
}

Vector Vector::crossProduct(Vector& b) {
	Vector c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
	return c;
}

GLfloat Vector::dotProduct(Vector& b) {
	return x * b.x + y * b.y + z * b.z;
}

void Vector::normalize() {
	GLdouble norm = x*x + y*y + z*z;
	if (norm < 0.0000001) {
		std::cerr << "\nnormalize() sees vector (0,0,0)!";
		return;
	}
	GLfloat scale = 1.0/(GLfloat)sqrt(norm);
	this->x *= norm;
	this->y *= norm;
	this->z *= norm;
	return;
}

void Vector::build4tuple(GLfloat* v) {
	v[0] = x; v[1] = y; v[2] = z; v[3] = 0.0f;
}

void Vector::printVector() {
	printf("(%f, %f, %f)\n", x, y, z);
	return;
}


