/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/botcleanlarge

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
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

struct point {
	int x, y;
};

const int neighbours = 1;
int h, w, length, shortest = 1000000000;
point bot;

int v[2500];
vector<int> curtour, tour;
vector<point> cells;

vector<pii> nearest[2500];
char grid[51][51];

int manhattan_distance(point p1, point p2){

	return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

void printDir(point p){

	if (p.x<bot.x)
		printf("LEFT\n");
	else if (p.x>bot.x)
		printf("RIGHT\n");
	else if (p.y<bot.y)
		printf("UP\n");
	else if (p.y>bot.y)
		printf("DOWN\n");
	else
		printf("CLEAN\n");
}


void DFS(int s,int depth){

	if (depth == cells.size()-1 && length<shortest){
		shortest = length;
		tour = curtour;
	}

	v[s] = 1;
	int c = 0;
	for(int i=0; c < neighbours && i<nearest[s].size(); i++){
		if (v[nearest[s][i].second] == 0){
			c++;
			length += nearest[s][i].first;
			curtour.pb(nearest[s][i].second);

			DFS(nearest[s][i].second, depth + 1);

			length -= nearest[s][i].first;
			curtour.pop_back();
		}
	}

	v[s] = 0;

}


int main(){

	scanf("%d %d", &bot.y, &bot.x);
	scanf("%d %d", &h, &w);
	cells.push_back(bot);
	REP(i, h)
		scanf("%s", grid[i]);
	
	REP(i, h){
		REP(j, w){
			if (grid[i][j] == 'd'){
				cells.push_back({ j, i });
			}
		}
	}

	REP(i, cells.size()){
		REP(j, cells.size()){
			if (i!=j){
				nearest[i].pb( mp(manhattan_distance(cells[i],cells[j]),j) );
			}
		}
		SORT(nearest[i], nearest[i].size());
	}

	DFS( 0, 0);
	printDir(cells[tour[0]]);
	return 0;
}

//