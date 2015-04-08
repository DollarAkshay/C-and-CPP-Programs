/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codezarena-v2/algorithm/line-of-sight/

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
struct vec2{ int x, y; };

vec2 a[50000];

float distancevec2(vec2 a, vec2 b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

float minimum_distance(vec2 v, vec2 w, vec2 p) {
	const float l2 = (v.x - w.x)*(v.x - w.x) + (v.y - w.y)*(v.y - w.y); 
	if (l2 == 0.0) return distancevec2(p, v);   
	vec2 a = {-v.x,-v.y }, b = { w.x - v.x, w.y - v.y };
	const float t = (a.x*b.x + a.y*b.y) / l2;
	if (t < 0.0) return distancevec2(p, v);      
	else if (t > 1.0) return distancevec2(p, w);  
	const vec2 projection = { v.x + t*b.x, v.y + t*b.y };
	return distancevec2(p, projection);
}


int main(){

	vec2 mid = { 0, 0 };
	int t=1, n,r;

	REP(tc, t){
		scanf("%d%d", &n,&r);
		REP(i, n)
			scanf("%d%d", &a[i].x, &a[i].y);
		int c = 0;
		REP(i, n){
			FOR(j,i+1,n-1){
				float dist = minimum_distance(a[i], a[j], mid);
				if ( dist > r)
					c++;
			}
		}
		printf("%d", c);
	}
	return 0;
}

//Solved ... I think Problem Setter's Solution is wrong