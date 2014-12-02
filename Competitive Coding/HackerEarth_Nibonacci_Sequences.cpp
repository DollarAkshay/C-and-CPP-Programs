/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/aadhaar-hackathon-screening-test/problems/

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

ll int ans[1000005];

void pre(){

	ll int pow = 1, i = 0;
	while (i < 1000005){
		ans[i] = pow - 1;
		pow = pow * 2 % MOD;
		i++;
	}

}

int main(){

	pre();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
	return 0;
}

//Solved