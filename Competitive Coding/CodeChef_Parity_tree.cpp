/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/MARCH16/problems/PARITREE

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

struct cond {
	int u, v;
	int x, len;
};

int parent[100001], level[100001];
cond c[100001];
vector<pii> edgelist;

vector<int> graph[100001];


ll int invert_mod(ll int a, ll int p) {
	ll int ne = 1, old = 0, q = p, r, h;
	ll int pos = 0;
	while (a > 0) {
		r = q%a;
		q = q / a;
		h = q*ne + old;
		old = ne;
		ne = h;
		q = a;
		a = r;
		pos = !pos;
	}
	return pos?old:(p - old);
}


ll int nCrMOD(int n, int r, int mod) {

	if (n == r || r==0)
		return 1;

	ll int res = 1, i = 1;

	r = n-r>r?n-r:r;

	while (n - r)
		res = ((res*n--) % mod * invert_mod(i++, mod)) % mod;

	return res;
}

ll int powMOD(int b, int e) {

	ll int res = 1;
	while (e--)
		res = ((ll int)res*b) % MOD;
	return res;

}


int path_len(int u, int v) {

	int len = 0;

	while (u!=v) {
		if (level[u]>level[v])
			u = parent[u];
		else
			v = parent[v];
		len++;
	}

	return len;

}

void setLevels(int root, int l) {

	level[root] = l;

	REP(i, graph[root].size()) {
		if (level[graph[root][i]]==0) {
			parent[graph[root][i]] = root;
			setLevels(graph[root][i], l+1);
		}
	}
}

ll int caclways(int k) {

	ll int res = 0;

	FOR(i, c[k].x, c[k].len) {
		res = (res + nCrMOD(c[k].len, i, MOD))%MOD;
		i++;
	}

	return res;

}

int main() {

	int t, n, q;
	scanf("%d", &t);
	REP(tc, t) {

		scanf("%d %d", &n, &q);
		REP(i, n-1) {
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
			edgelist.push_back(mp(u, v));
		}
		setLevels(1, 1); // Root is 1 at level 1

		REP(i, q) {
			scanf("%d %d %d", &c[i].u, &c[i].v, &c[i].x);
			c[i].len = path_len(c[i].u, c[i].v);
		}

		int lim = 2<<(n-1);



		edgelist.clear();
		FOR(i, 1, n)
			graph[i].clear();
		MS0(parent);
		MS0(level);
	}
	sp;
	return 0;
}

//