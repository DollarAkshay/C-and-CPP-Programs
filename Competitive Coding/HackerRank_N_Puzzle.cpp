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

	int size, score;
	point empty;
	int grid[5][5];

	board() {

	}
	bool operator!=(const board& rhs) const {
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j]!=rhs.grid[i][j])
					return true;
			}
		}
		return false;
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

		if (score != rhs.score)
			return score<rhs.score;
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j] != rhs.grid[i][j])
					return grid[i][j] < rhs.grid[i][j];
			}
		}
		return false;
	}

	bool operator>(const board& rhs) const {

		if (score != rhs.score)
			return score>rhs.score;
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j] != rhs.grid[i][j])
					return grid[i][j] > rhs.grid[i][j];
			}
		}
		return false;
	}

	void recalculate(int inScore) {
		score = inScore;
		REP(i, size) {
			REP(j, size) {
				if (grid[i][j]!=0) {
					int x = grid[i][j];
					score += abs(j-x%size) + abs(i-x/size);
				}
			}
		}
	}
};

point dir[] = { { 0,-1 },{ -1,0 },{ 1,0 },{ 0,1 } };
map<board, pair<board, int>> parent;

vector<board> path;

priority_queue<pair<board, int>, vector<pair<board, int>>, greater<pair<board, int>>> open;
set<board> closed;


void swap(board *b, point p) {

	int t = b->grid[p.y][p.x];
	b->grid[p.y][p.x] = b->grid[b->empty.y][b->empty.x];
	b->grid[b->empty.y][b->empty.x] = t;
	b->empty = p;
}

void printBoard(board b) {
	REP(i, b.size) {
		REP(j, b.size)
			printf("%d ", b.grid[i][j]);
		printf("\n");
	}
	printf("\n");
}

void AStar(board &original) {

	bool found = false;
	board ans;

	open.push(mp(original, 0));
	closed.insert(original);

	while (!open.empty() && !found) {

		int m = open.top().second;
		board b = open.top().first;
		board bcopy = b;
		open.pop();
		point empty = b.empty;
		REP(i, 4) {
			int px = b.empty.x + dir[i].x, py = b.empty.y + dir[i].y;
			if (px>=0 && px<b.size && py>=0 && py<b.size) {
				swap(&b, point(px, py));
				b.recalculate(m);
				if (closed.find(b)==closed.end()) {
					open.push(mp(b,m+1));
					closed.insert(b);
					parent[b] = mp(bcopy, i);
					if (b.score==m) {
						found = true;
						ans = b;
						break;
					}
				}
				swap(&b, empty);
				b.recalculate(m);
			}
		}
	}

	deque<int> q;
	while (parent.find(ans)!=parent.end()) {
		pair<board, int> pbi = parent[ans];
		q.push_back(pbi.second);
		ans = pbi.first;
	}

	printf("%d\n", q.size());

	while (!q.empty()) {
		int d = q.back();
		q.pop_back();
		if (d==0)
			puts("UP");
		else if (d==1)
			puts("LEFT");
		else if (d==2)
			puts("RIGHT");
		else
			puts("DOWN");
	}
}

int main() {

	int n;
	board original;

	scanf("%d", &n);
	original.size = n;
	REP(i, n) {
		REP(j, n) {
			scanf("%d", &original.grid[i][j]);
			if (original.grid[i][j]==0)
				original.empty = point(j, i);
		}
	}
	original.recalculate(0);
	AStar(original);

	sp;

	return 0;
}

//Solved