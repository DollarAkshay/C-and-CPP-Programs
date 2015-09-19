/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/battle-of-bots/multiplayer/isola/

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
#define ll long long
#define SIZE 7
#define SIZE_EX 9
struct point {
	int x, y;
	inline point operator +(const point &lhs) {
		point t = *this;
		t += lhs;
		return t;
	}
	inline point operator -(const point &lhs) {
		point t = *this;
		t -= lhs;
		return t;
	}
	inline void operator +=(const point &lhs) {
		x += lhs.x;
		y += lhs.y;
	}
	inline void operator -=(const point &lhs) {
		x -= lhs.x;
		y -= lhs.y;
	}
	inline bool operator ==(const point &lhs) const {
		return x==lhs.x && y==lhs.y;
	}
	inline bool operator !=(const point &lhs) const {
		return x!=lhs.x || y!=lhs.y;
	}
};

struct GameState {
	int board[SIZE_EX][SIZE_EX];
	point player, opponent;
};


int MAX_DEPTH = 3;
int player, opponent;
const int MIN = 1<<31;
const int MAX = ~0 - MIN;
const int off = 1;
const point offset = { 1, 1 };

int maxVal = MIN;
point bestBotMove, bestCellMove;

const point dir[] =
{
	{ -1, -1 },{ 0, -1 },{ 1, -1 },
	{ -1,  0 },{ 0,  0 },{ 1,  0 },
	{ -1,  1 },{ 0,  1 },{ 1,  1 },
};

const point cell[] = {
	{ 1, 1 },{ 1,  2 },{ 1, 3 },{ 1,  4 },{ 1, 5 },{ 1,  6 },{ 1,  7 },
	{ 2, 1 },{ 2,  2 },{ 2, 3 },{ 2,  4 },{ 2, 5 },{ 2,  6 },{ 2,  7 },
	{ 3, 1 },{ 3,  2 },{ 3, 3 },{ 3,  4 },{ 3, 5 },{ 3,  6 },{ 3,  7 },
	{ 4, 1 },{ 4,  2 },{ 4, 3 },{ 4,  4 },{ 4, 5 },{ 4,  6 },{ 4,  7 },
	{ 5, 1 },{ 5,  2 },{ 5, 3 },{ 5,  4 },{ 5, 5 },{ 5,  6 },{ 5,  7 },
	{ 6, 1 },{ 6,  2 },{ 6, 3 },{ 6,  4 },{ 6, 5 },{ 6,  6 },{ 6,  7 },
	{ 7, 1 },{ 7,  2 },{ 7, 3 },{ 7,  4 },{ 7, 5 },{ 7,  6 },{ 7,  7 }
};

inline bool makeValidBotMove(GameState &game, point move, bool maximizingPlayer) {
	if (maximizingPlayer) {
		if (game.board[move.y+game.player.y][move.x+game.player.x] == 1) {
			game.board[game.player.y][game.player.x] = 1;
			game.player += move;
			game.board[game.player.y][game.player.x] = '1';
			return true;
		}
		else
			return false;
	}
	else {
		if (game.board[move.y+game.opponent.y][move.x+game.opponent.x] == 1) {
			game.board[game.opponent.y][game.opponent.x] = 1;
			game.opponent += move;
			game.board[game.opponent.y][game.opponent.x] = '2';
			return true;
		}
		else
			return false;
	}
}

inline bool makeValidCellMove(GameState &game, point move) {
	if (game.board[move.y][move.x]==1) {
		game.board[move.y][move.x] = 0;
		return true;
	}
	else
		return false;
}

inline void undoBotMove(GameState &game, point move, bool maximizingPlayer) {
	if (maximizingPlayer) {
		game.board[game.player.y][game.player.x] = 1;
		game.player -= move;
		game.board[game.player.y][game.player.x] = '1';
	}
	else {
		game.board[game.opponent.y][game.opponent.x] = 1;
		game.opponent -= move;
		game.board[game.opponent.y][game.opponent.x] = '2';
	}
}

inline void undoCellMove(GameState &game, point move) {
	game.board[move.y][move.x] = 1;
}

inline int evaluate(GameState &game) {

	int maxMov = 0, minMov = 0;
	REP(i, 9) {
		point neighbourMax = game.player+dir[i], neighbourMin = game.opponent+dir[i];
		maxMov += game.board[neighbourMax.y][neighbourMax.x];
		minMov += game.board[neighbourMin.y][neighbourMin.x];
	}
	return maxMov - minMov;

}

inline bool playerStuck(GameState &game, bool maximizingPlayer) {

	if (maximizingPlayer) {
		REP(i, 9) {
			point neighbour = game.player+dir[i];
			if (game.board[neighbour.y][neighbour.x] == 1)
				return false;
		}
		return true;
	}
	else {
		REP(i, 9) {
			point neighbour = game.opponent+dir[i];
			if (game.board[neighbour.y][neighbour.x] == 1)
				return false;
		}
		return true;
	}
}

int minimax(GameState &game, int depth, int alpha, int beta, bool maximizingPlayer) {

	// Evaluation if Leaf Node
	if (maximizingPlayer && playerStuck(game, true)) {
		return -1000+depth;
	}
	else if (!maximizingPlayer && playerStuck(game, false)) {
		return 1000-depth;
	}
	else if (depth == MAX_DEPTH) {
		return evaluate(game);
	}

	if (maximizingPlayer) {
		int val = MIN;
		REP(i, 9) {
			if (makeValidBotMove(game, dir[i], maximizingPlayer)) {
				REP(j, 49) {
					if (makeValidCellMove(game, cell[j])) {
						val = max(val, minimax(game, depth+1, alpha, beta, !maximizingPlayer));
						undoCellMove(game, cell[j]);
						alpha = max(alpha, val);
						if (beta<=alpha)
							break;
					}
				}
				undoBotMove(game, dir[i], maximizingPlayer);
			}
		}
		return val;
	}
	else {
		int val = MAX;
		REP(i, 9) {
			if (makeValidBotMove(game, dir[i], maximizingPlayer)) {
				REP(j, 49) {
					if (makeValidCellMove(game, cell[j])) {
						val = min(val, minimax(game, depth+1, alpha, beta, !maximizingPlayer));
						undoCellMove(game, cell[j]);
						beta = min(beta, val);
						if (beta<=alpha)
							break;
					}
				}
				undoBotMove(game, dir[i], maximizingPlayer);
			}
		}
		return val;
	}
}

void printBestMove(GameState &game) {

	REP(i, 9) {
		if (makeValidBotMove(game, dir[i], true)) {
			REP(j, 49) {
				if (makeValidCellMove(game, cell[j])) {
					int curVal = minimax(game, 1, maxVal, MAX, false);
					undoCellMove(game, cell[j]);
					if (curVal > maxVal) {
						maxVal = curVal;
						bestBotMove = dir[i];
						bestCellMove = cell[j];
					}
				}
			}
			undoBotMove(game, dir[i], true);
		}
	}

	point BotMove = bestBotMove+game.player-offset;
	point CellMove = bestCellMove-offset;
	printf("%d %d\n", BotMove.y, BotMove.x);
	printf("%d %d\n", CellMove.y, CellMove.x);

}

int main() {

	GameState game;
	int x;
	point p1, p2;

	//Reading Board Input
	REP(i, SIZE_EX) {
		REP(j, SIZE_EX) {
			if (i<off || j<off || i>=SIZE_EX-off || j>=SIZE_EX-off) {
				game.board[i][j] = 0;
				continue;
			}
			scanf("%d", &x);
			if (x==-1) {
				game.board[i][j] = 0;
			}
			else if (x==0) {
				game.board[i][j] = 1;
			}
			else if (x==1) {
				p1 = { j, i };
				game.board[i][j] = '1';
			}
			else if (x==2) {
				p2 = { j, i };
				game.board[i][j] = '2';
			}
		}
	}

	//Setting Player and Opponent
	scanf("%d", &player);
	if (player==1) {
		game.player = p1;
		game.opponent = p2;
		opponent = 2;
	}
	else {
		game.player = p2;
		game.opponent = p1;
		opponent = 1;
	}

	printBestMove(game);

	sp;
	return 0;

}