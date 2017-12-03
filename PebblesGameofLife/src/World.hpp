/*
 * World.hpp
 *
 *  Created on: Nov 30, 2017
 *      Author: ghiy2250
 */

#ifndef CWORLD_HPP
#define CWORLD_HPP

#include <iostream>
#include <list>
#include <vector>
#include"main.hpp"


class World {
public:
	Shape* torus[1];
	Shape* list[20][20][20];
	World();
	~World();
	void draw_world(int); // draw all objects in the world
	void reset_world();
};

#endif

