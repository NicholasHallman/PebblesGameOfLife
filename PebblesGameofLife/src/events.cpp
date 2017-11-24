/*
 * events.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */
#include"events.hpp"
void mouseOver(int x, int y){
	y = 768 - y;
	int change = 0;
	for(int i = 0; i < 20; i++){
		if(buttons[i].position.x != -1){
			int posX = buttons[i].position.x;
			int posY = buttons[i].position.y;
			if(x > posX && x < posX + 120 && y > posY && y < posY + 26){
				glutSetCursor(GLUT_CURSOR_INFO);
				change = 1;
			}
		}
	}
	if(change == 0){
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}
}

void mouseClicked(int button, int state, int x, int y){
	y = 768 - y;
	if(button == 0 && state == 1){
		for(int i = 0; i < 20; i++){
			if(buttons[i].position.x != -1){
				int posX = buttons[i].position.x;
				int posY = buttons[i].position.y;
				if(x > posX && x < posX + 120 && y > posY && y < posY + 26){
					buttons[i].clicked();
				}
			}
		}
	}
}

