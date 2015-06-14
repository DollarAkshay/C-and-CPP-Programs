/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/indeed-prime-challenge/challenges/bells-or-waves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

struct point{
	float x, y;
};

point a[1001];

int main(){

	int n, square = 0, f, j = 0, LOCK = 0;
	scanf("%d", &n);
	point p[2];
	REP(i, n){
		scanf("%f %f", &a[i].x, &a[i].y);
		if (i && j<2 && a[i].y >= a[i - 1].y){
			p[j].x = a[i].x;
			p[j].y = a[i].y;
			LOCK = 0;
		}
		if (i && !LOCK && a[i].y < a[i - 1].y){
			j++;
			LOCK = 1;
		}

	}
	if (a[0].y == a[1].y || a[0].y == a[1].y)
		square = 1;
	f = (int)round((double)1 / ((double)p[1].x - p[0].x));
	if (square)
		printf("square-wave\n%d", f);
	else
		printf("sine-wave\n%d", f);

	return 0;
}

//Solved