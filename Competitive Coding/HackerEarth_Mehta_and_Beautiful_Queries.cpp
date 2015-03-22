/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

int main(){

	int a[500], b[500], c[500], d[500];
	int q, n;
	scanf("%d%d",&n, &q);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);

	REP(i, q){
		REP(j, n){
			c[j] = a[j];
			d[j] = b[j];
		}
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		sort(begin(c) + l, begin(c) + r);
		sort(begin(d) + l, begin(d) + r);
		ll int res = 0;
		r--;
		FOR(j, l, r) res += c[j] * d[j];
		printf("%lld\n", res);
	}
	
	return 0;
}

//Solved