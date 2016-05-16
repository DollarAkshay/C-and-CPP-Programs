/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/day-1-a-chessboard-game

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

int winner[15][15][2];

int solve(int x, int y, int player) {

	if (winner[y][x][player-1])
		return winner[y][x][player-1];

	if (x<0 || y<0) {
		return player;
	}
	else {

		int m1 = solve(x-2, y+1, player==1?2:1);
		int m2 = solve(x-2, y-1, player==1?2:1);
		int m3 = solve(x+1, y-2, player==1?2:1);
		int m4 = solve(x-1, y-2, player==1?2:1);

		if (m1==player || m2==player || m3==player || m4==player)
			winner[y][x][player-1] = player;
		else
			winner[y][x][player-1] = player==1?2:1;

		return winner[y][x][player-1];
	}


}

int main() {

	int t;
	scanf("%d", &t);
	REP(tc, t) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		puts(solve(x, y, 1)==1?"First":"Second");
	}
	sp;
	return 0;
}

//Solved