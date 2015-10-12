/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/ACMAMR15/problems/AMR15B

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

int a[100000];
int res[100000];

ll int gcd(ll int a,ll int b){
	ll int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);
		ll int lim = 1<<n;
		ll int prod = 1;
		REP(i, lim) {
			int x = i;
			vector<int> sub;
			int k = 0;
			while (x) {
				if (x%2)
					sub.pb(a[k]);
				x /= 2;
				k++;
			}
			if (sub.size()>0) {
				res[i] = sub[0];
				REP(k, sub.size())
					res[i] = gcd(res[i], sub[k]);
				prod = (prod*res[i])%MOD;
			}
		}
		printf("%d\n", prod);
	}
	sp;
	return 0;
}

//