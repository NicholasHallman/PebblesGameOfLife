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
					else if(map.cells[x][y].oldState == FALSE && neighbours == 3)
							newstate = 1;
					map.cells[x][y].newState = newstate;
			}
		}
	}
	glutPostRedisplay();
}
/*
void simulate3D(){
	for(int x = 0; x < map.size; x++){
		for(int y = 0; y < map.size; y++){
			for(int z = 0; z < map.size; map++){
				int neighbors = checkNeightbors3D(x,y,z);
				if(map.cells[x][y].oldState == 1 && (neighbours == 2 || neighbours == 3))
			}
		}
	}
}

int checkNeighbors3D(int x, int y, int z){
	int neighbors = 0;
	for(int i = x - 1; i <= x + 1; i++){
		for(int j = y - 1; j <= j + 1; j ++){
			for(int k = z - 1; z <= k + 1; k++){
				if(i != x && j != y && k != z){
					neighbors += map.cells[(i + map.size) % map.size][(j + map.size) % map.size][(k + map.size) % map.size].oldState;
				}

			}
		}
	}
	return neighbors;
}
*/

