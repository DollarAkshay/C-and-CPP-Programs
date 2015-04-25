/*~~~~~~~~~~~~~~~~~~*
*                   *
* $Dollar Akshay$   *
*                   *
*~~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/tech-weekend-online-coding/challenges/sachi-and-her-angles

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

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		double x, tot = 0;
		int flag = 0, flat = 1;
		REP(i, n){
			scanf("%lf", &x);
			if (x>360){
				flag = 1;
				break;
			}
			if (x == 360){
				flag = 1;
				break;
			}
			if (x>0 && x<360)
				flat = 0;
			if (x){
				x = 180 - x;
				tot += x;
			}
		}
		puts(tot == 360 && n>2 && !flag && !flat ? "Yes" : "No");
	}
	return 0;
}

//