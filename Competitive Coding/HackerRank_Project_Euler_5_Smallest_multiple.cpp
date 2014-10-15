
//https://www.hackerrank.com/contests/projecteuler/challenges/euler005

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

int p[41];

void seiv(){
	MS1(p);
	p[0] = p[1] = 0;
	int i, j, k;
	for (i = 2; i <= 40; i++){
		if (p[i]){
			for (j = i*i; j <= 40; j += i){
				p[j] = 0;
			}
		}
	}
}




int main(){

	seiv();
	int t, n;
	ll int res = 1;
	scanf("%d", &t);
	REP(tc, t){
		res = 1;
		scanf("%d", &n);
		FOR(i, 2, n){
			if (p[i]){
				int pow = i;
				while (pow <= n){
					res *= i;
					pow *= i;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

//Solved 