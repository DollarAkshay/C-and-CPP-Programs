#include<stdio.h>
#include<math.h>
#include<conio.h>

void main(){
	int n, sum=0,t;

	//Input n
	printf("Enter a 3 digit number :");
	scanf("%d", &n);
	t = n;

	while (t != 0){
		sum += pow( (double)(t%10), (double) 3);
		t /= 10;
	}

	if (sum == n)
		printf("It is armstrong");
	else
		printf("It is not armstrong");
	
	_getch();
}