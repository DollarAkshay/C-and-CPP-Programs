/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/tic-tac-toe

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
#define MIN (1<<31)
#define MAX (~0 - MIN)

struct point {
	int x, y;
};

struct GameState {
	char board[3][4];
	vector<point> availableMoves;
};

char player, opponent;
int turn;
GameState original;

bool checkPlayerWin(char board[3][4],char player) {

	REP(i, 3) {
		if ((board[0][i]==player && board[1][i]==player && board[2][i]==player) ||
			(board[i][0]==player && board[i][1]==player && board[i][2]==player))
			return true;
	}

	if ((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
		(board[0][2]==player && board[1][1]==player && board[2][0]==player))
		return true;
	else
		return false;
}

int scoreBoard(char board[3][4]) {

	if (checkPlayerWin(board, opponent))
		return -100;
	else if (checkPlayerWin(board, player))
		return 100;
	else
		return 0;

}

int minimax(GameState node, int alpha, int beta, bool maximizingPlayer) {


	int score = scoreBoard(node.board);
	if (score || node.availableMoves.size()==0)
		return score + (score<0?-1:1)*node.availableMoves.size();

	if (maximizingPlayer) {
		int value = MIN;
		REP(i, node.availableMoves.size()) {
			point move = node.availableMoves[i];
			GameState child = node;
			child.board[move.y][move.x] = player;
			child.availableMoves.erase(child.availableMoves.begin()+i);
			value = max(value, minimax(child, alpha, beta, !maximizingPlayer));
			alpha = max(value, alpha);
			if (beta<=alpha)
				break;
		}
		return value;
	}
	else {
		int value = MAX;
		REP(i, node.availableMoves.size()) {
			point move = node.availableMoves[i];
			GameState child = node;
			child.board[move.y][move.x] = opponent;
			child.availableMoves.erase(child.availableMoves.begin()+i);
			value = min(value, minimax(child, alpha, beta, !maximizingPlayer));
			beta = min(value, beta);
			if (beta<=alpha)
				break;
		}
		return value;
	}

	return 0;
}

point getBestMove() {

	int bestValue = MIN;
	point bestMove = { -1, -1 };
	REP(i, original.availableMoves.size()) {
		point move = original.availableMoves[i];
		GameState child = original;
		child.board[move.y][move.x] = player;
		child.availableMoves.erase(child.availableMoves.begin()+i);
		int moveValue = minimax(child, MIN, MAX, false);
		if (moveValue>bestValue) {
			bestMove = move;
			bestValue = moveValue;
		}
	}
	return bestMove;
}

int main() {

	scanf("%c", &player);
	opponent = player == 'X'?'O':'X';

	REP(i, 3) {
		getchar();
		REP(j, 3) {
			scanf("%c", &original.board[i][j]);
			if (original.board[i][j]=='_')
				original.availableMoves.push_back({j,i});
			else
				turn++;
		}
	}

	if (turn==0) {
		printf("1 2");
	}
	else{
		point curMove = getBestMove();
		printf("%d %d", curMove.y, curMove.x);
	}
	sp;
	return 0;
}

//Perfect Algo :)

/*
01 function alphabeta(node, depth, ?, ?, maximizingPlayer)
02      if depth = 0 or node is a terminal node
03          return the heuristic value of node
04      if maximizingPlayer
05          v := -?
06          for each child of node
07              v := max(v, alphabeta(child, depth - 1, ?, ?, FALSE))
08              ? := max(?, v)
09              if ? ? ?
10                  break (* ? cut-off *)
11          return v
12      else
13          v := ?
14          for each child of node
15              v := min(v, alphabeta(child, depth - 1, ?, ?, TRUE))
16              ? := min(?, v)
17              if ? ? ?
18                  break (* ? cut-off *)
19          return v
-----------------------------------------------------------------------------

(* Initial call *)
alphabeta(origin, depth, -?, +?, TRUE)

*/