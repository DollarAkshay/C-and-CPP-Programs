
//http://www.hackerearth.com/codexplod-1/algorithm/chandu-and-daspal/

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

int last[256];

void reset(){
	REP(i, 256)
		last[i] = -1;
}

int main(){

	int t;
	ll int ans;
	char x, str[1000000];
	scanf("%d", &t);
	REP(tc, t){
		ans = 0;
		scanf("%c%s", &x, str);
		int len = strlen(str);
		reset();
		REP(i, len){
			char c = str[i];
			if (last[c] == -1)
				last[c] = i;
			else{
				int n = i - last[c];
				ll int p = 1;
				while (n--) p = (p * 2) % MOD;
				ans = (ans + p) % MOD;
				last[c] = i;
			}
		}
		printf("%lld\n", ans);

	}
	return 0;
}

//Solved