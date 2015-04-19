/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/SPT2015/problems/SPIT04

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

	int n, m,l;
	int a[100000];
	int c[100001];
	scanf("%d%d", &n,&m);
	REP(i, n)
		scanf("%d", &a[i]);
	REP(i, m){
		scanf("%d", &l);
		int dist = 0;
		MS0(c);
		FOR(j, l - 1, n - 1){
			if (c[a[j]] == 0){
				dist++;
				c[a[j]]++;
			}
		}
		printf("%d\n", dist);
	}
	return 0;
}

//