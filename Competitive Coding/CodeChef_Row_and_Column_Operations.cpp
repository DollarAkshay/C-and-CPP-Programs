/*~~~~~~~~~~~~~~~~~~*
*                  *
* Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/problems/ROWCOLOP

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

int rows[314159], cols[314159];

int main() {

	int t, n, q;
	char str[100];
	scanf("%d %d", &n, &q);
	REP(qr, q) {
		int i, x;
		scanf("%s %d %d", str, &i, &x);
		if (str[0] == 'R') {
			rows[i - 1] += x;
		}
		else {
			cols[i - 1] += x;
		}
	}

	int res = *max_element(rows, rows + n) + *max_element(cols, cols + n);
	printf("%d", res);
	return 0;
}

//Solved