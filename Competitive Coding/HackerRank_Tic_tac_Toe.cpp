/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/tic-tac-toe

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
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

char player,opp;
char Board[3][4];
int X, Y, turn=1;

void transpose(char board[3][4]){

	REP(i, 3){
		FOR(j, 0, i){
			if (i == j)
				continue;
			char t = board[i][j];
			board[i][j] = board[j][i];
			board[j][i] = t;
		}
	}
}

int checkWinLoss(char board[3][4]){

	char *ptr;
	REP(i, 3){
		ptr = strstr(board[i], "XXX");
		if (ptr)
			return player == 'X' ? 1 : -1;

		ptr = strstr(board[i], "OOO");
		if (ptr)
			return player == 'O' ? 1 : -1;
	}
	transpose(board);
	REP(i, 3){
		ptr = strstr(board[i], "XXX");
		if (ptr){
			transpose(board);
			return player == 'X' ? 1 : -1;
		}

		ptr = strstr(board[i], "OOO");
		if (ptr){
			transpose(board);
			return player == 'O' ? 1 : -1;
		}
	}

	transpose(board);
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X'){
		return player == 'X' ? 1 : -1;
	}
	else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O'){
		return player == 'O' ? 1 : -1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X'){
		return player == 'X' ? 1 : -1;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O'){
		return player == 'O' ? 1 : -1;
	}
	return 0;
}

int calcScore(char board[3][4],int lvl,int mm){

	int score = 0;
	if (mm == 0)
		score = 100;
	else
		score = -100;
	REP(i, 3){
		REP(j, 3){
			if (board[i][j] == '_'){
				board[i][j] = mm ? player : opp;
				int WL = checkWinLoss(board);
				if (WL == 1 && mm == 1 && 10 - lvl > score)
					score = 10 - lvl;
				else if (WL == -1 && mm == 0 && lvl - 10 < score)
					score = lvl - 10;
				else {
					int temp = calcScore(board,lvl+1, !mm);
					if (mm == 1 && temp > score){
						score = temp;
					}
					else if (mm == 0 && temp < score){
						score = temp;
					}
				}
				board[i][j] = '_';
			}
		}
	}
	if (score == -100 || score == 100)
		score -= score;
	return score;
}

void miniMax(){
	if (turn == 3 && player == 'X' && Board[0][0] == 'X' && Board[1][1] == 'O'){
		Y = 1;
		X = 2;
		return;
	}
	int max = -1000000,WL;
	REP(i, 3){
		REP(j, 3){
			if (Board[i][j] == '_'){
				Board[i][j] = player=='X' ? 'X' : 'O';
				WL = checkWinLoss(Board);
				if ( WL == 1){
					Y = i;
					X = j;
					return;
				}
				int calc = calcScore(Board, 1, 0);
				if (calc > max){
					max = calc;
					Y = i;
					X = j;
				}
				Board[i][j] = '_';
			}
		}
	}
}

int main(){
	cin >> player;
	cin >> Board[0] >> Board[1] >> Board[2];
	REP(i, 3) REP(j, 3) if (Board[i][j] != '_') turn++;
	if (player == 'X')
		opp = 'O';
	else
		opp = 'X';
	miniMax();
	printf("%d %d\n", Y, X);
	sp;
	return 0;
}

// 148 wins / 0 Losses / 141 Ties ... Pretty Good