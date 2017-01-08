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

char maze[SIZE][SIZE+1],see[3][4];
int facing,thismove;
int x,y;

void saveMaze(FILE *file){

	file = fopen("maze.txt", "w+" );
	fprintf(file, "%d %d %d\n", x,y,facing);
	REP(i, SIZE)
		fprintf(file, "%s\n", maze[i]);

}

void loadMaze(FILE *file){

	fscanf(file, "%d %d %d", &x, &y, &facing);
	REP(i,SIZE)
		fscanf(file, "%s", maze[i]);
	
}

void printmove(){

	if (thismove == 0)
		y--;
	else if (thismove == 1)
		x++;
	else if (thismove == 2)
		y++;
	else if (thismove == 3)
		x--;
	
	thismove = (thismove - facing + 4)%4;

	if (thismove == 0){
		puts("UP");
	}
	else if (thismove == 1){
		puts("RIGHT");
		facing = (facing + 5) % 4;
	}
	else if (thismove == 2){
		facing = (facing + 6) % 4;
		puts("DOWN");
	}
	else if (thismove == 3){
		facing = (facing + 3) % 4;
		puts("LEFT");
	}
}

void normalize(){
	if (facing == 1){
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
	else if (facing == 3){
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
	else if (facing == 2){
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
		t = see[0][0];
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
}

int win(){
	if (see[0][1] == 'e' || ((see[0][0] == 'e' || see[0][2] == 'e') && see[0][1] != '#')){
		thismove = 0;
		return 1;
	}
	else if (see[1][2] == 'e' || ((see[0][2] == 'e' || see[2][2] == 'e') && see[1][2] != '#')){
		thismove = 1;
		return 1;
	}
	else if (see[2][1] == 'e' || ((see[2][0] == 'e' || see[2][2] == 'e') && see[2][1] != '#')){
		thismove = 2;
		return 1;
	}
	else if (see[1][0] == 'e' || ((see[0][0] == 'e' || see[2][0] == 'e') && see[1][0] != '#') ){
		thismove = 3;
		return 1;
	}
	return 0;
}

void findspot(){

}

int main(){

	int id;
	FILE *file;

	//Initializing the maze
	file = fopen("maze.txt", "r");
	if (file)
		loadMaze(file);
	else{
		x = y = 30;
		facing = 0;
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
	normalize();

	//Checking if this part was previously visited
	if (maze[y][x] == '+'){
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			see[i + 1][j + 1] = maze[y + i][x + j] ;
	}
	else{
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (maze[y + i][x + j]!='+')
				maze[y + i][x + j] = see[i + 1][j + 1];
			else 
				see[i + 1][j + 1] = maze[y + i][x + j];
		maze[y][x] = '+';
	}
	if (!win()){
		if (see[0][1] == '-'){
			thismove = 0;
		}
		else if (see[1][2] == '-'){
			thismove = 1;
		}
		else if (see[2][1] == '-'){
			thismove = 2;
		}
		else if (see[1][0] == '-'){
			thismove = 3;
		}
		else{
			thismove = -1;
		}
	}
	if (thismove != -1)
		printmove();
	else{
		findspot();
	}
	
	
	saveMaze(file);
	return 0;
}