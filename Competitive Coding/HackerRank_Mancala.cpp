/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/mancala6

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

#define SIZE 6
#define INIT_COUNT 4

class GameMove {

public:
	int player, pos, value;

	GameMove() {
		pos = -1;
		value = 0;
	}
	GameMove(int ivalue) {
		player = -1;
		pos = -1;
		value = ivalue;
	}
	GameMove(int iplayer, int ipos) {
		player = iplayer;
		pos = ipos;
		value = 0;
	}
	GameMove(int iplayer, int ipos, int ivalue) {
		player = iplayer;
		pos = ipos;
		value = ivalue;
	}

	inline bool operator > (const GameMove &rhs) const {
		return value > rhs.value;
	}

	inline bool operator < (const GameMove &rhs) const {
		return value < rhs.value;
	}

};

class GameState {

public:
	int holes[2][SIZE+1];

	GameState() {

		REP(p, 2) {
			REP(i, SIZE+1) {
				if (i==0)
					holes[p][i] = 0;
				else
					holes[p][i] = INIT_COUNT;
			}
		}

	}

	bool makeMove(GameMove move) {

		int player = move.player;
		int curplayer = move.player;
		int pos = move.pos;
		int stones = holes[player][pos];

		if (stones==0) {
			DB("ERROR : No stones in this hole\n");
			return false;
		}

		if (pos==0) {
			DB("ERROR :Cant remove stones from Mancala\n");
			return false;
		}

		holes[player][pos] = 0;
		pos--;

		while (stones>0) {

			while (pos>=0 && stones>0) {
				if ((curplayer==player && pos==0) || pos!=0) {
					holes[curplayer][pos] += 1;
					stones--;
				}
				pos--;
			}

			if (stones>0) {
				curplayer = !curplayer;
				pos = SIZE;
			}
		}

		pos++;

		if (pos==0) {
			return true;
		}
		else {
			if (curplayer==player && holes[curplayer][pos]==1) {
				holes[player][0] += holes[curplayer][pos] + holes[!curplayer][SIZE+1-pos];
				holes[!curplayer][SIZE+1-pos] = 0;
				holes[curplayer][pos] = 0;
			}
			return false;
		}
	}

	void displayBoard() {


		REP(i, SIZE+2) {
			DB("+----");
		}
		DB("+\n");


		REP(i, SIZE+2) {
			DB("|    ");
		}
		DB("|\n");


		DB("|    ");
		FOR(i, 1, SIZE) {
			DB("| %2d ", holes[1][i]);
		}
		DB("|    |\n");


		REP(i, SIZE+2) {
			DB("|    ");
		}
		DB("|\n");


		DB("| %2d ", holes[1][0]);
		FOR(i, 1, SIZE) {
			DB("+----");
		}
		DB("| %2d ", holes[0][0]);
		DB("|\n");


		REP(i, SIZE+2) {
			DB("|    ");
		}
		DB("|\n");


		DB("|    ");
		FORD(i, SIZE, 1) {
			DB("| %2d ", holes[0][i]);
		}
		DB("|    |\n");


		REP(i, SIZE+2) {
			DB("|    ");
		}
		DB("|\n");

		REP(i, SIZE+2) {
			DB("+----");
		}
		DB("+\n\n\n");

	}

	bool isGameOver() {

		bool empty1 = true, empty2 = true;

		//Check Player 1
		FOR(i, 1, SIZE) {
			if (holes[0][i]>0) {
				empty1 = false;
				break;
			}
		}
		if (empty1)
			return true;

		//Check Player 2
		FOR(i, 1, SIZE) {
			if (holes[1][i]>0) {
				empty2 = false;
				break;
			}
		}
		if (empty2)
			return true;

		return false;
	}

};

int player;
int max_depth = 18;
int nodesEvaluated;



int evaluate(GameState &game) {

	int score = game.holes[player][0] - game.holes[!player][0];
	
	if (game.isGameOver()) {
		FOR(i, 1, SIZE) {
			score -= game.holes[!player][i];
			score += game.holes[player][i];
		}
	}
	if (score<=-48) {
		DB("WTF\n");
	}

	return score;

}

GameMove minimax(GameState game, int depth, int alpha, int beta, bool maximizingPlayer) {

	if (depth == 0 || game.isGameOver()) {
		return GameMove(evaluate(game));
	}


	if (maximizingPlayer) {
		GameMove bestMove = GameMove(INT32_MIN);

		FOR(i, 1, SIZE) {
			if (game.holes[player][i]>0) {
				GameState cur = game;
				GameMove move = GameMove(player, i);
				bool canPlayAgain = cur.makeMove(move);
				GameMove returnedMove = minimax(cur, depth-1, alpha, beta, canPlayAgain?maximizingPlayer:!maximizingPlayer);
				if (returnedMove > bestMove) {
					bestMove = GameMove(player, i, returnedMove.value);
				}
				alpha = max(alpha, bestMove.value);
				if (beta<=alpha) {
					break;
				}
			}
		}

		return bestMove;
	}
	else {
		GameMove bestMove = GameMove(INT32_MAX);

		FOR(i, 1, SIZE) {
			if (game.holes[!player][i]>0) {
				GameState cur = game;
				GameMove move = GameMove(!player, i);
				bool canPlayAgain = cur.makeMove(move);
				GameMove returnedMove = minimax(cur, depth-1, alpha, beta, canPlayAgain?maximizingPlayer:!maximizingPlayer);
				if (returnedMove < bestMove) {
					bestMove = GameMove(!player, i, returnedMove.value);
				}
				beta = min(beta, bestMove.value);
				if (beta<=alpha) {
					break;
				}
			}
		}

		return bestMove;
	}
		

}

int main() {

	srand(time(NULL));

	GameState game;

	scanf("%d", &player);
	player--;

	scanf("%d", &game.holes[0][0]);
	FORD(i, SIZE, 1)
		scanf("%d", &game.holes[0][i]);

	scanf("%d", &game.holes[1][0]);
	FORD(i, SIZE, 1)
		scanf("%d", &game.holes[1][i]);

	GameMove bestMove = minimax(game, max_depth, INT32_MIN, INT32_MAX, true);

	DB("BEST MOVE : \n");
	DB("pos = %d\n", bestMove.pos);
	DB("value = %d\n", bestMove.value);

	printf("%d\n", SIZE+1-bestMove.pos);

	sp;
	return 0;

}

//