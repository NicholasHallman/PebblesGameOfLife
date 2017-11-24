/*
 * introscreen.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#include"introscreen.hpp"

using namespace peb;


// The programs title screen
void intro(){
	toolbar();
	glColor3f(1,1,1);
	const unsigned char* g = reinterpret_cast<const unsigned char *>
		("Welcome! Select a grid size to start.");
	glRasterPos2i(10, 700); // positions the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, g);
}

void toolbar(){
	glColor3f(.3,.35,.4);
	glBegin(GL_QUADS);
		glVertex2f(0,768);
		glVertex2f(1366,768);
		glVertex2f(1366,730);
		glVertex2f(0,730);
	glEnd();

	glColor3f(1,1,1); //sets text color to white
	const unsigned char* t = reinterpret_cast<const unsigned char *>("Pebble's Game of Life");
	glRasterPos2i(10, 740); // positions the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, t); //prints the text to the screen

	if(!introVisit){
		int bh = 735;
		Button s20; // create a new button
		s20.Name(( const unsigned char*)"20x20"); //name the button (acts as button text)
		s20.SetPosition(Vertex(210,bh,0)); //set the buttons position
		s20.onClick(but1); // set the function to activate when the button is pressed
		buttons[0] = s20; // add the button to the button draw array

		Button s50;
		s50.Name(( const unsigned char*)"50x50");
		s50.SetPosition(Vertex(s20.position.x + s20.rWidth + 10,bh,0));
		s50.onClick(but2);
		buttons[1] = s50;

		Button s100;
		s100.Name(( const unsigned char*)"100x100");
		s100.SetPosition(Vertex(s50.position.x + s50.rWidth + 10,bh,0));
		s100.onClick(but3);
		buttons[2] = s100;

		Button s150;
		s150.Name(( const unsigned char*)"150x150");
		s150.SetPosition(Vertex(s100.position.x + s100.rWidth + 10,bh,0));
		s150.onClick(but4);
		buttons[3] = s150;

		Button s200;
		s200.Name(( const unsigned char*)"200x200");
		s200.SetPosition(Vertex(s150.position.x + s150.rWidth + 10,bh,0));
		s200.onClick(but5);
		buttons[4] = s200;
	}

	buttons[0].Draw(); // draw the button
	buttons[1].Draw();
	buttons[2].Draw();
	buttons[3].Draw();
	buttons[4].Draw();
	introVisit = true;
}

// function executed when b1 is pressed
void but1(){
	map.size = 20;
	pState = 2;
}

void but2(){
	map.size = 50;
	pState = 2;
}

void but3(){
	map.size = 100;
	pState = 2;
}

void but4(){
	map.size = 150;
	pState = 2;
}

void but5(){
	map.size = 200;
	pState = 2;
}



