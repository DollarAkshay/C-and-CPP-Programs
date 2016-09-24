/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG16/problems/CHEFCRUN

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

ll int cost[200000];
ll int sumu_c[200000], sumu_a[200000];
ll int sumv_c[200000], sumv_a[200000];

int edgeUsed[100000];
ll int globres = 1E18;

void dfs(int u, ll  int curcost, int end, int n) {

	if (u==end) {
		globres = min(globres, curcost);
	}

	ll int eback = (u-1+n)%n, efront = u;

	if (edgeUsed[eback]<2) {
		edgeUsed[eback]++;
		dfs((u-1+n)%n, curcost+cost[eback], end, n);
		edgeUsed[eback]--;
	}

	if (edgeUsed[efront]<2) {
		edgeUsed[efront]++;
		dfs((u+1)%n, curcost+cost[efront], end, n);
		edgeUsed[efront]--;
	}

}

int main(){
	
	FILE *fp = fopen("input.txt", "r");
	ll int t, n;
	fscanf(fp, "%lld", &t);
	REP(tc, t){
		fscanf(fp, "%lld", &n);
		REP(i, n)
			fscanf(fp, "%lld", &cost[i]);

		ll int u, v;
		fscanf(fp, "%lld %lld", &u, &v);
		u--;
		v--;
		
		sumu_c[0] = sumu_a[0] = sumv_c[0] = sumv_a[0] = 0;

		FOR(i, 1, n) {
			int prevu = (u-i+n)%n;
			int nextu = (u+i-1+n)%n;
			sumu_c[i] = sumu_c[i-1] + cost[nextu];
			sumu_a[i] = sumu_a[i-1] + cost[prevu];

			int prevv = (v-i+n)%n;
			int nextv = (v+i-1+n)%n;
			sumv_c[i] = sumv_c[i-1] + cost[nextv];
			sumv_a[i] = sumv_a[i-1] + cost[prevv];
		}

		ll int cdist_u = u<v?v-u:n-(u-v);
		ll int adist_u = u<v?n-(v-u):u-v;

		ll int cdist_v = adist_u, adist_v = cdist_u;

		pair<ll int, ll int> cmin_u = mp(-1, 0);
		REP(i, cdist_u+1) {
			if (sumu_c[i]<cmin_u.second)
				cmin_u = mp(i, sumu_c[i]);
		}

		pair<ll int, ll int> cmin_v = mp(-1, 0);
		REP(i, cdist_v+1) {
			if (sumv_c[i]<cmin_v.second)
				cmin_v = mp(i, sumv_c[i]);
		}

		pair<ll int, ll int> amin_u = mp(-1, 0);
		REP(i, adist_u+1) {
			if (sumu_a[i]<amin_u.second)
				amin_u = mp(i, sumu_a[i]);
		}

		pair<ll int, ll int> amin_v = mp(-1, 0);
		REP(i, adist_v+1) {
			if (sumv_a[i]<amin_v.second)
				amin_v = mp(i, sumv_a[i]);
		}

		while (amin_u.first + cmin_v.first > adist_u) {
			if (sumu_a[amin_u.first-1] + sumv_c[cmin_v.first] > sumu_a[amin_u.first] + sumv_c[cmin_v.first-1]) {
				cmin_v.first--;
			}
			else {
				amin_u.first--;
			}
		}

		while (cmin_u.first + amin_v.first > cdist_u) {
			if (sumu_c[cmin_u.first-1] + sumv_a[amin_v.first] > sumu_c[cmin_u.first] + sumv_a[amin_v.first-1]) {
				amin_v.first--;
			}
			else {
				cmin_u.first--;
			}
		}

		ll int ccost_u = sumu_c[cdist_u];
		ll int acost_u = sumu_a[adist_u];

		ll int res = min( 

		globres = 1E18;
		dfs(u, 0, v, n);

		printf("ALGO = %lld\n", res);
		printf("BRUTE = %lld\n", globres);
		if (res!=globres) {
			printf("Huston we have a problem\n");
		}
	}

	sp;
	return 0;
}

//