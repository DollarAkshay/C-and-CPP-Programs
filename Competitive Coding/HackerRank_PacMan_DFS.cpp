
//https://www.hackerrank.com/challenges/pacman-dfs

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

struct point{
	int x, y;
};

point path[40 * 40];
point all[40 * 40];
stack<point> s;
char board[40][41];
int visit[40][40], e = 0;

void DFS(int px, int py, int fx, int fy, int r, int c){

	point p, i;
	p.x = px;
	p.y = py;
	visit[py][px] = 1;
	s.push(p); all[e++] = p;
	while (!s.empty()){
		i = s.top();
		s.pop();

		// Inserting Up Node
		if (visit[i.y - 1][i.x] == 0 && board[i.y - 1][i.x] != '%'){
			p.x = i.x;
			p.y = i.y - 1;
			visit[i.y - 1][i.x] = 1;
			s.push(p); all[e++] = p;
			if (p.x == fx && p.y == fy)
				return;
		}
		// Inserting Left Node
		if (visit[i.y][i.x - 1] == 0 && board[i.y][i.x - 1] != '%'){
			p.x = i.x - 1;
			p.y = i.y;
			visit[i.y][i.x - 1] = 1;
			s.push(p); all[e++] = p;
			if (p.x == fx && p.y == fy)
				return;
		}
		// Inserting Right Node
		if (visit[i.y][i.x + 1] == 0 && board[i.y][i.x + 1] != '%'){
			p.x = i.x + 1;
			p.y = i.y;
			visit[i.y][i.x + 1] = 1;
			s.push(p); all[e++] = p;
			if (p.x == fx && p.y == fy)
				return;
		}
		// Inserting Down Node
		if (visit[i.y + 1][i.x] == 0 && board[i.y + 1][i.x] != '%'){
			p.x = i.x;
			p.y = i.y + 1;
			visit[i.y + 1][i.x] = 1;
			s.push(p); all[e++] = p;
			if (p.x == fx && p.y == fy)
				return;
		}
	}
}

int main(){

	int px, py;
	int fx, fy;
	int r, c;
	scanf("%d%d%d%d%d%d", &py, &px, &fy, &fx, &r, &c);
	REP(i, r)
		scanf("%s", board[i]);
	DFS(px, py, fx, fy, r, c);

	printf("%d\n", e);
	REP(i, e)
		printf("%d %d\n", all[i].y, all[i].x);

	int size = s.size();
	printf("%d\n", size - 1);
	FORD(i, size - 1, 0){
		path[i] = s.top();
		s.pop();
	}
	REP(i, size)
		printf("%d %d\n", path[i].y, path[i].x);
	sp;
	return 0;
}

//Fail