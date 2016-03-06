/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/hourrank-6/challenges/bear-and-steady-gene

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

char s[500001];

int f[500001][4];
int cumf[500002][4];

int main(){

	int n;
	scanf("%d", &n);
	scanf("%s", s);

	REP(i, n) {
		if (s[i]=='A') 
			f[i][0]++;
		else if (s[i]=='C') 
			f[i][1]++;
		else if (s[i]=='G') 
			f[i][2]++;
		else if (s[i]=='T') 
			f[i][3]++;
	}

	REP(i, n) {
		cumf[i+1][0] = cumf[i][0] + f[i][0];
		cumf[i+1][1] = cumf[i][1] + f[i][1];
		cumf[i+1][2] = cumf[i][2] + f[i][2];
		cumf[i+1][3] = cumf[i][3] + f[i][3];
	}

	int res = n;
	
	FOR(i, 0, n-1) {
		FOR(j, i, n) {
			if (j-i< res &&
				cumf[n][0] - (cumf[j][0]-cumf[i][0])<=n/4 &&
				cumf[n][1] - (cumf[j][1]-cumf[i][1])<=n/4 &&
				cumf[n][2] - (cumf[j][2]-cumf[i][2])<=n/4 &&
				cumf[n][3] - (cumf[j][3]-cumf[i][3])<=n/4)
				res = min(res, j-i);
		}
	}

	printf("%d\n", res);
	sp;
	return 0;
}

//