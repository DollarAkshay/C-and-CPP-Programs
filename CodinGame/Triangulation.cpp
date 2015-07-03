/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

#include <stdio.h>
#include <stdlib.h>
#include <string>
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

point p, c;

int offx = 0, of
int w, h, n, x, y;
char board[10000][10000];

int dist(point a,point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

void updateBoard(point p, point c, bool warm){

	REP(i, h){
		REP(j, w){
			if (board[i][j] && dist(p, { j, i }) <= dist(c, { j, i }))
				board[i][j] = !warm;
			else if (board[i][j])
				board[i][j] = warm;
		}
	}
}

void printCentroid(){
	
	ll int n=0,sy = 0, sx = 0;
	point first = { -1, -1 };
	REP(i, h){
		REP(j, w){
			if (board[i][j]){
				if (first.x == -1){
					first.x = j;
					first.y = i;
				}
				n++;
				sy += i;
				sx += j;
			}
		}
	}

	c.y = round((double)sy / n); 
	c.x = round((double)sx / n);

	if (board[c.y][c.x])
		board[c.y][c.x] = 0;
	else{
		DB("Printing First", 0);
		c = first;
	}

	printf("%d %d\n", c.x, c.y);

}

void printMidPoint(point a, point b){

	c.x = round((a.x + b.x) / 2), c.y = round((a.y + b.y) / 2);
	if (board[c.y][c.x])
		board[c.y][c.x] = 0;
	else
		printCentroid();
	printf("%d %d\n", c.x, c.y);
}


int main(){

	char s[10];
	scanf("%d%d%d%d%d", &w, &h,&n,&c.x,&c.y);
	fprintf(stderr,"%d %d\n%d\n%d %d\n", w, h, n, c.x, c.y);
	REP(i, h)
		REP(j, w)
			board[i][j] = 1;

	if (w >= 5000)
		w /= 4;
	if (h >= 5000)
		h /= 4;

	while (1){
		scanf("%s", s);
		DB("Feedback = %s\n", s);
		if (s[0]=='W'){
			updateBoard(p,c,1);
			p = c;
			printCentroid();
		}
		else if (s[0]=='C'){
			updateBoard(p, c, 0);
			p = c;
			printCentroid();
		}
		else if (s[0]=='S'){
			p = c;
			printMidPoint(p,c);
		}
		else{
			p = c;
			printCentroid();
		}
	}
	
	return 0;
}

//