
//https://www.hackerrank.com/contests/inscription2014/challenges/save-middle-earth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<assert.h>
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

	int t, n, q, dist, px, py;
	char str[101];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &n, &q);
		REP(i, q){
			cin >> str;
			px = py = dist = 0;
			int len = strlen(str);
			REP(j, len){
				int c = str[j] - 97;
				dist += abs(px - c%n) + abs(py - c / n);
				py = c / n;
				px = c%n;
			}
			printf("%d\n", dist);
		}
	}
	return 0;
}

//Solved