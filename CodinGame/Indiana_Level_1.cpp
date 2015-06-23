/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1507178caf6b6046732065f946227731619dbd6

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
struct point{
	int x, y;
};

int w, h;
int grid[20][20],v[20][20];


int canGoLeft(int x, int y, char dir){

	x--;
	if (x < 0 || v[y][x])
		return 0;

	x++;
	if (grid[y][x] ==  3 || grid[y][x] ==  5 ||
		grid[y][x] ==  7 || grid[y][x] ==  8 ||
		grid[y][x] ==  9 || grid[y][x] == 11 ||
		grid[y][x] == 12 || grid[y][x] == 13 ||
		(grid[y][x] == 4 && dir == 'R'))
		return 0;

	x--;
	if (grid[y][x] ==  1 || grid[y][x] == 2 || grid[y][x] == 4 ||
		grid[y][x] ==  6 || grid[y][x] == 7 || grid[y][x] == 8 ||
		grid[y][x] == 12)
		return 1;
	else
		return 0;

}

int canGoRight(int x, int y, char dir){

	x++;
	if (x >= w || v[y][x])
		return 0;

	x--;
	if (grid[y][x] ==  3 || grid[y][x] ==  4 ||
		grid[y][x] ==  7 || grid[y][x] ==  8 ||
		grid[y][x] ==  9 || grid[y][x] == 10 ||
		grid[y][x] == 12 || grid[y][x] == 13 ||
		(grid[y][x] == 5 && dir == 'L'))
		return 0;

	x++;
	if (grid[y][x] ==  1 || grid[y][x] == 2 || grid[y][x] == 5 ||
		grid[y][x] ==  6 || grid[y][x] == 9 || grid[y][x] == 8 ||
		grid[y][x] == 13)
		return 1;
	else
		return 0;

}

int canGoDown(int x, int y,char dir){

	y++;
	if (y >= h || v[y][x])
		return 0;

	y--;
	if (grid[y][x] ==  2 || grid[y][x] ==  6 ||
		grid[y][x] == 10 || grid[y][x] == 11 ||
		(grid[y][x] == 4 && dir == 'T') ||
		(grid[y][x] == 5 && dir == 'T'))
		return 0;

	y++;
	if (grid[y][x] == 1 || grid[y][x] ==  3 || grid[y][x] ==  4 || 
		grid[y][x] == 5 || grid[y][x] ==  5 || grid[y][x] ==  7 || 
		grid[y][x] == 9 || grid[y][x] == 10 || grid[y][x] == 11)
		return 1;
	else
		return 0;

}

int main(){

	int ex,x,y;
	char dir[10];
	scanf("%d%d", &w, &h);
	DB("%d ", w);
	DB("%d\n", h);
	REP(i, h){
		REP(j, w){
			scanf("%d", &grid[i][j]);
			DB("%2d ", grid[i][j]);
		}
		DB("\n", 0);
	}
	scanf("%d", &ex);

	while (1){
		scanf("%d %d %s", &x, &y,dir);
		v[y][x] = 1;
		if (canGoDown(x,y,dir[0]))
			printf("%d %d\n", x, y + 1);
		else if (canGoLeft(x, y, dir[0]))
			printf("%d %d\n", x - 1, y);
		else if (canGoRight(x, y, dir[0]))
			printf("%d %d\n", x + 1, y);
		else{
			DB("Cur X = %d\n", x);
			DB("Cur Y = %d\n", y);
			DB("Visit Left = %d\n", v[y][x - 1]);
			DB("Visit Rigt = %d\n", v[y][x + 1]);
			DB("Visit Down = %d\n", v[y + 1][x]);
			printf("WTF\n");
		}
	}
	return 0;
}

//