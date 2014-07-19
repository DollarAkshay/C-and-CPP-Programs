#include <stdio.h>
#include<conio.h>

int num[160];

int getZero(){
	int i = 159;
	while (num[i] == 0 && i)i--;
	return i;

}

void factorial(int n){
	int carry = 0, prod;
	while (n){
		for (int i = 0; i <= getZero() || carry>0; i++){
			prod = num[i] * n + carry;
			carry = prod / 10;
			num[i] = prod % 10;
		}
		n--;
	}
}

void printArray(){
	int i = getZero() + 1;
	while (i--) {
		printf("%d", num[i]);
		num[i] = 0;
	}
	printf("\n");
}

int main()
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i<t; i++){
		num[0] = 1;
		scanf("%d", &n);
		factorial(n);
		printArray();
	}
	_getch();
}
