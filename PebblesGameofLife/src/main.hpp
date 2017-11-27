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
#include"Button.h"
#include"events.hpp"
#include"draw.hpp"
#include"simulate.hpp"
#include"toolbar.h"
#include"camera.h"

using namespace peb;

extern Button buttons[];
extern bool introVisit;
extern int pState;
extern int CSIZE;
extern bool colorW;
extern float colors[];

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

extern cellMap map;

void init2D();

#endif /* MAIN_HPP_ */
