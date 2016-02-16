#include <GL\glew.h>
#include <GL\freeglut.h>
#include<stdlib.h>

int mouseX, mouseY;
GLdouble eyeloc = 0;
GLfloat rtri;

void init() {

	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -2, -6, 0, 0, 0, 0, 1, 1);

}

void reshape(int w, int h) {
	if (h==0)
		h = 1;

	float ratio = 1.0*w/h;

	glMatrixMode(GL_PROJECTION);//defines viewing volume
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int a, int b) {

}

void mouse(int a, int b, int c, int d) {

}

void mousedrag(int x, int y) {

}

void display() {


	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(rtri, 0.0f, 1, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);   // Red   
	glVertex3f(0.0f, 1.0f, 0.0f);   // Top Of Triangle (Front) 
	glColor3f(0.0f, 1.0f, 0.0f);   // Green  
	glVertex3f(-1.0f, -1.0f, 1.0f);   // Left Of Triangle (Front)  
	glColor3f(0.0f, 0.0f, 1.0f);   // Blue  
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);   // Red   
	glVertex3f(0.0f, 1.0f, 0.0f);   // Top Of Triangle (Right) 
	glColor3f(0.0f, 0.0f, 1.0f);   // Blue   
	glVertex3f(1.0f, -1.0f, 1.0f);   // Left Of Triangle (Right) 
	glColor3f(0.0f, 1.0f, 0.0f);   // Green  
	glVertex3f(1.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);   // Red   
	glVertex3f(0.0f, 1.0f, 0.0f);   // Top Of Triangle (Back)
	glColor3f(0.0f, 1.0f, 0.0f);   // Green   
	glVertex3f(1.0f, -1.0f, -1.0f);   // Left Of Triangle (Back)  
	glColor3f(0.0f, 0.0f, 1.0f);   // Blue   
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f);   // Red   
	glVertex3f(0.0f, 1.0f, 0.0f);   // Top Of Triangle (Left)  
	glColor3f(0.0f, 0.0f, 1.0f);   // Blue   
	glVertex3f(-1.0f, -1.0f, -1.0f);   // Left Of Triangle (Left)  
	glColor3f(0.0f, 1.0f, 0.0f);   // Green   
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	rtri += 0.1f;
	glFlush();
	glutPostRedisplay();

}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);         
	glutInitWindowPosition(100, 100);             
	glutCreateWindow("Sample"); 
	glewInit();
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mousedrag);

	glutMainLoop();
	return 0;
}