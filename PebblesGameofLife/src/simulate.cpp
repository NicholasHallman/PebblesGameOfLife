/*
 * simulate.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */
#include"simulate.hpp"

bool canSim = false;

void genCells(){
	for(int i = 0; i < map.size; i++){
		for(int j = 0; j < map.size; j++){
			if(( (float)rand() / (float)RAND_MAX )  > .5){
				map.cells[i][j].oldState = 1;
			}
			else{
				map.cells[i][j].oldState = 0;
			}
		}
	}
}

void simulate2D(){
	if(canSim){
		int neighbours;
		int newstate;
		for(int y = 0; y < map.size; y++){
			for(int x = 0; x < map.size; x++){
					//Calculate the number of live processes around the cell
					neighbours = 	map.cells[(x - 1 + map.size) % map.size][y].oldState +
							map.cells[(x - 1 + map.size) % map.size][(y - 1 + map.size) % map.size].oldState +
							map.cells[(x - 1 + map.size) % map.size][(y + 1) % map.size].oldState +
							map.cells[(x + 1) % map.size][y].oldState +
							map.cells[(x + 1) % map.size][(y - 1 + map.size) % map.size].oldState +
							map.cells[(x + 1) % map.size][(y + 1) % map.size].oldState +
							map.cells[x][(y - 1 + map.size) % map.size].oldState +
							map.cells[x][(y + 1) % map.size].oldState;
					newstate = 0;
					//Update the cell's newstate based on the neighbours
					if(map.cells[x][y].oldState == 1 && (neighbours == 2 || neighbours == 3))
						newstate = 1;
					else if(map.cells[x][y].oldState == FALSE && neighbours == 3)
							newstate = 1;
					map.cells[x][y].newState = newstate;
			}
		}
	}
	glutPostRedisplay();
}


