/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/code_hunt_12/algorithm/fight-for-chocolate/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ll long long
#define MOD 1000000007

struct point{
	int x, y;
};

struct point dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

char a[10][10];
int n, m, ans;

int u_size = 0;
struct point u[100];

int checkValid(){

	REP(i, n-1){
		REP(j, m-1){
			if (a[i][j] == a[i][j+1] &&
				a[i][j] == a[i+1][j] &&
				a[i][j] == a[i+1][j+1])
				return 0;
		}
	}



	struct point T, D;

	REP(i, n){
		REP(j, m){
			if (a[i][j]=='T'){
				T.x = j;
				T.y = i;
			}
			else if (a[i][j]=='D'){
				D.x = j;
				D.y = i;
			}
		}
	}

	int v[10][10];
	struct point q[10000];

	int front = 0, rear = -1;
	REP(i, n)
		REP(j, m)
		v[i][j] = 0;

	v[T.y][T.x] = 1;
	q[++rear] = T;

	while (rear>=front){
		struct point u = q[front++];
		REP(i, 4){
			int dx = dir[i].x, dy = dir[i].y;
			if (u.x+dx>=0 && u.x+dx<m &&
				u.y+dy>=0 && u.y+dy<n &&
				v[u.y+dy][u.x+dx]==0 && a[u.y+dy][u.x+dx]=='T'){
				v[u.y+dy][u.x+dx] = 1;
				struct point tempp;
				tempp.x = u.x+dx;
				tempp.y = u.y+dy;
				q[++rear] = tempp;
			}
		}
	}

	front = 0;
	rear = -1;
	v[D.y][D.x] = 1;
	q[++rear] = D;

	while (rear>=front){
		struct point u = q[front++];
		REP(i, 4){
			int dx = dir[i].x, dy = dir[i].y;
			if (u.x+dx>=0 && u.x+dx<m &&
				u.y+dy>=0 && u.y+dy<n &&
				v[u.y+dy][u.x+dx]==0 && a[u.y+dy][u.x+dx] == 'D'){
				v[u.y+dy][u.x+dx] = 1;
				struct point tempp;
				tempp.x = u.x+dx;
				tempp.y = u.y+dy;
				q[++rear] = tempp;
			}
		}
	}


	REP(i, n){
		REP(j, m){
			if (v[i][j]==0)
				return 0;
		}
	}
	return 1;
}

void brute_force(int i){

	if (i==u_size)
		ans += checkValid();
	else{
		a[u[i].y][u[i].x] = 'T';
		brute_force(i+1);
		a[u[i].y][u[i].x] = 'D';
		brute_force(i+1);
	}


}

int main(){

	int k;
	scanf("%d%d%d", &n, &m, &k);
	REP(i, n)
		scanf("%s", a[i]);

	REP(i, n){
		REP(j, m)
			if (a[i][j]=='U'){
				u[u_size].x = j;
				u[u_size++].y = i;
			}
	}

	brute_force(0);
	printf("%d\n", ans);
	sp;
	return 0;
}

//Solved