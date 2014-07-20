/*
Everybody knows what an arithmetic progression is.
Sequences [1, 5], [10], [5, 4, 3] are arithmetic progressions and 
sequences [1, 3, 2], [1, 2, 4] are not.
Alexander has n cards containing integers. Arthur wants to give Alexander exactly 
one more card with a number so that he could use the resulting n+1 cards to make 
an arithmetic progression (Alexander has to use all of his cards).
Arthur has already bought a card but he hasn't written a number on it. Help him, 
print all integers that you can write on a card so that the described condition fulfilled.

Input
The first line contains integer n (1<=n<=10^5) — the number of cards.
The next line contains the sequence of integers — the numbers on Alexander's cards.
The numbers are positive integers, each of them doesn't exceed 10^8.

Output
If Arthur can write infinitely many distinct integers on the card, print on a single line -1.
Otherwise, print on the first line the number of integers that suit you.
In the second line, print the numbers in the increasing order.
Note that the numbers in the answer can exceed 10^8 or even be negative.

Sample Input :
3
4 1 7
Sample Output :
2
-2 10
Explanation*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int i, n, ap[100000], diff, gap = 0, filler;
	//Reading Input
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &ap[i]);

	if (n == 1)
		printf("-1");
	else{
		qsort(ap, n, sizeof(int), compare);
		diff = ap[n - 1] - ap[n - 2] < ap[1] - ap[0] ? ap[n - 1] - ap[n - 2] : ap[1] - ap[0];

		//Checking for gaps in AP sequence
		if (ap[0] == ap[n - 1])
			printf("1\n%d\n", ap[0]);
		else {
			for (i = 1; i < n; i++){
				if (ap[i - 1] + diff == ap[i])
					continue;
				else if (ap[i - 1] + 2 * diff == ap[i] && gap != 1){
					gap = 1;
					filler = ap[i - 1] + diff;
				}
				else{
					gap = 2;
				}
			}
			if (gap == 1){
				printf("1\n%d\n", filler);
			}
			else if (gap == 2){
				printf("0");
			}
			else {
				int a = ap[0] - diff, b = ap[n - 1] + diff;
				printf("2\n");
				printf("%d %d \n", a, b);

			}
		}

	}
	_getch();
}

//Solved