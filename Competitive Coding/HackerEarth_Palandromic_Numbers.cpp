#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long


int palindrome(int n){
	int res = 0, x = n * 10;
	while (x/=10) res = res*10 + x%10;
	if (res == n)
		return 1;
	else
		return 0;
}

int main(){

	int t, l, r;
	scanf("%d", &t);
	REP(i, t){
		scanf("%d%d", &l, &r);
		int c = 0;
		FOR(j, l, r) if (palindrome(j))c++;
		printf("%d\n", c);
	}
	system("pause");
	return 0;
	
}