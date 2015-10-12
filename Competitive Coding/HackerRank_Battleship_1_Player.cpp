/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/battleship1p

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
#define MSX(a,x) memset(a,x,sizeof(a))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
};

struct GameState {
	int size;
	int ships[6];
	char grid[10][10];
	
	GameState() {
		size = 10;
		ships[0] = 0;ships[1] = 2;ships[2] = 2;
		ships[3] = 1;ships[4] = 1;ships[5] = 1;
		MSX(grid, '-');
	}

};

bool undestroyedShip = false;
GameState original;

int probability[10][10];

point findMaxProbabilityPoint() {

	int value = probability[0][0];
	point p = { 0,0 };
	REP(i, original.size) {
		REP(j, original.size) {
			if (probability[i][j]>value) {
				value = probability[i][j];
				p = { j, i };
			}
		}
	}
	return p;

}

void updateDestroyedShips() {
	GameState copy = original;
	REP(i, copy.size) {
		REP(j, copy.size) {
			if (copy.grid[i][j]=='d') {
				int shipSize = 1;
				while()
			}
		}
	}
}

void pre() {
	if (datain) {
		fscanf(datain, "%d", &original.size);
		REP(i, 6)
			fscanf(datain, "%d", &original.ships[i]);
	}
}

int main(){
	
	pre();
	scanf("%d", &original.size);
	REP(i, original.size) {
		getchar();
		REP(j, original.size) {
			scanf("%c", original.grid[i][j]);
			if (original.grid[i][j] == 'h')
				undestroyedShip = true;
		}
	}

	updateDestroyedShips();

	


	if (undestroyedShip) {

	}
	else {
		generateProbabilityDensity();
		point p = findMaxProbabilityPoint();
		printf("%d %d", p.y, p.x);
	}


}

//