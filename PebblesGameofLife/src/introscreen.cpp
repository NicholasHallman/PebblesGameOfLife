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
		s20.SetPosition(Vertex(10,30,0));
		s20.onClick(but1);
		buttons[0] = s20;

		Button s50;
		s50.Name(( const unsigned char*)"50x50");
		s50.SetPosition(Vertex(140,30,0));
		s50.onClick(but2);
		buttons[1] = s50;

		Button s100;
		s100.Name(( const unsigned char*)"100x100");
		s100.SetPosition(Vertex(270,30,0));
		s100.onClick(but3);
		buttons[2] = s100;
	}

	buttons[0].Draw();
	buttons[1].Draw();
	buttons[2].Draw();
	introVisit = true;
}

void but1(){
	printf("set 20x20! \n");
}

void but2(){
	printf("set 50x50! \n");
}

void but3(){
	printf("set 100x100! \n");
}



