/*
 * Doughnut.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */

#include "Torus.hpp"

Torus::Torus() {
	C = 3;
	A = 1;
	x = 0;
	y = 0;
	z = 0;
	grid_size = 30;
}

void Torus::draw() {
	glPushMatrix();
	for (int v = 0; v < grid_size; v++) {

		glBegin(GL_LINE_LOOP);
		for (int u = 0; u < grid_size; u++) {
			x = (C + A*(float)cos(v*(2*M_PI/grid_size)))*(float)cos(u*(2*M_PI/grid_size));
			y = (C + A*(float)cos(v*(2*M_PI/grid_size)))*(float)sin(u*(2*M_PI/grid_size));
			z = A*(float)sin(v*(2*M_PI/grid_size));
			glVertex3d(x,y,z);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int u = 0; u < grid_size; u++) {
			x = (C + A*(float)cos(u*(2*M_PI/grid_size)))*(float)cos(v*(2*M_PI/grid_size));
			y = (C + A*(float)cos(u*(2*M_PI/grid_size)))*(float)sin(v*(2*M_PI/grid_size));
			z = A*(float)sin(u*(2*M_PI/grid_size));
			glVertex3d(x,y,z);
		}
		glEnd();
	}
	glPopMatrix();
}

void Torus::reset() {
	C = 3;
	A = 1;
	x = 0;
	y = 0;
	z = 0;
	grid_size = 30;
}


