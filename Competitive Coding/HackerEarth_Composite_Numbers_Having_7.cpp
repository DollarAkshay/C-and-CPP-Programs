
//http://www.hackerearth.com/tcetcyphers-2/algorithm/composite-numbers-having-7/

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


int check7(int n){
	if (n < 27)
		return 0;
	int lim = sqrt(n), prime = 1, d;
	FOR(i, 2, lim){
		if (n%i == 0){
			prime = 0;
			break;
		}
	}
	if (prime)
		return 0;
	else{
		while (n){
			if (n % 10 == 7)
				return 1;
			n /= 10;
		}
		return 0;
	}
}


int main(){

	int t, n, m, c[1000005];
	c[0] = 0;
	FOR(j, 1, 1000001){
		if (check7(j))
			c[j] = c[j - 1] + 1;
		else
			c[j] = c[j - 1];
	}
	scanf("%d", &t);
	REP(i, t){
		scanf("%d%d", &m, &n);
		int ans = c[n] - c[m];
		if (check7(m)) ans++;
		printf(ans ? "%d\n" : "-1\n", ans);
	}
	return 0;
}

//Solved