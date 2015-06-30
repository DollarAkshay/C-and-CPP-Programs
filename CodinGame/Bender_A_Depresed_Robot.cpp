/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/150866016204b231dc9f68b2d06f0bd1e93c53c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

struct point {
	int x, y;
	point(){
		x = 0;
		y = 0;
	}
	point(int px, int py){
		x = px;
		y = py;
	}
};

struct state{
	int beer;
	int dir; 
	int inv;
	char board[101][101];
	state(){
		beer = -1;
		dir = -1;
	}
	state(int b, int d,char g[101][101],int i){
		beer = b;
		dir = d;
		inv = i;
		REP(i, 101)
			REP(j, 101)
			board[i][j] = g[i][j];
	}

	bool operator==(state &a){
		if (a.beer == beer && a.dir == dir && a.inv == inv){
			REP(i, 101){
				REP(j, 101){
					if (a.board[i][j] != board[i][j])
						return false;
				}
			}
			return true;
		}
		else
			return false;
	}

};


char grid[101][101];
char p[4][10] = { "SOUTH", "EAST", "NORTH", "WEST" };

int w, h;
int curDir = 0,hasBeer = 0;

vector<string> path;

point dir[4] = { point(0, 1), point(1, 0), point(0, -1), point(-1, 0) };
point pos, tp1, tp2;

vector<state> v[100][100];

bool checkForLoops(int x, int y){

	state current = state(hasBeer, curDir, grid, dir[0].x);

	int size = v[y][x].size();
	REP(i, size){
		if (v[y][x][i] == current)
			return true;
	}
	return false;

}

void update(int x,int y){

	if (grid[y][ x] == 'X'){
		grid[ y][x] = ' ';
		DB("Breaking Shit\n", 0);
	}
	else if (grid[y][x] == 'B'){
		hasBeer = !hasBeer;
		if (hasBeer)
			DB("Drunk Beer\n", 0);
		else
			DB("Sober Now\n", 0);
	}
	else if (grid[y][x] == 'I'){
		DB("Right about Turn\n", 0);
		curDir = 3 - curDir;
		REV(dir, 4);
		REV(p, 4);
	}
	else if (grid[y][x] == 'T'){
		if (x == tp1.x && y == tp1.y){
			pos.x = tp2.x;
			pos.y = tp2.y;
		}
		else{
			pos.x = tp1.x;
			pos.y = tp1.y;
		}
		DB("Teleporting to %d,", pos.x);
		DB("%d\n", pos.y);
	}
	else if (grid[y][x] == 'S'){
		curDir = 0;
	}
	else if (grid[y][x] == 'E'){
		curDir = 1;
	}
	else if (grid[y][x] == 'N'){
		curDir = 2;
	}
	else if (grid[y][x] == 'W'){
		curDir = 3;
	}

}

void getTPandEnd(){
	REP(i, h){
		REP(j, w){
			if (grid[i][j] == 'T'){
				if (tp1.x == 0 && tp1.y == 0){
					tp1.x = j;
					tp1.y = i;
				}
				else{
					tp2.x = j;
					tp2.y = i;
				}
			}
			else if (grid[i][j] == '@'){
				pos.x = j;
				pos.y = i;
			}
		}
	}
}

int main(){

	scanf("%d%d", &h, &w);
	getchar();
	REP(i, h){
		scanf("%[^\n]s", grid[i]);
		getchar();
	}

	getTPandEnd();
	

	bool hasloop = false;
	while (!hasloop){
		v[pos.y][pos.x].push_back(state( hasBeer , curDir , grid, dir[0].x));
		if ((grid[pos.y + dir[curDir].y][pos.x + dir[curDir].x] != '#') && 
			(grid[pos.y + dir[curDir].y][pos.x + dir[curDir].x] != 'X' || hasBeer)){
			pos.y += dir[curDir].y;
			pos.x += dir[curDir].x;
			path.push_back(p[curDir]);
			if (grid[pos.y][pos.x] == '$')
				break;
			else
				update(pos.x, pos.y);
			hasloop = checkForLoops(pos.x, pos.y);
		}
		else{
			REP(i, 4){
				if ((grid[pos.y + dir[i].y][pos.x + dir[i].x] != '#') &&
					(grid[pos.y + dir[i].y][pos.x + dir[i].x] != 'X' || hasBeer)){
					curDir = i;
					break;
				}
			}
		}
	}
	DB(" ~~~~ END OF DEBUGGING ~~~~ \n", 0);
	if (hasloop)
		printf("LOOP\n");
	else{
		int size = path.size();
		REP(i,size)
			printf("%s\n", path[i].c_str());
	}


	return 0;
}

//