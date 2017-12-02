/*
 * simulate.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */
#include"simulate.hpp"

bool canSim = false;

void genCells(){
	/*
	for(int i = 0; i < map.size; i++){
		for(int j = 0; j < map.size; j++){
			if(( (float)rand() / (float)RAND_MAX )  > .2){
				map.cells[i][j].oldState = 1;
			}
			else{
				map.cells[i][j].oldState = 0;
			}
		}
	}
	*/
	map.cells[10][10].newState = 1;
	map.cells[10][9].newState = 1;
	map.cells[10][8].newState = 1;
	map.cells[9][8].newState = 1;
	map.cells[8][9].newState = 1;
	map.cells[20][20].newState = 1;
	map.cells[20][19].newState = 1;
	map.cells[20][18].newState = 1;
	map.cells[19][18].newState = 1;
	map.cells[18][19].newState = 1;
	map.cells[30][30].newState = 1;
	map.cells[30][29].newState = 1;
	map.cells[30][28].newState = 1;
	map.cells[29][28].newState = 1;
	map.cells[28][29].newState = 1;
	map.cells[5][5].newState = 1;
	map.cells[5][4].newState = 1;
	map.cells[5][3].newState = 1;
	map.cells[4][3].newState = 1;
	map.cells[3][4].newState = 1;
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
					else if(map.cells[x][y].oldState == 0 && neighbours == 3)
							newstate = 1;
					map.cells[x][y].newState = newstate;
			}
		}
	}
	glutPostRedisplay();
}

void simulate3D(){
	if(canSim){
		int neighbors;
		int newstate;
		// DISCLAIMER: DO NOT TRY THIS AT HOME KIDS!!!!
		for(int z = 0; z < map.size; z++){
			for(int y = 0; y < map.size; y++){
				for(int x = 0; x < map.size; x++){
					neighbors = map3D.cells[(x - 1 + map3D.size) % map3D.size][y][z].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][z].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][z].oldState +
							map3D.cells[(x + 1) % map3D.size][y][z].oldState +
							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][z].oldState +
							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][z].oldState +
							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][z].oldState +
							map3D.cells[x][(y + 1) % map3D.size][z].oldState +
							map3D.cells[x][y][(z + 1) % map3D.size].oldState +
							map3D.cells[x][y][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][y][(z + 1) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][y][(z + 1) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[x][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][y][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][y][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
							map3D.cells[x][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState;
					newstate = 0;
					//Update the cell's newstate based on the neighbours
					if(map3D.cells[x][y][z].oldState == 1 && (neighbors == 4 || neighbors == 5))
						newstate = 1;
					else if(map3D.cells[x][y][z].oldState == 0 && neighbors == 5)
							newstate = 1;
					map3D.cells[x][y][z].newState = newstate;
				}
			}
		}
	}
}


