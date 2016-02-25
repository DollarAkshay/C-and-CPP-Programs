/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/axiatech-codemaster/challenges/print-pattern

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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[100000];

int main() {

	int r, gg=0;

	char s[10000];
	
	scanf("%d\n%s", &r, s);
	int l = strlen(s);

	FOR(i, 0, r/2-1) {
		FOR(j, 0, r-1) {
			if (j==r/2-i || j==r/2+i)
				printf("%c", s[gg%l]);
			else if (j==r/2)
				printf("+");
			else
				printf(" ");
		}
		printf("\n");
		gg++;
	}

	if (r%2) {
		FOR(i, 1, r)
			printf("+");
		printf("\n");

	}


	FORD(i, r/2, 0) {
		FOR(j, 0, r-1) {
			if (j==r/2-i || j==r/2+i)
				printf("%c", s[gg%l]);
			else if (j==r/2)
				printf("+");
			else
				printf(" ");
		}
		printf("\n");
		gg++;
	}

	sp;

	return 0;
}

//Solved