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
		("Welcome! Select a grid size to start. Use the WASD keys to move.");
	glRasterPos2i(10, 700); // positions the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, g);
}



// function executed when b1 is pressed


void startSim(){
	canSim = true;
	pState = 3;
	buttons[5].Name(( const unsigned char*)"Stop");
	buttons[5].onClick(stopSim);
}

void stopSim(){
	canSim = false;
	buttons[5].Name(( const unsigned char*)"Simulate");
	buttons[5].onClick(startSim);
	pState = 2;
}

void addSim(){
	Button sim;
	sim.Name(( const unsigned char*)"Simulate");
	sim.SetPosition(Vertex(1270,735,0));
	sim.onClick(startSim);
	sim.active = true;
	buttons[5] = sim;
}



