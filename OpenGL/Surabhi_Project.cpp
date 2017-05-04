#include<windows.h>
#include<GL/glut.h>
#include<math.h>

int mouseX, mouseY;
int carX=-1000, carY=-1000;

GLdouble width = 800, height = 600;

void drawQuad(int x, int y, int z, int w, int h) {

	glBegin(GL_QUADS);
	glVertex3i(x, y, z);
	glVertex3i(x+w, y, z);
	glVertex3i(x+w, y+h, z);
	glVertex3i(x, y+h, z);
	glEnd();

}


void background() {

	// Green Lawn
	glColor3f(0.2, 1, 0);
	int lawnWidth = 2 * width / 5;
	int lawnHeight = 2 * height / 5;
	drawQuad(0, 0, 0, lawnWidth, lawnHeight);	// Bottom Left
	drawQuad(3 * width / 5, 0, 0, lawnWidth, lawnHeight);	// Bottom Right
	drawQuad(3 * width / 5, 3 * height / 5, 0, lawnWidth, lawnHeight);	// Top Right
	drawQuad(0, 3 * height / 5, 0, lawnWidth, lawnHeight);	// Top Left

	// Road
	glColor3f(0.4, 0.4, 0.4);
	drawQuad(lawnWidth, 0, 0, width/5, height);	// Vertical Road
	drawQuad(0, lawnHeight, 0, width, height/5);	// Horizontal Road


}


void cubel(int x1, int x2, int y1, int y2, int z1, int z2) {
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);// 1 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2, y2, z1);
	glVertex3i(x1, y2 - 40, z1);
	glEnd();
	glBegin(GL_QUADS);// 2 face
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x2, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 3 face
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10 - 40, z2);
	glEnd();
	glBegin(GL_QUADS);// 4 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10 - 40, z2);
	glVertex3i(x1, y2 - 40, z1);
	glEnd();
	glBegin(GL_QUADS);// 5 face
	glVertex3i(x1, y2 - 40, z1);
	glVertex3i(x2, y2, z1);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10 - 40, z2);
	glEnd();
	glBegin(GL_QUADS);// 6 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glEnd();
	glFlush();
}


void cuber(int x1, int x2, int y1, int y2, int z1, int z2) {
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);// 1 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2, y2 - 40, z1);
	glVertex3i(x1, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 2 face
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10 - 40, z2);
	glVertex3i(x2, y2 - 40, z1);
	glEnd();
	glBegin(GL_QUADS);// 3 face
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10 - 40, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glEnd();
	glBegin(GL_QUADS);// 4 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glVertex3i(x1, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 5 face
	glVertex3i(x1, y2, z1);
	glVertex3i(x2, y2 - 40, z1);
	glVertex3i(x2 + 10, y2 + 10 - 40, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glEnd();
	glBegin(GL_QUADS);// 6 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glEnd();
	glFlush();
}


void cubem(int x1, int x2, int y1, int y2, int z1, int z2) {
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);// 1 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2, y2, z1);
	glVertex3i(x1, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 2 face
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x2, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 3 face
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glEnd();
	glBegin(GL_QUADS);// 4 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glVertex3i(x1, y2, z1);
	glEnd();
	glBegin(GL_QUADS);// 5 face
	glVertex3i(x1, y2, z1);
	glVertex3i(x2, y2, z1);
	glVertex3i(x2 + 10, y2 + 10, z2);
	glVertex3i(x1 + 10, y2 + 10, z2);
	glEnd();
	glBegin(GL_QUADS);// 6 face
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y1, z1);
	glVertex3i(x2 + 10, y1 + 10, z2);
	glVertex3i(x1 + 10, y1 + 10, z2);
	glEnd();
	glFlush();
}


void car() {

	float i;
	int x1, y1, r;
	cubem(carX, carX + 20, carY, carY + 30, -20, 0);
	cubel(carX + 20, carX + 50, carY, carY + 70, -20, 0);
	cubem(carX + 50, carX + 90, carY, carY + 70, -20, 0);
	cuber(carX + 90, carX + 120, carY, carY + 70, -20, 0);
	cubem(carX + 120, carX + 140, carY, carY + 30, -20, 0);
	//wheels
	glColor3f(0, 0, 0);
	x1 = carX + 105;
	y1 = carY;
	r = 12;
	for (i = 0.0; i <= 2 * 3.14; i += 0.01) {
		glBegin(GL_POLYGON);
		glVertex3i(x1 + cos(i)*r, y1 + sin(i)*r, 0);
	}
	glEnd();
	x1 = carX + 35;
	y1 = carY;
	r = 12;
	for (i = 0.0; i <= 2 * 3.14; i += 0.01) {
		glBegin(GL_POLYGON);
		glVertex3i(x1 + cos(i)*r, y1 + sin(i)*r, 0);
	}
	glEnd();
	x1 = carX + 105;
	y1 = carY;
	r = 12;
	for (i = 0.0; i <= 2 * 3.14; i += 0.01) {
		glBegin(GL_POLYGON);
		glVertex3i(x1 + cos(i)*r, y1 + sin(i)*r, -20);
	}
	glEnd();
	x1 = carX + 35;
	y1 = carY;
	r = 12;
	for (i = 0.0; i <= 2 * 3.14; i += 0.01) {
		glBegin(GL_POLYGON);
		glVertex3i(x1 + cos(i)*r, y1 + sin(i)*r, -20);
	}
	glEnd();
	//windows
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);// 5 face
	glVertex3i(carX + 90 + 4, carY + 70 - 4, -20);
	glVertex3i(carX + 120 - 4, carY + 70 - 40 + 4, -20);
	glVertex3i(carX + 120 + 10 - 4, carY + 70 + 10 - 40 + 4, 0);
	glVertex3i(carX + 90 + 10 + 4, carY + 70 + 10 - 4, 0);
	glEnd();
	glBegin(GL_QUADS);// 5 face
	glVertex3i(carX + 20 + 4, carY + 70 - 40 + 4, -20);
	glVertex3i(carX + 50 - 4, carY + 70 - 4, -20);
	glVertex3i(carX + 50 + 10 - 4, carY + 70 + 10 - 4, 0);
	glVertex3i(carX + 20 + 10 + 4, carY + 70 + 10 - 40 + 4, 0);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3i(carX + 50 + 4, carY + 35 + 4, -20);
	glVertex3i(carX + 90 - 4, carY + 35 + 4, -20);
	glVertex3i(carX + 90 - 4, carY + 70 - 4, -20);
	glVertex3i(carX + 50 + 4, carY + 70 - 4, -20);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex3i(carX + 70, carY + 38, -20);
	glVertex3i(carX + 70, carY + 66, -20);
	glEnd();
	glFlush();

}


void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseX = x;
		mouseY = y;

		carX = mouseX;
		carY = height - mouseY;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		exit(0);

}



void reshape(int w, int h) {

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, (GLdouble)w, 0, (GLdouble)h, -20, 20);
	glMatrixMode(GL_MODELVIEW);
	width = w;
	height = h;
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);

	glLoadIdentity();
	background();
	car();
	glFlush();

	
	glutSwapBuffers();
	glutPostRedisplay();

}

void main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Traffic Management");
	glutMouseFunc(mouse);
	//glutKeyboardFunc(keyboard);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}



