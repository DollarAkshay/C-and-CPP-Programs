/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/162679759875772ba0d9a5007a81b5972386796

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point{
	int x, y;
};


int x, y, h, n;
point g[101];

double caclDist(point a, point b){

	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

}

double nearestGiant(int tx, int ty){
	double dist = 10000;
	REP(i, n)
		dist = min(dist, caclDist({ g[i].x, g[i].y }, { tx, ty }));
	return dist;
}

void printPoint(point p){

	string move = "";

	if (p.x==x && p.y==y)
		move = "WAIT";
	else{
		int tx=x, ty=y;
		if (p.y>y && y+1<18){
			move += "S";
			ty++;
		}
		else if (p.y<y && y-1>=0){
			move += "N";
			ty--;
		}
		if (p.x>x && x+1<40){
			move += "E";
			tx++;
		}
		else if (p.x<x && x-1>=0){
			move += "W";
			tx--;
		}
		
		double giant = nearestGiant(tx,ty);
		DB("Nearest Giant trigering strike = %lf\n", giant);
		DB("Move = '%s'", move.c_str());
		if (giant<2)
			move = "STRIKE";
		else if (move=="")
			move = "WAIT";
	}

	if (strchr(move.c_str(), 'N') && move.size()<=2)
		y--;
	else if (strchr(move.c_str(), 'S') && move.size()<=2)
		y++;
	if (strchr(move.c_str(), 'E') && move.size()<=2)
		x++;
	else if (strchr(move.c_str(), 'W') && move.size()<=2)
		x--;

	printf("%s\n", move.c_str());

}

int main(){

	
	scanf("%d%d", &x, &y);
	while(1){
		scanf("%d%d", &h, &n);
		double k = 100;
		double dist = 10000;
		double sx = 0, sy = 0;
		REP(i, n){
			scanf("%d%d", &g[i].x, &g[i].y);
			double curdist = caclDist({ g[i].x, g[i].y }, { x, y });
			double theta = atan2(g[i].y-y, x-g[i].x);
			sx += k*cos(theta)/(curdist*curdist);
			sy += k*sin(theta)/(curdist*curdist);
			dist = min(dist, curdist);

			DB("Giant %d vector is %lf, %lf | Dist = %lf\n", i+1, k*cos(theta)/curdist , k*sin(theta)/curdist, curdist);
		}

		DB("Nearest Giant = %lf\n", dist);
		DB("Net vector = %lf, %lf\n", sx, sy);
		int cx = round(sx+x), cy = round(sy+y);
		printPoint({ cx, cy });
	}
	
	return 0;
}

//