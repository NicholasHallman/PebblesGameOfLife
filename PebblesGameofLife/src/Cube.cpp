/*
 * Cube.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: ghiy2250
 */

#include "Cube.hpp"

Cube::Cube() {
	vertex[0][0] = -0.5;vertex[0][1] = -0.5;vertex[0][2] = -0.5;
	vertex[1][0] = -0.5;vertex[1][1] = 0.5; vertex[1][2] = -0.5;
	vertex[2][0] = 0.5;vertex[2][1] = -0.5; vertex[2][2] = -0.5;
	vertex[3][0] = 0.5;vertex[3][1] = 0.5;vertex[3][2] = -0.5;
	vertex[4][0] = -0.5;vertex[4][1] = -0.5;vertex[4][2] = 0.5;
	vertex[5][0] = -0.5;vertex[5][1] = 0.5; vertex[5][2] = 0.5;
	vertex[6][0] = 0.5;vertex[6][1] = -0.5;vertex[6][2] = 0.5;
	vertex[7][0] = 0.5;vertex[7][1] = 0.5;vertex[7][2] = 0.5;

    face[0][0] = 0;face[0][1] = 1;face[0][2] = 3;face[0][3] = 2;
    face[1][0] = 3;face[1][1] = 7;face[1][2] = 6;face[1][3] = 2;
    face[2][0] = 7;face[2][1] = 5;face[2][2] = 4;face[2][3] = 6;
    face[3][0] = 4;face[3][1] = 5;face[3][2] = 1;face[3][3] = 0;
    face[4][0] = 5;face[4][1] = 7;face[4][2] = 3;face[4][3] = 1;
    face[5][0] = 6;face[5][1] = 4;face[5][2] = 0;face[5][3] = 2;

    calcNormals();
}

void Cube::draw_face(int i) {
	glColor3f(.0,.1,.2);
	glEnable( GL_LINE_SMOOTH );
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
		glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
	glColor4f(0.2,1.0,0.0,0.8);
	glBegin(GL_QUADS);
		glNormal3d(normals[i].x, normals[i].y, normals[i].z);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
		glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
}

void Cube::drawOutline(int i) {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	glEnable( GL_LINE_SMOOTH );
	glLineWidth(1);
	glColor3f(.1, .7, .0);
	glBegin(GL_LINE_LOOP);
		glNormal3d(normals[i].x, normals[i].y, normals[i].z);
		glVertex3fv(&vertex[face[i][0]][0]);
		glVertex3fv(&vertex[face[i][1]][0]);
		glVertex3fv(&vertex[face[i][2]][0]);
		glVertex3fv(&vertex[face[i][3]][0]);
	glEnd();
	glPopMatrix();
}

void Cube::draw() {
	glPushMatrix();
	this->ctm_multiply();
	glScalef(s, s, s);
	for (int i = 0; i < 6; i++) {
		draw_face(i);
	}
	glPopMatrix();
}

void Cube::draw_simple()
{
    for (int i = 0; i < 6; i++) {
        draw_face(i);
    }
}

void Cube::calcNormals(){
	//find two vectors on the surface and find their cross product this gives a normal vector
	int i = 0;
	for(i = 0; i < 6; i++){
			// get two vectors
		double x1 = vertex[face[i][0]][0];
		double y1 = vertex[face[i][0]][1];
		double z1 = vertex[face[i][0]][2];

		double x2 = vertex[face[i][1]][0];
		double y2 = vertex[face[i][1]][1];
		double z2 = vertex[face[i][1]][2];

		double x3 = vertex[face[i][3]][0];
		double y3 = vertex[face[i][3]][1];
		double z3 = vertex[face[i][3]][2];

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


