/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codex-6-0/algorithm/dummy-4-1/

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int a[100][100];
ll int DP;
int v[100][100];
int n;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void DFS(int y,int x){
	v[y][x] = 1;
	DP++;
	REP(i, 4){
		if (y+dy[i]<n && x+dx[i]<n && a[y + dy[i]][x + dx[i]] == 0 && !v[y][x])
			DFS(y + dy[i], x + dx[i]);
	}

}


int main(){

	scanf("%d", &n);
	REP(i, n)
		REP(j, n)
		scanf("%d", &a[i][j]);

	DFS(0, 0);
	printf("%lld", DP);
	return 0;
}

//