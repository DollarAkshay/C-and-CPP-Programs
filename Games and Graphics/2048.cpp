
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int board[4][4],copy[4][4],score=0;

void createNewGame(){
	int i;
	for (i = 0; i < 16; i++)
		board[i / 4][i % 4] = copy[i / 4][i % 4]=0;
	score = 0;
}

void copyBoard(){
	int i;
	for (i = 0; i < 16; i++)
		copy[i / 4][i % 4] = board[i / 4][i % 4];
}

void rollbackBoard(){
	int i;
	for (i = 0; i < 16; i++)
		board[i / 4][i % 4] = copy[i / 4][i % 4];
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

	printf("\n");
	printf("\t\t    /^^^\\      /^^^\\    |^|           /^^^^\\      \n");
	printf("\t\t   /_/\\  \\    |  -  |   | |_|^|__    |  ()  |     \n");
	printf("\t\t      /  /    | | | |   |___   __|    >    <      \n");
	printf("\t\t     /  /_    |  -  |       | |      |  ()  |     \n");
	printf("\t\t    |_____|    \\___/        |_|       \\____/      \n");

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

int checkGameOver(){
	if (up()){
		rollbackBoard();
		return 0;
	}
	else if (down()){
		rollbackBoard();
		return 0;
	}
	else if (left()){
		rollbackBoard();
		return 0;
	}
	else if (right()){
		rollbackBoard();
		return 0;
	}
	return 1;
}

int generateNumber(char c){

	int blank = 0, i;
	for (i = 0; i < 16; i++)
	if (board[i / 4][i % 4] == 0)
		blank++;

	int square = rand() % blank;
	int n = rand() % 4;
	n = n < 3 ? 2 : 4;
	for (i = 0; i < 16; i++){
		if (square == 0 && board[i / 4][i % 4] == 0){
			board[i / 4][i % 4] = n;
			printBoard();
			printf("\nBoard %d,%d = %d", i / 4, i % 4, n);
			break;
		}
		else if (board[i / 4][i % 4] == 0)
			square--;
	}
	switch (c){
		case 'w' :
		printf("\nUP");
		break;
		case 's':
			printf("\nDOWN");
			break;
		case 'a':
			printf("\nLEFT");
			break;
		case 'd':
			printf("\nRIGHT");
			break;
	}
	if (blank == 1 && checkGameOver())
		return 1;
	else
		return 0;
}

void credits(){
	int i;
	printf("\n\n");

	for (i = 1; i <= 27; i++){
		printf("~");
		Sleep(80);
	}
	
	printf(" THANKS ");
	Sleep(400);
	printf("FOR ");
	Sleep(400);
	printf("PLAYING ");
	Sleep(400);
	printf("2");
	Sleep(400);
	printf("0");
	Sleep(400);
	printf("4");
	Sleep(400);
	printf("8 ");
	Sleep(400);
	for (i = 1; i <= 27; i++){
		printf("~");
		Sleep(80);
	}
	Sleep(500);
	printf("\n\n Created by ");
	Sleep(1000);
	printf("$ ");
	Sleep(500);
	printf("Akshay");
	Sleep(500);
	printf(".L.");
	Sleep(500);
	printf("Aradhya ");
	Sleep(500);
	printf("$");
	Sleep(1500);

	printf("\n Contact : akshay95aradhya@gmail.com \n  ");
	Sleep(500);
	printf("\n\n Press any key to exit...");

}

void main(){

	int change, finish = 0;

start:
	srand(1995);
	createNewGame();
	generateNumber(NULL);
	char c = _getch();

	while (c != 'x'){
		change = 0;
		if (c == 'w')
			change = up();
		else if (c == 's')
			change = down();
		else if (c == 'a')
			change = left();
		else if (c == 'd')
			change = right();

		if (change)
			finish = generateNumber(c);
		else
			printf("\nINVALID");

		if (finish)
			c = 'x';
		else
			c = _getch();
	}
	printf("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GAME OVER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
	printf("\n\n Your Score : %6d", score);
	printf("\n\n Do you want to play again ? (Y/N)  : ");

exit:
	c = _getche();
	if (c == 'y' || c == 'Y')
		goto start;
	else if (c == 'n')
		credits();
	else{
		printf("\b");
		goto exit;
	}
	_getch();

}