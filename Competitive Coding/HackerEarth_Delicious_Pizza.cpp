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

struct Pizza{ int p, d; }a[100000];

bool compare(Pizza lhs, Pizza rhs) {
	return lhs.d > rhs.d; 
}

ll int s[100000];

int main(){

	int n,q;
	scanf("%d%d", &n, &q);
	REP(i, n) scanf("%d", &a[i].p);
	REP(i, n) scanf("%d", &a[i].d);
	sort(a, a + n, compare);
	s[0] = a[0].p;

	FOR(i, 1, n - 1) s[i] = s[i - 1] + a[i].p;

	REP(i, q){
		int k;
		scanf("%d", &k);
		printf("%lld\n", s[k-1]);
	}
	return 0;
}

//Solved