
//https://www.hackerrank.com/contests/codathon/challenges/chetu-and-his-girlfriend

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int t, n, day;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		day = (32 - n) / 3 * 2 + 1;
		if (n % 3 == 2){
			day--;
			printf("NISHU %d\n", day);
		}
		else{
			printf("CHETU %d\n", day);
		}
	}
	return 0;
}

//Solved