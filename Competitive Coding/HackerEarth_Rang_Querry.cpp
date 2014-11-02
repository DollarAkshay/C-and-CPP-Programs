
//http://www.hackerearth.com/codexplod-v2/algorithm/range-query/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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

int dp[101][10000];



int main(){

	int q, n, x, y, v;
	int a[10000];
	scanf("%d", &n);
	REP(i, n){
		scanf("%d", &a[i]);
		if (i){
			FOR(j, 1, 100){
				if (j == a[i])
					dp[j][i] = dp[j][i - 1] + 1;
				else
					dp[j][i] = dp[j][i - 1];
			}
		}
		else
			dp[a[i]][i] = 1;
	}
	scanf("%d", &q);
	REP(i, q){
		scanf("%d%d%d", &x, &y, &v);
		int ans = dp[v][y] - dp[v][x];
		if (a[x] == v)
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}

//Solved
