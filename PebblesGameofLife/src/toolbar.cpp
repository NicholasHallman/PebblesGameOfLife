#include"toolbar.h"

void clearButtons(){
	for(int i = 0; i < 20; i++){
		Button temp;
		buttons[i] = temp;
	}
}

void toolbar(){

	glColor3f(.3,.35,.4);
	glBegin(GL_QUADS);
		glVertex2f(0,768);
		glVertex2f(1366,768);
		glVertex2f(1366,730);
		glVertex2f(0,730);
	glEnd();

	glColor3f(1,1,1); //sets text color to white
	const unsigned char* t = reinterpret_cast<const unsigned char *>("Pebble's Game of Life");
	glRasterPos2i(10, 740); // positions the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, t); //prints the text to the screen

	if(introVisit){
		int bh = 735;
		Button s20; // create a new button
		s20.Name(( const unsigned char*)"20x20"); //name the button (acts as button text)
		s20.SetPosition(Vertex(210,bh,0)); //set the buttons position
		s20.onClick(but1); // set the function to activate when the button is pressed
		s20.active = true;
		buttons[0] = s20; // add the button to the button draw array
		buttons[0].id = 0;

		Button s50;
		s50.Name(( const unsigned char*)"50x50");
		s50.SetPosition(Vertex(s20.position.x + s20.rWidth + 10,bh,0));
		s50.onClick(but2);
		s50.active = true;
		buttons[1] = s50;
		buttons[1].id = 1;

		Button s100;
		s100.Name(( const unsigned char*)"100x100");
		s100.SetPosition(Vertex(s50.position.x + s50.rWidth + 10,bh,0));
		s100.onClick(but3);
		s100.active = true;
		buttons[2] = s100;
		buttons[2].id = 2;

		Button s150;
		s150.Name(( const unsigned char*)"150x150");
		s150.SetPosition(Vertex(s100.position.x + s100.rWidth + 10,bh,0));
		s150.onClick(but4);
		s150.active = true;
		buttons[3] = s150;
		buttons[3].id = 3;

		Button s200;
		s200.Name(( const unsigned char*)"200x200");
		s200.SetPosition(Vertex(s150.position.x + s150.rWidth + 10,bh,0));
		s200.onClick(but5);
		s200.active = true;
		buttons[4] = s200;
		buttons[4].id = 4;

		Button splus;
		splus.Name(( const unsigned char*)"+");
		splus.SetPosition(Vertex(s200.position.x + s200.rWidth + 30,bh,0));
		splus.onClick(bplus);
		splus.active = true;
		buttons[5] = splus;
		buttons[5].id = 5;

		Button sminus;
		sminus.Name(( const unsigned char*)"-");
		sminus.SetPosition(Vertex(splus.position.x + splus.rWidth + 10,bh,0));
		sminus.onClick(bminus);
		sminus.active = true;
		buttons[6] = sminus;
		buttons[6].id = 6;

		Button sfull;
		sfull.Name(( const unsigned char*)"Full Screen");
		sfull.SetPosition(Vertex(sminus.position.x + sminus.rWidth + 30,bh,0));
		sfull.onClick(bfull);
		sfull.active = false;
		sfull.broken = true;
		buttons[7] = sfull;
		buttons[7].id = 7;

		Button scolor;
		scolor.Name(( const unsigned char*)"Color");
		scolor.SetPosition(Vertex(sfull.position.x + sfull.rWidth + 10,bh,0));
		scolor.onClick(bcolor);
		scolor.active = true;
		scolor.broken = false;
		buttons[8] = scolor;
		buttons[8].id = 8;

		Button sre;
		sre.Name(( const unsigned char*)"Clear");
		sre.SetPosition(Vertex(scolor.position.x + scolor.rWidth + 10,bh,0));
		sre.onClick(breset);
		sre.active = true;
		buttons[9] = sre;
		buttons[9].id = 9;

		Button sim;
		sim.Name(( const unsigned char*)"Simulate");
		sim.SetPosition(Vertex(sre.position.x + sre.rWidth + 10,bh,0));
		sim.onClick(startSim);
		sim.active = true;
		buttons[10] = sim;
		buttons[10].id = 10;

		Button quit;
		quit.Name(( const unsigned char*)"Exit Program");
		quit.SetPosition(Vertex(1240,735,0));
		quit.onClick(quitProgram);
		quit.active = true;
		buttons[11] = quit;
		buttons[11].id = 11;

		Button three_dimension;
		three_dimension.Name(( const unsigned char*)"3D Mode");
		three_dimension.SetPosition(Vertex(sim.position.x + sim.rWidth + 10,bh,0));
		three_dimension.onClick(b3D);
		three_dimension.active = true;
		buttons[12] = three_dimension;
		buttons[12].id = 12;
		introVisit = false;

		Button heat;
		heat.Name(( const unsigned char*)"Heat");
		heat.SetPosition(Vertex(three_dimension.position.x + three_dimension.rWidth + 10,bh,0));
		heat.onClick(heatM);
		heat.active = true;
		buttons[13] = heat;
		buttons[13].id = 13;
		introVisit = false;
	}
	for(int i = 0; i < 20; i++){
		if(buttons[i].active){
			buttons[i].Draw();
		} else if(buttons[i].broken) {
			buttons[i].DrawBroken();
		}
	}

}

void toolbar3D(){
	//init2D();
	glColor3f(.3,.35,.4);
	//glDisable(GL_COLOR_MATERIAL);
	glBegin(GL_QUADS);
		glVertex2f(0,768);
		glVertex2f(1366,768);
		glVertex2f(1366,730);
		glVertex2f(0,730);
	glEnd();

	glColor3f(1,1,1); //sets text color to white
	const unsigned char* t = reinterpret_cast<const unsigned char *>("Pebble's Game of Life");
	glRasterPos2i(10, 740); // positions the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, t); //prints the text to the screen

	if(introVisit){
		printf("???\n");
		clearButtons();

		int bh = 735;
		Button torusV; // create a new button
		torusV.Name(( const unsigned char*)"Torus View"); //name the button (acts as button text)
		torusV.SetPosition(Vertex(210,bh,0)); //set the buttons position
		torusV.onClick(btorView); // set the function to activate when the button is pressed
		torusV.active = true;
		buttons[0] = torusV; // add the button to the button draw array
		buttons[0].id = 0;

		Button torusD; // create a new button
		torusD.Name(( const unsigned char*)"Torus Draw"); //name the button (acts as button text)
		torusD.SetPosition(Vertex(torusV.position.x + torusV.rWidth + 10,bh,0)); //set the buttons position
		torusD.onClick(btorDraw); // set the function to activate when the button is pressed
		torusD.active = true;
		buttons[1] = torusD; // add the button to the button draw array
		buttons[1].id = 1;

		Button cube; // create a new button
		cube.Name(( const unsigned char*)"Cube View"); //name the button (acts as button text)
		cube.SetPosition(Vertex(torusD.position.x + torusD.rWidth + 10,bh,0)); //set the buttons position
		cube.onClick(b3D); // set the function to activate when the button is pressed
		cube.active = true;
		buttons[2] = cube; // add the button to the button draw array
		buttons[2].id = 2;

		Button quit;
		quit.Name(( const unsigned char*)"Exit Program");
		quit.SetPosition(Vertex(1240,735,0));
		quit.onClick(quitProgram);
		quit.active = true;
		buttons[11] = quit;
		buttons[11].id = 11;

		Button two;
		two.Name(( const unsigned char*)"2D Mode");
		two.SetPosition(Vertex(1052,bh,0));
		two.onClick(b2D);
		two.active = true;
		buttons[12] = two;
		buttons[12].id = 12;
		introVisit = false;

		Button sre;
		sre.Name(( const unsigned char*)"Clear");
		sre.SetPosition(Vertex(cube.position.x + cube.rWidth + 10,bh,0));
		sre.onClick(breset);
		sre.active = true;
		buttons[9] = sre;
		buttons[9].id = 9;
	}

	for(int i = 0; i < 20; i++){
		if(buttons[i].active){
			buttons[i].Draw();
		} else if(buttons[i].broken) {
			buttons[i].DrawBroken();
		}
	}

}

void update_grid() {
	map.cells = (cell **)malloc(map.size*sizeof(cell *)); //allocate the new size
	for(int i = 0;i < map.size; ++i)
		map.cells[i] = (cell *)malloc(map.size*sizeof(cell));
	for(int x = 0; x < map.size; x++){
		for(int y = 0; y < map.size; y++){
			map.cells[x][y].oldState = 0;
			map.cells[x][y].newState = 0;
		}
	}
	return;
}

void but1(){
	map.size = 20;
	update_grid();
	pState = 2;
	//addSim();

}

void but2(){
	map.size = 50;
	update_grid();
	pState = 2;
	//addSim();

}

void but3(){
	map.size = 100;
	update_grid();
	pState = 2;
	//addSim();

}

void but4(){
	map.size = 150;
	update_grid();
	pState = 2;
	//addSim();

}

void but5(){
	map.size = 200;
	update_grid();
	pState = 2;
	//addSim();

}

void bplus(){
	CSIZE += 5;
	if(CSIZE > 50){
		CSIZE = 50;
	}
}
void bminus(){
	CSIZE -= 5;
	if(CSIZE < 5){
		CSIZE = 5;
	}
}

void bfull(){
	glutGameModeString("1366x768");
	glutEnterGameMode();
	init2D();
	glutPostRedisplay();
}

void bcolor(){
	colorW = true;
}

void b3D(){
	//map.size = 36;
	//update_grid();
	myCamera.eye.x = 35;
	myCamera.eye.y = 35;
	myCamera.eye.z = 35;
	gen3DCells();
	introVisit = true;
	pState = 6;
	canSim = true;
}

void b2D(){
	map.size = 20;
	update_grid();

	introVisit = true;
	pState = 2;
	canSim = false;
}



void btorDraw(){
	if(map.size != 36){
		map.size = 36;
		update_grid();
	}
	canSim = false;
	map.size = 36;
	pState = 2;

}

void btorView(){
	if(map.size != 36){
		map.size = 36;
		update_grid();
	}
	myCamera.eye.x = 1;
	myCamera.eye.y = 1;
	myCamera.eye.z = 14;
	canSim = true;
	pState = 5;
}

void heatM(){
	heatMap = !heatMap;
}

void breset(){
	for(int y = 0; y < map.size; y++){
		for(int x = 0; x < map.size; x++){
			map.cells[x][y].oldState = 0;
			map.cells[x][y].newState = 0;
		}
	}
}


