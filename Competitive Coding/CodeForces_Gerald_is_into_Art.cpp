/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://codeforces.com/contest/560/problem/B

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

int bh, bw;
int a[1005][1005];

int place(int x, int y, int w, int h){

	int empty = 1;
	if (x+w-1>bw || y+h-1>bh)
		return 0;

	FOR(i, y, y+h-1){
		FOR(j, x, x+w-1){
			if (a[i][j]==1){
				empty = 0;
				i = y+h;
				break;
			}
		}
	}

	if (empty){
		FOR(i, y, y+h-1)
			FOR(j, x, x+w-1)
				a[i][j] = 1;
		return 1;
	}
	else
		return 0;

}

int main(){

	
	int h1, w1, h2, w2;
	scanf("%d%d", &bh, &bw);
	scanf("%d%d", &h1, &w1);
	scanf("%d%d", &h2, &w2);

	int pos = 0;

	if (place(1, 1, w1, h1)){
		FOR(i, 1, bh){
			FOR(j, 1, bw){
				if (place(j, i, w2, h2) || place(j, i, h2, w2)){
					pos = 1;
					i = bh+1;
					break;
				}
			}
		}
	}

	if (pos==0){
		MS0(a);
		place(1, 1, h1, w1);
		FOR(i, 1, bh){
			FOR(j, 1, bw){
				if (place(j, i, w2, h2) || place(j, i, h2, w2)){
					pos = 1;
					i = bh+1;
					break;
				}
			}
		}
	}

	puts(pos?"YES":"NO");
	return 0;

}

//Pre-Test Passed