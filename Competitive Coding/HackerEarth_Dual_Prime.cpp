/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codestellar-6/algorithm/dual-prime/

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
#define MAX 1000000

int a[100000];
char p[MAX];

void seiv() {

	MS1(p);
	p[0] = p[1] = 0;
	ll int i, j, lim = sqrt(MAX);
	for (i = 2; i<=lim; i++) {
		if (p[i]) {
			for (j = i*i; j<MAX; j += i)
				p[j] = 0;
		}
	}
}

int sumdig(int n) {

	int res = 0;
	while (n) {
		res += n%10;
		n /= 10;
	}
	return res;
}

int main(){

	seiv();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		puts(p[n] && p[sumdig(n)]?"YES":"NO");
	}
	return 0;
}

//Solved