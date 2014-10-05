#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
#define SIZE 61

char maze[SIZE][SIZE+1];
int lastmove;
int x,y;

void saveMaze(FILE *file){

	if (lastmove == 1)
		y--;
	else if (lastmove == 2)
		x--;
	else if (lastmove == 3)
		x++;
	else if (lastmove == 4)
		y++;
	file = fopen("maze.txt", "w+" );
	fprintf(file, "%d %d %d\n", x,y,lastmove);
	REP(i, SIZE)
		fprintf(file, "%s\n", maze[i]);

}


void loadMaze(FILE *file){

	fscanf(file, "%d %d %d", &x, &y, &lastmove);
	REP(i,SIZE)
		fscanf(file, "%s", maze[i]);
	
}

int win(char see[3][4] ){
	if (see[0][1] == 'e' || ((see[0][0] == 'e' || see[0][2] == 'e') && see[0][1] != '#')){
		lastmove = 1;
		printf("UP\n");
		return 1;
	}
	else if (see[1][0] == 'e' || ((see[0][0] == 'e' || see[2][0] == 'e') && see[1][0] != '#') ){
		lastmove = 2;
		printf("LEFT\n");
		return 1;
	}
	else if (see[1][2] == 'e' || ((see[0][2] == 'e' || see[2][2] == 'e') && see[1][2] != '#') ){
		lastmove = 3;
		printf("RIGHT\n");
		return 1;
	}
	else if (see[2][1] == 'e' || ((see[2][0] == 'e' || see[2][2] == 'e') && see[2][1] != '#') ){
		lastmove = 4;
		printf("DOWN\n");
		return 1;
	}
	return 0;
}

int main(){

	int id;
	char see[3][4];
	FILE *file;

	//Initializing the maze
	file = fopen("maze.txt", "r");
	if (file)
		loadMaze(file);
	else{
		x = y = 30;
		lastmove = 0;
		REP(i,SIZE-1){
			REP(j, SIZE - 1)
				maze[i][j] = '0';
			maze[i][SIZE - 1] = '\0';
		}
	}

	//Reading Input
	scanf("%d", &id);
	REP(i, 3)
		scanf("%s",see[i]);

	//Normalizing
	if (lastmove == 0){
		char t = see[0][0];
		see[0][0] = see[2][0];
		see[2][0] = see[2][2];
		see[2][2] = see[0][2];
		see[0][2] = t;
		t = see[0][1];
		see[0][1] = see[1][0];
		see[1][0] = see[2][1];
		see[2][1] = see[1][2];
		see[1][2] = t;
	}
	else if (lastmove == 0){
		char t = see[0][0];
		see[0][0] = see[0][2];
		see[0][2] = see[2][2];
		see[2][2] = see[2][0];
		see[2][0] = t;
		t = see[1][0];
		see[1][0] = see[0][1];
		see[0][1] = see[1][2];
		see[1][2] = see[2][1];
		see[2][1] = t;
	}
	else if (lastmove == 0){
		char t = see[0][0];
		see[0][0] = see[2][0];
		see[2][0] = t;
		t = see[0][1];
		see[0][1] = see[2][1];
		see[2][1] = t;
		t = see[0][2];
		see[0][2] = see[2][2];
		see[2][2] = t;
	}

	//Checking if this part was previously visited
	if (maze[x][y] == '+'){
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			see[i + 1][j + 1] = maze[x + i][y + j] ;
	}
	else{
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (maze[x + i][y + j]!='+')
			maze[x + i][y + j] = see[i + 1][j + 1];
		maze[x][y] = '+';
	}
	
	if (!win(see)){
		if (see[0][1] == '-'){
			lastmove = 1;
			printf("UP\n");
		}
		else if (see[1][0] == '-'){
			lastmove = 2;
			printf("LEFT\n");
		}
		else if (see[1][2] == '-'){
			lastmove = 3;
			printf("RIGHT\n");
		}
		else if (see[2][1] == '-'){
			lastmove = 4;
			printf("DOWN\n");
		}
		else{
			lastmove = 0;
			printf("DOOMED");
		}
	}
	saveMaze(file);
	sp;
	return 0;
}