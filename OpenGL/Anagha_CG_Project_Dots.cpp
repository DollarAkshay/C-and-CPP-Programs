// DOTS GAME - OpenGL Project by Anagha Aravind

#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int screen = 1;
int player = 1;
float color[3][3] = { {0.8,0.8,0.8}, {0,0.8,0}, {0,0.5,1} };
int horizontalLines[4][3];
int verticalLines[3][4];

void textdisp(int x, int y, char *str) {
	int z = 0;
	glRasterPos3f(x, y, z);
	for (char* c = str; *c!='\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}

void drawBox(int x, int y, int w, int h) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y+h);
	glVertex2f(x, y+h);
	glEnd();
}

void drawGrid(){

	//Draw Lines
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<3; j++) {
			if (horizontalLines[i][j]) {
				glColor3fv(color[horizontalLines[i][j]]);
				glBegin(GL_LINE_STRIP);
				glVertex2f(j*100+100, i*100+100);
				glVertex2f(j*100+200, i*100+100);
				glEnd();
			}
			if (verticalLines[j][i]) {
				glColor3fv(color[verticalLines[j][i]]);
				glBegin(GL_LINE_STRIP);
				glVertex2f(i*100+100, j*100+100);
				glVertex2f(i*100+100, j*100+200);
				glEnd();
			}
		}
	}

	//Draw Inner Boxes if player has conquered that box
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			if (horizontalLines[i][j] == horizontalLines[i+1][j] && verticalLines[i][j] == verticalLines[i][j+1] && horizontalLines[i][j] == verticalLines[i][j]) {
				glColor3fv(color[verticalLines[i][j]]);
				drawBox(j*100+105, i*100+105, 90, 90);
			}
		}
	}

	//Draw Points
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int y = 100; y<=400; y += 100) {
		for (int x = 100; x<=400; x += 100)
			glVertex2i(x, y);
	}
	glEnd();

	//drawing dotted lines
	glColor3f(0.4, 0.4, 0.4);
	glPushAttrib(GL_LINE_BIT);
	glEnable(GL_LINE_STIPPLE); //primitive for dotted line pattern
	glLineStipple(3, 0xAAAA);

	for (int i = 100; i<=400; i += 100) {
		glBegin(GL_LINE_STRIP);
		glVertex2f(100, i-5);
		glVertex2f(400, i-5);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(100, i+5);
		glVertex2f(400, i+5);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(i-5, 100);
		glVertex2f(i-5, 400);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(i+5, 100);
		glVertex2f(i+5, 400);
		glEnd();
	}

	glDisable(GL_LINE_STIPPLE);
	glPopAttrib(); //Removing the pattern

	glColor3f(0.2, 0.2, 0.2);
	drawBox(435, 0, 65, 30); //Quit Box
	drawBox(0, 0, 112, 30);  // Restart Box
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	if (screen==1){
		glColor3f(1, 0, 0);
		textdisp(120, 400, "T H E   D O T S   G A M E");
		glColor3f(0.1, 0.8, 0);
		textdisp(140, 310, "P R E S S   S P A C E ");
		textdisp(80, 280, "T O   S T A R T   T H E   G A M E");
		glColor3f(0, 0.6, 1);
		textdisp(265, 100, " Developed By : ");
		glColor3f(1.0, 0, 0.7);
		textdisp(270, 70, "ANAGHA A.");
	}
	else if (screen==2){
		drawGrid();
		glColor3f(0, 0.8, 1);
		textdisp(220.0, 440.0, "DOTS");
		textdisp(440.0, 4.0, "QUIT");
		textdisp(2.0, 4.0, "RESTART");
		if (player==1) {
			glColor3fv(color[1]);
			textdisp(150, 50, "Player 1");
		}
		else if (player==2) {
			glColor3fv(color[2]);
			textdisp(350, 50, "Player 2");
		}
	}
	glFlush();
}

void mouse(int btn, int state, int x, int y){

	y = 500-y;
	if (btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		if (screen==2) {
			if (((y>=95 && y<=105) || (y>=195 && y<=205) || (y>=295 && y<=305) || (y>=395 && y<=405)) && (x>=100 && x<=400)) {
				int ybox = round((y-100)/100.0);
				int xbox = floor((x-100)/100.0);
				horizontalLines[ybox][xbox] = player;
				player = player==1?2:1;
			}

			if (((x>=95 && x<=105) || (x>=195 && x<=205) || (x>=295 && x<=305) || (x>=395 && x<=405)) && (y>=100 && y<=400)) {
				int ybox = floor((y-100)/100.0);
				int xbox = round((x-100)/100.0);
				verticalLines[ybox][xbox] = player;
				player = player==1?2:1;
			}
			if (x>=435 && x<=500 && y>=0 && y<=30) {
				printf("Quitting");
				exit(0);
			}
			if (x>=0 && x<=112 && y>=0 && y<=30) {
				printf("Resetting");
				for (int i = 0; i<4; i++) {
					for (int j = 0; j<3; j++) {
						horizontalLines[i][j] = verticalLines[j][i] = 0;
					}
				}
			}
		}
	}

	
}

void myKey(unsigned char ch, int x, int y){

	if (ch==' ') {
		screen = 2;
		glutPostRedisplay();
	}
}

void mynit(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
}

void main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Dots Game");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKey);
	glutMouseFunc(mouse);
	mynit();
	glutMainLoop();
}