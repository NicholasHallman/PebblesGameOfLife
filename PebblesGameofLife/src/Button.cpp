/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Nicholas Hallman
 *      	    Omid Ghiyasian
 *
 */

#include "Button.h"
#include "main.hpp"

namespace peb {

Button::Button() {
	rWidth = -1;
	hover = false;
	broken = false;
	active = false;
	clickFunc = NULL;
	name = (unsigned char*)"";
	position.setVertex(-1,-1,-1);
	// TODO Auto-generated constructor stub
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::Draw(){
	// if the mouse is over the button make it white
	if(hover){
		if (this->id == 10)
			if (canSim == false)
				glColor3f(0.5, 1.0, 0.5);
			else
				glColor3f(0.8, 0.3, 0.3);
		else if (this->id == 11)
			glColor3f(0.8, 0.3, 0.3);
		else
			glColor3f(1.0,1.0,1.0);
	} else{
		// otherwise make it gray
		if (this->id == 10)
			if (canSim == true)
				glColor3f(0.6, 0.2, 0.2);
			else
				glColor3f(0.3, 0.8, 0.3);
		else if (this->id == 11)
			glColor3f(0.6, 0.2, 0.2);
		else if(this->id == 13 && heatMap) glColor3f(0.3, 0.8, 0.3);
		else if(this->id == 16 && glid) glColor3f(0.3, 0.8, 0.3);
		else
			glColor3f(.5,.55,.6);
	}
	//draws a rectangle that is 26 pixels tall and the
	//length of the name wide plus a 5 pixel buffer
	glBegin(GL_QUADS);
		glVertex2f(position.x,position.y);
		glVertex2f(position.x + rWidth,position.y);
		glVertex2f(position.x + rWidth,position.y + height);
		glVertex2f(position.x ,position.y + height);
	glEnd();
	//sets the color to black to draw the text
	glColor3f(0,0,0);
	glRasterPos2i(position.x + 5, position.y + 7);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, name);
}

void Button::DrawBroken(){
	// if the mouse is over the button make it broken color
	if(hover){
		glColor3f(.6,0,0);
	} else{
		// otherwise make it gray
		glColor3f(.6,.3,.3);
	}
	//draws a rectangle that is 26 pixels tall and the
	//length of the name wide plus a 5 pixel buffer
	glBegin(GL_QUADS);
		glVertex2f(position.x,position.y);
		glVertex2f(position.x + rWidth,position.y);
		glVertex2f(position.x + rWidth,position.y + height);
		glVertex2f(position.x ,position.y + height);
	glEnd();
	//sets the color to black to draw the text
	glColor3f(0,0,0);
	glRasterPos2i(position.x + 5, position.y + 7);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, name);
}

void Button::Name(const unsigned char* name){
	//sets the buttons text
	rWidth = 0;
	this->name = name;
	//goes through every character and adds the length of the character to a
	//variable used to determine the width of the button
	for(int i = 0; i < (int)strlen((char *)name); i++){ //This gives a warning but it works
		rWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, name[i]);
	}
	rWidth += 10;
}

void Button::SetPosition(Vertex newPos){
	position = newPos;
}

void Button::onClick(void (*f)(void)){
	this->clickFunc = f;
}

void Button::clicked(){
	if(clickFunc != NULL){
		clickFunc();
	}
}
} /* namespace hall7790 */
