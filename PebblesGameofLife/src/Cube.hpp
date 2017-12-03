/*
 * Cube.hpp
 *
 *  Created on: Dec 2, 2017
 *      Author: ghiy2250
 */

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <GL/glut.h>
#include "Shape.hpp"

class Cube: public Shape {
protected:
	GLfloat vertex[8][3];
	GLint face[6][4];
public:
	Cube();
	void draw_face(int);
	void draw();
	void draw_simple();
};



#endif /* CUBE_HPP_ */

