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
	glColor3f(1.0,0,0);
	glBegin(GL_POLYGON);

	glEnd();

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
