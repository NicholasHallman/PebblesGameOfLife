/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Nicholas Hallman
 *      	    Omid Ghiyasian
 *
 */

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include"Button.h"
#include"World.hpp"
#include"main.hpp"

extern Button buttons[];
extern World myWorld;
extern bool introVisit;
extern int pState;
extern int CSIZE;
extern bool colorW;
extern float colors[];
extern struct cellMap map;
extern struct cellMap3D map3D;
extern Camera myCamera;
extern bool heatMap;
extern bool perVertex;
extern bool liney;
extern bool glid;
#endif /* GLOBAL_HPP_ */
