/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/14917193d66f9c6f8f5bf1ff5335d40885153f2

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
#include <map>
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
	point(){}
	point(int px, int py){
		x = px;
		y = py;
	}
	bool operator <(const point &n)const{
		return (x < n.x) || (x == n.x && y < n.y);
	}
	
	bool operator ==(point &n){
		return x == n.x && y == n.y;
	}
	bool operator !=(const point &n)const{
		return x != n.x || y != n.y;
	}
};

bool runMthaFucka = false;
char grid[100][200];
int v[100][200];
int w, h, n;
point pos,start(-1,-1),ctrl(-1,-1);
point dir[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
map<point, point> m;

int distanceTo(point s,point e){

	queue<point> q;

	MS0(v);
	q.push(s);
	v[s.y][s.x] = 1;

	while (!q.empty()){
		point u = q.front();
		q.pop();
		REP(i, 4){
			int dx = dir[i].x, dy = dir[i].y;
			if (u.y + dy >= 0 && u.x + dx >= 0 && v[u.y + dy][u.x + dx] == 0 && grid[u.y + dy][u.x + dx] != '#'&&
				grid[u.y + dy][u.x + dx] != '?'){
				point temp = point(u.x + dx, u.y + dy);
				q.push(temp);
				v[u.y + dy][u.x + dx] = v[u.y][u.x] + 1;
				if (temp == e)
					return v[u.y + dy][u.x + dx] - 1;
			}
		}
	}

	return -1;
}

point bfs(point s, char c){

	queue<point> q;

	MS0(v);
	m.clear();
	q.push(s);
	v[s.y][s.x] = 1;

	while (!q.empty()){
		point u = q.front();
		q.pop();
		REP(i, 4){
			int dx = dir[i].x, dy = dir[i].y;
			if (u.y+dy>=0 && u.x+dx>=0 && v[u.y + dy][u.x + dx] == 0 && grid[u.y + dy][u.x + dx] != '#'
				&& (c == '?' || grid[u.y + dy][u.x + dx]!='?')
				){
				point temp = point(u.x + dx, u.y + dy);
				q.push(temp);
				m[temp] = u;
				v[u.y + dy][u.x + dx] = v[u.y][u.x] + 1;
				if (grid[u.y + dy][u.x + dx] == c)
					return temp;
			}
		}
	}

	return point(-1, -1);
}

void pointToMove(point u){

	if (u.x > pos.x)
		puts("RIGHT");
	else if (u.x < pos.x)
		puts("LEFT");
	else if (u.y < pos.y)
		puts("UP");
	else
		puts("DOWN");

}


int main(){

	scanf("%d %d %d", &h, &w, &n);
	DB("%d ", h);
	DB("%d ", w);
	DB("%d\n", n);
	while (1){
		scanf("%d%d", &pos.y, &pos.x);
		if (start.x == -1){
			start.x = pos.x;
			start.y = pos.y;
		}
		REP(i, h){
			scanf("%s", grid[i]);
			//DB("%s\n", grid[i]);
			if (strchr(grid[i], 'C')){
				ctrl.y = i;
				ctrl.x = strchr(grid[i], 'C') - grid[i];
			}
		}
		point u;
		if (ctrl.x == -1 && ctrl.x == -1)
			u = bfs(pos, '?');
		else if (runMthaFucka || (pos.x == ctrl.x && pos.y == ctrl.y)){
			runMthaFucka = true;
			DB("Run MothaFuckar!! Run!!\n", 0);
			u = bfs(pos, 'T');
		}
		else{
			u = bfs(pos, 'C');

			if (u.x == -1 && u.y == -1)
				DB("No Path to Ctrl Room Yet !!\n", 0);

			DB("Distance from Start to U is %d\n", distanceTo(start, u));
			DB("U = %d,", u.x);
			DB("%d\n", u.y);

			if ((u.x == -1 && u.y == -1) || n<distanceTo(start, u)){
				u = bfs(pos, '?');
				DB("Keep on Exploring Boys \n", 0);
			}
		}
		
		while (m[u] != pos){
			u = m[u];
		}
		pointToMove(u);
	}


	return 0;
}

//