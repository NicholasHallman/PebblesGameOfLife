/*
 * Button.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */

#include "Button.h"

namespace peb {

Button::Button() {
	clickFunc = NULL;
	name = (unsigned char*)"";
	position.setVertex(-1,-1,-1);
	// TODO Auto-generated constructor stub
}

Button::~Button() {
	// TODO Auto-generated destructor stub
}

void Button::Draw(){
	glColor3f(1,1,1);
	int nWidth = 0;
	for(int i = 0; i < strlen((char *)name); i++){
		nWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, name[i]);
	}
	nWidth += 10;
	glBegin(GL_QUADS);
		glVertex2f(position.x,position.y);
		glVertex2f(position.x + nWidth,position.y);
		glVertex2f(position.x + nWidth,position.y + height);
		glVertex2f(position.x ,position.y + height);
	glEnd();
	glColor3f(0,0,0);
	glRasterPos2i(position.x + 5, position.y + 7);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, name);
}

void Button::Name(const unsigned char* name){
	this->name = name;
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
