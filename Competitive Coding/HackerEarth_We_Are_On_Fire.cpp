/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/april-easy-challenge-15/algorithm/we-are-on-fire/

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
struct pos{ int x, y; };

int map[1001][1001];

int bfs(int rem, int x, int y,int n){

	queue<pos>q;
	int v[1001][1001];
	MS0(v);
	pos u;
	v[x][y] = 1;
	rem--;
	q.push({ x, y });

	while (!q.empty()){
		u = q.front();
		q.pop();
		if (u.x - 1 > 0 && map[u.x - 1][u.y] == 1 && v[u.x - 1][u.y] == 0){
			q.push({ u.x -1, u.y });
			v[u.x - 1][u.y] = 1;
			map[u.x - 1][u.y] = 0;
			rem--;
		}
		if (u.y + 1 <= n && map[u.x][u.y + 1] == 1 && v[u.x][u.y + 1] == 0){
			q.push({ u.x, u.y + 1 });
			v[u.x][u.y + 1] = 1;
			map[u.x][u.y + 1] = 2;
			rem--;
		}
		if (u.x + 1 <= n && map[u.x + 1][u.y] == 1 && v[u.x + 1][u.y] == 0){
			q.push({ u.x + 1, u.y });
			v[u.x + 1][u.y] = 1;
			map[u.x + 1][u.y] = 2;
			rem--;
		}
		if (u.y - 1 > 0 && map[u.x][u.y - 1] == 1 && v[u.x][u.y - 1] == 0){
			q.push({ u.x, u.y - 1 });
			v[u.x][u.y - 1] = 1;
			map[u.x][u.y - 1] = 2;
			rem--;
		}
	}
	return rem;
}


int main(){

	int t, n,m,q,rem=0;
	t = 1;
	REP(tc, t){
		scanf("%d%d%d", &n,&m,&q);
		FOR(i, 1, n){
			FOR(j, 1, m){
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)
					rem++;
			}
		}
		
		REP(i, q){
			int x, y;
			scanf("%d%d", &x, &y);
			if (map[x][y]==0){
				printf("%d\n", rem);
			}
			else{
				rem = bfs(rem,x,y,n);
				printf("%d\n", rem);
			}
		}
	}
	return 0;
}

//Not Solved