/*
 * Doughnut.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */

#include "Torus.hpp"

int Torus::fact(int a){
	if(a == 0 || a == 1){
		return 1;
	} else{
		return(fact(a - 1) * a);
	}
}

double Torus::comb(int n,int k){
	if(n==k) return 1;
	if (k==0 && n!=0) return 1;
	return( fact(n) / (fact(k) * fact(n-k)) );
}

Torus::Torus() {
	C = 3;
	A = 1;
	x = 0;
	y = 0;
	z = 0;
	B = 1.5;
	grid_size = 36;
	genVertices();
	genLines();
}

void Torus::draw() {

	glPushMatrix();
	this->ctm_multiply();
	int x = 0;
	int y = 0;
	for(int i = 0; i < grid_size * grid_size; i++){
		if(map.cells[x][y].newState == 1){
			if(heatMap){
				double age = (float) map.cells[x][y].age / 10.0;
				if(age > 1) age = 1;
					int n = 2;
					float r = comb(n, 2) * pow((1.0 - age), n - 2) * pow(age, 2) * 1;
					float g = comb(n, 1) * pow((1.0 - age), n - 1) * pow(age, 1) * 1;
					float b = comb(n, 0) * pow((1.0 - age), n - 0) * pow(age, 0) * 1;
					glColor3f(r,g,b);
				} else glColor3f(.0,.6,.8);
		} else{
			glColor3f(.0,.1,.2);
			GLfloat shine[] = {0.9,0.9,0.9,1};
			GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, .3f };
			glMaterialfv(GL_FRONT, GL_SHININESS, shine);
			glMaterialfv(GL_FRONT, GL_SPECULAR, specularLight);

		}
		glBegin(GL_QUADS);
		if(perVertex){
				glNormal3d(vNormals[i][3].x, vNormals[i][3].y, vNormals[i][3].z);
				glVertex3f(faces[i][3].x,faces[i][3].y,faces[i][3].z);

				glNormal3d(vNormals[i][2].x, vNormals[i][2].y, vNormals[i][2].z);
				glVertex3f(faces[i][2].x,faces[i][2].y,faces[i][2].z);

				glNormal3d(vNormals[i][1].x, vNormals[i][1].y, vNormals[i][1].z);
				glVertex3f(faces[i][1].x,faces[i][1].y,faces[i][1].z);

				glNormal3d(vNormals[i][0].x, vNormals[i][0].y, vNormals[i][0].z);
				glVertex3f(faces[i][0].x,faces[i][0].y,faces[i][0].z);
		} else{
				glNormal3d(normals[i].x, normals[i].y, normals[i].z);
				glVertex3f(faces[i][3].x,faces[i][3].y,faces[i][3].z);
				glVertex3f(faces[i][2].x,faces[i][2].y,faces[i][2].z);
				glVertex3f(faces[i][1].x,faces[i][1].y,faces[i][1].z);
				glVertex3f(faces[i][0].x,faces[i][0].y,faces[i][0].z);
		}
		glEnd();
		if(liney){
			glColor3f(.5,.1,.5);
			glLineWidth(3);
			glBegin(GL_LINE_STRIP);
				glNormal3d(normals[i].x, normals[i].y, normals[i].z);
				glVertex3f(lineV[i][0].x ,lineV[i][0].y ,lineV[i][0].z );
				glVertex3f(lineV[i][1].x ,lineV[i][1].y ,lineV[i][1].z );
				glVertex3f(lineV[i][2].x ,lineV[i][2].y ,lineV[i][2].z );
				glVertex3f(lineV[i][3].x ,lineV[i][3].y ,lineV[i][3].z );
				glEnd();
		}
		x++;
		if(x > 35){
			x = 0;
			y++;
		}
		map.cells[x][y].oldState = map.cells[x][y].newState;
	}

	glPopMatrix();
}

void Torus::drawOutline(int i){

}

void Torus::genVertices() {
	A = 1;
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

void Torus::genLines() {
	A = 1.005;
	int pos = 0;
	for (int v = 0; v < grid_size; v++) {
		for (int u = 0; u < grid_size; u++) {
			if(u != grid_size){
				int pointu = u;
				int pointv = v;
				lineV[pos][0].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				lineV[pos][0].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				lineV[pos][0].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u + 1;
				if(pointu == grid_size){
					pointu = 0;
				}
				pointv = v;
				lineV[pos][1].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				lineV[pos][1].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				lineV[pos][1].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u;
				pointv = v + 1;
				if(pointv == grid_size){
					pointv = 0;
				}
				lineV[pos][2].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				lineV[pos][2].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				lineV[pos][2].z = A*(float)sin(pointv*(2*M_PI/grid_size));
				pointu = u + 1;
				if(pointu == grid_size){
					pointu = 0;
				}
				pointv = v + 1;
				if(pointv == grid_size){
					pointv = 0;
				}
				lineV[pos][3].x = (C + A * (float) cos(pointv * (2 * M_PI / grid_size))) * (float) cos(pointu * (2 * M_PI / grid_size));
				lineV[pos][3].y = (C + A*(float)cos(pointv*(2*M_PI/grid_size)))*(float)sin(pointu*(2*M_PI/grid_size));
				lineV[pos][3].z = A*(float)sin(pointv*(2*M_PI/grid_size));

				Vertex temp1 = lineV[pos][0];
				Vertex temp2 = lineV[pos][3];
				lineV[pos][0] = lineV[pos][2];
				lineV[pos][3] = temp1;
				lineV[pos][2] = lineV[pos][1];
				lineV[pos][1] = temp2;

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

void Torus::calcNormals(){
	//find two vectors on the surface and find their cross product this gives a normal vector
	int i = 0;
	for(i = 0; i <= 36*36; i++){
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

		double dist = sqrt(pow(normals[i].x, 2) + pow(normals[i].y, 2) + pow(normals[i].z, 2));
		normals[i].x /= dist;
		normals[i].y /= dist;
		normals[i].z /= dist;
	}
	vertexNormals();
}

void Torus::vertexNormals() {
	int const len = grid_size;
	int const max = len * len;
	int x = 0;
	int y = 0;
	Vertex norms[36][36];
	for(int i = 0; i < 36*36; i++){
		norms[x][y] = normals[i];
		x++;
		if(x == 36){
			x = 0;
			y++;
		}
	}
	int i = 0;
	for(int y = 0; y < 36; y++){
		for(int x = 0; x < 36; x++){
			double avgNormX, avgNormY, avgNormZ = 0;
			avgNormX = (norms[x][y].x
					+ norms[((x - 1) + len) % len][y].x
					+ norms[((x - 1) + len) % len][((y - 1) + len) % len].x
					+ norms[x][((y - 1) + len) % len].x) / 4;

			avgNormY = (norms[x][y].y
					+ norms[((x - 1) + len) % len][y].y
					+ norms[((x - 1) + len) % len][((y - 1) + len) % len].y
					+ norms[x][((y - 1) + len) % len].y) / 4;

			avgNormZ = (norms[x][y].z
					+ norms[((x - 1) + len) % len][y].z
					+ norms[((x - 1) + len) % len][((y - 1) + len) % len].z
					+ norms[x][((y - 1) + len) % len].z) / 4;
			vNormals[i][3].x = avgNormX;
			vNormals[i][3].y = avgNormY;
			vNormals[i][3].z = avgNormZ;

			avgNormX = (norms[x][y].x
					+ norms[((x + 1) + len) % len][y].x
					+ norms[((x + 1) + len) % len][((y - 1) + len) % len].x
					+ norms[x][((y - 1) + len) % len].x) / 4;
			avgNormY = (norms[x][y].y
					+ norms[((x + 1) + len) % len][y].y
					+ norms[((x + 1) + len) % len][((y - 1) + len) % len].y
					+ norms[x][((y - 1) + len) % len].y) / 4;
			avgNormZ = (norms[x][y].z
					+ norms[((x + 1) + len) % len][y].z
					+ norms[((x + 1) + len) % len][((y - 1) + len) % len].z
					+ norms[x][((y - 1) + len) % len].z) / 4;
			vNormals[i][2].x = avgNormX;
			vNormals[i][2].y = avgNormY;
			vNormals[i][2].z = avgNormZ;

			avgNormX = (norms[x][y].x
					+ norms[((x - 1) + len) % len][y].x
					+ norms[((x - 1) + len) % len][((y + 1) + len) % len].x
					+ norms[x][((y + 1) + len) % len].x) / 4;
			avgNormY = (norms[x][y].y
					+ norms[((x - 1) + len) % len][y].y
					+ norms[((x - 1) + len) % len][((y + 1) + len) % len].y
					+ norms[x][((y + 1) + len) % len].y) / 4;
			avgNormZ = (norms[x][y].z
					+ norms[((x - 1) + len) % len][y].z
					+ norms[((x - 1) + len) % len][((y + 1) + len) % len].z
					+ norms[x][((y + 1) + len) % len].z) / 4;
			vNormals[i][0].x = avgNormX;
			vNormals[i][0].y = avgNormY;
			vNormals[i][0].z = avgNormZ;

			avgNormX = (norms[x][y].x
					+ norms[((x + 1) + len) % len][y].x
					+ norms[((x + 1) + len) % len][((y + 1) + len) % len].x
					+ norms[x][((y + 1) + len) % len].x) / 4;
			avgNormY = (norms[x][y].y
					+ norms[((x + 1) + len) % len][y].y
					+ norms[((x + 1) + len) % len][((y + 1) + len) % len].y
					+ norms[x][((y + 1) + len) % len].y) / 4;
			avgNormZ = (norms[x][y].z
					+ norms[((x + 1) + len) % len][y].z
					+ norms[((x + 1) + len) % len][((y + 1) + len) % len].z
					+ norms[x][((y + 1) + len) % len].z) / 4;
			vNormals[i][1].x = avgNormX;
			vNormals[i][1].y = avgNormY;
			vNormals[i][1].z = avgNormZ;


			i++;
		}
	}
}


