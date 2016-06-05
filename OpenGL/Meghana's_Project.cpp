#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>

using namespace std;

float curColor[3] = { 0, 1, 0 };

float weatherColor[3] = { 0, 1, 0 };
float perc = 1;

int leafCount = 7;
float leafy[100] = { 0, -100, 100, 200, 124, -212, -300 };
float leafx[100] = {-300, 20, 154, -200, 358, -52, 350 };
float leafsize[100] = { 0.45, 0.50, 0.55, 0.6, 0.7, 0.75, 0.8};
float leafangle[100] = { 130, 25, 50, 90, 251, 158, 0 };
float leafrotatespeed[100] = { 0.15, -0.2, 0.15, 0.1, -0.05, -0.07, 0.15 };

void spring() {

	perc = 0;
	weatherColor[0] = 0.1;
	weatherColor[1] = 0.8;
	weatherColor[2] = 0;

}

void summer() {

	perc = 0;
	weatherColor[0] = 0.9;
	weatherColor[1] = 0.8;
	weatherColor[2] = 0;

}

void winter(){

	perc = 0;
	weatherColor[0] = 0.2;
	weatherColor[1] = 0.6;
	weatherColor[2] = 0.8;

}

void fall() {

	perc = 0;
	weatherColor[0] = 0.9;
	weatherColor[1] = 0.2;
	weatherColor[2] = 0;

}

void leaf(int x, int y, float size, float angle) {

	glLoadIdentity();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	glScalef(size, size, size);

	// Stem
	glColor3f(curColor[0]*0.6, curColor[1]*0.6, curColor[2]*0.6);
	glBegin(GL_POLYGON);
	glVertex2f(- 4, - 0);
	glVertex2f(- 4, -50);
	glVertex2f(+ 4, -50);
	glVertex2f(+ 4, - 0);
	glEnd();

	
	// Leaf
	glColor3f(curColor[0]*(100-(rand()%20))/100.0, 
			  curColor[1]*(100-(rand()%20))/100.0,
			  curColor[2]*(100-(rand()%20))/100.0);
	glBegin(GL_POLYGON);
	glVertex2f(-  0, +  0);
	glVertex2f(- 65, - 10);
	glVertex2f(- 45, + 15);
	glVertex2f(-140, + 48);
	glVertex2f(-120, + 60);
	glVertex2f(-155, + 95);
	glVertex2f(-107, + 88);
	glVertex2f(-115, +120);
	glVertex2f(- 30, + 77);
	glVertex2f(- 45, +167);
	glVertex2f(- 20, +150);
	glVertex2f(+  0, +203);
	glVertex2f(+ 20, +150);
	glVertex2f(+ 45, +167);
	glVertex2f(+ 30, + 77);
	glVertex2f(+115, +120);
	glVertex2f(+107, + 88);
	glVertex2f(+155, + 95);
	glVertex2f(+120, + 60);
	glVertex2f(+140, + 48);
	glVertex2f(+ 45, + 15);
	glVertex2f(+ 65, - 10);
	glVertex2f(+  0, +  0);
	glEnd();

	//Veins
	glColor3f(curColor[0]*0.2, curColor[1]*0.2, curColor[2]*0.2);
	glBegin(GL_LINE_STRIP);
	glVertex2f(+0, +  0);
	glVertex2f(+3, + 50);
	glVertex2f(-2, +100);
	glVertex2f(+0, +200);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(+  3, + 50);
	glVertex2f(+ 20, + 30);
	glVertex2f(+120, + 75);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(+2.5, +30);
	glVertex2f(-20, +20);
	glVertex2f(-120, +75);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-2, +100);
	glVertex2f(+20, +120);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-2, +100);
	glVertex2f(-20, +115);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(-1.5, + 80);
	glVertex2f(-15, +90);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f( 0, + 65);
	glVertex2f(+22,+ 75);
	glEnd();

}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	glColor3f(0, 1, 0);

	for (int i = 0; i<leafCount; i++) {

		leaf(leafx[i], leafy[i], leafsize[i], leafangle[i]);

		leafy[i] -= 1*leafsize[i];

		leafangle[i] += leafrotatespeed[i];

		if (leafy[i] < -300-200*leafsize[i]) {
			leafy[i] = 400;
			leafx[i] = rand()%701 - 350;		
		}
	}

	for (int i = 0; i<3; i++) {
		curColor[i] = perc*weatherColor[i] + (1-perc)*curColor[i];
	}

	if(perc < 1)
		perc += 0.001;

	glFlush();
	Sleep(1);
	glutPostRedisplay();
}

void menu(int op) {
	switch (op) {
	case 1:
		spring();
		glutPostRedisplay();
		break;
	case 2:
		summer();
		glutPostRedisplay();
		break;
	case 3:
		winter();
		glutPostRedisplay();
		break;
	case 4:
		fall();
		glutPostRedisplay();
		break;
	case 5:
		exit(0);
	}

}

void main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("SEASONS");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-400, 400, -300, 300);
	glMatrixMode(GL_MODELVIEW);

	glutCreateMenu(menu);
	glutAddMenuEntry("spring", 1);
	glutAddMenuEntry("summer", 2);
	glutAddMenuEntry("winter", 3);
	glutAddMenuEntry("fall", 4);
	glutAddMenuEntry("Quit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();
}