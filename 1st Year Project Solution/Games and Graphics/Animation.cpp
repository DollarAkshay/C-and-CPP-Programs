#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>


const int m = 20, n = 30;
char board[m][n];

void choices();
void initializeBoard();
void printBoard();
void pattern1();
void pattern2();
void pattern3();
void pattern4();
void pattern5();


int main(){
	choices();
	initializeBoard();
	printBoard();
	char c = _getch();
	while (c != 'x'){
		switch (c){
		case 'a':
			pattern1();
			break;
		case 'b':
			pattern2();
			break;

		case 'r':
			initializeBoard();
			system("cls");
			choices();
			printBoard();
			break;
		}
	c = _getch();
	}
}


void choices()
{

	printf("~~ Enter any char from a-z to see a pattern ~~ Press X to exit ~~");
}


void initializeBoard(){
	for (int i = 0; i < m*n; i++)
		board[i / n][i%n] = 176;
}


void printBoard()
{
	for (int i = 0; i < m*n; i++){
		if (i%n == 0)
			printf("\n");
			printf("%c",board[i/n][i%n]);
	}
}

void pattern1(){
	for (int i = 0; i <m; i++){
		for (int j = 0; j <n; j++){
			board[i][j] = 219 + j % 2;
	}
		Sleep(50);
		system("cls");
		printBoard();
}
}

void pattern2(){
	for (int k = 0; k <=m+n; k++){
		for (int j = k >= n - 1 ? n - 1 : k, i = k >= n - 1 ? k - n - 1 : 0; i < m&&j >= 0; j--, i++)
			board[i][j] = board[i][j] = 244 + i % 2;
			system("cls");
			printBoard();
		Sleep(50);
	}
}






// Integration Sign =		board[i][j] = 244 + i%2;
// Thick Grid =					board[i][j] = 219+j%2;	
// Thin Grid =					board[i][j] = 197
//