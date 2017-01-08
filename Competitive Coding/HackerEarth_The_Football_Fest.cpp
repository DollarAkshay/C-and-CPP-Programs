
//http://www.hackerearth.com/superprofs-hiring-challenge/algorithm/the-football-fest-6/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

int main(){

	int t, n;
	int prev, cur;
	int id;
	char type, x;
	scanf("%d", &t);
	REP(tc, t){
		prev = cur = 0;
		scanf("%d%d", &n, &cur);
		REP(i, n){
			scanf("%c%c", &x, &type);
			if (type == 'P'){
				prev = cur;
				scanf("%d", &cur);
			}
			else{
				int t = cur;
				cur = prev;
				prev = t;
			}
		}
		printf("Player %d\n", cur);
	}
	return 0;
}

//Solved