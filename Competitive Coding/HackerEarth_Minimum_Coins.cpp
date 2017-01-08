/*
Ram has to pay Shyam R rupees and but the coins which he has got is of limited denomination .Assuming he has a limited 
knowledge of the mathematics and has unlimited number of coins of each denomination.Write a code to help Ram to pay the
money using minimum number of coins .Suppose Ram has coins of {1,2} denomination then the best way to pay 8 rupees is 
2+2+2+2 that means using 4 coins. Input: Money to be paid {array containing denominations available} Output Coins 
corresponding to each denomination and number of coins needed(ascending denomination) or print ERROR in other cases


Sample Input (Plaintext Link)
24
{1,7,3}

Sample Output (Plaintext Link)
Rupee 1 coin 0
Rupee 3 coin 1
Rupee 7 coin 3

*/


#include<conio.h>

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double coins[10000000], deno[10000000];
long int n = 0,error=0;

void scanip(){
	register int c = getchar();

	for (; c !=125; c = getchar()){
		if (c == 123 || c == 44)
			scanf("%lf", &deno[n++]);
		if (fmod(deno[n - 1], 1) || deno[n-1]<0)
			error = 1;
	}
}

int comp(const void * a, const void * b){
	if (*(double*)a > *(double*)b) return -1;
	else if (*(double*)a < *(double*)b) return 1;
	else return 0;
}


int main(){

	double amt;
	int  i;
	scanf("%lf", &amt);
	scanip();
	qsort(deno, n, sizeof(double), comp);
	if (amt <= 0 || deno[0]<=0 || error )
		printf("ERROR");
	else{
		for (i = 0; i < n && amt>0; i++){
			if (deno[i]>0){
				coins[i] = amt / deno[i];
				amt=fmod(amt, deno[i]);
			}
		}
		if (i == n && amt != 0)
			printf("ERROR");
		else
			while (n--)
				printf("Rupee %d coin %d\n", (int)deno[n], (int)coins[n]);		
	}
	_getch();
}
