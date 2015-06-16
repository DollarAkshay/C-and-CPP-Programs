/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_90-2/algorithm/climbing-stairs-10/

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

ll dp[10001];

ll int climb(int n){

	if (dp[n])
		return dp[n];
	if (n == 1)
		dp[n] = 1;
	else if (n == 2)
		dp[n] = 2;
	else
		dp[n] = climb(n - 1) + climb(n - 2);

	return dp[n];


}


int main(){

	dp[0] = 1;
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		assert(n >= 1 && n <= 1000);
		printf("%lld\n", climb(n));
	}
	return 0;
}

//Solved