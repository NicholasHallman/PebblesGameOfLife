/*
 * events.hpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#ifndef EVENTS_HPP_
#define EVENTS_HPP_

#include"main.hpp"
#include<math.h>
#include<time.h>
#include<GL/freeglut.h>

void mouseOver(int x, int y);

void mouseClicked(int button, int state, int x, int y);

void keyPress(unsigned char key, int x, int y);

void keyRelease(unsigned char key, int x, int y);

int buttonOver(int x, int y);

void mapChangePos(int x);

void resetHover();

#endif /* EVENTS_HPP_ */
