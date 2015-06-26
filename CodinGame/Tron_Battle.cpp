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
	point(){
		x = 0;
		y = 0;
	}
	point(int px,int py){
		x = px;
		y = py;
	}
};

clock_t t;
int board[22][32];
const int MAX_DEPTH = 50;
int n, me, x, y;
bool removed[5];
point p[5];
point dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };


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
		return "INVALID";
	else
		return possibleMoves[rand()%size];


}

int evaluateBoard(){
	
	int openSpace = 0;
	int board_copy[22][32];
	REP(i, 22)
		memcpy(board_copy[i], board[i],32*sizeof(board[i][0]));

	queue<pair<point,int>> q;
	pair<point,int> u;
	board_copy[y][x] = 1;
	q.push(make_pair(point(x, y), 1));

	while (!q.empty()){
		u = q.front();
		q.pop();
		REP(i, 4){
			int ty = u.first.y + dir[i].y, tx = u.first.x + dir[i].x;
			if (board_copy[ty][tx] == 0 && u.second<MAX_DEPTH){
				q.push(make_pair(point(tx, ty), u.second+1));
				board_copy[ty][tx] = 1;
				openSpace++;
			}
		}
	}
	return openSpace;
}

string getMove(){
	
	pair<string, int> score;
	score.first = "Haters,gonna HATE HATE HATE HATE baby... :)";
	score.second = 0;
	if (board[y][x + 1] == 0){
		board[y][++x] = me;
		int val = evaluateBoard();
		DB("Right has a score of %d\n", val);
		if (val > score.second){
			score.second = val;
			score.first = "RIGHT";
		}
		board[y][x--] = 0;
	}
	if (board[y][x - 1] == 0){
		board[y][--x] = me;
		int val = evaluateBoard();
		DB("Left has a score of %d\n", val);
		if (val > score.second){
			score.second = val;
			score.first = "LEFT";
		}
		board[y][x++] = 0;
	}
	if (board[y + 1][x] == 0){
		board[++y][x] = me;
		int val = evaluateBoard();
		DB("Down has a score of %d\n", val);
		if (val > score.second){
			score.second = val;
			score.first = "DOWN";
		}
		board[y--][x] = 0;
	}
	if (board[y - 1][x] == 0){
		board[--y][x] = me;
		int val = evaluateBoard();
		DB("Up has a score of %d\n", val);
		if (val > score.second){
			score.second = val;
			score.first = "UP";
		}
		board[y++][x] = 0;
	}

	return score.first;
}

void printMove(string s){
	printf("%s\n",s.c_str());
}

void removePlayer(int p){

	if (removed[p] == 1)
		return;

	REP(i, 22){
		REP(j, 32)
			if (board[i][j] == p)
				board[i][j] = 0;
	}
	removed[p] = 1;

}

int main(){

	init();
	while (1){
		t = clock();
		scanf("%d %d", &n, &me);
		me++;
		FOR(i, 1, n){
			int x, y;
			scanf("%d %d %d %d", &x, &y, &p[i].x, &p[i].y);
			if (x == -1)
				removePlayer(i);
			p[i].x++;
			p[i].y++;
		}
		updateBoard();
		debug(1, 1, 1);
		string move = getMove();
		printMove(move);
		t = clock() - t;
		DB("Time per round = %f ms \n", (float)t*100 / CLOCKS_PER_SEC);
	}

	return 0;
}

//