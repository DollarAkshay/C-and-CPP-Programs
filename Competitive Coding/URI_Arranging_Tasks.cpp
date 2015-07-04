/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.urionlinejudge.com.br/judge/en/problems/view/1704

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
#define MOD 1000000007

bool comp(pair<int, int> l, pair<int, int> r){
	return (l.first > r.first) || (l.first == r.first && l.second < r.second);
}

int main(){

	int n, h;
	while (scanf("%d%d", &n, &h) > 0){
		int a[1001];
		MS0(a);
		int money = 0, got = 0;

		vector<pair<int, int>> b;
		REP(i, n){
			int v, t;
			scanf("%d%d", &v, &t);
			money += v;
			b.pb(mp(v, t));
		}
		sort(begin(b), end(b), comp);
		REP(i, n){
			FORD(j, b[i].second, 1){
				if (a[j] == 0){
					a[j] = b[i].first;
					got += b[i].first;
					break;
				}
			}
		}
		printf("%d\n", money - got);
	}
	return 0;
}

//Solved