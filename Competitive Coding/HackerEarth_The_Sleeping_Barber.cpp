
//http://www.hackerearth.com/cryptex/algorithm/the-sleeping-barber/

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

long long int s[3000];

int comp(const void * a, const void * b){
	ll int x = *(long long int*)a, y = *(long long int*)b;
	if (x>y)
		return 1;
	else if (x == y)
		return 0;
	else
		return -1;
}


int main(){

	ll int t, g, m, serv;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &g, &m);
		REP(i, g)
			scanf("%lld", &s[i]);

		qsort(s, g, sizeof(long long int), comp);
		int i;
		serv = 0;
		for (i = 0; i<g; i++){
			if (serv + s[i]>m)
				break;
			serv += s[i];
		}
		cout << i << endl;
	}
	return 0;
}

//Solved