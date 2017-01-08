
//http://www.hackerearth.com/codeforgoal/algorithm/copytam-da/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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

int a[10001];

int main(){

	int t, n, x, c;
	scanf("%d", &t);
	REP(tc, t){
		c = 0;
		MS0(a);
		scanf("%d", &n);
		REP(i, n){
			scanf("%d", &x);
			if (a[x] == 0){
				a[x] = 1;
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}

//Solved