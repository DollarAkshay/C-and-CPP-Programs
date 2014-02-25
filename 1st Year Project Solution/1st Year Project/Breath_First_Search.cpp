/*
This is a Program to illustrate Breath First Serch
UP
LEFT
RIGHT
DOWN
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

char board[1000][1000];
int  level[1000][1000];
int  queue[10000];
int in_queue = 0;
int cur_level = 1;
int r, c;

void printBoard(){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}
}

void printLevels(){
	printf("\n  \n");
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			printf("%2d ", level[i][j]);
		printf("\n");
	}
}

void checkAdjacent(int x, int y){

	if (((board[x - 1][y] == '-') || (board[x - 1][y] == '.')) && (level[x - 1][y] == 0)){
		queue[in_queue++] = (x - 1)*c + y;
		level[x - 1][y] = cur_level;
	}
	if (((board[x][y - 1] == '-') || (board[x][y - 1] == '.')) && (level[x][y - 1] == 0)){
		queue[in_queue++] = (x)*c + y-1;
		level[x][y - 1] = cur_level;
	}
	if (((board[x][y + 1] == '-') || (board[x][y + 1] == '.')) && (level[x][y + 1] == 0)){
		queue[in_queue++] = (x)*c + y+1;
		level[x][y + 1] = cur_level;
	}
	if (((board[x + 1][y] == '-') || (board[x + 1][y] == '.')) && (level[x + 1][y] == 0)){
		queue[in_queue++] = (x + 1)*c + y;
		level[x + 1][y] = cur_level;
	}
	

}

void queueUpdate(){
	int n = 0;
	while (n < in_queue){
		queue[n] = queue[n+1];
		n++;
	}
	in_queue--;

}


void main(){
	
	int px, py, fx, fy;
	scanf("%d%d%d%d%d%d", &px, &py, &fx, &fy, &r, &c);
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			scanf("%c", &board[i][j]);
			while (board[i][j]=='\n')
				scanf("%c", &board[i][j]);
		}
	}
	printf("\n");
	int count = 2;
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
	if (board[i][j] == '-')
		count++;
	printf("%d\n", count);
	printf("%d %d\n",px,py);

	level[px][py] = 99;
	
	checkAdjacent(px, py);
	cur_level++;
	queue[in_queue++] = -1;

	
	while (in_queue>0){

		checkAdjacent(queue[0] / c, queue[0] % c);
		printf("%d %d\n", queue[0] / c, queue[0] % c);
		queueUpdate();
		if (queue[0] == -1){
			int n = 0;
			while (n < in_queue){
				queue[n] = queue[n + 1];
				n++;
			}
			in_queue--;
			cur_level++;
			if (in_queue>0)
			queue[in_queue++] = -1;
		
	}
	}
	int tx=fx, ty=fy;
	level[px][py] = 0;
	int food = level[fx][fy];
	printf("%d\n",food);
	int path[33];
	path[food] = tx*c + ty;
	while (food >= 0){
		if (level[tx-1][ty] == food - 1){
			path[food-1] = (tx-1)*c + ty;
			tx--;
			food--;
		}
		else if (level[tx][ty-1] == food - 1){
			path[food - 1] = tx*c + ty-1;
			food--;
			ty--;
		}
		else if (level[tx+1][ty] == food - 1){
			path[food - 1] = (tx+1)*c +ty;
			food--;
			tx++;
		}
		else {
			path[food - 1] = tx*c + ty+1;
			food--;
			ty++;
		}
	 

	}
	
	int fuck_this = 0;
	while (fuck_this <= 32){
		printf("%d %d\n", path[fuck_this] / c, path[fuck_this] % c);
		fuck_this++;
	}


	

	_getch();

}

/*

%%%%%%%%%%%%%%%%%%%%
%~~~~%~~~~~~~~%~~~~%
%~%%~%~%%~~%%~%.%%~%
%~%~~~~~%~~%~~~~~%~%
%~%~%%~%%~~%%~%%~%~%
%~~~~~~~~~~~%~%~~~~%
%~%~~~~%%%%%%~%~~%~%
%~%~~~~%~~~~%~%~~%~%
%~%~~~~%~%%%%~%~~%~%
%~%~~~~~~~~~~~%~~%~%
%~%%~%~%%%%%%~%~%%~%
%~~~~%~~~P~~~~%~~~~%
%%%%%%%%%%%%%%%%%%%%

98























11 9
11 8
11 10
11 7
11 11
11 6
11 12
10 6
11 13
9 6
10 13
8 6
9 5
9 7
9 13
7 6
8 5
9 4
9 8
8 13
9 12
6 6
7 5
8 4
9 3
10 4
8 8
9 9
7 13
9 11
5 6
6 5
7 4
8 3
11 4
7 8
9 10
6 13
4 6
5 5
5 7
6 4
7 3
11 3
7 9
5 13
3 6
5 4
5 8
6 3
11 2
7 10
4 13
2 6
3 5
3 7
5 3
5 9
11 1
7 11
3 13
1 6
3 4
4 3
5 2
4 9
5 10
10 1
2 13
3 12
3 14
1 7
2 4
3 3
5 1
3 9
4 10
5 11
9 1
1 13
3 15
1 8
1 4
4 1
6 1
2 9
3 10
8 1
1 12
2 15
3 16
1 9
1 3
3 1
7 1
2 10
1 11
1 15

*/
