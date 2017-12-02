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
	grid_size = 36;
	genVertices();
}

void Torus::draw() {
	/*

	for (int v = 0; v < grid_size; v++) {
		glColor3f(1.0,1.0,0.0);
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

	*/
	glPushMatrix();
	int x = 0;
	int y = 0;
	for(int i = 0; i < grid_size * grid_size; i++){
		if(map.cells[x][y].newState == 1){
			glColor3f(.0,.3,.8);
		} else{
			glColor3f(.3,.3,.3);
		}
		glBegin(GL_QUADS);
			glVertex3f(faces[i][0].x,faces[i][0].y,faces[i][0].z);
			glVertex3f(faces[i][1].x,faces[i][1].y,faces[i][1].z);
			glVertex3f(faces[i][2].x,faces[i][2].y,faces[i][2].z);
			glVertex3f(faces[i][3].x,faces[i][3].y,faces[i][3].z);
		glEnd();
		/*
		glColor3f(1,1,1);
		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i][0].x,faces[i][0].y,faces[i][0].z);
			glVertex3f(faces[i][1].x,faces[i][1].y,faces[i][1].z);
			glVertex3f(faces[i][2].x,faces[i][2].y,faces[i][2].z);
			glVertex3f(faces[i][3].x,faces[i][3].y,faces[i][3].z);
		glEnd();
		*/
		x++;
		if(x > 35){
			x = 0;
			y++;
		}
		map.cells[x][y].oldState = map.cells[x][y].newState;
	}

	glPopMatrix();
}

void Torus::genVertices() {
	int pos = 0;
	for (int v = 0; v < grid_size; v++) {
		for (int u = 0; u < grid_size; u++) {
			if(u != grid_size){
				int pointu = u;
				int pointv = v;
				faces[pos][0].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				faces[pos][0].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				faces[pos][0].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u + 1;
				if(pointu == grid_size){
					pointu = 0;
				}
				pointv = v;
				faces[pos][1].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				faces[pos][1].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				faces[pos][1].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u;
				pointv = v + 1;
				if(pointv == grid_size){
					pointv = 0;
				}
				faces[pos][2].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				faces[pos][2].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				faces[pos][2].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u + 1;
				if(pointu == grid_size){
					pointu = 0;
				}
				pointv = v + 1;
				if(pointv == grid_size){
					pointv = 0;
				}
				faces[pos][3].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				faces[pos][3].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				faces[pos][3].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				Vertex temp1 = faces[pos][0];
				Vertex temp2 = faces[pos][3];
				faces[pos][0] = faces[pos][2];
				faces[pos][3] = temp1;
				faces[pos][2] = faces[pos][1];
				faces[pos][1] = temp2;
				pos ++;
			}
		}
	}
}

void Torus::reset() {
	C = 3;
	A = 1;
	x = 0;
	y = 0;
	z = 0;
	grid_size = 30;
}


