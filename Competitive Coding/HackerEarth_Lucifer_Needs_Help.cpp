/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/algoholic-practice/algorithm/lucifer-needs-help-2/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int a[1000000];

int main(){

	int n,m;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	REP(i, m){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		FOR(j, l, r)
			a[j] += k;
	}
	REP(i, n){
		printf("%d\n", a[i]);
	}

	
	return 0;
}

//Partially Solved ~ TLE