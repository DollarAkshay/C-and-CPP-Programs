/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.quora.com/What-is-the-most-efficient-algorithm-to-generate-all-the-numbers-between-2-and-N-such-that-their-only-prime-factors-are-2-or-3

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int n;

void next(int x){

	if (x * 2 <= n){
		printf(" %d", x * 2);
		next(x * 2);
	}
	if (x*3 <= n){
		printf(" %d", x * 3);
		next(x * 3);
	}
	
}

int main(){

	
	scanf("%d", &n);
	next(1);
	printf("\n");
	system("pause");

	return 0;
}

//