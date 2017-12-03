/*
 * events.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: Nicholas Hallman
 *      		Omid Ghiyasian
 */
#include"events.hpp"

int speedX = 0;
int speedY = 0;

int runs = 0;

void mouseOver(int x, int y){
	y = 768 - y;
	int change = 0;
	int index = buttonOver(x, y);

	if(index != -1){
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		change = 1;
		buttons[index].hover = true;
		glutPostRedisplay();
	} else{
		resetHover();
	}


	if(change == 0){
		glutSetCursor(GLUT_CURSOR_INHERIT);
		glutPostRedisplay();
	}

}

void mouseClicked(int button, int state, int x, int y){
	bool leftC = false;
	bool rightC = false;

	if(button == 0 && state == 1) leftC = true;
	if(button == 2 && state == 1) rightC = true;

	if(leftC && colorW){
		glReadPixels(x,768 - y,1,1,GL_RGB,GL_FLOAT, colors);
		colorW = false;
	}

	y = 768 - y;
	int index = buttonOver(x,y);
	if(index != -1 && leftC){
		buttons[index].clicked();
	}

	if(pState == 2 && leftC && y < 730 && !colorW){
		int relX = floor(x - ( floor(1366 - (CSIZE * map.size))/2) - map.x) / CSIZE;
		int relY = floor(y - ( floor((768  - (CSIZE * map.size))/2) - 18) - map.y) / CSIZE;
		if(relX >= 0 && relX < map.size && relY >= 0 && relY < map.size){
			if(map.cells[relX][relY].newState == 1){
				map.cells[relX][relY].newState = 0;
			} else{
				map.cells[relX][relY].newState = 1;
			}
		}
	}

	if((pState == 2 || pState == 3) && rightC){
		map.x = 0;
		map.y = 0;
	}
}

void keyPress(unsigned char key, int x, int y){
	if(pState == 2 || pState == 3){
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
	if(pState == 2 || pState == 3){
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
		if(buttons[i].active){
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

void timer(int x){
	GLfloat rx;
	GLfloat ry;
	GLfloat rz;
	runs ++;
	map.x += speedX;
	map.y += speedY;
	if(runs == 10){
		runs = 0;
		if (pState == 6)
			simulate3D();
		else
			simulate2D();
	}

//	rx = myWorld.torus[0]->getMC().matrix[0][0];
//	ry = myWorld.torus[0]->getMC().matrix[1][0];
//	rz = myWorld.torus[0]->getMC().matrix[2][0];
//	myWorld.torus[0]->rotate_mc(rx,ry,rz,0.3);
//	rx = myWorld.torus[0]->getMC().matrix[0][1];
//	ry = myWorld.torus[0]->getMC().matrix[1][1];
//	rz = myWorld.torus[0]->getMC().matrix[2][1];
//	myWorld.torus[0]->rotate_mc(rx,ry,rz,0.5);
//	rx = myWorld.torus[0]->getMC().matrix[0][2];
//	ry = myWorld.torus[0]->getMC().matrix[1][2];
//	rz = myWorld.torus[0]->getMC().matrix[2][2];
//	myWorld.torus[0]->rotate_mc(rx,ry,rz,0.);

	myCamera.rotate(1.0,0.0,0.0,0.3);
	//myCamera.rotate(0.0,1.0,0.0,0.3);


	if (x)
	glutPostRedisplay();
	glutTimerFunc(16, timer, x);
}


void resetHover(){
	for(int i = 0; i < 20; i++){
		if(buttons[i].position.x != -1){
			buttons[i].hover = false;
		}
	}
}

