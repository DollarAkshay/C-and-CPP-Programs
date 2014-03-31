#include<stdio.h>
#include<conio.h>

void main(){
	int i, j, k, n = 10;

	for (i =0; i<n; i++){
		for (k = n-i; k<=n; k++){
			printf("%d", k % 10);
		}
		for (k = n-1; k >=n-i; k--){
			printf("%d", k % 10);
		}
		printf("\n");
	}

	_getch();
}
