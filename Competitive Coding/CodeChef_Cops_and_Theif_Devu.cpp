/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/COOK60/problems/COPS

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
#include <bitset>
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
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[101];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		MS0(a);
		int x, y, r;
		scanf("%d%d%d", &n, &x, &y);
		r = x*y;
		REP(i, n){
			int c;
			scanf("%d", &c);
			a[c] = 1;
			REP(j, r+1){
				if (c+j<=100)
					a[c+j] = 1;
				if (c-j>=0)
					a[c-j] = 1;
			}
		}
		int safe = 0;
		FOR(i, 1, 100)
			if (!a[i])
				safe++;
		printf("%d\n", safe);
	}
	sp;
	return 0;
}

//Solved