/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//

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

int v[100][100];
int a[100][100];

void dfs(int y, int x){

	v[y][x] = 1;
	if (a[y][x + 1] == 1 && v[y][x + 1] == 0)
		dfs(y, x + 1);
	if (a[y + 1][x] == 1 && v[y + 1][x] == 0)
		dfs(y + 1, x);
}

int main(){

	int n;
	while (scanf("%d", &n)>0){
		REP(i, n)
			REP(j, n)
			scanf("%d", &a[i][j]);
		MS0(v);
		dfs(0, 0);
		puts(v[n - 1][n - 1] ? "POSSIBLE" : "NOT POSSIBLE");
	}
	return 0;
}

//Solved