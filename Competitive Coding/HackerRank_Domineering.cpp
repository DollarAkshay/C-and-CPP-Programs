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

bool canPlace(char board[SIZE][SIZE], int x, int y, char type) {
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

struct point {
	int x, y;
};

struct GameState {
	char board[SIZE][SIZE];
	int moveV[SIZE][SIZE];
	int moveH[SIZE][SIZE];
	int movesH=0, movesV=0;

	void setMoveH(int x, int y, bool val) {
		if (x>=0 && y>=0 && moveH[y][x]!=val) {
			moveH[y][x] = val;
			val==1?movesH++:movesH--;
		}
	}
	void setMoveV(int x, int y, bool val) {
		if (x>=0 && y>=0 && moveV[y][x]!=val) {
			moveV[y][x] = val;
			val==1?movesV++:movesV--;
		}
	}
	void addMove(point p, char player) {
		if (player=='v') {
			board[p.y][p.x] = player;
			board[p.y+1][p.x] = player;
			setMoveV(p.x, p.y-1, 0);
			setMoveV(p.x, p.y, 0);
			setMoveV(p.x, p.y+1, 0);
			setMoveH(p.x, p.y, 0);
			setMoveH(p.x, p.y+1, 0);
			setMoveH(p.x-1, p.y, 0);
			setMoveH(p.x-1, p.y+1, 0);
		}
		else {
			board[p.y][p.x] = player;
			board[p.y][p.x+1] = player;
			setMoveH(p.x-1, p.y, 0);
			setMoveH(p.x, p.y, 0);
			setMoveH(p.x+1, p.y, 0);
			setMoveV(p.x, p.y, 0);
			setMoveV(p.x+1, p.y, 0);
			setMoveV(p.x, p.y-1, 0);
			setMoveV(p.x+1, p.y-1, 0);
		}
	}
	void removeMove(point p, char player) {
		if (player=='v') {
			board[p.y][p.x] = '-';
			board[p.y+1][p.x] = '-';
			setMoveV(p.x, p.y-1, canPlace(board, p.x, p.y-1, 'v'));
			setMoveV(p.x, p.y, canPlace(board, p.x, p.y, 'v'));
			setMoveV(p.x, p.y+1, canPlace(board, p.x, p.y+1, 'v'));
			setMoveH(p.x, p.y, canPlace(board, p.x, p.y, 'h'));
			setMoveH(p.x, p.y+1, canPlace(board, p.x, p.y+1, 'h'));
			setMoveH(p.x-1, p.y, canPlace(board, p.x-1, p.y, 'h'));
			setMoveH(p.x-1, p.y+1, canPlace(board, p.x-1, p.y+1, 'h'));
		}
		else {
			board[p.y][p.x] = '-';
			board[p.y][p.x+1] = '-';
			setMoveH(p.x-1, p.y, canPlace(board, p.x-1, p.y, 'h'));
			setMoveH(p.x, p.y, canPlace(board, p.x, p.y, 'h'));
			setMoveH(p.x+1, p.y, canPlace(board, p.x+1, p.y, 'h'));
			setMoveV(p.x, p.y, canPlace(board, p.x, p.y, 'v'));
			setMoveV(p.x+1, p.y, canPlace(board, p.x+1, p.y, 'v'));
			setMoveV(p.x, p.y-1, canPlace(board, p.x, p.y-1, 'v'));
			setMoveV(p.x+1, p.y-1, canPlace(board, p.x+1, p.y-1, 'v'));
		}
	}
};

int MAX_DEPTH = 10;
char player, opponent;
int turn, calls[100], totalCalls;

int evaluate(GameState &game, bool maximizingPlayer) {

	if (maximizingPlayer && ((player=='v' && game.movesV==0) || (player=='h' && game.movesH==0)))
		return -100 - (player=='v'?game.movesH:game.movesV);
	else if (!maximizingPlayer && ((opponent=='v' && game.movesV==0) || (opponent=='h' && game.movesH==0)))
		return 100 + (opponent=='v'?game.movesH:game.movesV);
	else
		return player=='v'?game.movesV-game.movesH:game.movesH-game.movesV;

}

int minimax(GameState &game, int depth, int alpha, int beta, bool maximizingPlayer) {

	calls[depth]++;

	if ( depth == MAX_DEPTH || 
		(maximizingPlayer && ((player=='v' && game.movesV==0) || (player=='h' && game.movesH==0))) ||
		(!maximizingPlayer && ((opponent=='v' && game.movesV==0) || (opponent=='h' && game.movesH==0)))) {
		return evaluate(game, maximizingPlayer);
	}

	if (maximizingPlayer) {
		int val = MIN;
		REP(i, SIZE) {
			REP(j, SIZE) {
				point move = { j, i };
				if ((player=='v' && game.moveV[i][j]) || (player=='h' && game.moveH[i][j])) {
					game.addMove(move, player);
					val = max(val, minimax(game, depth+1, alpha, beta, !maximizingPlayer));
					game.removeMove(move, player);
					alpha = max(alpha, val);
					if (beta<=alpha)
						break;
				}
			}
		}
		return val;
	}
	else {
		int val = MAX;
		REP(i, SIZE) {
			REP(j, SIZE) {
				point move = { j, i };
				if ((opponent=='v' && game.moveV[i][j]) || (opponent=='h' && game.moveH[i][j])) {
					game.addMove(move, opponent);
					val = min(val, minimax(game, depth+1, alpha, beta, !maximizingPlayer));
					game.removeMove(move, opponent);
					beta = min(beta, val);
					if (beta<=alpha)
						break;
				}
			}
		}
		return val;
	}
}

point getBestMove(GameState &game) {

	int maxVal = MIN;
	point bestMove;

	REP(i,SIZE){
		REP(j, SIZE) {
			point move = { j, i };
			if ((player=='v' && game.moveV[i][j]) || (player=='h' && game.moveH[i][j])) {
				game.addMove(move, player);
				int moveVal = minimax(game, 1, maxVal, MAX, false);
				game.removeMove(move, player);
				if (moveVal>maxVal) {
					maxVal = moveVal;
					bestMove = move;
				}
			}
		}
	}

	if (maxVal>=100)
		DB("I WON !! I WON !! :D\n");
	else if (maxVal>0)
		DB("You might loose :P\n");
	else if (maxVal<=-100)
		DB("I LOST :'( \n");

	return bestMove;
}

int main() {

	GameState game;
	scanf("%c", &player);
	opponent = player=='h'?'v':'h';

	REP(i, SIZE) {
		getchar();
		scanf("%s", game.board[i]);
		REP(j, SIZE) {
			if (game.board[i][j]!='-')
				turn++;
		}
	}

	turn /= 2;
	DB("Turn No : %d\n", turn);
	MS0(game.moveH);
	MS0(game.moveV);
	REP(i, SIZE) {
		REP(j, SIZE) {
			game.setMoveH( j, i, canPlace(game.board, j, i, 'h'));
			game.setMoveV( j, i, canPlace(game.board, j, i, 'v'));
		}
	}

	
	clock_t t = clock();
	point move = getBestMove(game);
	DB("Time Taken = %lf\n", (double)(clock() - t)/CLOCKS_PER_SEC);

	printf("%d %d\n", move.y, move.x);


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

//Improved my Efficiency like crazy