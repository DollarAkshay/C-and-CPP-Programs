/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

// https://www.codechef.com/problems/CHEFHCK2

#include <algorithm>
#include <assert.h>
#include <ctime>
#include <ctype.h>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_set>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i, a, b) for (long long int i = a; i <= b; ++i)
#define FORD(i, a, b) for (long long int i = a; i >= b; --i)
#define REP(i, n) FOR(i, 0, (int)n - 1)
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, 1, sizeof(x))
#define SORT(a, n) sort(begin(a), begin(a) + n)
#define REV(a, n) reverse(begin(a), begin(a) + n)
#define ll long long
#define pii pair<int, int>
#define MOD 1000000007

vector<int> primes;
vector<ll int> power;

ll int squaresBelow(ll int n) {
	return (int)floor(sqrt((long double)n - 1)) - 1; // Except 1
}

bool isSquare(ll int n) {
	ll int sqrt_n = sqrt((long double)n);
	return sqrt_n * sqrt_n == n;
}

void checkSquareBeforeInsert(ll int a) {
	if (isSquare(a) == false) {
		power.pb(a);
	}
}

bool isPowerNumber(ll int n) {
	if (isSquare(n)) {
		return true;
	}
	else if (binary_search(power.begin(), power.end(), n)) {
		return true;
	}
	else {
		return false;
	}
}

void generatePowerList() {
	ll int MAX = pow((long double)3141, 5);
	ll int limit = cbrt(MAX);
	FOR(i, 2, limit) {
		ll int prod = i;
		while ((double)prod * i * i <= MAX) {
			prod *= i * i;
			checkSquareBeforeInsert(prod);
		}
	}
	sort(power.begin(), power.end());
	power.erase(unique(power.begin(), power.end()), power.end());
}

ll int special_binary_search(ll int z) {

	if (z == (z & -z)) {
		return log2(z);
	}
	return 2 * log2(z) - log2(z & -z) - 1;
}

ll int calcTries(ll int n) {

	if (n == 0) {
		return 2;
	}
	else if (n == 1) {
		return 1;
	}

	ll int sq = squaresBelow(n);
	ll int po = (lower_bound(power.begin(), power.end(), n) - power.begin());
	if (isPowerNumber(n)) {
		return sq + po + 1;
	}
	else {
		return special_binary_search(n + 1 - sq - po);
	}
}

int main() {

	generatePowerList();

	int n;
	scanf("%d", &n);
	REP(i, n) {
		ll int pass;
		scanf("%I64d", &pass);
		printf("%I64d ", calcTries(pass));
	}

	return 0;
}

// Correct Solution but TLE