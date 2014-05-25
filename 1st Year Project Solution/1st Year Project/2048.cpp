#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>


int board[4][4],copy[4][4],score=0;

void copyBoard(){
	int i;
	for (i = 0; i < 16; i++)
		copy[i / 4][i % 4] = board[i / 4][i % 4];
}

int checkStateChange(){
	int i;
	for (i = 0; i < 16; i++)
		if (copy[i / 4][i % 4] != board[i / 4][i % 4])
		return 1;
	return 0;
}

void printBoard(){
	system("cls");
	printf("\n\nScore = %6d",score);
	printf("\n+----+----+----+----+\n");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
		if (board[i][j])
			printf("|%4d",board[i][j]);
		else
			printf("|    ");
		printf("|\n");
		printf("+----+----+----+----+\n");
	}
}

void generateNumber(){
	
	int blank = 0,i;
	for (i = 0; i < 16;i++)
	if (board[i / 4][i % 4] == 0)
		blank++;

	int square = rand() % blank;
	int n = rand()%4;
	n = n < 3 ? 2 : 4;
	for (i = 0; i < 16; i++){
		if (square == 0 && board[i / 4][i % 4] == 0){
			board[i / 4][i % 4] = n;
			printBoard();
			printf("\nBoard %d,%d = %d", i/4, i%4,n);
			break;
		}
		else if (board[i / 4][i % 4] == 0)
			square--;
	}
}

int down(){
	copyBoard();
	int i, j,k,x,y;
	for (j = 0; j < 4; j++){
		x = -1; y = -1;
		for (i = 3; i >= 0; i--)
		if (board[i][j] == 0){
			y = i;
			break;
		}

		for (i = y-1; i >= 0; i--)
		if (board[i][j] != 0){
			x = i;
			break;
		}
			
			for (i =y,k = x; k >=0&&i>=0; k--)
			if (board[k][j]){
				board[i][j] = board[k][j];
				board[k][j]=0;
				i--;
			}

			for (i = 3; i ; i--){
				if (board[i][j] == board[i - 1][j] && board[i][j] != 0){
					board[i][j] *= 2;
					score += board[i][j];
					for (k = i - 1; k > 0; k--)
						board[k][j] = board[k - 1][j];
					board[0][j] = 0;
				}
			}

	}
	return checkStateChange();
}

int up(){

	copyBoard();

	int i, j, k, x, y;
	for (j = 0; j < 4; j++){
		x = 4; y = 4;
		for (i = 0; i <4; i++)
		if (board[i][j] == 0){
			y = i;
			break;
		}

		for (i = y + 1; i <4; i++)
		if (board[i][j] != 0){
			x = i;
			break;
		}

		for (i = y, k = x; k <4 && i < 4; k++)
		if (board[k][j]){
			board[i][j] = board[k][j];
			board[k][j] = 0;
			i++;
		}

		for (i = 0; i<3; i++){
			if (board[i][j] == board[i + 1][j] && board[i][j] != 0){
				board[i][j] *= 2;
				score += board[i][j];
				for (k = i + 1; k <3; k++)
					board[k][j] = board[k +1][j];
				board[3][j] = 0;
			}
		}

	}
	return checkStateChange();
}

int left(){

	copyBoard();
	int i, j, k, x, y;
	for (i = 0; i < 4; i++){
		x = 4; y = 4;
		for (j = 0; j <4; j++)
		if (board[i][j] == 0){
			y = j;
			break;
		}

		for (j = y + 1; j <4; j++)
		if (board[i][j] != 0){
			x = j;
			break;
		}

		for (j = y, k = x; k <4 && j < 4; k++)
		if (board[i][k]){
			board[i][j] = board[i][k];
			board[i][k] = 0;
			j++;
		}

		for (j = 0; j<3; j++){
			if (board[i][j] == board[i][j+1] && board[i][j] != 0){
				board[i][j] *= 2;
				score += board[i][j];
				for (k = j + 1; k <3; k++)
					board[i][k] = board[i][k+1];
				board[i][3] = 0;
			}
		}

	}
	return checkStateChange();
}

int right(){

	copyBoard();

	int i, j, k, x, y;
	for (i = 0; i < 4; i++){
		x = -1; y = -1;
		for (j = 3; j >=0; j--)
		if (board[i][j] == 0){
			y = j;
			break;
		}

		for (j = y - 1; j >=0; j--)
		if (board[i][j] != 0){
			x = j;
			break;
		}

		for (j = y, k = x; k>=0 && j >=0; k--)
		if (board[i][k]){
			board[i][j] = board[i][k];
			board[i][k] = 0;
			j--;
		}

		for (j = 3; j; j--){
			if (board[i][j] == board[i][j - 1] && board[i][j] != 0){
				board[i][j] *= 2;
				score += board[i][j];
				for (k = j-1; k >0; k--)
					board[i][k] = board[i][k - 1];
				board[i][0] = 0;
			}
		}

	}
	return checkStateChange();
}

void main(){
	int change;
	srand(time(NULL));
	generateNumber();
	char c = _getch();
	while (c != 'x'){
		if (c == 'w'){
			change = up();
			if (change)
				printf("\nUP");
		}
		else if (c == 's'){
			change = down();
			if (change)
				printf("\nDOWN");
		}
		else if (c == 'a'){
			change = left();
			if (change)
				printf("\nLEFT");
		}
		else if (c == 'd'){
			change = right();
			if (change)
				printf("\nRIGHT");
		}
	
		if (change)
			generateNumber();
		else
			printf("\nINVALID");
		c = _getch();
	}
	_getch();

}