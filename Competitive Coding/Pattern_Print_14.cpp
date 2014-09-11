#include<stdio.h>
#include<conio.h>
#include<windows.h>

int a[10][10];

void matrix(){
	system("CLS");
	for (int i = 0; i < 100; i++){
		if (i % 10 == 0)
			printf("\n");
		printf("%6d", a[i / 10][i % 10]);
	}
}

void main(){

	int i, j, k, n = 1, round = 0;

	while(n <=100 ){
		for (i = round; i < 9 - round; i++){
			a[round][i] = n++;
			Sleep(100); matrix();
		}

		for (i = round; i < 9 - round; i++){
			a[i][9 - round] = n++;
			Sleep(100); matrix();
		}
		for (i = 9 - round; i>round; i--){
			a[9 - round][i] = n++;
			Sleep(100); matrix();
		}
		for (i = 9 - round; i > round; i--){
			a[i][round] = n++;
			Sleep(100); matrix();
		}
	round++;
	printf("\nChecking for Condition");
	Sleep(1000);
}
	_getch();

}









