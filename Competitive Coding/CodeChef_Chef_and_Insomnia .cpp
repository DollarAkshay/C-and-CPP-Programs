/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG15/problems/CHINSM

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

int a[100001];
vector<pii> bad;

bool good(int i, int j){

	REP(k, bad.size()){
		if (bad[k].first>=i && bad[k].second<=j)
			return false;
		else if (bad[k].first>j)
			break;
	}
	return true;
}

int main(){

	int n, k;
	scanf("%d%d", &n, &k);
	
	REP(i, n){
		scanf("%d", &a[i]);
		FORD(j, i-1, 0){
			if (a[j]%a[i]==k)
				bad.pb(mp(j, i));
		}
	}

	SORT(bad, bad.size());

	ll int ans = n;
	REP(i, n){
		FOR(j, i+1, n-1){
			if (good(i, j))
				ans++;
		}
	}
	printf("%lld", ans);
	sp;
	return 0;
}

//