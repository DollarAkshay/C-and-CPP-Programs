/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6254486/dashboard#s=p2

#include <InfInt.h>
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

vector<ll int> fact;

bool isPrime(InfInt n) {

	int lim = n.intSqrt().toLongLong();
	for (int i = 2; i<=lim; i++) {
		if (n%i==0) {
			fact.push_back(i);
			return false;
		}
	}

	return true;

}

InfInt readinBase(ll int c, int b) {

	InfInt res = 0;

	FORD(i, 32, 0) {
		res *= b;
		if (c & 1LL<<i)
			res += 1;
	}

	return res;

}

bool isJamCoin(ll int c) {

	FOR(b, 2, 10) {
		InfInt number = readinBase(c, b);
		cout<<number<<endl;
		if (isPrime(number))
			return false;
	}
	return true;
}

int main(){


	int n = 16, j = 50, k = 0;
	ll int coin = (1LL<<(n-1)) + 1;

	while (k<j) {

		if (isJamCoin(coin)) {
			string s = bitset<16>(coin).to_string();
			cout<<s;
			REP(i, fact.size())
				printf(" %lld", fact[i]);
			printf("\n");
		}

		fact.clear();
		coin += 2;

	}

	sp;
	return 0;

}

//