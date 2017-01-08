
// Data Structures in C - Horowitz
//Page no. 120
//Added a little twist, instead od 8 possible directions I have restricted it to only 4 N,E,S & W

#include <stdio.h>

struct cell {
	int row;
	int col;
	int dir;
};

struct offset {
	int vert;
	int hori;
};

struct cell stack[1000];
int top = -1;
struct offset move[4];

int maze[100][100];
int mark[100][100];
int r, c;

struct cell pop(){
	
	if (top >= 0)
		return stack[top--];
}

void push(struct cell x){

	stack[++top] = x;

}

void path(int exit_row,int exit_col){

	int row, col, nextrow, nextcol, dir, found = 0;
	struct cell position;
	
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;
	top = 0;
	mark[1][1] = 1;

	while (top > -1 && !found){
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		int pushed = 0;
		while (dir < 4 && !found){
			nextrow = row + move[dir].vert;
			nextcol = col + move[dir].hori;
			if (nextrow == exit_row && nextcol == exit_col)
				found = 1;
			else if (maze[nextrow][nextcol] && mark[nextrow][nextcol] == 0){
				if (!pushed){
					position.dir = ++dir;
					push(position);
					pushed = 1;
				}
				position.row = nextrow;
				position.col = nextcol;
				position.dir = 0;
				push(position);
				mark[nextrow][nextcol] = 1;
				row = nextrow;
				col = nextcol;
				dir = 0;
			}
			else
				dir++;
		}
	}

	if (found){
		printf("The path is :\n");
		printf("Row Col\n");
		for (int i = 0; i <= top; i++)
			printf("%3d %3d\n", stack[i].row, stack[i].col);
		printf("%3d %3d\n", row, col);
		printf("%3d %3d\n", exit_row, exit_col);
	}
	else
		printf("The maze dosent have a path\n");

}

void initmoves(){
	// Up
	move[0].vert = -1;
	move[0].hori =  0;
	// Right
	move[1].vert = 0;
	move[1].hori = 1;
	// Down
	move[2].vert = 1;
	move[2].hori = 0;
	// Left
	move[3].vert = 0;
	move[3].hori = -1;
}


void main(){

	initmoves();
	int n, m,i,j;
	printf("Enter the row and columns for the maze : ");
	scanf("%d%d", &r, &c);
	printf("   ");
	for (i = 0; i < c; i++)
		printf("%2d", i);
	printf("\n");
	for (i = 0; i < r; i++){
		printf("%2d  ", i);
		for (j = 0; j < c; j++)
			scanf("%d", &maze[i][j]);
	}
	printf("\nEnter point is defaulted to 1,1\n");
	printf("\nEnter the exit point : ");
	scanf("%d%d", &n, &m);
	path(n, m);
	system("pause");



}



