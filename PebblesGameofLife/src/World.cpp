/*
 * World.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */


#include "World.hpp"

World::World() {
	list[0] = new Torus();
}

World::~World(){
    delete list[0];
}

void World::draw_world() {
	list[0]->draw();
}

void World::reset_world() {
	list[0]->reset();
}


