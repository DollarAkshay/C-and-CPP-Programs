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

#define SIZE 8
#define SIZE_EX 10

#define TIME_LIMIT 1.9

#define WIN_SCORE 100000

#define DEPTH_MULTIPLIER 1

struct point {
	int x, y;
	point() {
		x = 0;
		y = 0;
	}
	point(int px, int py) {
		x = px;
		y = py;
	}
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
	inline point operator *(const int &val) {
		point t = *this;
		t *= val;
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
	inline void operator *=(const int &val) {
		x *= val;
		y *= val;
	}
	inline bool operator ==(const point &lhs) const {
		return x==lhs.x && y==lhs.y;
	}
	inline bool operator !=(const point &lhs) const {
		return x!=lhs.x || y!=lhs.y;
	}
	inline double distance(const point &lhs) const {
		return sqrt((x-lhs.x)*(x-lhs.x)+(y-lhs.y)*(y-lhs.y));
	}
};

struct Score {
	int value, depth;
	Score() {
		depth = -1;
	}
	Score(int v, int d) {
		value = v;
		depth = d;
	}
	inline bool operator >(const Score &rhs) const {
		return (value>rhs.value) || (value==rhs.value && depth>rhs.depth);
	}
	inline bool operator <(const Score &rhs) const {
		return (value<rhs.value) || (value==rhs.value && depth<rhs.depth);
	}
};

struct ScoredMove {
	Score score;
	point move;
	ScoredMove() {

	}
	ScoredMove(Score s, point p) {
		score = s;
		move = p;
	}
	ScoredMove(Score s) {
		score = s;
	}
};

struct GameState {
	int turn;
	int movesLeftPlayer, movesLeftOpponent;
	int playerMoves[SIZE_EX][SIZE_EX];
	int opponentMoves[SIZE_EX][SIZE_EX];
	char board[SIZE_EX][SIZE_EX];
};

const int MIN = 1<<31;
const int MAX = ~0 - MIN;
const point offset = { 1, 1 };

char player, opponent;
int maxDepth;
int nodesEvaluated;
float maxDepthReached;
clock_t time_elapsed;
ScoredMove bestMoveOverall;

inline void printBestMove() {

	printf("%d %d\n", bestMoveOverall.move.y-offset.y, bestMoveOverall.move.x-offset.x);

	//Extra Debug Statements
	DB("D=%.4f ", maxDepthReached);
	DB("N=%d ", nodesEvaluated);
	DB("V=%d \n", bestMoveOverall.score.value);
	if (bestMoveOverall.score.value>WIN_SCORE*0.9)
		DB("I win ^_^ ?\n");
	else if (bestMoveOverall.score.value<-WIN_SCORE*0.9)
		DB("I loose -_- ?\n");
}

inline void checkTime() {

	if (((double)clock()-time_elapsed)/CLOCKS_PER_SEC >= TIME_LIMIT) {
		printBestMove();
		printf("FE\n");
		sp;
		exit(EXIT_SUCCESS);
	}

}

inline bool canMove(GameState &game, point m, char player) {

	if (player=='v') {
		if (m.y>=SIZE_EX-2 || (game.board[m.y][m.x]!='-' && game.board[m.y+1][m.x]!='-'))
			return false;
		if (game.board[m.y][m.x]=='-' && game.board[m.y+1][m.x]=='-')
			return true;
		else
			return false;
	}
	else {
		if (m.x>=SIZE_EX-2)
			return false;
		if (game.board[m.y][m.x]=='-' && game.board[m.y][m.x+1]=='-')
			return true;
		else
			return false;
	}

}

void preCalculateMoves(GameState &game) {

	MS0(game.playerMoves);
	MS0(game.opponentMoves);
	game.turn = 0;
	game.movesLeftPlayer = 0;
	game.movesLeftOpponent = 0;

	FOR(i, offset.y, SIZE_EX-offset.y-1) {
		FOR(j, offset.x, SIZE_EX-offset.x-1) {
			if (canMove(game, { j, i }, player)) {
				game.playerMoves[i][j] = 1;
				game.movesLeftPlayer++;
			}
			if (canMove(game, { j, i }, opponent)) {
				game.opponentMoves[i][j] = 1;
				game.movesLeftOpponent++;
			}
			if (game.board[i][j]=='v' || game.board[i][j]=='h')
				game.turn++;
		}
	}
	game.turn /= 2;
}

inline void makeMove(GameState &game, point m, bool maximizingPlayer) {

	game.turn++;

	if (maximizingPlayer) {
		if (player=='v') {
			game.playerMoves[m.y][m.x] = 0;
			game.movesLeftPlayer--;

			if (canMove(game, { m.x, m.y+1 }, player)) {
				game.playerMoves[m.y+1][m.x] = 0;
				game.movesLeftPlayer--;
			}
			if (canMove(game, { m.x, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x] = 0;
				game.movesLeftOpponent--;
			}
			if (canMove(game, { m.x, m.y+1 }, opponent)) {
				game.opponentMoves[m.y+1][m.x] = 0;
				game.movesLeftOpponent--;
			}

			if (m.x>=offset.x) {
				if (canMove(game, { m.x-1, m.y }, opponent)) {
					game.opponentMoves[m.y][m.x-1] = 0;
					game.movesLeftOpponent--;
				}
				if (canMove(game, { m.x-1, m.y+1 }, opponent)) {
					game.opponentMoves[m.y+1][m.x-1] = 0;
					game.movesLeftOpponent--;
				}
			}
			if (m.y>offset.y && canMove(game, { m.x, m.y-1 }, player)) {
				game.playerMoves[m.y-1][m.x] = 0;
				game.movesLeftPlayer--;
			}
			game.board[m.y][m.x] = player;
			game.board[m.y+1][m.x] = player;
		}
		else {
			game.playerMoves[m.y][m.x] = 0;
			game.movesLeftPlayer--;

			if (canMove(game, { m.x+1, m.y }, player)) {
				game.playerMoves[m.y][m.x+1] = 0;
				game.movesLeftPlayer--;
			}
			if (canMove(game, { m.x, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x] = 0;
				game.movesLeftOpponent--;
			}
			if (canMove(game, { m.x+1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x+1] = 0;
				game.movesLeftOpponent--;
			}

			if (m.y>=offset.y) {
				if (canMove(game, { m.x, m.y-1 }, opponent)) {
					game.opponentMoves[m.y-1][m.x] = 0;
					game.movesLeftOpponent--;
				}
				if (canMove(game, { m.x+1, m.y-1 }, opponent)) {
					game.opponentMoves[m.y-1][m.x+1] = 0;
					game.movesLeftOpponent--;
				}
			}
			if (m.x>offset.x && canMove(game, { m.x-1, m.y }, player)) {
				game.playerMoves[m.y][m.x-1] = 0;
				game.movesLeftPlayer--;
			}
			game.board[m.y][m.x] = player;
			game.board[m.y][m.x+1] = player;
		}
	}


	else {
		if (opponent=='v') {
			game.opponentMoves[m.y][m.x] = 0;
			game.movesLeftOpponent--;

			
			if (canMove(game, { m.x, m.y-1 }, opponent)) {
				game.opponentMoves[m.y+1][m.x] = 0;
				game.movesLeftOpponent--;
			}
			if (canMove(game, { m.x, m.y }, player)) {
				game.playerMoves[m.y][m.x] = 0;
				game.movesLeftPlayer--;
			}
			if (canMove(game, { m.x, m.y+1 }, player)) {
				game.playerMoves[m.y+1][m.x] = 0;
				game.movesLeftPlayer--;
			}

			if (m.x>=offset.x) {
				if (canMove(game, { m.x-1, m.y }, player)) {
					game.playerMoves[m.y][m.x-1] = 0;
					game.movesLeftPlayer--;
				}
				if (canMove(game, { m.x-1, m.y+1 }, player)) {
					game.playerMoves[m.y+1][m.x-1] = 0;
					game.movesLeftPlayer--;
				}
			}
			if (m.y>offset.y && canMove(game, { m.x, m.y-1 }, opponent)) {
				game.opponentMoves[m.y-1][m.x] = 0;
				game.movesLeftOpponent--;
			}

			game.board[m.y][m.x] = opponent;
			game.board[m.y+1][m.x] = opponent;//
		}
		else {
			game.opponentMoves[m.y][m.x] = 0;
			game.movesLeftOpponent--;
			
			if (canMove(game, { m.x+1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x+1] = 0;
				game.movesLeftOpponent--;
			}
			if (canMove(game, { m.x, m.y }, player)) {
				game.playerMoves[m.y][m.x] = 0;
				game.movesLeftPlayer--;
			}
			if (canMove(game, { m.x+1, m.y }, player)) {
				game.playerMoves[m.y][m.x+1] = 0;
				game.movesLeftPlayer--;
			}

			if (m.y>=offset.y) {
				if (canMove(game, { m.x, m.y-1 }, player)) {
					game.playerMoves[m.y-1][m.x] = 0;
					game.movesLeftPlayer--;
				}
				if (canMove(game, { m.x+1, m.y-1 }, player)) {
					game.playerMoves[m.y-1][m.x+1] = 0;
					game.movesLeftPlayer--;
				}
			}
			if (m.x>offset.x && canMove(game, { m.x-1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x-1] = 0;
				game.movesLeftOpponent--;
			}
			game.board[m.y][m.x] = opponent;
			game.board[m.y][m.x+1] = opponent;
		}
	}

}

inline void undoMove(GameState &game, point m, bool maximizingPlayer) {

	game.turn--;

	if (maximizingPlayer) {
		if (player=='v') {
			game.board[m.y][m.x] = '-';
			game.board[m.y+1][m.x] = '-';

			game.playerMoves[m.y][m.x] = 1;
			game.movesLeftPlayer++;

			if (canMove(game, { m.x, m.y+1 }, player)) {
				game.playerMoves[m.y+1][m.x] = 1;
				game.movesLeftPlayer++;
			}
			if (canMove(game, { m.x, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x] = 1;
				game.movesLeftOpponent++;
			}
			if (canMove(game, { m.x, m.y+1 }, opponent)) {
				game.opponentMoves[m.y+1][m.x] = 1;
				game.movesLeftOpponent++;
			}
			if (m.x>=offset.x) {
				if (canMove(game, { m.x-1, m.y }, opponent)) {
					game.opponentMoves[m.y][m.x-1] = 1;
					game.movesLeftOpponent++;
				}
				if (canMove(game, { m.x-1, m.y+1 }, opponent)) {
					game.opponentMoves[m.y+1][m.x-1] = 1;
					game.movesLeftOpponent++;
				}
			}
			if (m.y>offset.y && canMove(game, { m.x, m.y-1 }, player)) {
				game.playerMoves[m.y-1][m.x] = 1;
				game.movesLeftPlayer++;
			}
		}
		else {
			game.board[m.y][m.x] = '-';
			game.board[m.y][m.x+1] = '-';

			game.playerMoves[m.y][m.x] = 1;
			game.movesLeftPlayer++;

			if (canMove(game, { m.x+1, m.y }, player)) {
				game.playerMoves[m.y][m.x+1] = 1;
				game.movesLeftPlayer++;
			}
			if (canMove(game, { m.x, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x] = 1;
				game.movesLeftOpponent++;
			}
			if (canMove(game, { m.x+1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x+1] = 1;
				game.movesLeftOpponent++;
			}
			if (m.y>=offset.y) {
				if (canMove(game, { m.x, m.y-1 }, opponent)) {
					game.opponentMoves[m.y-1][m.x] = 1;
					game.movesLeftOpponent++;
				}
				if (canMove(game, { m.x+1, m.y-1 }, opponent)) {
					game.opponentMoves[m.y-1][m.x+1] = 1;
					game.movesLeftOpponent++;
				}
			}
			if (m.x>offset.x && canMove(game, { m.x-1, m.y }, player)) {
				game.playerMoves[m.y][m.x-1] = 1;
				game.movesLeftPlayer++;
			}
		}
	}
	else {
		if (opponent=='v') {
			game.board[m.y][m.x] = '-';
			game.board[m.y+1][m.x] = '-';

			game.opponentMoves[m.y][m.x] = 1;
			game.movesLeftOpponent++;

			if (canMove(game, { m.x, m.y+1 }, opponent)) {
				game.opponentMoves[m.y+1][m.x] = 1;
				game.movesLeftOpponent++;
			}
			if (canMove(game, { m.x, m.y }, player)) {
				game.playerMoves[m.y][m.x] = 1;
				game.movesLeftPlayer++;
			}
			if (canMove(game, { m.x, m.y+1 }, player)) {
				game.playerMoves[m.y+1][m.x] = 1;
				game.movesLeftPlayer++;
			}
			if (m.x>=offset.x) {
				if (canMove(game, { m.x-1, m.y }, player)) {
					game.playerMoves[m.y][m.x-1] = 1;
					game.movesLeftPlayer++;
				}
				if (canMove(game, { m.x-1, m.y+1 }, player)) {
					game.playerMoves[m.y+1][m.x-1] = 1;
					game.movesLeftPlayer++;
				}
			}
			if (m.y>offset.y && canMove(game, { m.x, m.y-1 }, opponent)) {
				game.opponentMoves[m.y-1][m.x] = 1;
				game.movesLeftOpponent++;
			}
		}
		else {
			game.board[m.y][m.x] = '-';
			game.board[m.y][m.x+1] = '-';

			game.opponentMoves[m.y][m.x] = 1;
			game.movesLeftOpponent++;

			if (canMove(game, { m.x+1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x+1] = 1;
				game.movesLeftOpponent++;
			}
			if (canMove(game, { m.x, m.y }, player)) {
				game.playerMoves[m.y][m.x] = 1;
				game.movesLeftPlayer++;
			}
			if (canMove(game, { m.x+1, m.y }, player)) {
				game.playerMoves[m.y][m.x+1] = 1;
				game.movesLeftPlayer++;
			}
			if (m.x>=offset.x) {
				if (canMove(game, { m.x, m.y-1 }, player)) {
					game.playerMoves[m.y-1][m.x] = 1;
					game.movesLeftPlayer++;
				}
				if (canMove(game, { m.x+1, m.y-1 }, player)) {
					game.playerMoves[m.y-1][m.x+1] = 1;
					game.movesLeftPlayer++;
				}
			}
			if (m.x>offset.x && canMove(game, { m.x-1, m.y }, opponent)) {
				game.opponentMoves[m.y][m.x-1] = 1;
				game.movesLeftOpponent++;
			}
		}
	}
}

inline int evaluate(GameState &game) {

	nodesEvaluated++;
	return game.movesLeftPlayer-game.movesLeftOpponent;

}

ScoredMove minimax(GameState &game, int depth, int alpha, int beta, bool maximizingPlayer) {

	checkTime();

	if (maximizingPlayer && game.movesLeftPlayer==0) {
		return ScoredMove(Score(-WIN_SCORE-depth*DEPTH_MULTIPLIER, depth));
	}
	else if (!maximizingPlayer && game.movesLeftOpponent==0) {
		return ScoredMove(Score(WIN_SCORE+depth*DEPTH_MULTIPLIER, depth));
	}
	else if (depth==0) {
		return ScoredMove(Score(evaluate(game), depth));
	}

	if (maximizingPlayer) {
		ScoredMove bestMove = ScoredMove(Score(MIN, -1));

		FOR(i, offset.y, SIZE_EX-offset.y-1) {
			FOR(j, offset.x, SIZE_EX-offset.x-1) {
				if (depth == maxDepth)
					maxDepthReached = (maxDepth-1) + (float)(i*SIZE+j)/(SIZE*SIZE);
				if (game.playerMoves[i][j]) {
					makeMove(game, { j, i }, maximizingPlayer);
					ScoredMove curMove = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
					undoMove(game, { j, i }, maximizingPlayer);
					if (curMove.score>bestMove.score) {
						bestMove.move = { j, i };
						bestMove.score = curMove.score;
					}
					alpha = max(alpha, bestMove.score.value);
					if (beta<=alpha)
						break;
				}
			}
		}

		bestMove.score.depth++;
		if (depth==maxDepth)
			bestMoveOverall = bestMove;
		return bestMove.score;
	}
	else {
		ScoredMove bestMove = ScoredMove(Score(MAX, -1));

		FOR(i, offset.y, SIZE_EX-offset.y-1) {
			FOR(j, offset.x, SIZE_EX-offset.x-1) {
				if (game.opponentMoves[i][j]) {
					makeMove(game, { j, i }, maximizingPlayer);
					ScoredMove curMove = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
					undoMove(game, { j, i }, maximizingPlayer);
					if (curMove.score<bestMove.score) {
						bestMove.move = { j, i };
						bestMove.score = curMove.score;
					}
					beta = min(beta, bestMove.score.value);
					if (beta<=alpha)
						break;
				}
			}
		}

		bestMove.score.depth++;
		return bestMove.score;
	}

}

int main() {

	time_elapsed = clock();
	GameState game;

	//Reading Player Info
	scanf("%c\n", &player);
	if (player=='v')
		opponent = 'h';
	else
		opponent = 'v';

	//Reading Board Info
	REP(i, SIZE_EX) {
		REP(j, SIZE_EX) {
			if (i<offset.y || j<offset.x || i>=SIZE_EX-offset.y || j>=SIZE_EX-offset.x) {
				game.board[i][j] = '#';
				continue;
			}
			scanf("%c", &game.board[i][j]);
			
		}
		if (i>=offset.y && i<SIZE_EX-offset.y) {
			getchar();
		}
	}

	preCalculateMoves(game);

	FOR(d, 1, 100) {
		maxDepth = d;
		minimax(game, maxDepth, MIN, MAX, true);
	}
	printBestMove();
	sp;
	return 0;
}

// Awesome Bot