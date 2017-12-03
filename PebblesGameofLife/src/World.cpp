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
				list[i][j][k]->translate((GLfloat)i-10,(GLfloat)j-10,(GLfloat)k-10);
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
					list[i][j][k]->draw();
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


