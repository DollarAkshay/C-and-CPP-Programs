/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codathon-1/algorithm/afraid-of-darkness-2/

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
#define gc getchar_unlocked
struct Edge{ int v, w; };

bool compare(ll int a, ll int b){
	return a>b;
}

int main(){

	ll int t, n;
	int a[25001];
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		ll int day = 0;
		MS0(a);
		REP(i, n){
			scanf("%d", &a[i]);
		}
		int flag = 1;
		while (flag && n){
			sort(begin(a), begin(a) + n, compare);
			REP(i, day + 1){
				if (--a[i]<0){
					flag = 0;
					break;
				}
			}
			if (flag)
				day++;
		}
		assert(day <= n);
		printf("%lld\n", day);
	}
	return 0;
}

//Partially Solved