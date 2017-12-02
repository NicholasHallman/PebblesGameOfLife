/*
 * 	CP411
 * 	HongBing Fan
 *
 *  Created on: Nov 23, 2017
 *      Authors: 	Nicholas Hallman
 *      			Omid Ghiyasian
 *
 */

#include"main.hpp"

int widthG = 1366;
int heightG = 768;
int pState = 2;
int CSIZE = 20;
bool colorW = false;
float colors[3] = {1,0,0};

Button buttons[20];
bool introVisit = false;
cellMap map;
World myWorld;

Camera myCamera;

void init2D(void) {
	glLoadIdentity();
	glViewport(0,0,widthG,heightG);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, widthG,0.0, heightG);

	//Default grid
	map.size = 20;
	map.cells = (cell **)malloc(map.size*sizeof(cell *));
	for(int i = 0;i < map.size; ++i)
	  	map.cells[i] = (cell *)malloc(map.size*sizeof(cell));
}

void init3D(void) {
	glEnable(GL_CULL_FACE);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	myCamera.setProjectionMatrix();
	pState = 5;
}

void renderer(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(pState){
	case 1:
		// Opens program on the intro screen
		intro();
		drawGrid();
		break;
	case 2:
		//user draws on cell map to add cells;
		drawCells();
		drawGrid();
		toolbar();
		if(colorW){
			drawColorWheel();
		}
		break;
	case 3:
		drawCells();
		drawGrid();
		toolbar();
		if(colorW){
			drawColorWheel();
		}
		break;
		//User watches simulation;
	case 4:
		//User inputs seed for generation, selects shape;
		break;
	case 5:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		myCamera.setProjectionMatrix();
		glColor3f(.4,.4,.4);
		myWorld.draw_world();
		glFlush();
		//Doughnut Simulation;
		break;
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
	/*
	glutGameModeString("1366x768");
	glutEnterGameMode();
	*/
	init2D();
	initButton();
	timer(1);

	glutPassiveMotionFunc(mouseOver);
	glutMouseFunc(mouseClicked);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyRelease);
	glutDisplayFunc(renderer);
	glutMainLoop();
}


int gothrough(){
	for(int x = 0; x < map.size; x++){
		for(int y = 0; y < map.size; y++){
			for(int z = 0; z < map.size; map++){
				checkNeightbors(x,y,z);
			}
		}
	}
}

int checkNeighbors(int x, int y, int z){
	int neighbors = 0;
	for(int i = x - 1; i <= x + 1; i++){
		for(int j = y - 1; j <= j + 1; j ++){
			for(int k = z - 1; z <= k + 1; k++){
				if(i != x && j != y && k != z){
					neighbors += map.cells[(i + map.size) % map.size][(j + map.size) % map.size][(k + map.size) % map.size];
				}

			}
		}
	}
	return neighbors;
}
