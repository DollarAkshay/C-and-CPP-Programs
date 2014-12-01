/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/december-easy-challenge-1/algorithm/aniruddha-and-hackerearth/

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

ll int fib[1000010], sum[1000010];

void pre(){

	fib[0] = fib[1] = 1;
	sum[0] = 0;
	sum[1] = 0;
	FOR(i, 2, 1000009){
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
		sum[i] = (sum[i - 1] + fib[i]) % MOD;
	}

}

int main(){

	pre();
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		printf("%lld\n", sum[n + 1]);
	}
	return 0;
}

//Solved