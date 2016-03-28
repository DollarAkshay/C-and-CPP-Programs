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
	1 - Top
	2 - Bottom
	3 - Left
	4 - Right
	5 - Back
	*/

	char cube[6][3][3];

	State() {
		REP(k, 6) {
			REP(i, 3)
				REP(j, 3)
				cube[k][i][j] = k;
		}
	}


	void printCube(int type=0) {

		if (type==0) {
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[5][i][0], cube[5][i][1], cube[5][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[1][i][0], cube[1][i][1], cube[1][i][2]);
			REP(i, 3)
				printf("%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 
					   cube[3][i][0], cube[3][i][1], cube[3][i][2], 
					   cube[0][i][0], cube[0][i][1], cube[0][i][2], 
					   cube[4][i][0], cube[4][i][1], cube[4][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[2][i][0], cube[2][i][1], cube[2][i][2]);
			printf("\n");

		}
		else if (type==1) {
			REP(i, 3) {
				REP(k, 6) {
					REP(j, 3)
						printf("%2d", cube[k][i][j]);
					printf(" ");
				}
				printf("\n");
			}
		}
	}

	void front_clock() {

		int t[3];
		REP(i, 3)
			t[i] = cube[1][2][i];

		REP(i, 3)
			cube[1][2][i] = cube[3][i][2];

		REP(i, 3)
			cube[3][i][2] = cube[2][0][i];

		REP(i, 3)
			cube[2][0][i] = cube[4][i][0];

		REP(i, 3)
			cube[4][i][0] = t[i];

	}

	/*
	0 - Front
	1 - Top
	2 - Bottom
	3 - Left
	4 - Right
	5 - Back
	*/

};

float angleY = 0;

float v[8][3] = { {-1,+1,+1}, {+1,+1,+1}, {+1,-1,+1}, {-1,-1,+1},
				  {-1,+1,-1}, {+1,+1,-1}, {+1,-1,-1}, {-1,-1,-1} };


color colorList[6] = { color(1,0,0), color(0.3,0.8,0), color(0,0.6,1), color(1,1,0), color(1,0.4,0), color(1,0,0.8) };

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);
	glMatrixMode(GL_MODELVIEW);
}

void init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -2, -6, 0, 0, 0, 0, 1, 1);

}

void mouse(int button, int state, int x, int y) {


}

void drawFace(float *a, float *b, float *c, float *d, color col) {

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

	glColor3f(col.r, col.g, col.b);

	FOR(i, 0, 2) {
		FOR(j, 0, 2) {
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

	drawFace(v[0], v[1], v[2], v[3], colorList[0]);		// Front
	drawFace(v[4], v[5], v[1], v[0], colorList[1]);		// Top
	drawFace(v[4], v[5], v[6], v[7], colorList[2]);		// Back
	drawFace(v[2], v[3], v[7], v[6], colorList[3]);		// Bottom
	drawFace(v[0], v[4], v[7], v[3], colorList[4]);		// Left
	drawFace(v[1], v[5], v[6], v[2], colorList[5]);		// Right
	

}

void display() {

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	glLoadIdentity();
	glRotatef(angleY, 0.5, 1, 0.5);

	drawCube();
	angleY += 0.1;

	glutSwapBuffers();
	glutPostRedisplay();

}




int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TSP");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glutMainLoop();
	return 0;

}

//