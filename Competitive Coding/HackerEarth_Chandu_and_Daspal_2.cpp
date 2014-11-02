
//http://www.hackerearth.com/codexplod-v2/algorithm/chandu-and-daspal-2/

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

int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int play(int x, int y){
	int turn = 0;
	while (x>0 && y>0){
		int f = gcd(x, y);
		x -= f;
		y -= f;
		turn++;
	}
	return turn;
}

int main(){

	int t, x, y;
	char name[100];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d%s", &x, &y, name);
		int turns = play(x, y);
		if (!strcmp(name, "Daspal"))
			puts(turns % 2 ? "Daspal" : "Chandu");
		else
			puts(turns % 2 ? "Chandu" : "Daspal");
	}
	return 0;
}

//Solved