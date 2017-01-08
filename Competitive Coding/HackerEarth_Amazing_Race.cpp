
//http://www.hackerearth.com/superprofs-hiring-challenge/algorithm/amazing-race-3/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

struct team {
	ll int x, y;
	ll int speed;
	ll int t;
}T[200];

struct point{
	ll int x, y;
}chk[200];


bool compare(team lhs, team rhs){
	return lhs.t < rhs.t;
}


int findNearest(ll int x, ll int y, ll int m){

	int pos;
	ll int near = -1;
	REP(i, m){
		ll int dist = (chk[i].x - x)*(chk[i].x - x) + (chk[i].y - y)*(chk[i].y - y);
		if (near == -1){
			near = dist;
			pos = i;
		}
		else if (dist<near){
			near = dist;
			pos = i;
		}
	}
	return pos;
}

void timesforTeams(int n, int m){

	ll int x, y, cx, cy, s;
	REP(i, n){
		x = T[i].x;
		y = T[i].y;
		s = T[i].speed;
		int cp = findNearest(x, y, m);
		cx = chk[cp].x;
		cy = chk[cp].y;
		T[i].t = ceil(((cx - x)*(cx - x) + (cy - y)*(cy - y)) / (float)(s*s));

	}
	sort(T, T + n, compare);
}

int main(){

	ll int n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	REP(i, n)
		scanf("%lld %lld", &T[i].x, &T[i].y);
	REP(i, m)
		scanf("%lld %lld", &chk[i].x, &chk[i].y);
	REP(i, n)
		scanf("%lld", &T[i].speed);
	timesforTeams(n, m);

	printf("%lld", T[k - 1].t);
	return 0;
}

//Partially Solved 10/100