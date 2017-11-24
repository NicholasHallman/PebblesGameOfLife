/*
 * draw.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */

#include"main.hpp"


void drawGrid(){
	int width = 12 * map.size;
	int height = 12 * map.size;
	int startx = (1366 - width) / 2;
	int starty = (730 - height) / 2;
	glColor3f(.4,.4,.4);
	glBegin(GL_LINE_LOOP);
		glVertex2d(startx + map.x,starty + map.y);
		glVertex2d(startx + map.x,height + starty + map.y);
		glVertex2d(width + startx + map.x, height + starty + map.y);
		glVertex2d(width + startx + map.x,starty + map.y);
	glEnd();
	glColor3f(.4,.4,.4);

	glBegin(GL_LINES);
	for(int x = startx + map.x; x < width + startx + map.x; x += width / map.size){
		glVertex2d(x,starty + map.y);
		glVertex2d(x,starty + height + map.y);
	}
	for(int y = starty + map.y; y < height + starty + map.y; y += height / map.size){
		glVertex2d(startx + map.x, y);
		glVertex2d(startx + width + map.x, y);
	}
	glEnd();
}

void drawCells(){
	int width = 12 * map.size;
	int height = 12 * map.size;
	int startx = (1366 - width) / 2;
	int starty = (768 - height) / 2;

	starty -= 6;

	for(int y = 0; y < map.size; y++){
		for(int x = 0; x < map.size; x++){
			if(map.cells[x][y].newState == 1){
				glColor3f(1.0,0.0,0.0);
				glBegin(GL_QUADS);
					glVertex2d(map.x + startx + (x * 12)      , map.y + starty + ((y + 1) * 12));
					glVertex2d(map.x + startx + ((x + 1) * 12), map.y + starty + ((y + 1) * 12));
					glVertex2d(map.x + startx + ((x + 1) * 12), map.y + starty + (y * 12));
					glVertex2d(map.x + startx + (x * 12)      , map.y + starty + (y * 12));
				glEnd();
			}
		}
	}
}

