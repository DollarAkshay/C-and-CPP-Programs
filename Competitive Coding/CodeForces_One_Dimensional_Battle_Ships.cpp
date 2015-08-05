/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/567/problem/D

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

int a[100000];

int main(){

	int n, k, a, m;
	scanf("%d%d%d", &n, &k, &a);
	scanf("%d", &m);
	int ans = -1;
	list<pii> seg;
	seg.pb(mp(1, n));
	REP(i, m){
		int x;
		scanf("%d", &x);
		for (auto it = seg.begin(); it!=seg.end(); it++){
			int l = it->first, r = it->second;
			if (x>=l && x<=r){
				if (l<=x-1){
					seg.insert(it, mp(l, x-1));
				}
				if (r>=x+1){
					seg.insert(it, mp(x+1, r));
				}
				seg.erase(it);
				break;
			}
		}

		int ships = 0;
		for (auto it = seg.begin(); it!=seg.end(); it++)
			ships += (it->second-it->first+2)/(a+1);
		if (ships<k){
			ans = i+1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

//