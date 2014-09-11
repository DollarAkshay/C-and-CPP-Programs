/*
Write a program to find the mode of a given list of integers. Mode of a number is defined
as the number which is most frequently occured.

It is possible that multiple answers are possible for a list. In that case print all possible
answers in non-increasing order.

Input:
First Line of input contains an integer t represeting the number of test cases.
Where first line of each test case has an integers N - number of integers in list.
Next line contains N integers.

Output:
print all the possible modes in non-increasing order.

Constraints:
1<=t<=100
1<=N<100000
1<=a[i]<=1000000

Sample Input :
2
5
1 2 2 2 2
6
1 2 2 3 3 4

Sample Output :
2
3 2

*/

#include <stdio.h>

int a[1000000], max;

void maxn(int big){

	for (int i = 1000000; i >= 0; i--){
		if (a[i] == big)
			printf("%d ", i);
		if (a[i])
			a[i] = 0;
	}
}

int main(t, n, x)
{
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		while (n--){
			scanf("%d", &x);
			a[x]++;
			if (a[x]>max)
				max = a[x];
		}
		maxn(max);
		max = 0;
		printf("\n");
	}
}

//Solved