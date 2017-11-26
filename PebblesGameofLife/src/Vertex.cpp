/*
 * Vertex.cpp
 *
 *  Created on: Nov 3, 2017
 *      Author: Advanderar
 */

#include "Vertex.hpp"
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.1415926538

namespace peb {

Vertex::Vertex() {
	x = 0;
	y = 0;
	z = 0;
}

Vertex::Vertex(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vertex::setVertex(double newX, double newY, double newZ){
	this->x = newX;
	this->y = newY;
	this->z = newZ;
	return;
}

void Vertex::setVertex(Vertex& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return;
}

void Vertex::changeVertex(double newX, double newY, double newZ){
	this->x += newX;
	this->y += newY;
	this->z += newZ;
}

void Vertex::printValues(){
	printf("X: %f, Y: %f, Z: %f \n", x, y, z);
}

void Vertex::drawVertex(){
	float rad; rad = PI/180;
	glBegin(GL_POLYGON);
		for(int j = 0; j < 360 ; j ++){
			int radius = 3;
			double yComp = sin(j * rad) * radius;
			double xComp = cos(j * rad) * radius;

			glColor3f(0.8,0.8,0.8);
			glVertex2f((xComp) + x, (yComp) + (720 - z));
		}
	glEnd();
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

} /* namespace hall7790 */
