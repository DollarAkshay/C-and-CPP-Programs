/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codejunk/algorithm/showdown/

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


vector<int> a, b;

int ans = 0,n;

vector<int> g[100];
int deg[100];


bool comp(int l, int r){
	return l > r;
}


void BF(int l){

	if (l == n){
		int cur = 0;
		REP(i, n){
			if (a[i] > b[g[i][0]])
				cur += 100;
			else if (a[i] == b[g[i][0]])
				cur += 50;
		}
		ans = max(ans, cur);
	}
	else{
		REP(i,n){
			if (deg[i] == 0){
				g[l].push_back(i);
				deg[i] = 1;
				BF(l + 1);
				g[l].pop_back();
				deg[i] = 0;
			}
		}
	}

}

int main(){

	scanf("%d", &n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		a.pb(x);
	}
	REP(i, n){
		int x;
		scanf("%d", &x);
		b.pb(x);
	}
	sort(begin(a), end(a), comp);
	sort(begin(b), end(b), comp);
	BF(0);
	
	printf("%d", ans);
	return 0;
}

//