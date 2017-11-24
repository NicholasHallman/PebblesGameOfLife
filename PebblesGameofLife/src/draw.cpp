/*
 * draw.cpp
 *
 *  Created on: Nov 24, 2017
 *      Author: Advanderar
 */

#include"main.hpp"


void drawGrid(){
	int width = 600;
	int height = 600;
	int startx = 383;
	int starty = 65;
	glColor3f(.4,.4,.4);
	glBegin(GL_LINE_LOOP);
		glVertex2d(startx,starty);
		glVertex2d(startx,height + starty);
		glVertex2d(width + startx, height + starty);
		glVertex2d(width + startx,starty);
	glEnd();
	glColor3f(.4,.4,.4);

	glBegin(GL_LINES);
	for(int x = startx; x < width + startx; x += width / map.size){
		glVertex2d(x,starty);
		glVertex2d(x,starty + height);
	}
	for(int y = starty; y < height + starty; y += height / map.size){
		glVertex2d(startx, y);
		glVertex2d(startx + width, y);
	}
	glEnd();
}

