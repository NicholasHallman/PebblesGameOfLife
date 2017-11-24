#include"toolbar.h"

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

	if(!introVisit){
		int bh = 735;
		Button s20; // create a new button
		s20.Name(( const unsigned char*)"20x20"); //name the button (acts as button text)
		s20.SetPosition(Vertex(210,bh,0)); //set the buttons position
		s20.onClick(but1); // set the function to activate when the button is pressed
		s20.active = true;
		buttons[0] = s20; // add the button to the button draw array

		Button s50;
		s50.Name(( const unsigned char*)"50x50");
		s50.SetPosition(Vertex(s20.position.x + s20.rWidth + 10,bh,0));
		s50.onClick(but2);
		s50.active = true;
		buttons[1] = s50;

		Button s100;
		s100.Name(( const unsigned char*)"100x100");
		s100.SetPosition(Vertex(s50.position.x + s50.rWidth + 10,bh,0));
		s100.onClick(but3);
		s100.active = true;
		buttons[2] = s100;

		Button s150;
		s150.Name(( const unsigned char*)"150x150");
		s150.SetPosition(Vertex(s100.position.x + s100.rWidth + 10,bh,0));
		s150.onClick(but4);
		s150.active = true;
		buttons[3] = s150;

		Button s200;
		s200.Name(( const unsigned char*)"200x200");
		s200.SetPosition(Vertex(s150.position.x + s150.rWidth + 10,bh,0));
		s200.onClick(but5);
		s200.active = true;
		buttons[4] = s200;

		Button splus;
		splus.Name(( const unsigned char*)"+");
		splus.SetPosition(Vertex(s200.position.x + s200.rWidth + 30,bh,0));
		splus.onClick(bplus);
		splus.active = true;
		buttons[6] = splus;

		Button sminus;
		sminus.Name(( const unsigned char*)"-");
		sminus.SetPosition(Vertex(splus.position.x + splus.rWidth + 10,bh,0));
		sminus.onClick(bminus);
		sminus.active = true;
		buttons[7] = sminus;

		Button sfull;
		sfull.Name(( const unsigned char*)"Full Screen");
		sfull.SetPosition(Vertex(sminus.position.x + sminus.rWidth + 30,bh,0));
		sfull.onClick(bfull);
		sfull.active = false;
		sfull.broken = true;
		buttons[8] = sfull;

		Button scolor;
		scolor.Name(( const unsigned char*)"Color");
		scolor.SetPosition(Vertex(sfull.position.x + sfull.rWidth + 10,bh,0));
		scolor.onClick(bcolor);
		scolor.active = false;
		scolor.broken = true;
		buttons[9] = scolor;
	}
	for(int i = 0; i < 20; i++){
		if(buttons[i].active){
			buttons[i].Draw();
		} else if(buttons[i].broken) {
			buttons[i].DrawBroken();
		}
	}
	introVisit = true;
}

void but1(){
	map.size = 20;
	pState = 2;
	addSim();
}

void but2(){
	map.size = 50;
	pState = 2;
	addSim();
}

void but3(){
	map.size = 100;
	pState = 2;
	addSim();
}

void but4(){
	map.size = 150;
	pState = 2;
	addSim();
}

void but5(){
	map.size = 200;
	pState = 2;
	addSim();
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
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	int colorW = glutCreateWindow("ColorPicker");
}


