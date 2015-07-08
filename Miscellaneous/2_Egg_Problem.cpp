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
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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

int n = 10000;

int a[2][1000001];

int main(){

	FILE *fp = fopen("testcase.txt", "w");
	FOR(i, 1, n)
		a[0][i] = i;
	fprintf(fp, "+----------+----------+\n");
	fprintf(fp, "|  Floors  | Attempts |\n");
	fprintf(fp, "+----------+----------+\n");
	FOR(i, 1, n){
		int least = a[0][i];
		FOR(j, 1, i)
			least = min(least, 1 + max(a[0][j-1],a[1][i-j]));
		a[1][i] = least;
		fprintf(fp, "|  %5d   |   %4d   |\n", i, a[1][i]);
	}
	fprintf(fp, "+----------+----------+\n");
	sp;
	return 0;
}

//