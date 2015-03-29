/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/LTIME22/problems/PAINTBOX

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

int ways(int n,int w){

	int res = 0;

	REP(i, n){
		int col = a[i], flag = 1;
		if (i + w <= n){
			FOR(j, i + 1, i + w - 1){
				if (a[j] != col){
					flag = 0;
					break;
				}
			}
			if (flag)
				res++;
		}
	}
	return res;
}

int main(){

	int t, n,w,pos,col,q;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n,&w);
		REP(i, n) scanf("%d", &a[i]);
		scanf("%d", &q);
		REP(i, q){
			scanf("%d%d", &pos, &col);
			a[pos-1] = col;
			printf("%d\n",ways(n,w));
		}
	}
	return 0;
}

//Partially Solved ~ TLE