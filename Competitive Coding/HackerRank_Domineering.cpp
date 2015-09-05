/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/domineering

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
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

#define MIN (1<<31)
#define MAX (~0 - MIN)

#define SIZE 8
#define BOARD_SIZE 10



struct point {
	int x, y;
};

struct GameState {
	char board[BOARD_SIZE][BOARD_SIZE];
	void addMove(point p, char player) {
		if (player=='v') {
			board[p.y][p.x] = player;
			board[p.y+1][p.x] = player;
		}
		else {
			board[p.y][p.x] = player;
			board[p.y][p.x+1] = player;
		}
	}
};

int MAX_DEPTH = 4;
char player, opponent;
int turn, calls[100], totalCalls;

bool canPlace(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char type) {
	if (type=='v') {
		if (y>=0 && y<SIZE-1 && board[y][x]=='-' && board[y+1][x]=='-')
			return true;
		else
			return false;
	}
	else {
		if (x>=0 && x<SIZE-1 && board[y][x]=='-' && board[y][x+1]=='-')
			return true;
		else
			return false;
	}
}

vector<point> getMoves(GameState g, char player) {

	vector<point> moves;
	REP(i, SIZE) {
		REP(j, SIZE) {
			if (canPlace(g.board, j, i, player))
				moves.push_back({ j,i });
		}
	}
	return moves;

}

int evaluate(vector<point> &movesMax, vector<point> &movesMin, bool maximizingPlayer) {

	if (maximizingPlayer && movesMax.size()==0)
		return -100 - movesMin.size();
	else if (!maximizingPlayer && movesMin.size()==0)
		return 100 + movesMax.size();
	else
		return movesMax.size() - movesMin.size();

}

int minimax(GameState node, int depth, int alpha, int beta, bool maximizingPlayer) {

	calls[depth]++;
	vector<point> movesMax = getMoves(node, player);
	vector<point> movesMin = getMoves(node, opponent);

	if (depth == MAX_DEPTH || (maximizingPlayer && movesMax.size()==0) || (!maximizingPlayer && movesMin.size()==0)) {
		return evaluate(movesMax, movesMin, maximizingPlayer);
	}

	if (maximizingPlayer) {
		int val = MIN;
		REP(i, movesMax.size()) {
			GameState child = node;
			child.addMove(movesMax[i], player);
			val = max(val, minimax(child, depth+1, alpha, beta, !maximizingPlayer));
			alpha = max(alpha, val);
			if (beta<=alpha)
				break;
		}
		return val;
	}
	else {
		int val = MAX;
		REP(i, movesMin.size()) {
			GameState child = node;
			child.addMove(movesMin[i], opponent);
			val = min(val, minimax(child, depth+1, alpha, beta, !maximizingPlayer));
			beta = min(beta, val);
			if (beta<=alpha)
				break;
		}
		return val;
	}
}

point getBestMove(GameState g) {


	MAX_DEPTH = 4;
	DB("Max Tree Depth = %d\n", MAX_DEPTH);

	int maxVal = MIN;
	point bestMoves;
	vector<point> possibleMoves = getMoves(g, player);

	REP(i, possibleMoves.size()) {
		GameState child = g;
		child.addMove(possibleMoves[i], player);
		int moveVal = minimax(child, 1, maxVal, MAX, false);
		if (moveVal>maxVal) {
			maxVal = moveVal;
			bestMoves = possibleMoves[i];
		}
	}
	if (maxVal>=100)
		DB("I WON !! I WON !! :D\n");
	else if (maxVal>0)
		DB("You might loose :P\n");
	else if (maxVal<=-100)
		DB("I LOST :'( \n");

	return bestMoves;
}

int main() {

	GameState original;
	scanf("%c", &player);
	opponent = player=='h'?'v':'h';

	REP(i, SIZE) {
		getchar();
		scanf("%s", original.board[i]);
		REP(j, SIZE) {
			if (original.board[i][j]!='-')
				turn++;
		}
	}
	turn /= 2;
	DB("Turn No : %d\n", turn);
	clock_t t = clock();
	point move = getBestMove(original);
	printf("%d %d\n", move.y, move.x);
	t = clock() - t;
	DB("Time Taken = %lf\n", (double)t/CLOCKS_PER_SEC);

	DB("\nFunction Calls :");
	FOR(i, 1, 100) {
		totalCalls += calls[i];
		if (calls[i]==0)
			break;
		else
			DB("%d, ", calls[i]);
	}
	DB("\nTotal Function Calls : %d\n", totalCalls);
	sp;
	return 0;
}

//My algo looks pretty damn good :)