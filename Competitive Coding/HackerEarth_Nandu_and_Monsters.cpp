
//http://www.hackerearth.com/iitkgpheoct14/algorithm/nandu-and-monsters-3/

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


int r[100001];


int main(){

	int n, q, a, b, pos;
	char c;

	scanf("%d%d", &n, &q);
	getchar();

	REP(i, n){
		c = getchar();
		r[i + 1] = c - '0';
	}

	REP(i, q){
		scanf("%d%d", &a, &b);
		pos = 1;
		if (r[a] || r[b])
			pos = 0;
		else{
			while (a != b){
				a>b ? a /= 2 : b /= 2;
				if (r[a] || r[b]){
					pos = 0;
					break;
				}
			}
		}
		puts(pos ? "Yes" : "No");
	}
	return 0;
}

//Solved