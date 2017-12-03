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
bool introVisit = true;
cellMap map;
cellMap3D map3D;
World myWorld;

Camera myCamera;

void init2D(void) {
	glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0,1366.0,0.0,768.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glClear(GL_DEPTH_BUFFER_BIT);


	/*
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1366.0,0.0,768.0);
	glMatrixMode(GL_MODELVIEW);
	*/
}

void initCells(){
	map.size = 20;
	map.cells = (cell **)calloc(map.size,sizeof(cell *));
	for(int i = 0;i < map.size; ++i)
	  	map.cells[i] = (cell *)calloc(map.size,sizeof(cell));

	map3D.size = 20;
	map3D.cells = (cell ***)calloc(map3D.size, sizeof(cell **));
	for(int i = 0;i < map3D.size; ++i) {
		map3D.cells[i] = (cell **)calloc(map3D.size,sizeof(cell *));
		for(int j = 0;j < map3D.size; ++j)
			map3D.cells[i][j] = (cell *)calloc(map3D.size,sizeof(cell));
	}
}

void initLighting(void) {

	glShadeModel(GL_SMOOTH);


	// Create light components
	GLfloat ambientLight[] = { 0.5f, 0.6f, 0.7f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { -1.0f, -1.0f, 0.0f, 0.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
    // Assign created components to GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
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
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		myCamera.setProjectionMatrix();
		initLighting();
		myWorld.draw_world(pState);

		init2D();
		toolbar3D();
		glMatrixMode(GL_PROJECTION);
		//glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		//Doughnut Simulation;

		break;
	case 6:
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		myCamera.setProjectionMatrix();
		initLighting();
		myWorld.draw_world(pState);

		init2D();
		toolbar3D();
		glMatrixMode(GL_PROJECTION);
		//glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		//Doughnut Simulation;
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
	initCells();

	initButton();
	timer(1);

	glutPassiveMotionFunc(mouseOver);
	glutMouseFunc(mouseClicked);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyRelease);
	glutDisplayFunc(renderer);
	glutMainLoop();
}

