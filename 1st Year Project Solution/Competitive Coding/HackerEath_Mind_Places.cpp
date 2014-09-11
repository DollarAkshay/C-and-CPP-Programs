#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)
#define ll long long

int mind[1000][1000];

void saddleSearch(int x, int n, int m){
	int i = n - 1, j = 0;
	while (i >= 0 && j<m){
		int cell = mind[i][j];
		if (cell == x){
			printf("%d %d\n", i, j);
			return;
		}
		cell>x ? i-- : j++;
	}
	printf("-1 -1\n");
}

int main(){
	int n, m, q, x;
	scanf("%d%d", &n, &m);
	REP(i, n){
		REP(j, m){
			scanf("%d", &mind[i][j]);
		}
	}
	scanf("%d", &q);
	REP(i, q){
		scanf("%d", &x);
		saddleSearch(x, n, m);
	}
	return 0;
}