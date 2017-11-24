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
#include"Vertex.hpp"

const int height = 26;
const int width = 50;

namespace peb {

class Button {
private:
	const unsigned char * name;
	Vertex position;
public:
	Button();
	void Draw();
	void Name(const unsigned char * name);
	void SetPosition(Vertex newPos);
	virtual ~Button();
};

} /* namespace hall7790 */

#endif /* BUTTON_H_ */
