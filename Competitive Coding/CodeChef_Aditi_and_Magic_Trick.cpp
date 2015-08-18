/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG15/problems/ADMAG

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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007


ll int fib[100];
ll int cum[100];

void pre(){

	fib[1] = fib[2] = 1;
	cum[1] = 1;
	cum[2] = 2;
	FOR(i, 3, 99){
		fib[i] = fib[i-1] + fib[i-2];
		cum[i] = cum[i-1] + fib[i];
		if (cum[i] > 1000000000000000000 || cum[i]<0 ){
			break;
		}
	}
	
}



int main(){

	pre();
	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld", &n);
		ll int ans;
		FOR(i, 1, 100){
			if (n>cum[i-1] && n<=cum[i]){
				ans = i;
				break;
			}
		}
		printf("%lld\n", ans);

	}
	sp;
	return 0;
}

//Solved