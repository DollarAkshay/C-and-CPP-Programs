/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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

char player, opp;
char Board[3][4];
int bidP[10], bidO[10];
int balP=4, balO=4;
int X, Y, turn = 1,bid,gurantee;
int minS=100, maxS=-100;

char action[10];
char draw = 'X';

void getData(){

	char x;

	//Reading Player,Opponent and Action
	scanf("%c", &player);
	if (player == 'X')
		opp = 'O';
	else
		opp = 'X';
	scanf("%s",action);getchar();

	//Reading Bids of X and O
	while ((x = getchar()) != '\n'){
		if (isdigit(x)){
			if (player == 'X')
				bidP[turn++ - 1] = x - '0';
			else
				bidO[turn++ - 1] = x - '0';
		}
	}
	REP(i, turn - 1){
		if (player == 'X')
			scanf("%d", &bidO[i]);
		else
			scanf("%d", &bidP[i]);
	}

	//Reading Board
	REP(i, 3)
		scanf("%s", Board[i]);

	//Calculating Balance and whose favour the draw is in.
	REP(i, turn - 1){
		if (bidP[i] > bidO[i]){
			balP -= bidP[i];
			balO += bidP[i];
		}
		else if (bidO[i] > bidP[i]){
			balO -= bidO[i];
			balP += bidO[i];
		}
		else if (draw == 'X'){
			balP -= bidP[i];
			balO += bidP[i];
			draw = 'O';
		}
		else{
			balO -= bidO[i];
			balP += bidO[i];
			draw = 'X';
		}
	}
	
	if (draw == opp)
		gurantee = balO + 1;
	else
		gurantee = max(balO, 1);
}

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

int calcScore(char board[3][4], int lvl, int mm){

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
					int temp = calcScore(board, lvl + 1, !mm);
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
	
	int WL;
	REP(i, 3){
		REP(j, 3){
			if (Board[i][j] == '_'){
				Board[i][j] = player == 'X' ? 'X' : 'O';
				WL = checkWinLoss(Board);
				int calc;
				if (WL == 1){
					calc = 10;
				}
				else
				calc = calcScore(Board, 1, 0);
				if (calc > maxS){
					maxS = calc;
					Y = i;
					X = j;
				}
				minS = min(calc, minS);
				Board[i][j] = '_';
			}
		}
	}
}

int main(){

	
	getData();
	miniMax();
	printf("Max / Min : %d/%d\n",maxS,minS);
	if (strcmp(action, "BID") == 0){
		if (maxS >= 10){
			bid = balP;
		}
		else if (minS <= -9)
			bid = min(balP, gurantee);
		else{
			if (balP >= 6)
				bid = gurantee;
			else if (balP >= 4)
				bid = balP - 2;
			else
				bid = 1;
		}
		printf("%d\n",bid);
	}
	else{
		if (turn==2)
		printf("%d %d\n", Y, X);
	}
	sp;
	return 0;
}

//