/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/592/problem/0

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



int main(){

	char board[8][9];
	int w[8], b[8];


	REP(i, 8) {
		scanf("%s", board[i]);
		w[i] = b[i] = -1;
	}

	REP(i, 8) {
		REP(j, 8) {
			if (board[j][i]=='W' && w[i]==-1)
				w[i] = j;
			if (board[7-j][i]=='B' && b[i]==-1)
				b[i] = j;
		}
	}

	int minA = 100, minB = 100;
	REP(i, 8) {
		if (w[i]!=-1 && b[i]==-1)
			minA = w[i];
		else if (w[i]==-1 && b[i]!=-1)
			minB = b[i];
	}
	puts(minA<=minB?"A":"B");
	return 0;
}

//Solved Pretests 