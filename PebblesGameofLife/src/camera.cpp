/*
 * Shape.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: Omid Ghiyasian
 *      		Nicholas Hallman
 */

#include <stdio.h>
#include "camera.h"
#include "Matrix.hpp"

Camera::Camera() {
	eye.x = 35.0, eye.y = 35.0, eye.z = 35.0;
	reference.x = 0.0, reference.y = 0.0, reference.z = 0.0;
	viewup.x = 0.0,viewup.y = 1.0, viewup.z = 0.0;
	aspect = 16.0/9.0, viewAngle = 40.0, nearDist = 1.0, farDist = 80.0;
}

void Camera::setDefaultCamera(void) {
	eye.x = 3.0, eye.y = 3.0, eye.z = 7.0;
	reference.x = 0.0, reference.y = 0.0, reference.z = 0.0;
	viewup.x = 0.0,viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 20.0;
	return;
}

void Camera::setCamera(Vertex newEye, Vertex newReference, Vector newViewup) {
	eye.setVertex(newEye);
	reference.setVertex(newReference);
	viewup.setVector(newViewup);
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 20.0;
	return;
}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle){
	 Matrix *m =  new Matrix();
	 m->rotate(rx, ry, rz, angle);
	 GLfloat vector[4];
	 vector[0] = eye.x;
	 vector[1] = eye.y;
	 vector[2] = eye.z;
	 vector[3] = 1;
	 m->multiply_vector(vector);
	 eye.x = vector[0];
	 eye.y = vector[1];
	 eye.z = vector[2];
	 return;
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz){ //w.r.p.t WC
	eye.x += tx;
	eye.y += ty;
	eye.z += tz;
	return;
}

void Camera::setProjectionMatrix() {
	glEnable(GL_CULL_FACE);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(viewAngle, aspect, nearDist, farDist);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(eye.x, eye.y, eye.z, reference.x, reference.y, reference.z,
			viewup.x,viewup.y,viewup.z);
	return;

}

void Camera::resetCamera() {
	eye.x = 3.0, eye.y = 3.0, eye.z = 7.0;
	reference.x = 0.0, reference.y = 0.0, reference.z = 0.0;
	viewup.x = 0.0,viewup.y = 1.0, viewup.z = 0.0;
	aspect = 1.0, viewAngle = 40.0, nearDist = 1.0, farDist = 10.0;
	return;
}
