
//https://www.hackerrank.com/contests/codeomania/challenges/street-walk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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

int paths = 0;
char maze[1001][1001];
int n;

void go(int y, int x){
	if (x == n - 1 && y == n - 1){
		paths = (paths + 1) % MOD;
		return;
	}
	if (x + 1 < n && maze[y][x + 1] != 'x')
		go(y, x + 1);
	if (y + 1 < n && maze[y + 1][x] != 'x')
		go(y + 1, x);

}

int main(){

	int t;
	char x;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%c", &n, &x, &x);
		REP(i, n)
			gets(maze[i]);
		paths = 0;
		go(0, 0);
		if (!paths)
			paths = -1;
		printf("%d\n", paths);
	}
	return 0;
}

//Partially Solved 40/100