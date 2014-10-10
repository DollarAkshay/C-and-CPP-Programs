http://www.spoj.com/problems/TOE1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
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

	int t, n, x, o;
	char line[4];

	scanf("%d", &t);
	REP(tc, t){
		x = o = 0;
		REP(i, 3){
			gets(line);
			REP(j, 3){
				if (line[j] == 'X')
					x++;
				else if (line[j] == 'O')
					o++;
			}
		}
		if (x >= o)
			puts("yes");
		else
			puts("no");
			getchar();

	}
	return 0;
}
