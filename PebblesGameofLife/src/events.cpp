/*
 * events.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Advanderar
 */
#include"events.hpp"

int speedX = 0;
int speedY = 0;

void mouseOver(int x, int y){
	y = 768 - y;
	int change = 0;
	int index = buttonOver(x, y);

	if(index != -1){
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		change = 1;
		buttons[index].hover = true;
	} else{
		resetHover();
	}


	if(change == 0){
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}
	glutPostRedisplay();
}

void mouseClicked(int button, int state, int x, int y){
	y = 768 - y;
	int index = buttonOver(x,y);
	if(index != -1 && button == 0 && state == 1){
		buttons[index].clicked();
	}

	if(pState == 2 && button == 0 && state == 1 && y < 730){
		int relX = floor(x - ( floor(1366 - (12 * map.size))/2) - map.x) / 12;
		int relY = floor(y - ( floor(768  - (12 * map.size))/2) - map.y) / 12;
		if(relX >= 0 && relX < 200 && relY >= 0 && relY < 200){
			if(map.cells[relX][relY].newState == 1){
				map.cells[relX][relY].newState = 0;
			} else{
				map.cells[relX][relY].newState = 1;
			}
		}
	}
}

void keyPress(unsigned char key, int x, int y){
	if(pState == 2){
		switch(key){
		case 'w':
			speedY = -4;
			break;
		case 's':
			speedY = 4;
			break;
		case 'd':
			speedX = -4;
			break;
		case 'a':
			speedX = 4;
			break;
		}

	}
}

void keyRelease(unsigned char key, int x, int y){
	if(pState == 2){
		switch(key){
		case 's':
		case 'w':
			speedY = 0;
			break;
		case 'a':
		case 'd':
			speedX = -0;
			break;
		}
	}
}

int buttonOver(int x, int y){
	for(int i = 0; i < 20; i++){
		if(buttons[i].position.x != -1){
			int posX = buttons[i].position.x;
			int posY = buttons[i].position.y;
			int wide = buttons[i].rWidth;
			if(x > posX && x < posX + wide && y > posY && y < posY + 26){
				return i;
			}
		}
	}
	return -1;
}

void mapChangePos(int x){
	map.x += speedX;
	map.y += speedY;

	if (x)
	glutPostRedisplay();
	glutTimerFunc(16, mapChangePos, x);
}


void resetHover(){
	for(int i = 0; i < 20; i++){
		if(buttons[i].position.x != -1){
			buttons[i].hover = false;
		}
	}
}

