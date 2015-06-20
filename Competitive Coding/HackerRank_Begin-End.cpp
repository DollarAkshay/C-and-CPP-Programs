/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/epiccode/challenges/begin-end

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

ll int f[256];

int main(){

	ll int n;
	char s[1000010];
	scanf("%lld", &n);
	getchar();
	scanf("%s", s);
	ll int len = strlen(s);
	ll int ans = len;
	REP(i, len)
		f[s[i]]++;
	REP(i, 256)
		ans += f[i] * (f[i] - 1) / 2;
	printf("%lld\n", ans);

	return 0;
}

//Solved