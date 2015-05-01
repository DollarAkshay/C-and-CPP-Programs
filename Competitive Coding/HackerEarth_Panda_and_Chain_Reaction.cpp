/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-chain-reaction/

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
#define MOD 1000003
#define gc getchar_unlocked
struct Edge{ int v, w; };

int mul[100003];

void pre(){

	mul[1] = 1;
	FOR(i, 2, 100002)
		mul[i] = (i*(ll int)mul[i - 1]) % MOD;

}

int main(){

	pre();
	ll int t, n, x;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &n, &x);
		x = n<1000003 ? (x*mul[n]) % MOD : 0;
		printf("%lld\n", x);
	}
	return 0;
}

//Solved