#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>

using namespace std;

float curColor[3] = { 0, 1, 0 };
float weatherColor[3] = { 0, 1, 0 };

int leafCount = 7;
float leafy[100] = { 0, -100, 100, 200, 124, -212, -300 };
float leafx[100] = {-300, 20, 154, -200, 358, -52, 350 };
float leafsize[100] = { 0.45, 0.50, 0.55, 0.6, 0.7, 0.8, 0.7};
float leafangle[100] = { 130, 25, 50, 90, 251, 158, 0 };
float leafrotatespeed[100] = { 0.15, 0.2, 0.15, 0.1, 0.05, 0.07, 0.15 };

void spring() {

}

void summer() {


}

void winter(){


}

void fall() {


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

	glColor3f(curColor[0], curColor[1], curColor[2]);
	// Leaf
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

	
	

}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	glColor3f(0, 1, 0);

	for (int i = 0; i<leafCount; i++) {
		leaf(leafx[i], leafy[i], leafsize[i], leafangle[i]);

		leafy[i] -= 1*leafsize[i];
		leafangle[i] += leafrotatespeed[i];

		if (leafy[i]< -300-200*leafsize[i]) {
			leafy[i] = 400;
			leafx[i] = rand()%701 - 350;
		}
	}

	for (int i = 0; i<3; i++)
		curColor[i] = (weatherColor[i]+curColor[i])/2;

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

	int id = glutCreateMenu(menu);
	glutAddMenuEntry("spring", 1);
	glutAddMenuEntry("summer", 2);
	glutAddMenuEntry("winter", 3);
	glutAddMenuEntry("fall", 4);
	glutAddMenuEntry("Quit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();
}