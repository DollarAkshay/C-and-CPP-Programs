/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/JAN16/problems/RGAME

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
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[100001], pow2[100001], sum[100001];

void preCalc() {

	pow2[0] = pow2[1] = 2;
	FOR(i, 2, 100000)
		pow2[i] = (pow2[i-1]*2LL) %MOD;

}

int main(){
	
	preCalc();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		MS0(sum);
		scanf("%d", &n);
		ll int res = 0;
		REP(i, n+1) {
			res *= 2;
			scanf("%d", &a[i]);
			int x = (ll int)pow2[i]*a[i]%MOD;
			sum[i] = i?(x+sum[i-1])%MOD:x;
			if (i)
				res = (res + (ll int)a[i]*sum[i-1]%MOD)%MOD;
		}
		printf("%lld\n", res);
	}
	sp;
	return 0;
}

//Solved