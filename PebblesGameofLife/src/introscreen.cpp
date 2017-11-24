/*
 * introscreen.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#include"introscreen.hpp"

void intro(){
	const unsigned char* t = reinterpret_cast<const unsigned char *>("Pebble's Game of Life");
	glRasterPos2i(100, 650);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, t);
}

void menu1(int value){

}

void introMenu(){
	glutCreateMenu(menu1);
		glutAddMenuEntry("20x20",1);
		glutAddMenuEntry("40x40",2);
		glutAddMenuEntry("60x60",3);
		glutAddMenuEntry("80x80",4);
		glutAddMenuEntry("100x100",5);
		glutAddMenuEntry("150x150",6);
		glutAddMenuEntry("200x200",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}



