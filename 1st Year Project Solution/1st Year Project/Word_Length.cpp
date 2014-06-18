#include<stdio.h>
#include<conio.h>

void printBinary(int n){
	char bin[33];
	bin[32] = '\0';
	int count = sizeof(int)* 8;
	while (count-- > 0){
		if (n & 1)
			bin[count] = '1';
		else
			bin[count] = '0';
		n >>= 1;
	}
	puts(bin);
}


void main(){

	

	int c = 0, n = -4;
	printf("%d\n", n);
	while (c<32){
		n = n >> 1;
		printf("%10d\t", n);
		printBinary(n);
		c++;
	}
	printf("%d",c);
	_getch();
	


}