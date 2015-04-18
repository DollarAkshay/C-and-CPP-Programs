#include<stdio.h>
#include<stdlib.h>
int main(){

	int c = 0;
	for (int i = 10000; i <= 99999; i++)
		if (i % 4 == 0) c++;
	printf("5 digit numbers divisible by 4 is %d\n\n", c);
	system("pause");
}