#include <stdio.h>
#include <conio.h>
#define MAX 100

char stack[MAX];
int top = -1;

int palindrome(char s[]){

	int i=0;
	while (s[i])
		stack[++top] = s[i++];

	i = 0;
	while (s[i])
		if (s[i++] != stack[top--])
			return 0;
	
	return 1;

}

void main(){

	char s[100];
	printf("Enter the string : ");
	scanf("%s",s);
	if (palindrome(s))
		puts("String is Palindrome");
	else
		puts("String is not Palindrome");

	_getch();

}