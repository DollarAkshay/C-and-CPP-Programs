#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define PI 3.1415926

float manX = 0, manY = 0;
float manSpeedX = 0.00;

float t = 0;

inline double degtorad(double deg){
	return deg*PI/180;
}

void drawCircle(float x, float y, float r){

	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	for(double i=0; i<=360; i+=1){
		double px = r*cos(degtorad(i)) + x;
		double py = r*sin(degtorad(i)) + y;
		glVertex2f(px, py); 
		glColor3f( (px+1)/2, (py+1)/2, 0);
	}
	glEnd();
	glFlush();
}

void drawMan(float x, float y){

	drawCircle(x, y, 0.1);

}

void drawString(){

	float freq = 1;

	for(double x = -1; x<=1; x+=0.05){
		double ang = (x+1)/2*360*freq + t;
		double y = 0.5*sin(degtorad(ang));
		drawCircle(x, y, 0.1);
	}

}


void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);

	

	drawString();

	manX+=manSpeedX;
	t+=0.1;

	if(manX>=1 || manX<=-1)
		manSpeedX = -manSpeedX;

	glutSwapBuffers();
	glutPostRedisplay();

}


int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutCreateWindow("SS");
	glutDisplayFunc(display);
	glLoadIdentity();
	glutMainLoop();
	return 0;

}
