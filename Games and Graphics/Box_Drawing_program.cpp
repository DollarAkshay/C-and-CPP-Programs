#include<stdio.h>
#include<conio.h>


int main(){
	char a[5] = { 220, 221, 222, 223 };
	printf("%c%c%c\n%c%c%c\n%c%c%c\n", a[2], a[3], a[1], a[2], ' ', a[1], a[2], a[0], a[1]);
	_getch();

}