/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/567/problem/B

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

int a[1000001];
int cap[101];

int main(){

	char s;
	int t, n;
	scanf("%d", &t);
	FOR(i,1,t){
		getchar();
		scanf("%c %d", &s, &n);
		if (s=='+'){
			cap[i] = 1 + cap[i-1];
			a[n]++;
		}
		else{
			if (a[n]==0){
				FORD(j, i-1, 0)
					cap[j]++;
				cap[i] = cap[i-1] - 1;
			}
			else{
				a[n]--;
			}
		}
	}

	int ans = 0;
	FOR(i, 0, t)
		ans = max(cap[i], ans);
	printf("%d\n", ans);
	return 0;
}

//Pre Test Passed