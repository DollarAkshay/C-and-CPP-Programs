/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/JULY15/problems/EGBOBRD

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int a[100000];

int main(){

	ll int sum, k;
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%lld", &n, &k);
		REP(i, n){
			scanf("%d", &a[i]);
			sum = i ? sum + a[i] : a[i];
			sum += sum%k ? 1 : 0;
		}
		printf("%lld\n", (ll int)ceil((double)sum/k) );
	}
	return 0;
}

//Solved