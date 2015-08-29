/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/pacman-dfs

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
	bool operator <(const point& rhs) const {
		return (x < rhs.x)||(x == rhs.x && y < rhs.y);
	}
};


bool foundFood = false;
int w, h;
point pac, food;

vector<point> explored, path;
point dir[] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };

char board[31][31];
bool visit[31][31];

void DFS(point src) {

	stack<point> s;
	
	map<point, point> parent;

	s.push(src);
	visit[src.y][src.x] = true;
	parent[src] = { -1, -1 };

	while (!s.empty() && !foundFood) {
		point p = s.top();
		s.pop();
		explored.push_back({ p.x, p.y });
		if (board[p.y][p.x]=='.') {
			break;
			foundFood = true;
		}
		REP(i, 4) {
			int x = p.x + dir[i].x, y = p.y + dir[i].y;
			if (x>=0 && x<w && y>=0 && y<h && !visit[y][x] && (board[y][x]=='-' || board[y][x]=='.')) {
				s.push({ x, y });
				visit[y][x] = true;
				parent[{x, y}] = p;
			}
		}
	}
	
	point u = food, end = { -1, -1 };
	while (u.x != end.x && u.y != end.y) {
		path.push_back(u);
		u = parent[u];
	}

}

int main() {

	scanf("%d %d", &pac.y, &pac.x);
	scanf("%d %d", &food.y, &food.x);
	scanf("%d %d", &h, &w);
	REP(i, h) {
		getchar();
		scanf("%s", board[i]);
	}
	DFS(pac);

	int v = 0;
	REP(i, 30)
		REP(j, 30)
		v += visit[i][j];

	printf("%d\n", explored.size());
	REP(i, explored.size())
		printf("%d %d\n", explored[i].y, explored[i].x);

	printf("%d\n", path.size()-1);
	REV(path, path.size());
	REP(i, path.size())
		printf("%d %d\n", path[i].y, path[i].x);
	sp;
	return 0;
}

//Solved --- Fucking Crazy Confusing Problem 