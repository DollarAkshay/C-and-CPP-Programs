/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/INLO2015/problems/LAZY01

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

int c[14][14],k,n,start;
int v[14],dist,ans=0;


void findCycle(int s,int lev){

	if (lev == n){
		dist += c[s][start];
		if (dist == k)
			ans = 1;
		return;
	}


	v[s] = 1;
	REP(i, n){
		if (ans==0 && c[s][i] != 0 && v[i] == 0){
			v[i] = 1;
			dist += c[s][i];
			findCycle(i, lev + 1);
			if (ans) return;
			v[i] = 0;
			dist -= c[s][i];
		}
	}
	

}


int main(){

	scanf("%d%d", &n,&k);
	REP(i, n)
		REP(j, n)
			scanf("%d", &c[i][j]);
	for (start = 0;!ans && start < n;start++)
		findCycle(start, 1);

	puts(ans ? "POSSIBLE" : "IMPOSSIBLE");
	return 0;
}

//