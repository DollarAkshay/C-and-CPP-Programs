/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/epiccode/challenges/dance-in-pairs

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

int main(){

	int n,k;
	int b[100000], g[100000];
	scanf("%d%d", &n, &k);
	REP(i, n)
		scanf("%d", &b[i]);
	REP(i, n)
		scanf("%d", &g[i]);

	SORT(b, n);
	SORT(g, n);
	int p1 = 0;
	for (int i = 0, j = 0; i < n && j < n;){
		if (abs(b[i] - g[j]) <= k){
			p1++;
			i++;
			j++;
		}
		else if (g[j]-b[i] > k){
			i++;
		}
		else
			j++;
	}

	int p2 = 0;
	for (int i = 0, j = 0; i < n && j < n;){
		if ( abs(b[i] - g[j]) <= k){
			p2++;
			i++;
			j++;
		}
		else if (b[i] - g[j] > k){
			j++;
		}
		else
			i++;
	}

	int ans = max(p1, p2);
	printf("%d\n", ans);
	return 0;
}

//Solved