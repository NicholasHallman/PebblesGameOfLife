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

using namespace peb;

extern Button buttons[];
extern bool introVisit;

typedef struct cell{
	int newState;
	int oldState;
	int age;
}cell;

typedef struct cellMap{
	int size;
	cell map[];
}cellMap;


#endif /* MAIN_HPP_ */
