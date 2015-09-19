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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007


struct GameMove {
	int cell, bot;
};

struct GameState {
	ll int board;
	int player, opponent;
};

const int SIZE = 4;
const int MIN = 1<<31;
const int MAX = ~0 - MIN;
int MAX_DEPTH = 6;

int player, opponent;

inline bool checkValidBotMove(GameState game, int move, bool player) {
	if (player) {
		if (move>=0 && move<=48 && game.player!=move && game.opponent!=move && abs(move%7-game.player%SIZE)<=1 && abs(move/SIZE-game.player/SIZE)<=1 && (game.board&1LL<<move))
			return true;
		else
			return false;
	}
	else {
		if (move>=0 && move<=48 && game.player!=move && game.opponent!=move && abs(move%SIZE-game.opponent%SIZE)<=1 && abs(move/SIZE-game.opponent/SIZE)<=1 && (game.board&1LL<<move))
			return true;
		else
			return false;
	}
}

inline bool checkValidCellMove(GameState game, int move) {
	if ((game.board & 1LL<<move) && move!=game.player && move!=game.opponent)
		return true;
	else
		return false;
}

inline int evaluate(GameState game, bool maximizingPlayer) {

	if (maximizingPlayer) {
		int res = 0;
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.player+i*SIZE+j;
				if (checkValidBotMove(game, newPos, maximizingPlayer))
					res++;
			}
		}
		return res;
	}
	else {
		int res = 0;
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.opponent+i*SIZE+j;
				if (checkValidBotMove(game, newPos, maximizingPlayer))
					res++;
			}
		}
		return res;
	}

}

inline bool playerStuck(GameState game, bool player) {
	if (player) {
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.player+i*SIZE+j;
				if (checkValidBotMove(game, newPos, player) && (game.board & 1LL<<newPos) && newPos!=game.opponent)
					return false;
			}
		}
		return true;
	}
	else {
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.opponent+i*SIZE+j;
				if (checkValidBotMove(game, newPos, player) && (game.board & 1LL<<newPos) && newPos!=game.player)
					return false;
			}
		}
		return true;
	}
}

int minimax(GameState game, int depth, int alpha, int beta, bool maximizingPlayer) {

	if (maximizingPlayer && playerStuck(game, true)) {
		return -100+depth;
	}
	else if (!maximizingPlayer && playerStuck(game, false)) {
		return 100-depth;
	}
	else if (depth == MAX_DEPTH) {
		return evaluate(game, maximizingPlayer);
	}

	if (maximizingPlayer) {
		int val = MIN;
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.player+i*SIZE+j;
				if (checkValidBotMove(game, newPos, maximizingPlayer)) {
					GameState cur = game;
					cur.player = newPos;
					REP(k, SIZE*SIZE) {
						if (checkValidCellMove(cur, k)) {
							cur.board ^= 1LL<<k;
							val = max(val, minimax(cur, depth+1, alpha, beta, !maximizingPlayer));
							alpha = max(alpha, val);
							if (beta<=alpha)
								break;
						}
					}
				}
			}
		}
		return val;
	}
	else {
		int val = MAX;
		FOR(i, -1, 1) {
			FOR(j, -1, 1) {
				int newPos = game.opponent+i*SIZE+j;
				if (checkValidBotMove(game, newPos, maximizingPlayer)) {
					GameState cur = game;
					cur.opponent = newPos;
					REP(k, SIZE*SIZE) {
						if (checkValidCellMove(game, k)) {
							cur.board ^= 1LL<<k;
							val = min(val, minimax(cur, depth+1, alpha, beta, !maximizingPlayer));
							beta = min(beta, val);
							if (beta<=alpha)
								break;
						}
					}
				}
			}
		}
		return val;
	}
}

void printBestMove(GameState game) {

	int maxVal = MIN;
	GameMove bestMove;
	FOR(i, -1, 1) {
		FOR(j, -1, 1) {
			int newPos = game.player+i*SIZE+j;
			if (checkValidBotMove(game, newPos, true)) {
				GameState cur = game;
				cur.player = newPos;
				REP(k, SIZE*SIZE) {
					if (checkValidCellMove(cur, k)) {
						cur.board ^= 1LL<<k;
						int curVal = minimax(cur, 1, maxVal, MAX, false);
						if (curVal > maxVal) {
							maxVal = curVal;
							bestMove.cell = k;
							bestMove.bot = newPos;
						}
					}
				}
			}
		}
	}

	printf("%d %d\n", bestMove.bot/SIZE, bestMove.bot%SIZE);
	printf("%d %d\n", bestMove.cell/SIZE, bestMove.cell%SIZE);

}

int main() {

	GameState original;
	original.board = 0;
	int x, p1, p2;
	REP(i, SIZE*SIZE) {
		scanf("%d", &x);
		if (x!=-1) {
			original.board |= 1LL<<i;
			if (x==1)
				p1 = i;
			else if (x==2)
				p2 = i;
		}
	}

	scanf("%d", &player);
	if (player==1) {
		original.player = p1;
		original.opponent = p2;
	}
	else {
		original.player = p2;
		original.opponent = p1;
	}

	printBestMove(original);

	sp;
	return 0;

}

//