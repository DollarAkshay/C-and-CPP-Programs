/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/problems/STDDEV

#include <algorithm>
#include <assert.h>
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
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)
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

int a[1000000];

int main() {

	ll int t, n, std;
	scanf("%lld", &t);
	REP(tc, t) {
		scanf("%lld %lld", &n, &std);
		if (n == 1 && std > 0) {
			printf("-1\n");
		}
		else if (n == 1 && std == 0) {
			printf("0\n");
		}
		else if (n % 2 == 0) {
			REP(i, n) {
				printf("%lld ", i % 2 ? std : -std);
			}
		}
		else {
			double special = sqrt(std * std * 3 / 2.0);
			printf("0 %lf %lf ", -special, special);
			REP(i, n - 3) {
				printf("%lld ", i % 2 ? std : -std);
			}
		}
		printf("\n");
	}
	return 0;
}

//Solved