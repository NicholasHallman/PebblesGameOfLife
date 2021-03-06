/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Nicholas Hallman
 *      	    Omid Ghiyasian
 *
 */

#ifndef INTROSCREEN_HPP_
#define INTROSCREEN_HPP_

#include<GL/freeglut.h>
#include"Button.h"
#include"main.hpp"
#include"simulate.hpp"
#include"toolbar.h"

void intro(void);

void startSim(void);
void stopSim(void);
void quitProgram(void);
void addSim();

#endif /* INTROSCREEN_HPP_ */
