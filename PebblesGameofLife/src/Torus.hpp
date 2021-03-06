/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Nicholas Hallman
 *      	    Omid Ghiyasian
 *
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
	void vertexNormals();
	Vertex normals[36 * 36];
	Vertex vNormals[36 * 36][4];
};

#endif /* TORUS_HPP_ */
