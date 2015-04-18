/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/april-clash-15/algorithm/aabbaac/

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

char s[50][101];
ll int t[50], ls[50];

char findx(ll int x, ll int rev, ll int n){

	assert(x >= 0);

	if (n <= 0){
		return rev == 1 ? s[0][ls[0] - 1 - x] : s[0][x];
	}

	if (rev == 0){
		if (x < t[n - 1])
			return findx(x, 0, n - 1);
		else if (x >= t[n - 1] && x < 2 * t[n - 1])
			return findx(x - t[n - 1], 1, n - 1);
		else
			return s[n][x - 2 * t[n - 1]];
	}
	else{
		if (x < ls[n])
			return s[n][ls[n] - x - 1];
		else if (x >= ls[n] && x < ls[n] + t[n - 1])
			return findx(x - ls[n], 0, n - 1);
		else
			return findx(x - (ls[n] + t[n - 1]), 1, n - 1);
	}

}

int main(){


	ll int n, g, m, x;
	scanf("%lld", &g);
	REP(tc, g){
		scanf("%lld%lld", &n, &m);
		REP(i, n){
			scanf("%s", s[i]);
			ls[i] = strlen(s[i]);
			t[i] = i ? 2 * t[i - 1] + ls[i] : ls[i];
		}
		REP(i, m){
			scanf("%lld", &x);
			printf("%c", findx(x, 0, n - 1));
		}
		printf("\n");

	}
	sp;
	return 0;
}

//Solved