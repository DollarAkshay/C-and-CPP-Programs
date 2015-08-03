/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/101hack27/challenges/special-lcm-of-subarray

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

int a[100000];

int main(){

	int n, q;
	int t1=-1, t2=-1;
	scanf("%d%d", &n, &q);

	REP(i, n){
		scanf("%d", &a[i]);
		if (a[i]==3){
			if (t1==-1)
				t1 = i;
			else
				t2 = i;
		}
	}

	REP(i, q){
		int x, y;
		scanf("%d %d", &x, &y);
		x--;y--;
		if ((t1>=x && t1<=y) || (t2>=x && t2<=y))
			printf("0\n");
		else{
			int ans = 1;
			int v[1000001];
			MS0(v);
			FOR(j, x, y){
				if (v[a[j]]==0){
					ans = (ans*a[j])%3;
					v[a[j]] = 1;
				}
			}
			printf("%d\n", ans);
		}
	}
	sp;
	return 0;
}

//