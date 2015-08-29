/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/pacman-astar

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
#define MS0(a) memset(a,0,sizeof(a))
#define MSX(a,x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
	point() {
		x = 0;
		y = 0;
	}
	point(int px, int py) {
		x = px;
		y = py;
	}
	bool operator <(const point& rhs) const {
		return (x < rhs.x)||(x == rhs.x && y < rhs.y);
	}
	bool operator==(const point& rhs) const {
		return (x==rhs.x && y==rhs.y);
	}
};

struct cost {
	int g, h;
	int f;
	cost() {
		g = 0;
		h = 0;
		f = 0;
	}
	cost(int gc, int hc) {
		g = gc;
		h = hc;
		f = g + h;
	}
	bool operator <(const cost& rhs) const {
		return (f < rhs.f)||(f == rhs.f && h < rhs.h);
	}
};

int w, h;
point pac, food;

point dir[] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };
vector<point> path;
map<point, point> parent;

char board[101][101];

int dist(point p1, point p2) {
	return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

point leastCostPoint(map<point, cost> hash) {

	cost least = hash.begin()->second;
	point p = hash.begin()->first;

	for (auto i = hash.begin(); i!=hash.end(); i++) {
		if ((i->second)<least) {
			least = i->second;
			p = i->first;
		}
	}
	return p;
}

void AStar() {

	set<point> closed;
	map<point, cost> open;

	open[pac] = cost( dist(pac, pac), dist(pac, food) );
	parent[pac] = { -1,-1 };

	while (1) {

		point p = leastCostPoint(open);
		open.erase(p);
		closed.insert(p);

		if (p==food) 
			break;

		REP(i, 4) {
			int x = p.x + dir[i].x, y = p.y + dir[i].y;
			if (x>=0 && x<w && y>=0 && y<h && (board[y][x]=='-' || board[y][x]=='.')) {
				point neighbour = { x, y };
				if (closed.count(neighbour))
					continue;
				parent[neighbour] = p;
				open[neighbour] = cost(dist(neighbour, pac), dist(neighbour, food));
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

	AStar();
	printf("%d\n", path.size()-1);
	REV(path, path.size());
	REP(i, path.size())
		printf("%d %d\n", path[i].y, path[i].x);

	sp;
	return 0;
}

//