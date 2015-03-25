/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/problem/algorithm/sherlock-magic

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

struct crim {
	int x, y;
	char d;
	bool vanish = false;
}a[50];

int grid[5000][5000];

void moveCrim(int n){

	REP(i, n){
		if (a[i].vanish)
			continue;
		if (a[i].d == 'N')
			a[i].y++;
		else if (a[i].d == 'S')
			a[i].y--;
		else if (a[i].d == 'E')
			a[i].x++;
		else
			a[i].x--;
	}
}

void removeCrims(int n){

	REP(i, n){
		if (a[i].vanish)
			continue;
		int y = a[i].y + 999, x = a[i].x + 999;
		if (grid[y][x] == 0)
			grid[y][x] = i+1;
		else{
			a[i].vanish = true;
			a[grid[y][x]-1].vanish = true;
		}
	}
	REP(i, n){
		if (!a[i].vanish){
			int y = a[i].y + 999, x = a[i].x + 999;
			grid[y][x] = 0;
		}
	}

}

void sim(int n){
	FOR(i, 1, 2000){
		moveCrim(n);
		removeCrims(n);
	}
}


int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n){
			scanf("%d%d %c", &a[i].x, &a[i].y, &a[i].d);
			a[i].vanish = false;
		}
		sim(n);
		int c = 0;
		REP(i, n) if (!a[i].vanish)c++;
		cout << c <<endl;
	}
	return 0;
}

//Not Solved