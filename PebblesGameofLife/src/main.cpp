/*
 * 	CP411
 * 	HongBing Fan
 *
 *  Created on: Nov 23, 2017
 *      Author: 	Omid Ghiyasian
 *      			Nicholas Hallman
 */

#include"main.hpp"

int widthG = 1280;
int heightG = 720;
int pState = 1;

void init2D(void) {
	glLoadIdentity();
	glViewport(0,0,640,480);
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
		intro();
		break;
	case 2:
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
	glutPostRedisplay();
}

void reshape(int width, int height){
	widthG = width;
	heightG = height;
	init2D();

}

int main(int argv, char* argc[]) {

	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutGameModeString("1280x720");
	glutEnterGameMode();

	glutReshapeFunc(reshape);
	glutDisplayFunc(renderer);
	glutMainLoop();

}
