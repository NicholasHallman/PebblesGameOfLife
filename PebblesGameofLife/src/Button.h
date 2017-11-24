/*
 * Button.h
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
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
	Vertex position;
	Button();
	void Draw();
	void Name(const unsigned char * name);
	void SetPosition(Vertex newPos);
	void onClick(void (*f)(void));
	void clicked();
	virtual ~Button();
};

} /* namespace hall7790 */

#endif /* BUTTON_H_ */
