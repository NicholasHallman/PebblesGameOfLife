/*
 * header.hpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */

#ifndef SIMULATE_HPP_
#define SIMULATE_HPP_

#include"main.hpp"

void simulate2D();
void simulate3D();
void genCells();
void gen3DCells();
int checkNeighbor(int , int, int);

extern bool canSim;


#endif /* SIMULATE_HPP_ */
