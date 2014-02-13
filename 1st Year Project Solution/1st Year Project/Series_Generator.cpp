/* Printing Mathematical Series*/

#include<stdio.h>
#include<conio.h>

void main(){
	int n, t;

	printf("Enter the Series you want to display :\n");
	printf("1. Fibonacci Series\n");
	printf("2. Power of 2 Series\n");
	printf("3. Sum upto n Numbers\n");
	printf("4. N factorial series\n");
	scanf("%d", &n);
	printf("Upto how many terms ? : ");
	scanf("%d", &t);

	if (n == 1)
	{
		int a = 0, b = 1;
		printf("0, 1");
		for (int i = 3; i <= t; i++){
			if (a<b)
				printf(", %d", a = a + b);
			else
				printf(", %d", b = a + b);
		}
	}
	else if (n == 2)
	{
		int x = 2;
		printf(" 2");
		for (int i = 2; i <= t; i++)
			printf(", %d", x *= 2);
	}
	else if (n == 3)
	{
		int sum = 1;
		printf(" 1");
		for (int i = 2; i <= t; i++)
			printf(", %d", sum += i);
	}
	else if (n == 4)
	{
		long int fact = 1;
		printf(" 1");
		for (int i = 2; i <= t; i++)
			printf(", %d", fact *= i);
	}
	else{
		printf("\n ~~~ INVALID CHOICE ~~~");
	}

	_getch();
}