
//https://www.hackerrank.com/challenges/battleship

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


char board[10][11];
int checkedShips[10][10];
int lastx = -1, lasty = -1;

int aliveShips[6] = { 0, 2, 2, 1, 1, 1 };

int smallestShip;

int checkRedundant(int y, int x){

	int i = y, j = x, space = 0;
	for (j = x; j<10 && board[i][j] == '-'; j++);
	for (space = 0; j - 1 >= 0 && board[i][--j] == '-' && space < smallestShip; space++);
	if (space >= smallestShip)
		return 0;
	for (i = y; i<10 && board[i][j] == '-'; i++);
	for (space = 0; i - 1 >= 0 && board[--i][j] == '-' && space < smallestShip; space++);
	if (space >= smallestShip)
		return 0;
	return 1;

}

void checkLastMove(){

	int len = 0, i;
	if (board[lasty][lastx] == 'd'){
		if (lastx + 1<10 && board[lasty][lastx + 1] == 'd')
		for (i = lastx; i<10 && board[lasty][i] == 'd' && !checkedShips[lasty][i]; checkedShips[lasty][i++] = 1, len++);

		else if (lastx - 1 >= 0 && board[lasty][lastx - 1] == 'd')
		for (i = lastx; i >= 0 && board[lasty][i] == 'd' && !checkedShips[lasty][i]; checkedShips[lasty][i--] = 1, len++);

		else if (lasty + 1<10 && board[lasty + 1][lastx] == 'd')
		for (i = lasty; i<10 && board[i][lastx] == 'd' && !checkedShips[i][lastx]; checkedShips[i++][lastx] = 1, len++);

		else if (lasty - 1 >= 0 && board[lasty - 1][lastx] == 'd')
		for (i = lasty; i >= 0 && board[i][lastx] == 'd' && !checkedShips[i][lastx]; checkedShips[i--][lastx] = 1, len++);

		else {
			len++;
			checkedShips[lasty][lastx] = 1;
		}
		aliveShips[len]--;
	}
	for (int i = 1; i <= 5; i++){
		if (aliveShips[i]){
			smallestShip = i;
			break;
		}

	}

}

void placeShips(){

	//Temporary Algorithm
	printf("9 7\n");
	printf("7 2\n");
	printf("6 6:6 7\n");
	printf("5 7:5 8\n");
	printf("1 1:3 1\n");
	printf("8 1:8 4\n");
	printf("0 3:4 3\n");

}

void bombAt(int i, int j){


	printf("%d %d\n", i, j);

	//Writing Data to a file
	FILE *f = fopen("data.txt", "w");
	//Current Move
	fprintf(f, "%d %d\n", i, j);
	//Cout of Alive ships
	for (int k = 1; k <= 5; k++)
		fprintf(f, "%d ", aliveShips[k]);
	//Checked Ships
	fprintf(f, "\n");
	for (int n = 0; n < 10; n++){
		for (int m = 0; m < 10; m++)
			fprintf(f, "%d ", checkedShips[n][m]);
		fprintf(f, "\n");
	}
	fclose(f);

}

int noobCheck(){

	if (board[0][0] == '-'){
		bombAt(0, 0);
		return 0;
	}
	else if (board[4][2] == '-'){
		bombAt(4, 2);
		return 0;
	}
	else if (board[7][4] == '-'){
		bombAt(7, 4);
		return 0;
	}
	else if (board[3][7] == '-'){
		bombAt(3, 7);
		return 0;
	}
	else if (board[7][8] == '-'){
		bombAt(7, 8);
		return 0;
	}
	else if (board[3][4] == '-'){
		bombAt(3, 4);
		return 0;
	}
	else if (board[6][0] == '-'){
		bombAt(6, 0);
		return 0;
	}
	else
		return 1;
}

void nextMove(){

	int i, j, k, empty = 0, hx = -1, hy = -1;
	int right = 0, up = 0;
	int hit = 0;

	//Check for any non-destroyed ships
	for (i = 0; i<10; i++){
		for (j = 0; j<10; j++){
			if (board[i][j] == 'h' && hx == -1 && hy == -1){
				hy = i;
				hx = j;
				hit = 1;
			}
			if (board[i][j] == '-')
				empty++;
		}
	}

	i = hy;
	j = hx;
	if (j + 1<10 && board[i][j + 1] == 'h'){
		for (k = j + 2; k<10; k++){
			if (board[i][k] == '-'){
				bombAt(i, k);
				return;
			}
			else if (board[i][k] == 'm'){
				right = 1;
				break;
			}
		}
	}
	if (i + 1<10 && board[i + 1][j] == 'h'){
		for (k = i + 2; k<10; k++){
			if (board[k][j] == '-'){
				bombAt(k, j);
				return;
			}
			else if (board[k][j] == 'm'){
				up = 1;
				break;
			}
		}
	}
	if ((j - 1 >= 0 && board[i][j - 1] == 'h') || right){
		for (k = j - 1; k >= 0; k--){
			if (board[i][k] == '-'){
				bombAt(i, k);
				return;
			}
		}
	}
	if ((i - 1 >= 0 && board[i - 1][j] == 'h') || up){
		for (k = i - 1; k >= 0; k--){
			if (board[k][j] == '-'){
				bombAt(k, j);
				return;
			}
		}
	}
	if (hit){
		if (j + 1<10 && board[i][j + 1] == '-'){
			bombAt(i, j + 1);
			return;
		}
		else if (j - 1 >= 0 && board[i][j - 1] == '-'){
			bombAt(i, j - 1);
			return;
		}
		else if (i - 1 >= 0 && board[i - 1][j] == '-'){
			bombAt(i - 1, j);
			return;
		}
		else if (i + 1<10 && board[i + 1][j] == '-'){
			bombAt(i + 1, j);
			return;
		}
	}

	if (noobCheck()){
		if (empty >= 15){
			int x = rand() % 10;
			int y = rand() % 10;
			while (1){
				if (board[y][x] == '-' && checkRedundant(y, x) == 0)
					break;
				x = rand() % 10;
				y = rand() % 10;
			}
			bombAt(y, x);
		}
		else{
			for (i = 0; i<10; i++){
				for (j = 0; j<10; j++){
					if (board[i][j] == '-' && checkRedundant(i, j) == 0){
						bombAt(i, j);
						return;
					}
				}
			}
		}
	}
}

int main() {

	char line[11];
	int i, j;
	FILE *f;

	srand(1006);

	f = fopen("data.txt", "r");
	if (f){
		fscanf(f, "%d%d", &lasty, &lastx);
		for (i = 1; i <= 5; i++)
			fscanf(f, "%d", &aliveShips[i]);
		for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			fscanf(f, "%d", &checkedShips[i][j]);
	}

	gets(line);
	if (!strcmp(line, "INIT")){
		placeShips();
	}
	else{
		for (i = 0; i < 10; i++)
			gets(board[i]);
		if (lastx != -1 && lastx != -1)
			checkLastMove();
		nextMove();
	}
}

//Not the ideal Algorithm