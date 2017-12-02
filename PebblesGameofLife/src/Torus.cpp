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

	glPushMatrix();
	this->ctm_multiply();
	int x = 0;
	int y = 0;
	for(int i = 0; i < grid_size * grid_size; i++){
		if(map.cells[x][y].newState == 1){
			glColor3f(.0,.3,.8);
		} else{
			glColor3f(.3,.3,.3);
			GLfloat shine[] = {0.5,0.5,0.5,1};
			GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, .3f };
			glMaterialfv(GL_FRONT, GL_SHININESS, shine);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);

		}
		glBegin(GL_QUADS);
			glNormal3d(normals[i].x, normals[i].y, normals[i].z);
			glVertex3f(faces[i][3].x,faces[i][3].y,faces[i][3].z);
			glVertex3f(faces[i][2].x,faces[i][2].y,faces[i][2].z);
			glVertex3f(faces[i][1].x,faces[i][1].y,faces[i][1].z);
			glVertex3f(faces[i][0].x,faces[i][0].y,faces[i][0].z);

		glEnd();

		glColor3f(.5,.5,.5);
		glLineWidth(3);
		glBegin(GL_LINE_STRIP);
			glVertex3f(faces[i][0].x * 1.0005,faces[i][0].y * 1.0005,faces[i][0].z * 1.0005);
			glVertex3f(faces[i][1].x * 1.0005,faces[i][1].y * 1.0005,faces[i][1].z * 1.0005);
			glVertex3f(faces[i][2].x * 1.0005,faces[i][2].y * 1.0005,faces[i][2].z * 1.0005);
			glVertex3f(faces[i][3].x * 1.0005,faces[i][3].y * 1.0005,faces[i][3].z * 1.0005);
		glEnd();

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
	calcNormals();
}

void Torus::reset() {
	C = 3;
	A = 1;
	x = 0;
	y = 0;
	z = 0;
	grid_size = 30;
}

void Torus::calcNormals(){
	//find two vectors on the surface and find their cross product this gives a normal vector
	int i = 0;
	for(i = 0; i < 36*36; i++){
			// get two vectors
		double x1 = faces[i][0].x;
		double y1 = faces[i][0].y;
		double z1 = faces[i][0].z;

		double x2 = faces[i][1].x;
		double y2 = faces[i][1].y;
		double z2 = faces[i][1].z;

		double x3 = faces[i][3].x;
		double y3 = faces[i][3].y;
		double z3 = faces[i][3].z;
		Vertex vector1;
		vector1.x = x2 - x1;
		vector1.y = y2 - y1;
		vector1.z = z2 - z1;

		Vertex vector2;
		vector2.x = x3 - x1;
		vector2.y = y3 - y1;
		vector2.z = z3 - z1;
		normals[i].x = (vector1.y * vector2.z) - (vector2.y * vector1.z);
		normals[i].y = (vector1.z * vector2.x) - (vector2.z * vector1.x);
		normals[i].z = (vector1.x * vector2.y) - (vector2.x * vector1.y);
	}
}


