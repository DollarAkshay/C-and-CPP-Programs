/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/report/15086825d500585e2db6b1e003a3cfdbe189506

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

bool compare(pair<int, int> l, pair<int, int> r){
	return l.second < r.second;
}

int main(){

	int n;
	vector<pair<int, int>> a;
	scanf("%d", &n);
	REP(i, n){
		int s, e;
		scanf("%d%d", &s, &e);
		a.push_back(make_pair(s, s + e));
	}
	sort(begin(a), end(a), compare);
	int ans = 1, last = 0;
	FOR(i, 1, n - 1){
		if (a[i].first >= a[last].second){
			ans++;
			last = i;
		}
	}
	printf("%d", ans);

	return 0;
}

//Solved