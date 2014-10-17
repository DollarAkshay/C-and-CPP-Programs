
//https://www.hackerrank.com/contests/inscription2014/challenges/equal-lightsabers

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

	int t, a, b, c;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &a, &b);
		if (a == b){
			puts(a % 3 == 1 ? "0" : "1");
		}
		else{
			c = 0;
			while (a % 3)
			if (a++ % 3 == 2)
				c++;
			while (b % 3)
			if (b-- % 3 == 2)
				c++;

			c += (b - a) / 3 * 2 + 1;
			printf("%d\n", c);
		}
	}
	return 0;
}

//Solved