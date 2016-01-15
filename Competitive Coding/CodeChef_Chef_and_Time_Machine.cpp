/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/JAN16/problems/CHEFTMA

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

int n, m;

int u[100001];
int diff[100001], button[100001];

int bsearch_lt(int l, int h,int key) {

	int mid, index=-1;
	while (l<=h) {
		mid = (h+l)/2;
		if (button[mid]<=key) {
			l = mid+1;
			index = mid;
		}
		else {
			h = mid-1;
		}
	}
	return index;

}

int main(){

	int t, n, m, x;
	scanf("%d", &t);
	REP(tc, t){

		scanf("%d%d%d", &n, &m, &x);
		m += x;

		REP(i, n)
			scanf("%d", &diff[i]);
		REP(i, n) {
			int x;
			scanf("%d", &x);
			diff[i] -= x;
		}

		REP(i, m)
			scanf("%d", &button[i]);

		SORT(button, m);

		ll int res = 0;
		REP(i, n) {

			int idx = bsearch_lt(0, m-1, diff[i]);

			while (idx>=0 && u[idx])
				idx--;

			if (idx>=0) {
				diff[i] -= button[idx];
				u[idx] = 1;
			}
			res += diff[i];
		}

		printf("%lld\n", res);
		MS0(u);
	}

	sp;
	return 0;
}

//Solved