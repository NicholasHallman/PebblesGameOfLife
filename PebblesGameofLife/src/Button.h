/*
 * toolbar.h
 *
 *  Created on: Nov 24, 2017
 *      Author: Nicholas Hallman
 *      	    Omid Ghiyasian
 *
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include<GL/freeglut.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include"Vertex.hpp"
#include"string.h"

const int height = 26;
const int width = 120;

namespace peb {

class Button {
private:
	void (*clickFunc)(void);
	const unsigned char * name;
public:
	int id;
	bool active;
	bool broken;
	bool hover;
	int rWidth;
	Vertex position;
	Button();
	void Draw();
	void DrawBroken();
	void Name(const unsigned char * name);
	void SetPosition(Vertex newPos);
	void onClick(void (*f)(void));
	void clicked();
	virtual ~Button();
};

} /* namespace hall7790 */

#endif /* BUTTON_H_ */
