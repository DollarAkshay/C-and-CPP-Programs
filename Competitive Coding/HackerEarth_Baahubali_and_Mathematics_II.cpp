/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/cm1508/algorithm/baahubali-and-mathematics-ii/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <list>
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

int a[5];
int fuck = 0;

int perm(int n) {

	int nc = n;
	vector<int> sym;
	while (n) {
		sym.pb(n%3);
		n /= 3;
	}

	while (sym.size()<4)
		sym.pb(0);

	vector<int> res;
	REP(i, 5)
		res.pb(a[i]);

	REP(i, sym.size()) {
		if (sym[i]==2) {
			int a = res[i], b = res[i+1];
			res.erase(res.begin()+i);
			res.erase(res.begin()+i);
			sym.erase(sym.begin()+i);
			res.insert(res.begin()+i, a*b);
			i--;
		}
	}
	int val = res[0];

	REP(i, sym.size()) {
		if (sym[i])
			val -= res[i+1];
		else
			val += res[i+1];
	}

	return val;
}

int check() {
	int lim = pow(3, 4);
	int ans = 0;
	REP(i, lim) {
		if (perm(i)==23) {
			ans = 1;
			break;
		}
	}
	return ans;
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permute(int l, int r) {
	int i;
	if (l == r) {
		fuck = max(fuck, check());
		if (fuck)
			return;
	}
	else {
		for (i = l; i <= r; i++) {
			swap((a+l), (a+i));
			permute(l+1, r);
			swap((a+l), (a+i));
		}
	}
}


int main() {

	int t, n;
	scanf("%d", &t);
	REP(tc, t) {
		REP(i, 5)
			scanf("%d", &a[i]);
		permute(0, 4);
		printf(fuck?"YES\n":"NO\n");
	}
	return 0;
}

//