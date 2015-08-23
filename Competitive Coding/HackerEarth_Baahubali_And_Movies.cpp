/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/cm1508/algorithm/a2789f907a2142a5a9fbfb98d024f0f2/

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

int r[100000], c[100000];


int main(){

	int t, n, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &k);
		REP(i, n) 
			scanf("%d", &r[i]);
		REP(i, n)
			scanf("%d", &c[i]);
		int lc = 101, pos = -1;
		REP(i, n) {
			if (r[i]>=k && c[i]<lc) {
				lc = c[i];
				pos = i;
			}
		}
		printf("%d\n", pos);
	}
	return 0;
}

//Solved