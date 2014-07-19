#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

void printBinary(int n){
	char bin[33];
	bin[32] = '\0';
	int count = sizeof(int)*8;
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

	unsigned int a = ~0; a <<= 1;
	unsigned int b = ~0;
	unsigned int c = b - a;
	printBinary( a );

	printf("%u", a );
	_getch();
}