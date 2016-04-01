

#include<stdlib.h>
#include<gl/glut.h>
#include <time.h>
#include<stdio.h>
#include<math.h>
int SCREENH = 600, SCREENW = 800;

//-------------------declarations---------------
bool pause = false, lflag = true, wflag = true, gameEndStatus = false, instflag = false, abtflag = false, start = false;  //flags
float plane_mvmt = 0.0;//jet movement up or down
float score = 1;
char score_Str[20], slevel[20];   //score string and levelstring
int level = 1, buildColor;     // initial level=1
building b;  // building struct
Cloud s;     // cloud struct
			 //plane bounds
			 //-------------function prototypes------------------
void keyPressed(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void drawCloud();
bool cloudHit();
bool buildingHit();
void printScore();
void display();
void moveJetU();
void moveJetD();


void buildingBlock()
{
	b.block_x = 50.0;
	srand(time(0));
	b.no_floors = rand()%3+4;
	buildColor = rand()%3;

	b.block_y = b.no_floors*10 +15;   // generate block y cordinate depending on no of floors
	b.state = true;
	s.state = false;

}

void CloudBlock()
{
	s.block_x = 50.0;
	srand(time(0));
	s.block_y = (rand()%30)+50;   //randomly generate block y cordinate 
	s.state = true;
	b.state = false;
}

void Circle(float x1, float y1, float radius)
{
	float x2, y2;
	float angle;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	for (angle = 1.0f; angle<361.0f; angle += 1.0)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();

}

void drawJet()
{
	//left tail wing

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(5.5, 47.0);
	glVertex2f(8.5, 47.0);
	glVertex2f(5.5, 48.0);
	glVertex2f(4.5, 48.0);
	glEnd();


	//left front wing

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 47.0);
	glVertex2f(20.0, 47.0);
	glVertex2f(13.0, 50.0);
	glVertex2f(11.0, 50.0);
	glEnd();

	//tail
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(4.7, 45.0);
	glVertex2f(5.5, 51.0);
	glVertex2f(7.0, 51.0);
	glVertex2f(9.0, 45.0);
	glEnd();


	//body
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(5.0, 48.0);
	glVertex2f(11.0, 48.0);
	glVertex2f(22.0, 46.5);
	glVertex2f(22.0, 45.0);
	glVertex2f(5.0, 45.0);
	glEnd();


	//right front wing
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 46.0);
	glVertex2f(18.0, 46.0);
	glVertex2f(13.0, 41.0);
	glVertex2f(11.0, 41.0);
	glEnd();


	//dome
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 47.0);
	glVertex2f(15.0, 48.5);
	glVertex2f(17.0, 49.0);
	glVertex2f(19.0, 48.0);
	glVertex2f(21.0, 46.0);
	glVertex2f(17.0, 46.0);
	glVertex2f(15.0, 47.5);
	glVertex2f(13.0, 47.0);
	glEnd();


	//right tail wing
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(5.5, 47.0);
	glVertex2f(8.5, 47.0);
	glVertex2f(5.5, 43.0);
	glVertex2f(4.5, 43.0);
	glEnd();


	// front tip
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(22.0, 45.0);
	glVertex2f(22.3, 45.375);
	glVertex2f(22.6, 45.75);
	glVertex2f(22.3, 46.125);
	glVertex2f(22.0, 46.5);
	glEnd();
}


void printString(float x, float y, float z, void *font, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}



void drawCloud()
{
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(s.block_x, s.block_y, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(6, -3.0, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(0, 6.0, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(6, -3.0, 0.0);
	glutSolidSphere(5, 100, 10);

}

bool cloudHit()
{
	if (s.block_x < 13 && s.block_x> -5)
		if (plane_mvmt-3+50 >s.block_y-3 && plane_mvmt-3+50 < s.block_y+3)   // plane front to cloud mid box1
			return true;

	if (s.block_x < 12 && s.block_x> -4)
		if (plane_mvmt-3+50 >s.block_y-5 && plane_mvmt-3+50 < s.block_y+5)   // plane front to cloud mib box2
			return true;

	if (s.block_x < 10 && s.block_x> -1)
		if (plane_mvmt-3+50 >s.block_y-6 && plane_mvmt-3+50 < s.block_y-2)
			return true;

	//for top wing and bottom wing
	if (s.block_x < 5 && s.block_x> -3)
		if (plane_mvmt-3+50 >s.block_y-11 && plane_mvmt-3+50 < s.block_y+13)
			return true;

	return false;
}


bool buildingHit()
{
	if (((int)b.block_x<=8 &&(int)b.block_x>=-7 && ((int)plane_mvmt+50)-b.block_y<=3))   //buildin back  body to tail
		return true;
	else if (((int)b.block_x<=10 &&(int)b.block_x>=-5 && ((int)plane_mvmt+50)-b.block_y<=0))   //body to tail
		return true;
	else if (((int)b.block_x<=6 &&(int)b.block_x>=-3 && ((int)plane_mvmt+47)-b.block_y<=0))  //right wing
		return true;
	else if (((int)b.block_x<=4 &&(int)b.block_x>=-4 && ((int)plane_mvmt+47)-b.block_y<=3))  //   building back right wing
		return true;
	else
		return false;
}


void printScore()
{
	glColor3f(1.0, 1.0, 0.0);//score


	sprintf_s(slevel, "%d", (int)level);
	printString(58, 1.8, 0, GLUT_BITMAP_TIMES_ROMAN_10, "Level");
	printString(58, 3.5, 0, GLUT_BITMAP_TIMES_ROMAN_24, slevel);

	if (booster >0 && boost)
		score += 0.03;//SCORE with booster
	else
		score += 0.005;//SCORE without booster

	printString(38, 1.5, 0, GLUT_BITMAP_TIMES_ROMAN_10, "Distance");
	sprintf_s(score_Str, "%d", (int)score);
	printString(38, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, score_Str);

	printString(47, 2, 0, GLUT_BITMAP_HELVETICA_12, "Altitude");
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//GameOver Checking
	if (gameEndStatus == true)
	{
		gameEnd();
	}
	else if (wflag==true)//Welcome Screen
	{
		welcome();
	}




	void mouse(int button, int state, int x, int y)            // takes input from mouse
	{

	}


	void keyPressed(unsigned char key, int x, int y) // int x and y are mouse pos at time of press
	{
		if (key == 27)
		{
			exit(0);
		}
		else if (key == 'p' || key == 'P')
		{
			if (pause == true)
				pause = false;
			else
				pause = true;
		}
		glutPostRedisplay();
	}

	void myReshape(int w, int h)
	{
		SCREENH = h, SCREENW = w;
		printf("width = %d\theight= %d", w, h);
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 100.0, 0.0, 100.0, -5.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
	}


	int main(int argc, char** argv)
	{

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
		glutInitWindowSize(SCREENW, SCREENH);
		glutInitWindowPosition(50, 50);
		glutCreateWindow("*EscPlane!!");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(myReshape);
		glutMouseFunc(mouse);
		glutKeyboardFunc(keyPressed);
		glutMainLoop();
		return 0;

	}
