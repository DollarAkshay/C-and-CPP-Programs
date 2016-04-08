/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

#include <Eigen/Eigen>
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
#include <GL/freeglut.h>

using namespace std;
using namespace Eigen;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ll long long


class color {

public :
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

class State {

	/*
	0 - Front 
	1 - Back
	2 - Left
	3 - Right
	4 - Up
	5 - Down
	*/

public:
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

	void up_anticlock() {

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

	void up_clock() {

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

	void down_anticlock() {

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

	void down_clock() {

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
	4 - Up
	5 - Down
	*/

};

bool change = false;
int width = 600, height = 600;
int px = -1, py = -1;
float angleY = 0, angleX = 0;
const double PI = 3.1415926535;

State cube;
Quaterniond camera = Quaterniond{ AngleAxisd{1,Vector3d{0,0,0}} };

color colorList[6] = { color(0.3,0.8,0), color(0,0.5,1), color(1,0.8,0), color(0.9,0.9,0.9),  color(1,0.4,0), color(0.9,0,0) };

float v[8][3] = { {-1,+1,+1}, {+1,+1,+1}, {+1,-1,+1}, {-1,-1,+1},
				  {-1,+1,-1}, {+1,+1,-1}, {+1,-1,-1}, {-1,-1,-1} };

double modelMat[16], test[16];

void printMatrix(double m[]) {

	REP(i, 4) {
		REP(j, 4)
			printf("% .6lf ", m[i*4 +j]);
		printf("\n");
	}
	printf("\n");

}

double* getRotationMatrix(Quaterniond &q) {

	Matrix3d rotMat = q.normalized().toRotationMatrix();
	double *matrix = new double[16];

	matrix[0] = rotMat(0, 0);	matrix[4] = rotMat(0, 1);	matrix[8] = rotMat(0, 2);	matrix[12] = 0;
	matrix[1] = rotMat(1, 0);	matrix[5] = rotMat(1, 1);	matrix[9] = rotMat(1, 2);	matrix[13] = 0;
	matrix[2] = rotMat(2, 0);	matrix[6] = rotMat(2, 1);	matrix[10] = rotMat(2, 2);	matrix[14] = 0;
	matrix[3] = 0;				matrix[7] = 0;				matrix[11] = 0;				matrix[15] = 1;

	return matrix;

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
		cube.up_anticlock();
		cube.printCube();
	}
	else if (key=='z') {
		cube.up_clock();
		cube.printCube();
	}

	if (key=='X') {
		cube.down_anticlock();
		cube.printCube();
	}
	else if (key=='x') {
		cube.down_clock();
		cube.printCube();
	}

}

void mouse(int button, int state, int x, int y) {

	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
		px = x;
		py = y;
	}

	if (button==GLUT_LEFT_BUTTON && state==GLUT_UP) {
		py = px = -1;
	}

}

void mouseWheel(int button, int dir, int x, int y){

	double factor = 0.05;
	Quaterniond qz = Quaterniond{ AngleAxisd{ dir*factor, Vector3d{ 0, 0, 1 } } };
	camera = qz*camera;

}

void motion(int x, int y) {

	if (px!=-1 && py!=-1) {
		double factor = 0.005;
		Quaterniond qx = Quaterniond{ AngleAxisd{ (y-py)*factor, Vector3d{ 1, 0, 0 } } };
		Quaterniond qy = Quaterniond{ AngleAxisd{ (x-px)*factor, Vector3d{ 0, 1, 0 } } };
		camera = qx*qy*camera;
	}
	px = x;
	py = y;

}

void reshape(int w, int h) {

	double widthScale = (double)w/width, heightScale = (double)h/height;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2*widthScale, 2*widthScale, -2*heightScale, 2*heightScale, -2, 2);
	glMatrixMode(GL_MODELVIEW);
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
	drawFace(v[4], v[5], v[1], v[0], 4);		// Up
	drawFace(v[3], v[2], v[6], v[7], 5);		// Down

}

void display() {

	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();
	glMultMatrixd(getRotationMatrix(camera));
	
	drawCube();

	glutSwapBuffers();
	glutPostRedisplay();

}

int main(int argc, char *argv[]) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Rubics Cube");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutMouseWheelFunc(mouseWheel);

	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glutMainLoop();
	return 0;

}

//