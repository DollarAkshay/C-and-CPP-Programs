
//http://www.hackerearth.com/codexplod-v2/algorithm/modified-power-set/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
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
struct Edge{ int v, w; };

int check[256];

int dist(char s[]){

	int l = 0;
	MS0(check);
	int len = strlen(s);
	for (int i = 0; i<len; i++){
		if (check[s[i]] == 0){
			check[s[i]] = 1;
			l++;
		}
	}
	return l;
}

int main(){
	ll int t;
	char str[2000000], x;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%c%s", &x, str);
		ll int n = dist(str);
		ll int ans = n*(n + 1) / 2;
		printf("%d\n", ans);
	}
	return 0;
}

//Solved 