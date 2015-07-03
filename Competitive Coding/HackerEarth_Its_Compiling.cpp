/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codejunk/algorithm/to-be-changed-compile-time-fun/

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

vector<int> a;

int findmax(int n){

	int max = 0,pos=-1;
	FOR(i,1,n-2){
		if (a[i - 1] * a[i + 1] > max){
			max = a[i - 1] * a[i + 1];
			pos = i;
		}
	}
	return pos;
}

int main(){

	int n;
	
	scanf("%d", &n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		a.pb(x);
	}

	ll int ans = 0;
	while (a.size() > 2){
		int i = findmax(a.size());
		ans += a[i - 1] * a[i + 1];
		a.erase(begin(a)+i);
	}
	printf("%lld\n", ans);
	
	return 0;
}

//Solved