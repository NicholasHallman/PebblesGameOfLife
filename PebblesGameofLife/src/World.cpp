/*
 * World.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */


#include "main.hpp"

World::World() {

	torus[0] = new Torus();

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++) {
				list[i][j][k] = new Cube();
				glPushMatrix();
				list[i][j][k]->translate((GLfloat)i-10 + (0.25 * i),(GLfloat)j-10 + (0.25 * j),(GLfloat)k-10 + (0.25 * k));
				glPopMatrix();
			}
		}
	}
}

World::~World(){

	delete torus[0];

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++) {
				delete list[i][j][k];
			}
		}
	}
}

void World::draw_world(int item) {
	if (item == 5)
		torus[0]->draw();
	else if (item == 6){
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 0; k < 20; k++) {
					if(map3D.cells[i][j][k].newState == 1) list[i][j][k]->draw();
					else if(i == 0 || j == 0 || k == 0) {
						if(i == 0) list[i][j][k]->drawOutline(3);
						if(j == 0) list[i][j][k]->drawOutline(5); // good
						if(k == 0) list[i][j][k]->drawOutline(0); // good
					}
					map3D.cells[i][j][k].oldState = map3D.cells[i][j][k].newState;
				}
			}
		}
	}
}

void World::reset_world() {
	torus[0]->reset();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			for (int k = 0; k < 20; k++) {
				list[i][j][k]->reset();
			}
		}
	}
}


