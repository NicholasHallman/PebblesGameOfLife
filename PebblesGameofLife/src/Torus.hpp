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
#include "Vertex.hpp"
#include"global.hpp"
#include<stdio.h>

class Torus: public Shape {
protected:
	GLfloat C;
	GLfloat A;
	GLdouble x;
	GLdouble y;
	GLdouble z;
	int grid_size;
public:
	Vertex faces[36 * 36][4];
	Torus();
	void draw();
	void reset();
private:
	void genVertices();
	void drawSolid();
	void drawGrid();
};

#endif /* TORUS_HPP_ */
