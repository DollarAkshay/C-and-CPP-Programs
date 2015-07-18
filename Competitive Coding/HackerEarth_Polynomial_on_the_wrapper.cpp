/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/CodeTreat1/algorithm/polynomial-on-the-wrapper-1/

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

int a, b, c;

ll int val(ll int x){
	return (ll int)a*x*x + b*x - c;
}

int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d", &a, &b, &c);
		int lo = 0, hi = 20;
		int x;
		while (hi>=lo){
			int mid = (lo+hi)/2;
			if (val(mid)>=0){
				x = mid;
				hi = mid-1;
			}
			else
				lo = mid+1;
		}
		unsigned ll int f = 1;
		FOR(i, 2, x)
			f *= i;
		printf("%llu\n", f);
	}
	return 0;
}

//Solved