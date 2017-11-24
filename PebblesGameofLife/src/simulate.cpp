/*
 * simulate.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */
#include"simulate.hpp"

bool canSim = false;

void simulate2D(){
	if(canSim){
		for(int y = 0; y < map.size; y++){
			for(int x = 0; x < map.size; x++){
				int n = 0;
				if(y != 0){
					if(x != 0 && map.cells[x-1][y-1].oldState == 1) n++;
					if(map.cells[x][y-1].oldState == 1)   n++;
					if(x != 199 && map.cells[x+1][y-1].oldState == 1) n++;
				}

				if(x != 0 && map.cells[x-1][y].oldState == 1)   n++;
				if(x != 199 && map.cells[x+1][y].oldState == 1)   n++;

				if(y != 199){
					if(x != 0 && map.cells[x-1][y+1].oldState == 1) n++;
					if(map.cells[x][y+1].oldState == 1)   n++;
					if(x != 199 && map.cells[x+1][y+1].oldState == 1) n++;
				}

				if(map.cells[x][y].oldState == 1){
					if(n < 2) map.cells[x][y].newState = 0;
					else if(n > 3) map.cells[x][y].newState = 0;
					else map.cells[x][y].newState = 1;
				} else{
					if(n == 3) map.cells[x][y].newState = 1;
				}
			}
		}
	}
	glutPostRedisplay();
}


