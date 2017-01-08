
//http://www.hackerearth.com/problem/algorithm/number-of-chocolates/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int q, n, g1, g2, p1, p2;
	unsigned long long int ans;
	unsigned int choc[1000005], sum[1000005];
	scanf("%d%d", &n, &q);
	REP(i, n){
		scanf("%d", &choc[i]);
		if (i)
			sum[i] = sum[i - 1] + choc[i];
		else
			sum[i] = choc[i];
	}
	REP(j, q){
		scanf("%d%d%d%d", &g1, &p1, &g2, &p2);
		if (g1<p1){
			ans = sum[g2] - sum[g1] + choc[g1];
			g2++;
			p1 = g2>p1 ? g2 : p1;
			if (p2 >= p1)
				ans = ans + sum[p2] - sum[p1] + choc[p1];
		}
		else{
			ans = sum[p2] - sum[p1] + choc[p1];
			p2++;
			g1 = p2>g1 ? p2 : g1;
			if (g2 >= g1)
				ans = ans + sum[g2] - sum[g1] + choc[g1];
		}
		printf("%llu\n", ans);
	}
	return 0;
}

// Partially Solved : 45/100