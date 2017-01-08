
//http://www.hackerearth.com/iitkgpheoct14/algorithm/bomb-defusal-4/

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

int main(){

	int t, p, x, y, u, v;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%d%d%d", &p, &x, &y, &u, &v);
		int p1 = abs((x + y) % 2), p2 = abs((v + u) % 2);
		double slope = (double)(y - v) / (x - u);
		slope = fabs(slope);
		if (p1 == p2){
			if (p>2)
				puts("Counter-Terrorists Win !");
			else if (p == 2 && slope == 1)
				puts("Counter-Terrorists Win !");
			else if (p == 1 && x == u && y == v)
				puts("Counter-Terrorists Win !");
			else
				puts("Terrorists Win !");
		}
		else
			puts("Terrorists Win !");
	}
	return 0;
}

//Solved