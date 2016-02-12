#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>

typedef float point[3];  // Array of 3 floats

// Initial tetrahedron
point v[] = { { 200, 200, 0 }, 
			  { 400, 546, 0 }, 
			  { 600, 200, 0 },
			  { 400, 315, 346 } };

int dp;

void triangle(point a, point b, point c, int n){

	float x = max(a[0], b[0], c[0]);
	float dx = (float)(x-200)/400;
	glColor3f(dx*(0.1 +0.3*n), 0, (1-dx)*(0.1 +0.3*n));
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
	glFlush();

}

void tetrahedron(point a, point b, point c, point d){      

	triangle(a, b, c, 0);
	triangle(a, b, d, 1);
	triangle(b, d, c, 2);
	triangle(a, d, c, 3);
	Sleep(500/dp/dp);												//Sleeps for 10 ms

}

void divideGasket(point a, point b, point c, point d, int div){

	float mid[6][3];

	if (div>0){
		for (int i = 0; i<3; i++) {
			mid[0][i] = (a[i]+b[i])/2;
			mid[1][i] = (a[i]+c[i])/2;
			mid[2][i] = (a[i]+d[i])/2;
			mid[3][i] = (b[i]+c[i])/2;
			mid[4][i] = (b[i]+d[i])/2;
			mid[5][i] = (c[i]+d[i])/2;
		}

		divideGasket(a, mid[0], mid[1], mid[2], div-1);		//Left Tetrahedron
		divideGasket(mid[0], b, mid[3], mid[4], div-1);		//Top Tetrahedron
		divideGasket(mid[1], mid[3], c, mid[5], div-1);		//Right Tetrahedron
		divideGasket(mid[2], mid[4], mid[5], d, div-1);		//Front Tetrahedron
		
	}
	else {
		tetrahedron(a, b, c, d);
	}
}

void display(){

	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glFlush();
	Sleep(1000);

	for (int div = 1; div<=4; div++) {											//Number of Recursive Divisions
		dp = div;
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		divideGasket(v[0], v[1], v[2], v[3], div);
		Sleep(500);
	}
}


int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3D Gasket");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}

// :)