/*
 * 	CP411
 * 	HongBing Fan
 *
 *  Created on: Nov 23, 2017
 *      Author: 	Omid Ghiyasian
 *      			Nicholas Hallman
 */

#include"main.hpp"

int widthG = 1366;
int heightG = 768;
int pState = 1;

Button buttons[10];
bool introVisit = false;
cellMap map;

void init2D(void) {
	glLoadIdentity();
	glViewport(0,0,widthG,heightG);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, widthG,0.0, heightG);
}

void init3D() {

}

void renderer(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	switch(pState){
	case 1:
		// Opens program on the intro screen
		intro();

		break;
	case 2:
		drawCells();
		drawGrid();

		toolbar();
		//user draws on cell map to add cells;
		break;
	case 3:
		//User watches simulation;
	case 4:
		//User inputs seed for generation, selects shape;
	case 5:
		//Doughnut Simulation;
	case 6:
		//Volumetric Cube Simulation;
	break;
	}

	glutSwapBuffers();
}

void initButton(){
	for(int i = 0; i < 20; i++){
		buttons[i].active = false;
	}
}

int main(int argv, char* argc[]) {

	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(1366,768);
	glutCreateWindow("Pebble's game of life");

	init2D();
	initButton();
	mapChangePos(1);
	/*
	glutGameModeString("1366x768");
	glutEnterGameMode();
	*/

	glutPassiveMotionFunc(mouseOver);
	glutMouseFunc(mouseClicked);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyRelease);
	glutDisplayFunc(renderer);
	glutMainLoop();

}
