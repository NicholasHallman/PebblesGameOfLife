/*
 * draw.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */

#include"main.hpp"


void drawGrid(){
	int width = CSIZE * map.size;
	int height = CSIZE * map.size;
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
	int width = CSIZE * map.size;
	int height = CSIZE * map.size;
	int startx = (1366 - width) / 2;
	int starty = (768 - height) / 2;

	starty -= 18;

	for(int y = 0; y < map.size; y++){
		for(int x = 0; x < map.size; x++){
			if(map.cells[x][y].newState == 1){
				glColor3f(colors[0],colors[1],colors[2]);
				glBegin(GL_QUADS);
					glVertex2d(map.x + startx + (x * CSIZE)      , map.y + starty + ((y + 1) * CSIZE));
					glVertex2d(map.x + startx + ((x + 1) * CSIZE), map.y + starty + ((y + 1) * CSIZE));
					glVertex2d(map.x + startx + ((x + 1) * CSIZE), map.y + starty + (y * CSIZE));
					glVertex2d(map.x + startx + (x * CSIZE)      , map.y + starty + (y * CSIZE));
				glEnd();
			}
			map.cells[x][y].oldState = map.cells[x][y].newState;
		}
	}
}

void drawColorWheel(){
	glColor3f(.2,.25,.3);
	glBegin(GL_QUADS);
		glVertex2d(218,654);
		glVertex2d(488,114);
		glVertex2d(1138,114);
		glVertex2d(858,654);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,1);
		glVertex2d(818,634);
		glColor3f(.5,.5,.5);
		glVertex2d(568,134);
		glColor3f(0,0,0);
		glVertex2d(1078,134);

		glColor3f(1,0,0);
		glVertex2d(518,134);
		glColor3f(0,1,0);
		glVertex2d(268,634);
		glColor3f(0,0,1);
		glVertex2d(768,634);


	glEnd();
}

