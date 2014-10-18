
//https://www.hackerrank.com/contests/inscription2014/challenges/the-dragon-warrior

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

struct point {
	int x;
	int y;
};

struct point p[100];

int gain;
int n, m, q, k;

int calc(int px, int py){

	int cal = gain*k;
	REP(i, k){
		if (abs(px - p[i].x)<abs(py - p[i].y)){
			py = p[i].y;
			cal -= abs(px - p[i].x);
		}
		else{
			px = p[i].x;
			cal -= abs(py - p[i].y);
		}
		if (cal < q)
			return 0;
	}
	return 1;
}

int main(){

	//Reading Constraints
	scanf("%d%d%d%d", &n, &m, &q, &k);
	gain = m + n;

	//Reading Points
	REP(i, k)
		scanf("%d%d", &p[i].x, &p[i].y);
	int found = 0;
	REP(i, n){
		REP(j, m){
			if (calc(i, j)){
				found = 1;
				break;
			}
		}
	}
	puts(found ? "1" : "0");
	return 0;
}

//Not Solved
