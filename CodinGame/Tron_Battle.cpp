/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1523780e4028914a1b79243dce618034b7bf1b2

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

struct point{
	int x, y;
};

char board[22][32];
int n, me, x, y;
point p[5];

void debug(bool DBpos, bool DBboard, bool DBenemy){

	if (DBpos){
		fprintf(stderr, "My Positon = %d, %d\n", x, y);
	}
	if (DBboard){
		REP(i, 22){
			REP(j, 32){
				if (board[i][j])
					fprintf(stderr, "%c", board[i][j] + '0');
				else
					fprintf(stderr, " ");
			}
			fprintf(stderr, "\n");
		}
	}
	if (DBenemy){
		FOR(i,1,n){
			if (i!=me)
				fprintf(stderr, "Enemy %d @ %d, %d\n", i, p[i].x, p[i].y);
		}
	}
}

void init(){

	srand(time(NULL));

	REP(i, 32){
		board[ 0][i] = 'X'-'0';
		board[21][i] = 'X'-'0';
		if (i < 22){
			board[i][0] = 'X' - '0';
			board[i][31] = 'X' - '0';
		}
	}

}

void updateBoard(){

	FOR(i, 1, n)
		board[p[i].y][p[i].x] = i;
	x = p[me].x;
	y = p[me].y;

}

string randomMove(){

	vector<string> possibleMoves;
	if (board[y][x+1] == 0)
		possibleMoves.push_back("RIGHT");
	if (board[y][x-1] == 0)
		possibleMoves.push_back("LEFT");
	if (board[y+1][x] == 0)
		possibleMoves.push_back("DOWN");
	if (board[y-1][x] == 0)
		possibleMoves.push_back("UP");

	int size = possibleMoves.size();

	if (size == 0)
		return{ -1, -1 };
	else
		return possibleMoves[rand()%size];


}

void printMove(string s){

	printf("%s\n",s.c_str());
}

int main(){

	init();

	while (1){
		scanf("%d %d", &n, &me);
		me++;
		FOR(i, 1, n){
			int x, y;
			scanf("%d %d %d %d", &x, &y, &p[i].x, &p[i].y);
		}
		updateBoard();
		debug(1, 0, 1);
		string move = randomMove();
		printMove(move);
	}

	return 0;
}

//