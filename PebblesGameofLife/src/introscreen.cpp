/*
 * introscreen.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#include"introscreen.hpp"

using namespace peb;

void intro(){
	glColor3f(1,1,1);
	const unsigned char* t = reinterpret_cast<const unsigned char *>("Pebble's Game of Life");
	glRasterPos2i(100, 740);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, t);

	if(!introVisit){
		Button s20;
		s20.Name(( const unsigned char*)"20x20");
		s20.SetPosition(Vertex(10,10,0));
		s20.onClick(but1);
		buttons[0] = s20;

		Button s40;
		s40.Name(( const unsigned char*)"40x40");
		s40.SetPosition(Vertex(140,10,0));
		s40.onClick(but2);
		buttons[1] = s40;
	}

	buttons[0].Draw();
	buttons[1].Draw();
	introVisit = true;
}

void but1(){
	printf("set 20x20! \n");
}

void but2(){
	printf("set 40x40! \n");
}



