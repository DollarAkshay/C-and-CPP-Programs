/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codestellar-4/algorithm/higher-multiples-of-triangular-numbers/

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

int divz(ll int n){
	int c = 0, lim = sqrt(n);
	FOR(i, 1, lim){
		if (n%i==0){
			c++;
			if (n/i>lim)
				c++;
		}
	}
	return c;
}


int main(){

	ll int t, n, m;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		for (ll int i = 1, j = 1;; j++, i += j){
			if (divz(i)>n){
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
}

//Solved