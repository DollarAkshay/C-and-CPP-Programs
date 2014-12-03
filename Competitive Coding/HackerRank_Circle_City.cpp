/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/circle-city

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

	int t, r, k;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d %d", &r, &k);
		r = sqrt(r);
		int c = 1;
		FOR(i, 0, r - 1){
			FOR(j, 0, r - 1){
				float hyp = sqrt(j*j + i*i);
				float diff = hyp - (int)hyp;
				if (diff == 0 && hyp == r)
					c++;
			}
		}
		//printf("C = %d\n",c);
		puts(c * 4 <= k ? "possible" : "impossible");
	}
	return 0;
}

// ~ TLE