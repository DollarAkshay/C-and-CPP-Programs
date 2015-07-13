/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/JULY15/problems/MCHEF

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
#define gc getchar

void scanint(int &x){
	register int c = gc();
	x = 0;
	int neg = 0;
	for (; ((c<48 || c>57) && c != '-'); c = gc());
	if (c == '-') { neg = 1; c = gc(); }
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}

ll int minimizeKnapsack(vector<pair<int, int>> a, int cost[], int k){

	ll int *dp = (ll int*)malloc((k+1)*sizeof(ll int)), *prev=(ll int*)calloc(k+1, sizeof(ll int));
	REP(i,a.size()){
		if (cost[a[i].second]>0){
			FOR(j, 0, k){
				if (j >= cost[a[i].second])
					dp[j] = min(prev[j], prev[j - cost[a[i].second]] + a[i].first);
				else
					dp[j] = prev[j];
			}
			free(prev);
			prev = dp;
			dp = (ll int*)malloc((k+1)*sizeof(ll int));
		}
	}
	return prev[k];
}


int main(){

	int t, n,m,k;
	scanint(t);
	
	REP(tc, t){
		ll int rating = 0;
		vector<pair<int,int>> neg;
		scanint(n); scanint(k); scanint(m);
		int *a = (int*)malloc((n + 1)*sizeof(int)), cost[100001];
		MS0(cost);
		FOR(i, 1, n){
			scanint(a[i]);
			rating += a[i];
			if (a[i]<0)
				neg.pb(mp(a[i],i));
		}
		vector<pii> L[100001];
		vector<pii> R[100001];
		FOR(i, 1, m){
			int c, l, r;
			scanint(l); scanint(r); scanint(c);
			L[l].pb(mp(c,i));
			R[r].pb(mp(c,i));
		}
		set<pii> iset;
		FOR(i, 1, n){
			REP(j, L[i].size())
				iset.insert(L[i][j]);

			cost[i] = iset.begin()->first;

			REP(j, R[i].size())
				iset.erase(R[i][j]);
		}
		printf("%lld\n", rating - minimizeKnapsack(neg, cost, k));
	}
	sp;
	return 0;
}

//Solved :D EEEEEEEEEEeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee