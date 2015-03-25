/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/december-clash/algorithm/xor-in-sequence/

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
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int a[100000];
int f[100000];

int main(){


	f[0] = 0;
	int t, n, q, l, r;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n){
			scanf("%d", &a[i]);
			f[i + 1] = f[i] ^ a[i];
		}
		scanf("%d", &q);
		REP(qu, q){
			scanf("%d%d", &l, &r);
			ll int c = 0;
			FOR(i, 1, n){
				FOR(j, i, n){
					int res = f[j] ^ f[i - 1];
					if (res >= l && res <= r)
						c++;
				}
			}
			printf("%lld\n", c);
		}
	}
	return 0;
}

//Partially Solved