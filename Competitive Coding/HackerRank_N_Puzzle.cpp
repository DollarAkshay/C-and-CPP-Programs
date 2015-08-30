/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/n-puzzle

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
	point() {
		x = -1;
		y = -1;
	}
	point(int px, int py) {
		x = px;
		y = py;
	}
};

struct board {
	int size;
	point empty;
	int grid[5][5];
	board() {

	}
	bool operator==(const board& rhs) const {
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j]!=rhs.grid[i][j])
					return false;
			}
		}
		return true;
	}
	bool operator<(const board& rhs) const {
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j]!=rhs.grid[i][j])
					return grid[i][j] < rhs.grid[i][j];
			}
		}
		return false;
	}
};

board ans;

point dir[] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };
map<board, board> parent;

vector<board> path;


void swap(board *b, point p1, point p2){

	int t = b->grid[p1.y][p1.x];
	b->grid[p1.y][p1.x] = b->grid[p2.y][p2.x];
	b->grid[p2.y][p2.x] = t;
}

void BFS(board src, int n) {

	queue<board> q;
	set<board> visit;

	q.push(src);
	visit.insert(src);

	while (!q.empty()) {
		board cur = q.front();
		q.pop();
		if (cur==ans)
			break;
		REP(i, 4) {
			point p = point(cur.empty.x+dir[i].x, cur.empty.y+dir[i].y);
			if (p.x>=0 && p.x<n && p.y>=0 && p.y<n) {
				board next = cur;
				swap(&next, p, cur.empty);
				next.empty = p;
				if (visit.count(next)==0) {
					q.push(next);
					parent[next] = cur;
				}

			}
		}
	}

	board u = ans;
	while (!(u==src)) {
		path.push_back(u);
		u = parent[u];
	}
	path.push_back(u);
	REV(path, path.size());

}

void printBoard(board b) {
	REP(i, b.size) {
		REP(j, b.size) 
			printf("%d ", b.grid[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main(){

	int n;
	board original;
	scanf("%d", &n);
	ans.size = original.size = n;
	REP(i, original.size) {
		REP(j, original.size) {
			scanf("%d", &original.grid[i][j]);
			if (original.grid[i][j]==0)
				original.empty = point(j, i);
		}
	}

	int k = 0;
	REP(i, ans.size)
		REP(j, ans.size)
			ans.grid[i][j] = k++;
	ans.empty = point(0, 0);

	BFS(original, n);

	REP(i, path.size()) {
		printBoard(path[i]);
	}

	sp;

	return 0;
}

//