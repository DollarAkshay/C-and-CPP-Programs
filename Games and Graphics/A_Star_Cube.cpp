/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

struct State {

	/*
	0 - Front 
	1 - Top
	2 - Bottom
	3 - Left
	4 - Right
	5 - Back
	*/
	char cube[6][3][3];

	State() {
		REP(k, 6) {
			REP(i, 3)
				REP(j, 3)
				cube[k][i][j] = k;
		}
	}


	void printCube(int type=0) {

		if (type==0) {
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[5][i][0], cube[5][i][1], cube[5][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[1][i][0], cube[1][i][1], cube[1][i][2]);
			REP(i, 3)
				printf("%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 
					   cube[3][i][0], cube[3][i][1], cube[3][i][2], 
					   cube[0][i][0], cube[0][i][1], cube[0][i][2], 
					   cube[4][i][0], cube[4][i][1], cube[4][i][2]);
			REP(i, 3)
				printf("      %2d%2d%2d      \n", cube[2][i][0], cube[2][i][1], cube[2][i][2]);
			printf("\n");

		}
		else if (type==1) {
			REP(i, 3) {
				REP(k, 6) {
					REP(j, 3)
						printf("%2d", cube[k][i][j]);
					printf(" ");
				}
				printf("\n");
			}
		}
	}

	void front_clock() {

		int t[3];
		REP(i, 3)
			t[i] = cube[1][2][i];

		REP(i, 3)
			cube[1][2][i] = cube[3][i][2];

		REP(i, 3)
			cube[3][i][2] = cube[2][0][i];

		REP(i, 3)
			cube[2][0][i] = cube[4][i][0];

		REP(i, 3)
			cube[4][i][0] = t[i];

	}

	/*
	0 - Front
	1 - Top
	2 - Bottom
	3 - Left
	4 - Right
	5 - Back
	*/
	

};

int main(){


	State s;

	s.printCube();
	s.front_clock();
	s.printCube();
	s.front_clock();
	s.printCube();
	s.front_clock();
	s.printCube();
	s.front_clock();
	s.printCube();

	getchar();
	sp;
	

	return 0;
}

//