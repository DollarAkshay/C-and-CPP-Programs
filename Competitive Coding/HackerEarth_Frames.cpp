/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/april-clash-15/algorithm/frames-4/

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

int main(){

	int m, n;
	int a[2000][2000];
	char x;
	ll int ans = 0;
	scanf("%d%d", &n,&m);
	getchar();
	REP(i, n){
		REP(j, m){
			scanf("%c", &x);
			a[i][j] = x - '0';
			if (!a[i][j]) 
				ans++;
		}
		getchar();
	}
	int lim = min(m, n);
	FOR(k, 2, lim){
		FOR(i, 0, n - k){
			FOR(j, 0, m - k){
				int frame = 1;
				REP(l, k){
					if (a[i][j+l] || a[i+l][j] || a[i+k-1][j+l] || a[i+l][j+k-1]){
						frame = 0;
						break;
					}
				}
				if (frame)
					ans++;
			}
		}
	}
	printf("%lld\n", ans);
	sp;
	return 0;
}

//