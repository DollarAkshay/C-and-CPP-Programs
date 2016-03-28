/*Include Files*/
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>

#define UP 1
#define Down 2
#define LEFT 3
#define RIGHT 4

// Status Variables
GLint   lvl = 1;
GLint   points = 0;
GLint   size = 0;
GLbyte  gameOver = true;
GLbyte  EnableLight = true;

// Snake Variables
GLint   bodyPos[2][100] = { {} };
GLint   x = 5;
GLint   z = 10;
GLint   oldX[2] = {};
GLint   oldZ[2] = {};
GLbyte  direction = 0;

// Food Variables
GLint   bx = 0;
GLint   bz = 0;

// Screen variables
GLint   w = 800;
GLint   h = 550;
GLint   Giw = 0;
GLint   Gih = 0;
GLint   Gfw = 150;
GLint   Gfh = 150;

//Variables for the Camera Angle
static GLfloat view_rotx = 45.0F;
static GLfloat view_roty = 0.0F;
static GLfloat view_rotz = 0.0F;

static GLfloat headRotation = 90.0F;
static GLfloat zoom = -300.0F;

// Variables to check the FPS
DWORD   g_dwLastFPS = 0;
int		g_nFPS = 0, g_nFrames = 0;

//Configure the lightning
void initLight()
{
	//Add ambient light
	GLfloat ambientColor[] = { 0.3f, 0.4f, 0.8f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = { 0.95f, 0.5f, 0.5f, 1.0f };
	GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
}

//initialize the first configurations
void myInit(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.3, 0.80, 0.9, 0.0f); //Change the background to blue
	if (EnableLight) {
		glEnable(GL_COLOR_MATERIAL); //Enable color
		glEnable(GL_LIGHTING); //Enable lighting
		glEnable(GL_LIGHT0); //Enable light #0
		glEnable(GL_LIGHT1); //Enable light #1
		glEnable(GL_NORMALIZE); //Automatically normalize normals
	}
}

//Configure window resize
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1, 800.0);
}

void Write(char *string) {//Write string on the screen
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);//GLUT_BITMAP_TIMES_ROMAN_24
}
//This Function will rotate the object according to the Angles
void ManipulateViewAngle() {
	glRotatef(view_rotx, 1.0, 0.0, 0.0);//Rotate Arround X axis
	glRotatef(view_roty, 0.0, 1.0, 0.0);//Rotate Arround Y axis
	glRotatef(view_rotz, 0.0, 0.0, 1.0);//Rotate Arround Z axis
}

//This Function will reset the snake size and location...
void Reset() {
	x = 5;
	z = 10;
	direction = 0;
	lvl = 1;
	points = 0;
	size = 0;
	gameOver = false;
	view_rotx = 45.0F;
	view_roty = 0.0F;
	view_rotz = 0.0F;
	headRotation = 90.0F;
	zoom = -300.0F;
}

//Display a welcome screen
void WelcomeScreen() {
	char tmp_str[40];

	glColor3f(0.0, 0.0, 0);
	glRasterPos2f(0, 20);
	Write("Welcome To Snake Game.");

	glColor3f(0.18, 0.28, 0.29);
	glRasterPos2f(0, 10);
	Write("Prepared By Gayathri");

	glColor3f(0, 0, 1);
	glRasterPos2f(0, 0);
	Write("To Start Playing please press 'n'. Enjoy");
}

void DrawSnake() {
	int  i;

	//Drawing the head & the plane
	glPushMatrix();
	ManipulateViewAngle();
	//This will draw the plane that the snake will run on.
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);//black place
	glTranslatef(75.0, -16.0, 75.0);
	glScalef(155, 5.0, 155);
	glutSolidCube(1);
	glPopMatrix();
	//Here we will draw the Head of the snake
	glColor3f(1.0, 0.86, 0);//Color it Yellow
	glTranslatef(x, -10.0, z);//Give it the location according to x & z
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(10, 20, 20);//Draw the head as a sphere a litle bit bigger than the body spheres
	glRotatef(headRotation, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0, 0.0, 6.0);
	glScalef(0.8, 1.0, 1.0);
	glutSolidCone(10, 10, 20, 20);
	glColor3f(0, 0, 0);
	glTranslatef(-4.0, 10.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	glutSolidSphere(10, 20, 20);
	glTranslatef(26.0, 0.0, 0.0);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();

	//Drawing the body
	for (i = 0; i<size; i++) {//Loop throw the size and draw spheres representing the body
		glPushMatrix();
		ManipulateViewAngle();
		glTranslatef(bodyPos[0][i], -10.0, bodyPos[1][i]);//this will locate the spheres
		glColor3f(0.91, 0.06, 0.17);//Color pink
		glScalef(0.5, 0.5, 0.5);
		glutSolidSphere(7, 20, 20);
		glPopMatrix();
	}
}

void DrawFood()
{
	//Draw the Sphere representing the Food for the snake
	glPushMatrix();
	ManipulateViewAngle();
	glTranslatef(bx, -10.0, bz);
	glColor3f(0.4, 0.7, 0.4);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(7, 20, 20);
	glPopMatrix();
}

void GameStatus() {

	char tmp_str[40];

	// Print the status of the game on the screen
	glColor3f(0.18, 0.28, 0.29);
	glRasterPos2f(5, 50);

	sprintf(tmp_str, "Level: %d Points: %d", lvl, points);
	Write(tmp_str);
	glRasterPos2f(5, 40);
	Write("To start and control the snake,press the arrow keys.");
}

// This function generates random numbers for the location of the food that the snake will eat.
int RandomNumber(int high, int low)
{
	return (rand() % (high-low))+low;
}

//Generate the New Food that the snake will eat
void newFood() {
	time_t seconds;
	time(&seconds);
	srand((unsigned int)seconds);
	bx = RandomNumber(Gfw-Giw, Giw+10);
	bz = RandomNumber(Gfh-Gih, Gih+10);
}

//This function will calculate the frame per second to display on the screen
void getFPS() {
	char tmp_str[40];

	if (GetTickCount() - g_dwLastFPS >= 1000)				// When A Second Has Passed...
	{
		g_dwLastFPS = GetTickCount();					// Update Our Time Variable
		g_nFPS = g_nFrames;						// Save The FPS
		g_nFrames = 0;							// Reset The FPS Counter
	}
	g_nFrames++;

	glRasterPos2f(75, 50);
	//sprintf(tmp_str, "FPS: %d", g_nFPS);
	//Write(tmp_str);

	glRasterPos2f(50, 60);
	//sprintf(tmp_str, "Pos X: %d Pos Z: %d", x, z);
	//Write(tmp_str);
}

//This function will check for Collision
bool collision() {
	int i;

	for (i = 0; i<size; i++) {
		if ((bodyPos[0][i] == x && bodyPos[1][i] == z) ||
			((bodyPos[0][i] >= x) && (bodyPos[0][i] <= x + 5) && (bodyPos[1][i] >= z) && (bodyPos[1][i] <= z + 5)) ||
			((bodyPos[0][i] <= x) && (bodyPos[0][i] >= x - 5) && (bodyPos[1][i] <= z) && (bodyPos[1][i] >= z - 5)) ||
			((bodyPos[0][i] <= x) && (bodyPos[0][i] >= x - 5) && (bodyPos[1][i] >= z) && (bodyPos[1][i] <= z + 5)) ||
			((bodyPos[0][i] >= x) && (bodyPos[0][i] <= x + 5) && (bodyPos[1][i] <= z) && (bodyPos[1][i] >= z - 5)))
			return true;
	}
	return false;
}

//This Function will move the snake according to the directions 
//Taken from the Keyboard keys
void Run(int value) {
	int i;

	oldX[1] = x;
	oldZ[1] = z;
	switch (direction) {
	case RIGHT:
		headRotation = 90;
		x += 6;
		if (x > Gfw-2) x = Giw-1;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case LEFT:
		headRotation = -90;
		x -= 6;
		if (x < 0) x = Gfw-2;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case UP:
		headRotation = 0;
		z += 6;
		if (z > Gfh-2) z = Gih-1;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case Down:
		headRotation = 180;
		z -= 6;
		if (z < 2) z = Gfh-2;//This will check if the snake is going into the border so it will appear on the other side
		break;
	}

	//Checks for Collisoin if yes Game Over
	if (collision()) gameOver = true;

	//Checks if the snake ate the food (check the X and Y)
	// If yes it will increase the points & the size of the snake & create a new food
	if ((x == bx && z == bz) ||
		((x >= bx) && (x <= bx + 4) && (z >= bz) && (z <= bz + 4)) ||
		((x <= bx) && (x >= bx - 4) && (z <= bz) && (z >= bz - 4)) ||
		((x <= bx) && (x >= bx - 4) && (z >= bz) && (z <= bz + 4)) ||
		((x >= bx) && (x <= bx + 4) && (z <= bz) && (z >= bz - 4))) {
		points++;
		if (points < 100) size++;
		if (points%5 == 0 && lvl < 15) lvl++;
		newFood();
	}

	for (i = 0; i<size; i++) {// Save the positions of the body parts
		oldX[0] = oldX[1];
		oldZ[0] = oldZ[1];
		oldX[1] = bodyPos[0][i];
		oldZ[1] = bodyPos[1][i];
		bodyPos[0][i] = oldX[0];
		bodyPos[1][i] = oldZ[0];
	}

	//Set the Timer
	glutTimerFunc(130-lvl*4, Run, 0);
}

void Display() {//Draw Function
				// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (EnableLight) initLight();

	glTranslatef(-60.0, 40.0, zoom);
	//Check if the value of the Flag "Game Over is not True it will continue the game"
	if (!gameOver) {
		GameStatus();
		DrawFood();
		DrawSnake();
	}
	else
		WelcomeScreen();

	getFPS();

	// Updates the screen
	glutPostRedisplay();
	glutSwapBuffers();
}

void Special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (direction != LEFT)
			direction = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (direction != RIGHT)
			direction = LEFT;
		break;
	case GLUT_KEY_UP:
		if (direction != UP)
			direction = Down;
		break;
	case GLUT_KEY_DOWN:
		if (direction != Down)
			direction = UP;
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		//All Snake Rotation Over X, Y, Z angles
	case 'x': view_rotx += 2;
		glutPostRedisplay();
		break;
	case 'X': view_rotx -= 2;
		glutPostRedisplay();
		break;
	case 'y': view_roty += 2;
		glutPostRedisplay();
		break;
	case 'Y': view_roty -= 2;
		glutPostRedisplay();
		break;
	case 'z': view_rotz += 2;
		glutPostRedisplay();
		break;
	case 'Z': view_rotz -= 2;
		glutPostRedisplay();
		break;
	case 'a': size++;
		glutPostRedisplay();
		break;
	case 'A': size--;
		glutPostRedisplay();
		break;
	case '+': zoom++;
		glutPostRedisplay();
		break;
	case '-': zoom--;
		glutPostRedisplay();
		break;
	case 'n': Reset();
		glutPostRedisplay();
		break;

		//ESC to Exit
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(80, 80);
	glutCreateWindow("Snake Game - (Gayathri Gokuldas)");
	glutSpecialFunc(Special);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(Display);
	glutReshapeFunc(resize);

	newFood();
	Run(0);

	myInit();
	glutMainLoop();
	return 0;
}