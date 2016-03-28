#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<GL/glut.h>

#define PI 3.1415926

struct point {
	float x, y;
};

bool finish = false;

int nodeCount = 0;
point nodeList[1000];

using namespace std;

inline double degtorad(double deg){
	return deg*PI/180;
}

void drawCircle(float x, float y, float r){

	glBegin(GL_POLYGON);
	for(double i=0; i<=360; i+=5){
		double px = r*cos(degtorad(i)) + x;
		double py = r*sin(degtorad(i)) + y;
		glVertex2f(px, py);
	}
	glEnd();
	glFlush();
}

void drawMan(float x, float y){

	drawCircle(x, y, 0.1);

}

void drawNodes() {

	for (int i = 0; i<nodeCount; i++) {

		if (i==0)
			glColor3f(0, 0.7, 1);
		else
			glColor3f(1, 1, 1);

		drawCircle(nodeList[i].x, nodeList[i].y, 0.05);
	}

}

double dist(point a, point b) {

	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );

}

int findNearestNode(int node, bool visited[]) {

	int nearestNode = -1;
	double minDist = 1000000;

	for (int i = 0; i<nodeCount; i++) {
		if (visited[i]==false && dist(nodeList[node], nodeList[i])< minDist) {
			minDist = dist(nodeList[node], nodeList[i]);
			nearestNode = i;
		}
	}

	return nearestNode;

}

void solveTSP() {

	int count = 0;

	bool visited[100];
	int path[100];

	for (int i = 0; i<100; i++)
		visited[i] = false;

	visited[0] = true;
	path[count] = 0;
	count++;

	while (count < nodeCount) {
		int nearestNode = findNearestNode(path[count-1], visited);
		visited[nearestNode] = true;
		path[count] = nearestNode;
		count++;
	}

	glLineWidth(2);
	glColor3f(0, 0.8, 0.2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <nodeCount; i++)
		glVertex2f(nodeList[path[i]].x, nodeList[path[i]].y);

	glEnd();
	glFlush();
}


void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);

	drawNodes();
	if (finish==true) {
		solveTSP();
	}

	glutSwapBuffers();
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y) {

	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && finish == false) {
		nodeList[nodeCount].x = (float)(x-300)/300;
		nodeList[nodeCount].y = (float)(300-y)/300;
		nodeCount++;
	}
	else if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && finish == false) {
		nodeList[nodeCount].x = (float)(x-300)/300;
		nodeList[nodeCount].y = (float)(300-y)/300;
		nodeCount++;
		finish = true;
	}
}


int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TSP");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glLoadIdentity();
	glutMainLoop();
	return 0;

}
