/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/JAN16/problems/CBALLS

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

#define MAX 10000

int p[MAX+1];
int a[10000];

void sieve() {

	REP(i, MAX+1)
		p[i] = 1;

	int lim = sqrt(MAX);

	p[0] = p[1] = 0;

	FOR(i, 2, lim) {
		if (p[i]) {
			FOR(j, i*i, MAX) {
				p[j] = 0;
				j += i;
				j--;
			}
		}
	}

}

ll int cost(int n, int x) {

	ll int res = 0;
	int b[10000];
	REP(i, n)
		b[i] = a[i];

	REP(i, n) {
		if (i && b[i]<b[i-1]) {
			res += b[i-1]-b[i];
			b[i] = b[i-1];
		}
		else if(b[i]%x>0){
			res += x-b[i]%x;
			b[i] += x-b[i]%x;
		}
	}
	return res;

}

int main(){

	sieve();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		ll int minV = 1E10;
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &a[i]);

		FOR(i, 2, MAX) {
			if (p[i])
				minV = min(minV, cost(n, i));
		}
		printf("%d\n", minV);
	}
	sp;
	return 0;
}

//Solved