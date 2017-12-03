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

void gen3DCells() {
	map3D.cells[0][1][0].newState = 1;
	map3D.cells[0][2][0].newState = 1;
	map3D.cells[1][0][0].newState = 1;
	map3D.cells[2][0][0].newState = 1;
	map3D.cells[3][1][0].newState = 1;
	map3D.cells[3][2][0].newState = 1;
	map3D.cells[1][1][1].newState = 1;
	map3D.cells[2][1][1].newState = 1;
	map3D.cells[1][2][1].newState = 1;
	map3D.cells[2][2][1].newState = 1;
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
		for(int z = 0; z < map3D.size; z++){
			for(int y = 0; y < map3D.size; y++){
				for(int x = 0; x < map3D.size; x++){
					neighbors = checkNeighbor(x,y,z);

//							map3D.cells[(x - 1 + map3D.size) % map3D.size][y][z].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][z].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][z].oldState +
//							map3D.cells[(x + 1) % map3D.size][y][z].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][z].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][z].oldState +
//							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][z].oldState +
//							map3D.cells[x][(y + 1) % map3D.size][z].oldState +
//							map3D.cells[x][y][(z + 1) % map3D.size].oldState +
//							map3D.cells[x][y][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][y][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][y][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[x][(y + 1) % map3D.size][(z + 1) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][y][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x - 1 + map3D.size) % map3D.size][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][y][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[(x + 1) % map3D.size][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[x][(y - 1 + map3D.size) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState +
//							map3D.cells[x][(y + 1) % map3D.size][(z - 1 + map3D.size) % map3D.size].oldState;
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

int checkNeighbor(int x, int y, int z) {
	int count = 0;
	for(int i = x - 1; i <= x + 1; i++)
		for(int j = y - 1; j <= y + 1; j++)
			for(int k = z - 1; k <= z + 1; k++)
				if (i != x || j != y || k != z)
					count = count + map3D.cells[(i + map3D.size) % map3D.size][(j + map3D.size) % map3D.size][(k + map3D.size) % map3D.size].oldState;
	return count;
}

