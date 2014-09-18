
//http://www.hackerearth.com/problem/algorithm/mystery-1/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

	int t, n;
	char s[101];
	scanf("%d", &t);
	REP(i, t){
		scanf("%s%d", s, &n);
		n %= 26;
		if (n<0) n += 26;
		int len = strlen(s);
		REP(j, len){
			s[j] = s[j] + n>122 ? s[j] + n - 26 : s[j] + n;
		}
		printf("%s\n", s);
	}
	return 0;
}

//Solved