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
	GLfloat B;
	GLdouble x;
	GLdouble y;
	GLdouble z;
	int grid_size;
public:
	Vertex lineV[36 * 36][4];
	Vertex faces[36 * 36][4];
	Torus();
	void draw();
	void drawOutline(int);
	void reset();
private:
	int fact(int);
	double comb(int, int);
	void genVertices();
	void genLines();
	void drawSolid();
	void drawGrid();
	void calcNormals();
	Vertex normals[36 * 36];
};

#endif /* TORUS_HPP_ */
