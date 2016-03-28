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

// Function to convert degrees to radians
double degtorad(double deg){
	return deg*PI/180;
}

// Function to Calculate Distance between 2 points
double dist(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

// Function to draw a circle
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

void drawNodes() {

	for (int i = 0; i<nodeCount; i++) {
		if (i==0)
			glColor3f(0, 0.7, 1);									// Set the Colour to blue for the first Node
		else
			glColor3f(1, 1, 1);										// For the rest of the nodes its a white color
		drawCircle(nodeList[i].x, nodeList[i].y, 0.03);				// Draw a circle at the point nodeList[i] with a 0.03 radius
	}

}


// Function to find the nearest node to a given node N
int findNearestNode(int N, bool visited[]) {

	int nearestNode = -1;
	double minDist = 1000000;										// Set a really high initial value for minimum distance

	for (int i = 0; i<nodeCount; i++) {
		if (visited[i]==false && dist(nodeList[N], nodeList[i]) < minDist) {		// If the node is not visited and the distance to the node is less than the existing distance choose this node
			minDist = dist(nodeList[N], nodeList[i]);
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
		visited[i] = false;									// Initially set the visited to false for all nodes

	visited[0] = true;										// Start node is 0th node (Blue Node) so we visit that first
	path[count] = 0;
	count++;

	while (count < nodeCount) {
		int nearestNode = findNearestNode(path[count-1], visited);	//Find the nearest node tp path[count-1] and add it to the path list
		visited[nearestNode] = true;
		path[count] = nearestNode;
		count++;
	}

	// This part draws a Line Loop in the order specified by the Path List
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
		solveTSP();				// Solve TSP only if finished is true. Finished will be true when you do a right mouse click
	}

	glutSwapBuffers();			
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y) {

	// If a Left mouse button is pressed store the cordinates of that point in nodeList
	if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && finish == false) {
		nodeList[nodeCount].x = (float)(x-300)/300;					// x cordinates will be in the range [1, 600] because window width is 600 we need to convert this range to [-1, +1]
		nodeList[nodeCount].y = (float)(300-y)/300;					// y cordinates will be in the range [600, 1] because window height is 600 we need to convert this range to [-1, +1]
		nodeCount++;
	}

	// If a Righ mouse button is pressed store the cordinates of that point in nodeList and also set the finished variable to true so that you cans start solving the TSP Graph
	else if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && finish == false) {
		nodeList[nodeCount].x = (float)(x-300)/300;
		nodeList[nodeCount].y = (float)(300-y)/300;
		nodeCount++;
		finish = true;
	}
}


int main(int argc, char *argv[]){


	//This is main function bullshit
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
