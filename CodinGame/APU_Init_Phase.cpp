/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/15017662284855d7c149d3659397443818aa9c8

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

int w, h;
char s[31][31];

void bfs(point src){

	int v[30][30];
	MS0(v);
	point u=src;
	queue<point> q;
	q.push(u);

	while (!q.empty()){
		u = q.front();
		q.pop();
		if (v[u.y][u.x] == 0 && s[u.y][u.x] == '0'){
			printf("%d %d ", u.x, u.y);
			int rn = 0;
			FOR(i, u.x + 1, w - 1){
				if (s[u.y][i] == '0'){
					printf("%d %d ", i, u.y);
					rn = 1;
					break;
				}
			}
			if (rn == 0)
				printf("-1 -1 ");

			int bn = 0;
			FOR(i, u.y + 1, h - 1){
				if (s[i][u.x] == '0'){
					printf("%d %d\n", u.x, i);
					bn = 1;
					break;
				}
			}
			if (bn == 0)
				printf("-1 -1\n");
			v[u.y][u.x] = 1;
			q.push({ u.x+1, u.y });
			q.push({ u.x, u.y+1 });
		}
		else{
			q.push({ u.x + 1, u.y });
			q.push({ u.x, u.y + 1 });
		}
	}

}

int main(){

	
	scanf("%d%d", &w, &h);
	REP(i, h){
		scanf("%s", s[i]);
		DB("%s\n", s[i]);
	}

	bfs({ 0, 0 });
	return 0;
}

//Solved