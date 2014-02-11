#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>


void main(){
	int posx = rand() % 20, posy = rand() % 20;
	int snake_length;
	int n=20;
	char board[20][20];
	printf("Use the W,S,A,D keys to move\n");
	for (int i = 0; i < n ; i++){
		for (int j = 0; j < n ; j++){
			board[i][j] = '.';
		}
	}
	
    board[posy][posx] = '*';
	for (int i = 0; i < n; i++){
	for (int j = 0; j < n; j++){
		printf("%c", board[i][j]);
	}
	printf("\n");
	}
	char c1 = _getch();
	while(c1 != 'o') 

	{

		if (c1 == 'a'){
			posx--;
		if (posx == -1)
			posx = n - 1;
	}

		else if (c1 == 'd'){
			posx = (posx + 1) % n;
		}
		else if (c1 == 'w'){
			posy--;
			if (posy == -1)
				posy = n - 1;
		}

		else if(c1 == 's'){
			posy = (posy + 1) % n;
		}

		system("cls");
		printf("Use the W,S,A,D keys to move\n");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				board[i][j] = '.';
			}
		}
		board[posy][posx] = '*';
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				printf("%c", board[i][j]);
			}
			printf("\n");
		}

		
		Sleep(200);
		c1 = _getch();
	}
	
}
