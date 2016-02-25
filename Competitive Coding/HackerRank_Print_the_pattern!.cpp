/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/long-contest-2/challenges/print-the-pattern/submissions/code/5311035

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


int main() {

	int t;
	scanf("%d", &t);
	REP(tc, t) {
		int r, c, s;
		scanf("%d%d%d", &r, &c, &s);
		REP(k, r) {
			FOR(i, 1, s) {
				REP(g, c) {
					FOR(j, 1, s-i)
						printf(".");

					printf("/");

					FOR(j, 1, (i-1)*2)
						printf("*");

					printf("\\");

					FOR(j, 1, s-i)
						printf(".");
				}
				printf("\n");
			}
			FORD(i, s, 1) {
				REP(g, c) {
					FOR(j, 1, s-i)
						printf(".");

					printf("\\");

					FOR(j, 1, (i-1)*2)
						printf("*");

					printf("/");

					FOR(j, 1, s-i)
						printf(".");
				}
				printf("\n");
			}
		}
		printf("\n");
	}

	sp;
}

//Solved