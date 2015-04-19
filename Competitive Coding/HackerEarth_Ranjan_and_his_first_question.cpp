/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/lets-see-how-fast-you-can-code/algorithm/ranjan-and-his-first-question/

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

int main(){

	ll int t, n, m;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &n, &m);
		ll int res;
		if (m <= n){
			res = m*(m - 1) / 2;
			res = res*(n / m);
			int lim = n%m;
			res += lim*(lim + 1) / 2;
		}
		else{
			res = n*(n + 1) / 2;
		}
		printf("%lld\n", res);
	}
	return 0;
}

//Solved