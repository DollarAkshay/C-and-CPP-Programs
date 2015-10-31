/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/588/problem/B

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

vector<ll int> fact;

void calcFact(ll int n) {

	int lim = sqrt(n);
	FOR(i, 1, lim) {
		if (n%i==0) {
			fact.push_back(i);
			if (n/i>lim)
				fact.push_back(n/i);
		}
	}
}

bool check(ll int n) {

	int lim = sqrt(n);
	for (ll int i = 2; i<=lim; i++) {
		if (n%(i*i)==0)
			return false;
	}
	return true;
}

int main(){

	ll int n;
	scanf("%I64d", &n);
	calcFact(n);
	SORT(fact, fact.size());
	FORD(i, fact.size()-1, 0) {
		if (check(fact[i])) {
			printf("%I64d\n", fact[i]);
			break;
		}
	}
	return 0;
}

//Solved