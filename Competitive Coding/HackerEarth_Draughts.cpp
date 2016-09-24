/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/battle-of-bots-6/multiplayer/draughts/

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
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

#define TIME_LIMIT 0.9000

#define WIN_SCORE 10000
#define LOSE_SCORE -10000

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
	inline void operator /=(const int &val) {
		x /= val;
		y /= val;
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

struct Move {
	bool isjump;
	point src, dest;
	vector<point> jumps;

	Move() {
	}
	Move(bool isjumpin, point srcin, point destin) {
		isjump = isjumpin;
		src = srcin;
		dest = destin;
	}
	Move( bool isjumpin, point srcin, vector<point> jumpsin) {
		isjump = isjumpin;
		src = srcin;
		jumps = jumpsin;
	}
};

struct Score {
	int value, depth;
	Score() {
		value = 0;
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
	Move move;
	bool valid;
	ScoredMove() {
		valid = false;
	}
	ScoredMove(Move m, Score s, bool v) {
		valid = v;
		move = m;
		score = s;
	}
	ScoredMove(Score s, bool v) {
		valid = v;
		score = s;
	}
	inline bool operator >(const ScoredMove &rhs) const {
		return score>rhs.score;
	}
	inline bool operator <(const ScoredMove &rhs) const {
		return score<rhs.score;
	}
};

struct GameState {
	int board[8][8];
};

const int MIN = 1<<31;
const int MAX = ~0 - MIN;

int player, opponent, maxDepth;
int nodesEvaluated = 0;
float maxDepthReached;

Move curJump;
ScoredMove bestScoredMoveOverall;
clock_t time_elapsed;


vector<Move> jumps;

void printBestMove() {

	Move bestmove = bestScoredMoveOverall.move;

	if (bestmove.isjump) {
		printf("%d %d\n", bestmove.src.y, bestmove.src.x);
		printf("%d\n", bestmove.jumps.size());
		REP(i, bestmove.jumps.size()) {
			printf("%d %d\n", bestmove.jumps[i].y, bestmove.jumps[i].x);
		}
	}
	else {
		printf("%d %d\n1\n", bestmove.src.y, bestmove.src.x);
		printf("%d %d\n", bestmove.dest.y, bestmove.dest.x);
	}


	//Extra Debug Statements
	printf(" D=%.2f ", maxDepthReached);
	printf(" N=%d ", nodesEvaluated);
	printf(" V=%d \n", bestScoredMoveOverall.score.value);
	if (bestScoredMoveOverall.score.value > 9000) {
		printf("I WIN ^_^ \n");
	}
	if (bestScoredMoveOverall.score.value < -9000) {
		printf("I LOOSE T_T \n");
	}
}

inline void checkTime() {

	if (((double)clock()-time_elapsed)/CLOCKS_PER_SEC >= TIME_LIMIT) {
		printBestMove();
		printf("FE\n");
		sp;
		exit(EXIT_SUCCESS);
	}

}

// *** Functions Related to Moves and Move Genereation  ***

void doJump(GameState &game, point src, point  dest) {

	point pivot = dest-src;
	pivot /= 2;
	pivot += src;

	game.board[dest.y][dest.x] = game.board[src.y][src.x];
	game.board[src.y][src.x] = 0;
	game.board[pivot.y][pivot.x] = 0;

}

void doMove(GameState &game, Move move) {

	if (move.isjump==false) {
		game.board[move.dest.y][move.dest.x] = game.board[move.src.y][move.src.x];
		game.board[move.src.y][move.src.x] = 0;
	}
	else {
		point src = move.src;
		REP(i, move.jumps.size()) {
			doJump(game, src, move.jumps[i]);
			src = move.jumps[i];
		}
	}

}

void undoJump(GameState &game, point src, point  dest) {

	point pivot = dest-src;
	pivot /= 2;
	pivot += src;

	game.board[src.y][src.x] = game.board[dest.y][dest.x];
	game.board[dest.y][dest.x] = 0;
	game.board[pivot.y][pivot.x] = game.board[src.y][src.x]==1 ? 2 : 1;

}

void undoMove(GameState &game, Move move) {

	if (move.isjump==false) {
		game.board[move.src.y][move.src.x] = game.board[move.dest.y][move.dest.x];
		game.board[move.dest.y][move.dest.x] = 0;
	}
	else {
		point dest = move.jumps[move.jumps.size()-1];

		FORD(i, move.jumps.size()-2, 0 ) {
			undoJump(game, move.jumps[i], dest);
			dest = move.jumps[i];
		}
		undoJump(game, move.src, dest);
	}
}

bool canJumpTo(GameState &game, point src, point dest) {

	point pivot = dest-src;
	pivot /= 2;
	pivot += src;

	if (dest.x >=0 && dest.x <=7 && dest.y>=0 && dest.y<=7 &&
		game.board[dest.y][dest.x]==0 && game.board[pivot.y][pivot.x]!=0 &&
		game.board[pivot.y][pivot.x]!=game.board[src.y][src.x]) {
		return true;
	}
	else {
		return false;
	}

}

bool canMove(GameState &game, point src, point dest) {

	if (dest.x >=0 && dest.x <=7 && dest.y>=0 && dest.y<=7 &&
		game.board[dest.y][dest.x]==0) {
		return true;
	}
	else {
		return false;
	}

}

void findJumps(GameState &game, point src, int player) {

	point destl, destr;

	if (player==1) {
		destl = point(src.x-2, src.y+2);
		destr = point(src.x+2, src.y+2);
	}
	else {
		destl = point(src.x-2, src.y-2);
		destr = point(src.x+2, src.y-2);
	}

	if (!canJumpTo(game, src, destl) && !canJumpTo(game, src, destr) && curJump.jumps.size()>0) {
		jumps.push_back(curJump);
	}

	if (canJumpTo(game, src, destl)) {
		curJump.jumps.push_back(destl);
		doJump(game, src, destl);
		findJumps(game, destl, player);
		undoJump(game, src, destl);
		curJump.jumps.pop_back();
	}

	if (canJumpTo(game, src, destr)) {
		curJump.jumps.push_back(destr);
		doJump(game, src, destr);
		findJumps(game, destr, player);
		undoJump(game, src, destr);
		curJump.jumps.pop_back();
	}

}

vector<Move> generateMoves(GameState &game, int playerID) {

	vector<Move> moveList;

	// Jumps
	REP(i, 8) {
		REP(j, 8) {
			if (game.board[i][j]==playerID) {
				point src = point(j, i);
				curJump.src = src;
				curJump.isjump = true;
				findJumps(game, src, playerID);
				moveList.insert(moveList.end(), jumps.begin(), jumps.end());
				jumps.clear();
			}
		}
	}

	// Simple diagonal Moves
	REP(i, 8) {
		REP(j, 8) {
			if (game.board[i][j]==playerID) {
				point src = point(j, i);
				point destl, destr;

				if (playerID==1) {
					destl = point(src.x-1, src.y+1);
					destr = point(src.x+1, src.y+1);
				}
				else {
					destl = point(src.x-1, src.y-1);
					destr = point(src.x+1, src.y-1);
				}

				if (canMove(game, src, destl)) {
					moveList.push_back(Move(false, src, destl));
				}
				if (canMove(game, src, destr)) {
					moveList.push_back(Move(false, src, destr));
				}
			}
		}
	}

	return moveList;

}

// *** Functions Related to Score Evaluation  ***

int evaluate(GameState &game) {

	nodesEvaluated++;
	int score = 0;

	REP(i, 8) {
		REP(j, 8) {
			if (game.board[i][j] == player) {
				score++;
			}
			if (game.board[i][j] == opponent) {
				score--;
			}
		}
	}

	return score;

}

int countPiecesDiff(GameState &game) {


	int diff = 0;

	REP(i, 8) {
		REP(j, 8) {
			if (game.board[i][j] == player) {
				diff++;
			}
			if (game.board[i][j] == opponent) {
				diff--;
			}
		}
	}

	return diff;
}

Score minimax(GameState &game, int depth, int alpha, int beta, bool maximizingPlayer) {

	checkTime();

	if (depth==0) {
		return Score(evaluate(game), depth); 
	}


	if (maximizingPlayer) {

		ScoredMove bestScoredMove = ScoredMove( Score(MIN, -1), false);
		vector<Move> moveList = generateMoves(game, player);

		if (moveList.size()==0) {
			int pieces = countPiecesDiff(game);
			if (pieces<0) {
				return Score(LOSE_SCORE+evaluate(game), depth);
			}
			else if (pieces>0) {
				return Score(WIN_SCORE+evaluate(game), depth);
			}
			else {
				return Score(0, depth);
			}
		}

		REP(i, moveList.size()) {

			if (depth == maxDepth)
				maxDepthReached = (maxDepth-1) + (float)i/moveList.size();

			doMove(game, moveList[i]);
			Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
			undoMove(game, moveList[i]);

			if (curScore > bestScoredMove.score) {
				bestScoredMove.valid = true;
				bestScoredMove.score = curScore;
				bestScoredMove.move = moveList[i];
			}
			alpha = max(alpha, bestScoredMove.score.value);
			if (beta<=alpha)
				break;
		}

		if (depth == maxDepth) {
			bestScoredMoveOverall = bestScoredMove;
		}

		return bestScoredMove.score;

	}
	else {

		ScoredMove bestScoredMove = ScoredMove(Score(MAX, -1), false);
		vector<Move> moveList = generateMoves(game, opponent);

		if (moveList.size()==0) {
			int pieces = countPiecesDiff(game);
			if (pieces<0) {
				return Score(LOSE_SCORE+evaluate(game), depth);
			}
			else if (pieces>0) {
				return Score(WIN_SCORE+evaluate(game), depth);
			}
			else {
				return Score(0, depth);
			}
		}

		REP(i, moveList.size()) {
			doMove(game, moveList[i]);
			Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
			undoMove(game, moveList[i]);

			if (curScore < bestScoredMove.score) {
				bestScoredMove.valid = true;
				bestScoredMove.score = curScore;
				bestScoredMove.move = moveList[i];
			}
			beta = min(beta, bestScoredMove.score.value);
			if (beta<=alpha)
				break;
		}

		return bestScoredMove.score;
	}

}

int main() {

	time_elapsed = clock();

	GameState game;

	REP(i, 8) {
		REP(j, 8) {
			scanf("%d", &game.board[i][j]);

		}
	}
	scanf("%d", &player);

	opponent = player==1 ? 2 : 1;

	FOR(d, 5, 40) {
		maxDepth = d;
		minimax(game, maxDepth, MIN, MAX, true);
	}
	
	printBestMove();
	sp;
	return 0;
}

//Looks good :)