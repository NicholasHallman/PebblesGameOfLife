/*
 * camera.h
 *
 *  Created on: Nov 26, 2017
 *      Author: malus
 */



#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/glut.h>
#include "Vertex.hpp"
#include "Vector.hpp"

using namespace peb;

class Camera {
public:
	Vertex eye;
	Vertex reference;
	Vector viewup;
	GLfloat aspect, nearDist, farDist, viewAngle;

	Camera();
	void setDefaultCamera();
	void setCamera(Vertex newEye, Vertex newReference, Vector newViewup);
	void resetCamera();
	void rotate(GLfloat rotateX, GLfloat rorateY, GLfloat rotateZ, GLfloat angle);
	void translate(GLfloat translateX, GLfloat translateY, GLfloat translateZ);
	void setProjectionMatrix();
	void printCamera(void);
};


#endif /* CAMERA_H_ */
