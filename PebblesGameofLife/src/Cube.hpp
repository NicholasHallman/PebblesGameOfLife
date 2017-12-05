/*
 * Cube.hpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Omid Ghiyasian
 *      		Nicholas Hallman
 */

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vertex.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
public:
	Cube();
	void draw_face(int);
	void draw();
	void drawOutline(int);
	void draw_simple();
private:
	Vertex normals[6];
	void calcNormals();
};



#endif /* CUBE_HPP_ */

