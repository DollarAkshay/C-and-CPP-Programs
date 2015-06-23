/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/150212073a567e20c7a9fb5f15a093e5e7283dd

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
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
struct point{
	int x, y;
};

vector<int> e[15];

int main(){

	int h, w, r, ey, ex, pop, addele, ele;
	int x, y;
	char dir[10];
	scanf("%d%d%d%d%d%d%d%d", &h, &w, &r, &ey, &ex, &pop, &addele, &ele);
	REP(i, ele){
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
	}

	while (1){
		scanf("%d %d %s", &y,&x,dir);
		DB("x = %d\n", ex);
		DB("y = %d\n", ey);
		DB("Dir = %s\n", dir);

		if (ey == y && ( (ex<x && !strcmp(dir, "RIGHT")) || (ex>x && !strcmp(dir, "LEFT")) ) )
			printf("BLOCK\n");
		else if ( e[y].size() && ( (e[y][0]<x && !strcmp(dir, "RIGHT")) || (e[y][0]>x && !strcmp(dir, "LEFT")) ) )
			printf("BLOCK\n");
		else
			printf("WAIT\n");
	}
	return 0;
}

//Solved