/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_100-1/algorithm/play-with-string/

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

int main(){

	int t, n;
	char s[100000];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", &s);
		int len = strlen(s), funny = 1;
		REP(i, len - 1){
			if (abs(s[i] - s[i + 1]) != abs(s[len - 1 - i] - s[len - 1 - i - 1])){
				funny = 0;
				break;
			}
		}
		puts(funny ? "Funny" : "Not Funny");
	}
	return 0;
}

//Solved