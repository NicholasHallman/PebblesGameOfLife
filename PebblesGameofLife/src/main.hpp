/*
 * main.hpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include"introscreen.hpp"
#include"events.hpp"
#include"draw.hpp"
#include"simulate.hpp"
#include"toolbar.h"
#include"camera.h"
#include"Shape.hpp"
#include"global.hpp"
#include"Torus.hpp"
#include"Cube.hpp"

using namespace peb;

typedef struct cell{
	int newState;
	int oldState;
	int age;
}cell;

typedef struct cellMap{
	int size;
	int x;
	int y;
	cell** cells;
	// if you can figure out how to make
	// this dynamic plz do
}cellMap;

typedef struct cellMap3D {
	int size;
	int x;
	int y;
	int z;
	cell*** cells;
}cellMap3D;

void init2D();
void init3D();

#endif /* MAIN_HPP_ */
