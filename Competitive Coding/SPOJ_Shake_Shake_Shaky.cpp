/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/MAIN8_C/

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

int a[50000];

ll int calcPersons(int x,int n){

	ll int ans = 0;
	REP(i, n)
		ans += a[i]/x;
	return ans;
}

int main(){

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n,&k);
		int hi = 0 , lo, mid, ans=0;
		REP(i, n){
			scanf("%d", &a[i]);
			hi=max(hi,a[i]);
		}
		lo = 1;
		while (hi>=lo){
			mid = (hi+lo)/2;
			if (calcPersons(mid, n)>=k){
				lo = mid+1;
				ans = mid;
			}
			else
				hi = mid-1;
		}
		printf("%d\n", ans);
	}
	sp;
	return 0;
}

//Solved