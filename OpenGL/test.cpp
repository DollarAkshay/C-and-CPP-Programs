#include <GL/glut.h>
#include <GL/gl.h>
#include<stdio.h>

int k[10][2];
int d = 0, cnt = 0, b = 1;
GLint t = 0, m = 0, sum = 0;
int c[10][10];
int w[10][2];
int z[10][10], s[10];
int hj = 0, q, e, kl, lk, n, jr, rj, pq, qp, qn, qu, i, j;
char c1[2], c2[2];
char c3[26] = "COST OF SPANNING TREE =";
char c4[] = "CLICK RIGHT BUTTON FOR NEXT OPTION";

void first()
{
	b = 0;


	glColor3f(.6, .6, .6);




	for (int j = 0; j<50000; j++)
		for (int k = 0; k<50000; k++);
	glClear(GL_COLOR_BUFFER_BIT);
	printf("ENTER NUMBER OF NODES\n");
	scanf("%d", &n);
	printf("GO TO DISPLAY WINDOW AND CLICK RIGHT BUTTON\n");
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (b==1)
		first();
	glFlush();
}

int find(int v)
{
	while (s[v]!=v)v = s[v];
	return v;
}



void drawSquare(int x, int y) {

	//y = 500-y;
	cnt++;
	if (cnt>n)
	{
		//printf("NODES EXCEEDING INITIAL VALUE\n");
		return;
	}
	k[d][0] = x;
	k[d][1] = y;
	d++;
	glPointSize(10);
	glColor3f(0.6f, 0.55f, 0.89f);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	//glutSwapBuffers();
	glFlush();
}





void mouse(int bin, int state, int x, int y)
{


	if (bin==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		drawSquare(x, 500-y);

	}


}

void afg()
{
	int i, j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (c[i][j]>0 && c[i][j]!=999)
			{
				glColor3f(0.7, 0.7, 0.8);
				glBegin(GL_LINES);
				glVertex2i(k[i][0], k[i][1]);
				glVertex2i(k[j][0], k[j][1]);
				glEnd();
				glColor3f(032, .78, .99);
				glBegin(GL_POINTS);
				glVertex2i(k[i][0], k[i][1]);
				glVertex2i(k[j][0], k[j][1]);
				glEnd();


			}
		}

	}

	glColor3f(.98, .78, .67);
	glRasterPos2f(50, 30);
	for (int r = 0; c4[r]!='\0'; r++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c4[r]);


	glFlush();
}


void init(void)
{

	glClearColor(.12, .22, .04, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT);

	//glViewport( 0,0, 500, 500 );

	gluOrtho2D(0.0, 600.0, 0.0, 500.0);
	glMatrixMode(GL_PROJECTION);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void top_menu(int option)
{
	int i, j;
	char buffer[40];
	switch (option)
	{
	case 0:

		printf("ENTER THE COST MATRIX\n");
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
			{
				scanf("%d", &c[i][j]);
				z[i][j] = c[i][j];
			}

		printf("\n");
		printf("GO TO DISPLAY WINDOW AND CLICK RIGHT BUTTON FOR NEXT OPTION\n");
		break;

	case 1:
		afg();

		break;

	case 2:for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if ((c[i][j]==c[j][i]) && ((c[i][j])>0 && (c[i][j]!=999)) && ((c[j][i]>0) && (c[j][i]!=999)))
			{
				glBegin(GL_LINES);
				glVertex2i(k[i][0], k[i][1]);
				glVertex2i(k[j][0], k[j][1]);
				glEnd();
				//itoa(c[i][j],buffer,10);
				if (c[i][j]<=9)
				{
					int x = c[i][j];
					char c = '0'+x;

					glRasterPos2f((k[i][0]+k[j][0])/2, (k[i][1]+k[j][1])/2);
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
				}
				else
				{

					q = c[i][j]/10;
					e = c[i][j]%10;
					c1[0] = '0'+q;
					c1[1] = '0'+e;

					glColor3f(.5, .5, .5);
					glRasterPos2f((k[i][0]+k[j][0])/2, (k[i][1]+k[j][1])/2);
					for (int jk = 0; jk<2; jk++)
					{

						glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c1[jk]);
					}


				}
			}
		}
	}
		   //glutSwapBuffers();
		   glFlush();
		   break;

	case 3:
		int count, min, u, v, h, g;
		for (i = 0; i<n; i++)s[i] = i;
		count = 0;
		sum = 0;

		while (count<n-1)
		{
			min = 999;
			for (i = 0; i<n; i++)
			{
				for (j = 0; j<n; j++)
				{
					if ((c[i][j]!=0)&&(c[i][j]<min))
					{
						min = c[i][j];
						u = i, v = j;
					}
				}
			}

			if (min==999)break;
			i = find(u);
			j = find(v);
			if (i!=j)
			{
				w[m][0] = u;
				w[m][1] = v;
				m++;

				count++;
				sum += min;
				s[v] = u;
			}
			c[u][v] = c[v][u] = 999;
		}//while
		if (count!=n-1)
		{


			glColor3f(.65, .98, .21);
			char c3[] = "SPANNING TREE DOES NOT EXIST!!!";
			glRasterPos2f(50, 450);
			for (int fd = 0; c3[fd]!='\0'; fd++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c3[fd]);

			glFlush();
			return;
		}

		for (m = 0; m<n-1; m++)
		{

			h = w[m][0];
			g = w[m][1];

			glColor3f(032, .78, .99);
			glBegin(GL_POINTS);
			glVertex2i(k[h][0]+30, k[h][1]+200);
			glVertex2i(k[g][0]+30, k[g][1]+200);
			glEnd();


			glColor3f(0.96, 0.5, 0.78);
			glBegin(GL_LINES);
			glVertex2i(k[h][0]+30, k[h][1]+200);
			glVertex2i(k[g][0]+30, k[g][1]+200);
			glEnd();
			//  glFlush();
			for (int vb = 0; vb<30000; vb++)
				for (int bv = 0; bv<30000; bv++);

			if (z[h][g]<=9)
			{
				int x = z[h][g];
				char c = '0'+x;
				glColor3f(.5, .5, .5);
				glRasterPos2f(((k[h][0]+k[g][0])/2)+30, ((k[h][1]+k[g][1])/2)+200);
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
				glFlush();
			}

			else
			{
				kl = z[h][g]/10;
				lk = z[h][g]%10;
				c2[0] = '0'+kl;
				c2[1] = '0'+lk;
				glColor3f(.5, .5, .5);
				glRasterPos2f(((k[h][0]+k[g][0])/2)+30, ((k[h][1]+k[g][1])/2)+200);

				for (int nm = 0; nm<2; nm++)
				{
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c2[nm]);
				}
				glFlush();
			}
		}

		// glFlush();
		break;

	case 4:printf("\n");
		printf("COST OF SPANNING TREE=%d\n", sum);
		glColor3f(.5, .5, .5);

		glRasterPos2f(50, 60);
		if (sum>99)
		{
			pq = sum%10;
			qp = sum/10;
			qu = qp%10;
			qn = qp/10;
			c3[23] = '0'+qn;
			c3[24] = '0'+qu;
			c3[25] = '0'+pq;
		}
		else
		{
			jr = sum/10;
			rj = sum%10;
			c3[23] = '0'+jr;
			c3[24] = '0'+rj;
		}
		for (int fd = 0; c3[fd]!='\0'; fd++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c3[fd]);
		glFlush();
		break;

	case 5:exit(0);
	}
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(900, 200);

	glutCreateWindow("KRUSKAL_SHORTEST_SPANNING_TREE");


	glutDisplayFunc(display);
	init();
	printf(" KRUSKAL SPANNING TREE\n\n");



	glutMouseFunc(mouse);
	glutCreateMenu(top_menu);

	glutAddMenuEntry("enter_cost_matrix", 0);
	glutAddMenuEntry("display_graph_with_edges", 1);
	glutAddMenuEntry("display_weighted_graph", 2);
	glutAddMenuEntry("spanning_tree", 3);
	glutAddMenuEntry("cost_of_spanning_tree", 4);
	glutAddMenuEntry("exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
}