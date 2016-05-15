#include <stdio.h>
#include <GL/glut.h>

GLuint head_x1 = 5, head_y1 = 30, head_x2 = 15, head_y2 = 30, head_x3 = 15, head_y3 = 40, head_x4 = 5, head_y4 = 40;

// shape
GLuint listID;

void MrRobot(GLsizei displayListID){

	glNewList(displayListID, GL_COMPILE);

	//Save current colour state
	glPushAttrib(GL_CURRENT_BIT);

	// body
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0, 10);
	glVertex2f(20, 10);
	glVertex2f(20, 30);
	glVertex2f(0, 30);
	glEnd();

	// head
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(head_x1, head_y1);
	glVertex2f(head_x2, head_y2);
	glVertex2f(head_x3, head_y3);
	glVertex2f(head_x4, head_y4);
	glEnd();

	// legs
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(10, 10);
	glVertex2f(20, 0);
	glVertex2f(10, -5);
	glVertex2f(0, 0);
	glEnd();

	// right hand
	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(20, 30);
	glVertex2f(30, 27.5);
	glVertex2f(20, 25);
	glEnd();

	// left hand
	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-10, 27.5);
	glVertex2f(0, 30);
	glVertex2f(0, 25);
	glEnd();

	//Recall saved colour state
	glPopAttrib();

	glEndList();
}

void display(){

	glClearColor(0, 0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1, 0, 0);

	//Defining a modelview transform matrix
	glScalef(0.3, 0.3, 0.3);

	//Execute the display list (the modelview matrix will be applied)
	glCallList(listID);
	MrRobot(listID);

	glFlush();
}

void keyboard(unsigned char key, int x, int y){

	printf("\nKeyboard event detected. \nCharacter key: %c\nMouse pointer position: x=%d y=%d", key, x, y);

	if (key=='w'){
		printf("W :D :D \n");
		head_y1++;
		head_y2++;
		head_y3++;
		head_y4++;
	}
	if (key==GLUT_KEY_DOWN)
	{
		head_y1--;
		head_y2--;
		head_y3--;
		head_y4--;
	}
	if (key==GLUT_KEY_LEFT)
	{
		head_x1--;
		head_x2--;
		head_x3--;
		head_x4--;
	}
	if (key==GLUT_KEY_RIGHT)
	{
		head_x1++;
		head_x2++;
		head_x3++;
		head_x4++;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Mr Robot");

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-5, 35, -5, 30);

	listID = glGenLists(1);
	MrRobot(listID);


	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}