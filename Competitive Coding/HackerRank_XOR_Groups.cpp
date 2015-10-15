/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/hourrank-1/challenges/xor-groups

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

int a[100005];
int XOR[100005];

int XORLR(int l, int r) {
	if (r<0)
		return 0;
	return XOR[l]^XOR[r+1];
}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		XOR[i+1] = XOR[i]^a[i];
	}
	ll int c = 0;
	REP(i, n) {
		FOR(j, i, i==n-1?n-1:n-2) {
			if ( (XOR[i]^XOR[j+1]) == (XOR[0]^XOR[i]^XOR[j+1]^XOR[n]) )
				c++;
		}
	}
	printf("%lld\n", c%MOD);
	sp;
	return 0;
}

//