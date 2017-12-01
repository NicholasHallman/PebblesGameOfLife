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
#include "Torus.hpp"


class World {
public:
	Shape* list[1];
	World();
	~World();
	void draw_world(); // draw all objects in the world
	void reset_world();
};

#endif

