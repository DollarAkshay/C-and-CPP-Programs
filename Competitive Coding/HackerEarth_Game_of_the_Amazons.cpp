/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/bot-challenge-india-hacks-2016/multiplayer/amazons/

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
#include <random>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define ll long long

#define BOTS 4
#define SIZE 10
#define SIZE_EX 12
#define HASH_SIZE 1000000
#define HASH_OFFSET 1000

#define TIME_LIMIT 90000
#define RANDOM_SEED 26640195

#define BLOCK_SCORE 100
#define WIN_SCORE 100000

#define CELLS_MULTIPLIER 60
#define DEPTH_MULTIPLIER 5
#define FILL_MULTIPLIER 1000
#define MOVES_MULTIPLIER 20
#define RING_MULTIPLIER 10

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

struct Move {
	bool maximizingPlayer;
	int amazon;
	point src, dest, shot;

	Move() {
		amazon = -1;
		src = point(-1, -1);
		dest = point(-1, -1);
		shot = point(-1, -1);
	}
	Move(bool maxPlayer, int bot, point start, point end, point arrow) {
		maximizingPlayer = maxPlayer;
		amazon = bot;
		src = start;
		dest = end;
		shot = arrow;
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
	int turn;
	int board[SIZE_EX][SIZE_EX];
	vector<point> player, opponent;
};

const int MIN = 1<<31;
const int MAX = ~0 - MIN;
const int off = 1;
const point offset = { 1, 1 }, invalid = { -1, -1 };
const point dir[] = {
	{ -1, -1 },{ 0, -1 },{ 1, -1 },
	{ -1,  0 },{ 0,  0 },{ 1,  0 },
	{ -1,  1 },{ 0,  1 },{ 1,  1 },
};

bool independence;
int player, opponent, maxDepth;
int nodesEvaluated = 0, hashEntries = 0;
float maxDepthReached;
ScoredMove bestScoredMoveOverall;
GameState original;
clock_t time_elapsed;

bool maxCompare(ScoredMove lhs, ScoredMove rhs) {
	if (lhs.score.depth==-1 && rhs.score.depth==-1) {
		return false;
	}
	else if (lhs.score.depth==-1 && rhs.score.depth>=0) {
		return false;
	}
	else if (lhs.score.depth>=0 && rhs.score.depth==-1) {
		return true;
	}
	else {
		return lhs.score > rhs.score;
	}
}

bool minCompare(ScoredMove lhs, ScoredMove rhs) {
	if (lhs.score.depth==-1 && rhs.score.depth==-1) {
		return false;
	}
	else if (lhs.score.depth==-1 && rhs.score.depth>=0) {
		return false;
	}
	else if (lhs.score.depth>=0 && rhs.score.depth==-1) {
		return true;
	}
	else {
		return lhs.score < rhs.score;
	}
}

void printBestMove(GameState &game) {

	point AmazonSource = bestScoredMoveOverall.move.src-offset;
	point AmazonDestination = bestScoredMoveOverall.move.dest-offset;
	point ArrowMove = bestScoredMoveOverall.move.shot-offset;

	printf("%d %d\n", AmazonSource.y, AmazonSource.x);
	printf("%d %d\n", AmazonDestination.y, AmazonDestination.x);
	printf("%d %d\n", ArrowMove.y, ArrowMove.x);

	//Extra Debug Statements
	printf(" D=%.4f ", maxDepthReached);
	printf(" N=%d ", nodesEvaluated);
	printf(" V=%d \n", bestScoredMoveOverall.score.value);
	if (bestScoredMoveOverall.score.value>90000)
		printf(" I win ^_^ ?\n");
	else if (bestScoredMoveOverall.score.value<-90000)
		printf(" I loose -_- ?\n");
}

inline void checkTime(GameState &game) {

	if (((double)clock()-time_elapsed)/CLOCKS_PER_SEC >= TIME_LIMIT) {
		printBestMove(game);
		printf("FE\n");
		sp;
		exit(EXIT_SUCCESS);
	}

}

// *** Functions Related to Score Evaluation  ***

inline bool hasEnemyNeighbour(GameState &game, point p, bool maximizingPlayer) {

	if (maximizingPlayer) {
		REP(i, BOTS) {
			if (max(abs(game.opponent[i].x-p.x), abs(game.opponent[i].y-p.y))<=1)
				return true;
		}
		return false;
	}
	else {
		REP(i, BOTS) {
			if (max(abs(game.player[i].x-p.x), abs(game.player[i].y-p.y))<=1)
				return true;
		}
		return false;
	}

}

inline int getRingNumber(point p) {
	p -= offset;
	int r = max(min(abs(p.x-4), abs(p.x-5)), min(abs(p.y-4), abs(p.y-5)));
	return min(4-r, r);
}

pair<int, int> getAreaControlled(GameState &game) {

	independence = true;
	int run = 0;
	int cellsinRun[100];
	int v[SIZE_EX][SIZE_EX];
	MS0(v);

	REP(i, SIZE_EX) {
		REP(j, SIZE_EX) {
			if (v[i][j]==0 && i>=off && j>=off && i<SIZE_EX-off && j<SIZE_EX-off) {

				point src = { j, i };
				queue<point> q;
				run++;
				cellsinRun[run] = 0;
				v[src.y][src.x] = run;

				if (game.board[src.y][src.x]!=-1)
					q.push(src);
				if (game.board[src.y][src.x]==0)
					cellsinRun[run]++;

				while (!q.empty()) {
					point p = q.front();
					q.pop();
					REP(i, 9) {
						point dest = p + dir[i];
						if (v[dest.y][dest.x]==0) {
							if (game.board[dest.y][dest.x]==0) {
								q.push(dest);
								v[dest.y][dest.x] = run;
								cellsinRun[run]++;
							}
							else if (game.board[dest.y][dest.x]!=-1) {
								v[dest.y][dest.x] = run;
							}
						}
					}
				}
			}
		}
	}

	bool runIncluded[2][100];
	MS0(runIncluded);
	pair<int, int> res(0, 0);
	REP(i, 4) {
		int r = v[game.player[i].y][game.player[i].x];
		if (runIncluded[0][r] == 0) {
			res.first += cellsinRun[r];
			runIncluded[0][r] = 1;
		}
	}
	REP(i, 4) {
		int r = v[game.opponent[i].y][game.opponent[i].x];
		if (runIncluded[1][r] == 0) {
			res.second += cellsinRun[r];
			runIncluded[1][r] = 1;
			if (runIncluded[0][r]==1)
				independence = false;
		}

	}

	return res;

}

inline int countPossiblePoints(GameState &game, point p) {

	int res = 0;
	REP(i, 9) {
		if (i==4)
			continue;
		point move = p + dir[i];
		while (game.board[move.y][move.x]==0) {
			res++;
			move += dir[i];
		}
	}
	return res;

}

inline bool playerStuck(GameState &game, bool maximizingPlayer) {

	if (maximizingPlayer) {
		REP(i, 4) {
			REP(j, 9) {
				point neighbour = game.player[i]+dir[j];
				if (game.board[neighbour.y][neighbour.x] == 0)
					return false;
			}
		}
		return true;
	}
	else {
		REP(i, 4) {
			REP(j, 9) {
				point neighbour = game.opponent[i]+dir[j];
				if (game.board[neighbour.y][neighbour.x] == 0)
					return false;
			}
		}
		return true;
	}
}

inline bool AmazonStuck(GameState &game, int amazon, bool maximizingPlayer) {

	if (maximizingPlayer) {
		REP(i, 9) {
			if (i==4)
				continue;
			point neighbour = game.player[amazon]+dir[i];
			if (game.board[neighbour.y][neighbour.x] != -1)
				return false;
		}
		return true;
	}
	else {
		REP(i, 9) {
			if (i==4)
				continue;
			point neighbour = game.opponent[amazon]+dir[i];
			if (game.board[neighbour.y][neighbour.x] != -1)
				return false;
		}
		return true;
	}
}

inline int evaluate(GameState &game) {

	nodesEvaluated++;
	pair<int, int> areaControlled = getAreaControlled(game);
	if(independence)
		return (areaControlled.first - areaControlled.second)*FILL_MULTIPLIER;

	int maxScore = 0, minScore = 0;

	REP(i, 4) {
		int moves = countPossiblePoints(game, game.player[i]);
		maxScore += moves*MOVES_MULTIPLIER;
		if (moves==0 && AmazonStuck(game, i, true))
			maxScore -= BLOCK_SCORE;
		maxScore += RING_MULTIPLIER*getRingNumber(game.player[i]);
	}
	maxScore += areaControlled.first*CELLS_MULTIPLIER;

	REP(i, 4) {
		int moves = countPossiblePoints(game, game.opponent[i]);
		minScore += moves*MOVES_MULTIPLIER;
		if (moves==0 && AmazonStuck(game, i, false))
			minScore -= BLOCK_SCORE;
		minScore += RING_MULTIPLIER*getRingNumber(game.opponent[i]);
	}
	minScore += areaControlled.second*CELLS_MULTIPLIER;

	return maxScore - minScore;

}

// *** Functions Related to Moves and Move Genereation  ***

inline void makeAmazonMove(GameState &game,const point &amazon, point dest, bool maximizingPlayer) {

	if (maximizingPlayer) {
		game.board[amazon.y][amazon.x] = 0;
		game.board[dest.y][dest.x] = player;
	}
	else {
		game.board[amazon.y][amazon.x] = 0;
		game.board[dest.y][dest.x] = opponent;
	}

}

inline void undoAmazonMove(GameState &game,const point &amazon, point dest, bool maximizingPlayer) {

	if (maximizingPlayer) {
		game.board[amazon.y][amazon.x] = player;
		game.board[dest.y][dest.x] = 0;
	}
	else {
		game.board[amazon.y][amazon.x] = opponent;
		game.board[dest.y][dest.x] = 0;
	}

}

inline void makeMove(GameState &game, const Move &move) {

	if (move.maximizingPlayer) {
		//Amazon Move
		game.board[move.src.y][move.src.x] = 0;
		game.player[move.amazon] = move.dest;
		game.board[move.dest.y][move.dest.x] = player;
		//Arrow Shot
		game.board[move.shot.y][move.shot.x] = -1;
	}
	else {
		//Amazon Move
		game.board[move.src.y][move.src.x] = 0;
		game.opponent[move.amazon] = move.dest;
		game.board[move.dest.y][move.dest.x] = opponent;
		//Arrow Shot
		game.board[move.shot.y][move.shot.x] = -1;
	}


}

inline void undoMove(GameState &game, const Move &move) {

	if (move.maximizingPlayer) {
		//Arrow Shot
		game.board[move.shot.y][move.shot.x] = 0;
		//Amazon Move
		game.board[move.dest.y][move.dest.x] = 0;
		game.player[move.amazon] = move.src;
		game.board[move.src.y][move.src.x] = player;
	}
	else {
		//Arrow Shot
		game.board[move.shot.y][move.shot.x] = 0;
		//Amazon Move
		game.board[move.dest.y][move.dest.x] = 0;
		game.opponent[move.amazon] = move.src;
		game.board[move.src.y][move.src.x] = opponent;
	}

}

vector<point> generatePossiblePoints(GameState &game, point p) {

	vector<point> res;
	REP(i, 9) {
		if (i==4)
			continue;
		point move = p + dir[i];
		while (game.board[move.y][move.x]==0) {
			res.push_back(move);
			move += dir[i];
		}
	}
	return res;
}

void generateMovesAggressive(GameState &game, vector<Move> &scoredmoveList, bool maximizingPlayer) {

	scoredmoveList.clear();
	if (maximizingPlayer) {
		REP(i, BOTS) {
			vector<point> possibleMoves = generatePossiblePoints(game, game.player[i]);
			REP(pm, possibleMoves.size()) {
				makeAmazonMove(game, game.player[i], possibleMoves[pm], maximizingPlayer);
				vector<point> possibleShots = generatePossiblePoints(game, possibleMoves[pm]);
				undoAmazonMove(game, game.player[i], possibleMoves[pm], maximizingPlayer);
				REP(ps, possibleShots.size()) {
					if (hasEnemyNeighbour(game, possibleShots[ps], maximizingPlayer)) {
						scoredmoveList.push_back(Move(maximizingPlayer, i, game.player[i], possibleMoves[pm], possibleShots[ps]));
					}
				}
			}
		}
	}
	else {
		REP(i, BOTS) {
			vector<point> possibleMoves = generatePossiblePoints(game, game.opponent[i]);
			REP(pm, possibleMoves.size()) {
				makeAmazonMove(game, game.opponent[i], possibleMoves[pm], maximizingPlayer);
				vector<point> possibleShots = generatePossiblePoints(game, possibleMoves[pm]);
				undoAmazonMove(game, game.opponent[i], possibleMoves[pm], maximizingPlayer);
				REP(ps, possibleShots.size()) {
					if (hasEnemyNeighbour(game, possibleShots[ps], maximizingPlayer)) {
						scoredmoveList.push_back(Move(maximizingPlayer, i, game.opponent[i], possibleMoves[pm], possibleShots[ps]));
					}
				}
			}
		}
	}

}

void generateMovesAll(GameState &game, vector<Move> &scoredmoveList, bool maximizingPlayer) {

	scoredmoveList.clear();
	if (maximizingPlayer) {
		REP(i, BOTS) {
			vector<point> possibleMoves = generatePossiblePoints(game, game.player[i]);
			REP(pm, possibleMoves.size()) {
				makeAmazonMove(game, game.player[i], possibleMoves[pm], maximizingPlayer);
				vector<point> possibleShots = generatePossiblePoints(game, possibleMoves[pm]);
				undoAmazonMove(game, game.player[i], possibleMoves[pm], maximizingPlayer);
				REP(ps, possibleShots.size()) {
					scoredmoveList.push_back(Move(maximizingPlayer, i, game.player[i], possibleMoves[pm], possibleShots[ps]));
				}
			}
		}
	}
	else {
		REP(i, BOTS) {
			vector<point> possibleMoves = generatePossiblePoints(game, game.opponent[i]);
			REP(pm, possibleMoves.size()) {
				makeAmazonMove(game, game.opponent[i], possibleMoves[pm], maximizingPlayer);
				vector<point> possibleShots = generatePossiblePoints(game, possibleMoves[pm]);
				undoAmazonMove(game, game.opponent[i], possibleMoves[pm], maximizingPlayer);
				REP(ps, possibleShots.size()) {
					scoredmoveList.push_back(Move(maximizingPlayer, i, game.opponent[i], possibleMoves[pm], possibleShots[ps]));
				}
			}
		}
	}

}

Score minimax(GameState &game, int depth, int alpha, int beta, bool maximizingPlayer) {

	checkTime(game);

	// Evaluation if Leaf Node
	if (maximizingPlayer && playerStuck(game, true)) {
		return Score(-WIN_SCORE-depth*DEPTH_MULTIPLIER, depth);
	}
	else if (!maximizingPlayer && playerStuck(game, false)) {
		return Score(WIN_SCORE+depth*DEPTH_MULTIPLIER, depth);
	}
	else if (depth == 0) {
		return Score(evaluate(game), depth);
	}


	if (maximizingPlayer) {
		ScoredMove bestScoredMove = ScoredMove(Score(MIN, -1), false);
		vector<Move> scoredmoveList;

		generateMovesAggressive(game, scoredmoveList, maximizingPlayer);
		REP(i, scoredmoveList.size()) {
			if (depth == maxDepth)
				maxDepthReached = (maxDepth-1) + (float)i/scoredmoveList.size();
			makeMove(game, scoredmoveList[i]);
			Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
			undoMove(game, scoredmoveList[i]);
			if (curScore > bestScoredMove.score) {
				bestScoredMove.valid = true;
				bestScoredMove.score = curScore;
				bestScoredMove.move = scoredmoveList[i];
			}
			alpha = max(alpha, bestScoredMove.score.value);
			if (beta<=alpha)
				break;
		}

		if (bestScoredMove.valid==false) {
			generateMovesAll(game, scoredmoveList, maximizingPlayer);
			REP(i, scoredmoveList.size()) {
				if (depth == maxDepth)
					maxDepthReached = (maxDepth-1) + (float)i/scoredmoveList.size();
				makeMove(game, scoredmoveList[i]);
				Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
				undoMove(game, scoredmoveList[i]);
				if (curScore > bestScoredMove.score) {
					bestScoredMove.valid = true;
					bestScoredMove.score = curScore;
					bestScoredMove.move = scoredmoveList[i];
				}
				alpha = max(alpha, bestScoredMove.score.value);
				if (beta<=alpha)
					break;
			}
		}

		if (depth==maxDepth)
			bestScoredMoveOverall = bestScoredMove;
		bestScoredMove.score.depth++;
		return bestScoredMove.score;
	}
	else {
		ScoredMove bestScoredMove = ScoredMove(Score(MAX, -1), false);
		vector<Move> scoredmoveList;

		generateMovesAggressive(game, scoredmoveList, maximizingPlayer);
		REP(i, scoredmoveList.size()) {
			makeMove(game, scoredmoveList[i]);
			Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
			undoMove(game, scoredmoveList[i]);
			if (curScore < bestScoredMove.score) {
				bestScoredMove.valid = true;
				bestScoredMove.score = curScore;
				bestScoredMove.move = scoredmoveList[i];
			}
			beta = min(beta, bestScoredMove.score.value);
			if (beta<=alpha)
				break;
		}

		if (bestScoredMove.valid==false) {
			generateMovesAll(game, scoredmoveList, maximizingPlayer);
			REP(i, scoredmoveList.size()) {
				makeMove(game, scoredmoveList[i]);
				Score curScore = minimax(game, depth-1, alpha, beta, !maximizingPlayer);
				undoMove(game, scoredmoveList[i]);
				if (curScore < bestScoredMove.score) {
					bestScoredMove.valid = true;
					bestScoredMove.score = curScore;
					bestScoredMove.move = scoredmoveList[i];
				}
				beta = min(beta, bestScoredMove.score.value);
				if (beta<=alpha)
					break;
			}
		}
		bestScoredMove.score.depth++;
		return bestScoredMove.score;
	}

}

int main() {
	time_elapsed = clock();

	GameState game;
	int x;
	vector<point> p1, p2;

	//Reading Board Input
	game.turn = 0;
	REP(i, SIZE_EX) {
		REP(j, SIZE_EX) {
			if (i<off || j<off || i>=SIZE_EX-off || j>=SIZE_EX-off) {
				game.board[i][j] = -1;
				continue;
			}
			scanf("%d", &game.board[i][j]);
			if (game.board[i][j]==1) {
				p1.push_back(point(j, i));
			}
			else if (game.board[i][j]==2) {
				p2.push_back(point(j, i));
			}
			else if (game.board[i][j]==-1) {
				game.turn++;
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

	original = game;

	FOR(d, 1, 100) {
		maxDepth = d;
		minimax(game, maxDepth, MIN, MAX, true);
	}
	printBestMove(game);
	sp;
	return 0;

}

//Pretty Good