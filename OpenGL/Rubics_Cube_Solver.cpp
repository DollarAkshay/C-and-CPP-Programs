/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/


#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <GL/glut.h>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ll long long

struct color {
	float r, g, b;

	color(float ir, float ig, float ib) {
		r = ir;
		g = ig;
		b = ib;
	}

	float * getArray() {
		float c[3];
		c[0] = r;
		c[1] = g;
		c[2] = b;
		return c;
	}
};

struct State {

	/*
	0 - Front 
	1 - Back
	2 - Left
	3 - Right
	4 - Top
	5 - Bottom
	*/

	char faces[6][3][3];

	State() {
		REP(k, 6) {
			REP(i, 3)
				REP(j, 3)
				faces[k][i][j] = k;
		}
	}

	void printCube(int type=0) {

		if (type==0) {
			REP(i, 3)
				printf("      %2d%2d%2d      \n", faces[1][i][0], faces[1][i][1], faces[1][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", faces[4][i][0], faces[4][i][1], faces[4][i][2]);
			REP(i, 3)
				printf("%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 
					   faces[2][i][0], faces[2][i][1], faces[2][i][2],
					   faces[0][i][0], faces[0][i][1], faces[0][i][2], 
					   faces[3][i][0], faces[3][i][1], faces[3][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", faces[5][i][0], faces[5][i][1], faces[5][i][2]);
			printf("\n");

		}
		else if (type==1) {
			REP(i, 3) {
				REP(k, 6) {
					REP(j, 3)
						printf("%2d", faces[k][i][j]);
					printf(" ");
				}
				printf("\n");
			}
		}
	}

	void front_anticlock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][2][2-i];
			faces[4][2][2-i] = faces[3][2-i][0];
			faces[3][2-i][0] = faces[5][0][i];
			faces[5][0][i] = faces[2][i][2];
			faces[2][i][2] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[0][0][2-i];
			faces[0][0][2-i] = faces[0][2-i][2];
			faces[0][2-i][2] = faces[0][2][i];
			faces[0][2][i] = faces[0][i][0];
			faces[0][i][0] = t[i];
		}

	}

	void front_clock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][2][i];
			faces[4][2][i] = faces[2][2-i][2];
			faces[2][2-i][2] = faces[5][0][2-i];
			faces[5][0][2-i] = faces[3][i][0];
			faces[3][i][0] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[0][0][i];
			faces[0][0][i] = faces[0][2-i][0];
			faces[0][2-i][0] = faces[0][2][2-i];
			faces[0][2][2-i] = faces[0][i][2];
			faces[0][i][2] = t[i];
		}

	}

	void back_anticlock() {
		int t[3];

		REP(i, 3) {
			t[i] = faces[4][0][i];
			faces[4][0][i] = faces[2][2-i][0];
			faces[2][2-i][0] = faces[5][2][2-i];
			faces[5][2][2-i] = faces[3][i][2];
			faces[3][i][2] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[1][0][2-i];
			faces[1][0][2-i] = faces[1][2-i][2];
			faces[1][2-i][2] = faces[1][2][i];
			faces[1][2][i] = faces[1][i][0];
			faces[1][i][0] = t[i];
		}
	}

	void back_clock() {
		int t[3];

		REP(i, 3) {
			t[i] = faces[4][0][2-i];
			faces[4][0][2-i] = faces[3][2-i][2];
			faces[3][2-i][2] = faces[5][2][i];
			faces[5][2][i] = faces[2][i][0];
			faces[2][i][0] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[1][0][i];
			faces[1][0][i] = faces[1][2-i][0];
			faces[1][2-i][0] = faces[1][2][2-i];
			faces[1][2][2-i] = faces[1][i][2];
			faces[1][i][2] = t[i];
		}
	}

	void left_anticlock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][2-i][0];
			faces[4][2-i][0] = faces[0][2-i][0];
			faces[0][2-i][0] = faces[5][2-i][0];
			faces[5][2-i][0] = faces[1][i][2];
			faces[1][i][2] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[2][0][2-i];
			faces[2][0][2-i] = faces[2][2-i][2];
			faces[2][2-i][2] = faces[2][2][i];
			faces[2][2][i] = faces[2][i][0];
			faces[2][i][0] = t[i];
		}

	}

	void left_clock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][i][0];
			faces[4][i][0] = faces[1][2-i][2];
			faces[1][2-i][2] = faces[5][i][0];
			faces[5][i][0] = faces[0][i][0];
			faces[0][i][0] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[2][0][i];
			faces[2][0][i] = faces[2][2-i][0];
			faces[2][2-i][0] = faces[2][2][2-i];
			faces[2][2][2-i] = faces[2][i][2];
			faces[2][i][2] = t[i];
		}

	}

	void right_anticlock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][i][2];
			faces[4][i][2] = faces[1][2-i][0];
			faces[1][2-i][0] = faces[5][i][2];
			faces[5][i][2] = faces[0][i][2];
			faces[0][i][2] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[3][0][2-i];
			faces[3][0][2-i] = faces[3][2-i][2];
			faces[3][2-i][2] = faces[3][2][i];
			faces[3][2][i] = faces[3][i][0];
			faces[3][i][0] = t[i];
		}

	}

	void right_clock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[4][2-i][2];
			faces[4][2-i][2] = faces[0][2-i][2];
			faces[0][2-i][2] = faces[5][2-i][2];
			faces[5][2-i][2] = faces[1][i][0];
			faces[1][i][0] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[3][0][i];
			faces[3][0][i] = faces[3][2-i][0];
			faces[3][2-i][0] = faces[3][2][2-i];
			faces[3][2][2-i] = faces[3][i][2];
			faces[3][i][2] = t[i];
		}

	}

	void top_anticlock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[1][0][i];
			faces[1][0][i] = faces[3][0][i];
			faces[3][0][i] = faces[0][0][i];
			faces[0][0][i] = faces[2][0][i];
			faces[2][0][i] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[4][0][2-i];
			faces[4][0][2-i] = faces[4][2-i][2];
			faces[4][2-i][2] = faces[4][2][i];
			faces[4][2][i] = faces[4][i][0];
			faces[4][i][0] = t[i];
		}
	}

	void top_clock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[1][0][2-i];
			faces[1][0][2-i] = faces[2][0][2-i];
			faces[2][0][2-i] = faces[0][0][2-i];
			faces[0][0][2-i] = faces[3][0][2-i];
			faces[3][0][2-i] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[4][0][i];
			faces[4][0][i] = faces[4][2-i][0];
			faces[4][2-i][0] = faces[4][2][2-i];
			faces[4][2][2-i] = faces[4][i][2];
			faces[4][i][2] = t[i];
		}

	}

	void bottom_anticlock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[0][2][2-i];
			faces[0][2][2-i] = faces[3][2][2-i];
			faces[3][2][2-i] = faces[1][2][2-i];
			faces[1][2][2-i] = faces[2][2][2-i];
			faces[2][2][2-i] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[5][0][2-i];
			faces[5][0][2-i] = faces[5][2-i][2];
			faces[5][2-i][2] = faces[5][2][i];
			faces[5][2][i] = faces[5][i][0];
			faces[5][i][0] = t[i];
		}

	}

	void bottom_clock() {

		int t[3];

		REP(i, 3) {
			t[i] = faces[0][2][i];
			faces[0][2][i] = faces[2][2][i];
			faces[2][2][i] = faces[1][2][i];
			faces[1][2][i] = faces[3][2][i];
			faces[3][2][i] = t[i];
		}

		REP(i, 2) {
			t[i] = faces[5][0][i];
			faces[5][0][i] = faces[5][2-i][0];
			faces[5][2-i][0] = faces[5][2][2-i];
			faces[5][2][2-i] = faces[5][i][2];
			faces[5][i][2] = t[i];
		}

	}


	/*
	0 - Front
	1 - Back
	2 - Left
	3 - Right
	4 - Top
	5 - Bottom
	*/

};

State cube;

double savedmatrix[16];

bool temp = true;
int px = -1, py = -1;
float angleY = 0, angleX = 0;

float v[8][3] = { {-1,+1,+1}, {+1,+1,+1}, {+1,-1,+1}, {-1,-1,+1},
				  {-1,+1,-1}, {+1,+1,-1}, {+1,-1,-1}, {-1,-1,-1} };


color colorList[6] = { color(0.3,0.8,0), color(0,0.5,1), color(1,0.8,0), color(0.9,0.9,0.9),  color(1,0.4,0), color(0.9,0,0) };

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);
	glMatrixMode(GL_MODELVIEW);

	glGetDoublev(GL_MODELVIEW_MATRIX, savedmatrix);
}

void mouse(int button, int state, int x, int y) {

	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		px = x;
		py = y;
		temp = true;
	}

	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) {
		angleY = (float)(x - px)*360/600;
		angleX = (float)(y - py)*360/600;
		temp = false;
		py = px = -1;
	}

}

void motion(int x, int y) {

	angleY = (float)(x - px)*360/600;
	angleX = (float)(y - py)*360/600;

}

void init() {
	
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -2, -6, 0, 0, 0, 0, 1, 1);

}

void drawFace(float *a, float *b, float *c, float *d, int face) {

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();

	int constComp[3], iComp[3], jComp[3];

	REP(i, 3) {
		constComp[i] = 1-abs(a[i]-c[i])/2;
		iComp[i] = (a[i]-d[i])/2;
		jComp[i] = (b[i]-a[i])/2;
	}


	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
			glColor3f(colorList[cube.faces[face][i][j]].r, colorList[cube.faces[face][i][j]].g, colorList[cube.faces[face][i][j]].b);
			glBegin(GL_QUADS);
			glVertex3f(a[0] + (0.05 + j*0.65)*jComp[0] - (0.05 + i*0.65)*iComp[0] + constComp[0]*0.01*a[0]/fabs(a[0]),
					   a[1] + (0.05 + j*0.65)*jComp[1] - (0.05 + i*0.65)*iComp[1] + constComp[1]*0.01*a[1]/fabs(a[1]),
					   a[2] + (0.05 + j*0.65)*jComp[2] - (0.05 + i*0.65)*iComp[2] + constComp[2]*0.01*a[2]/fabs(a[2]));

			glVertex3f(a[0] + (0.65 + j*0.65)*jComp[0] - (0.05 + i*0.65)*iComp[0] + constComp[0]*0.01*a[0]/fabs(a[0]),
					   a[1] + (0.65 + j*0.65)*jComp[1] - (0.05 + i*0.65)*iComp[1] + constComp[1]*0.01*a[1]/fabs(a[1]),
					   a[2] + (0.65 + j*0.65)*jComp[2] - (0.05 + i*0.65)*iComp[2] + constComp[2]*0.01*a[2]/fabs(a[2]));

			glVertex3f(a[0] + (0.65 + j*0.65)*jComp[0] - (0.65 + i*0.65)*iComp[0] + constComp[0]*0.01*a[0]/fabs(a[0]),
					   a[1] + (0.65 + j*0.65)*jComp[1] - (0.65 + i*0.65)*iComp[1] + constComp[1]*0.01*a[1]/fabs(a[1]),
					   a[2] + (0.65 + j*0.65)*jComp[2] - (0.65 + i*0.65)*iComp[2] + constComp[2]*0.01*a[2]/fabs(a[2]));

			glVertex3f(a[0] + (0.05 + j*0.65)*jComp[0] - (0.65 + i*0.65)*iComp[0] + constComp[0]*0.01*a[0]/fabs(a[0]),
					   a[1] + (0.05 + j*0.65)*jComp[1] - (0.65 + i*0.65)*iComp[1] + constComp[1]*0.01*a[1]/fabs(a[1]),
					   a[2] + (0.05 + j*0.65)*jComp[2] - (0.65 + i*0.65)*iComp[2] + constComp[2]*0.01*a[2]/fabs(a[2]));
			glEnd();
			glFlush();
		}
	}
}

void drawCube() {

	glColor3f(1, 1, 1);

	drawFace(v[0], v[1], v[2], v[3], 0);		// Front
	drawFace(v[5], v[4], v[7], v[6], 1);		// Back
	drawFace(v[4], v[0], v[3], v[7], 2);		// Left
	drawFace(v[1], v[5], v[6], v[2], 3);		// Right
	drawFace(v[4], v[5], v[1], v[0], 4);		// Top
	drawFace(v[3], v[2], v[6], v[7], 5);		// Bottom
	
	

}

void display() {

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);


	if (temp) {
		glLoadIdentity();
		glLoadMatrixd(savedmatrix);
		glRotatef(angleX, 1, 0, 0);
		glRotatef(angleY, 0, 1, 0);
	}
	else {
		glLoadIdentity();
		glLoadMatrixd(savedmatrix);
		glRotatef(angleX, 1, 0, 0);
		glRotatef(angleY, 0, 1, 0);
		angleX = 0;
		angleY = 0;
		glGetDoublev(GL_MODELVIEW_MATRIX, savedmatrix);
	}

	drawCube();
	
	glutSwapBuffers();
	glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y) {

	if (key=='Q') {
		cube.front_anticlock();
		cube.printCube();
	}
	else if (key=='q') {
		cube.front_clock();
		cube.printCube();
	}

	if (key=='W') {
		cube.back_anticlock();
		cube.printCube();
	}
	else if (key=='w') {
		cube.back_clock();
		cube.printCube();
	}

	if (key=='A') {
		cube.left_anticlock();
		cube.printCube();
	}
	else if (key=='a') {
		cube.left_clock();
		cube.printCube();
	}

	if (key=='S') {
		cube.right_anticlock();
		cube.printCube();
	}
	else if (key=='s') {
		cube.right_clock();
		cube.printCube();
	}

	if (key=='Z') {
		cube.top_anticlock();
		cube.printCube();
	}
	else if (key=='z') {
		cube.top_clock();
		cube.printCube();
	}

	if (key=='X') {
		cube.bottom_anticlock();
		cube.printCube();
	}
	else if (key=='x') {
		cube.bottom_clock();
		cube.printCube();
	}

}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rubics Cube");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);

	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glutMainLoop();
	return 0;

}

//