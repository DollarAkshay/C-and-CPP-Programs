#include<stdio.h>
#include<conio.h>
#include<omp.h>
#include<time.h>

int main(){

	int n = 20000, c = 0,i;
	clock_t t = clock();
	for (int j = 2; j < n; j++){
		int d = 0;
#pragma omp parallel for
		for (i = 2; i < j; i++){
			
			if (j%i == 0)
				d++;
		}
			if (d == 0)
				c++;
		}

	t = clock() - t;
	printf("It took %d clicks\n",t);
	printf("There are %d primes between 2 and %d",c,n);
	_getch();


}