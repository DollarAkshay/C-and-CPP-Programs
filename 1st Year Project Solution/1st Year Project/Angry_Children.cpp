/*
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to 
each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like 
to pick K out of N packets such that the unfairness is minimized.

Suppose the K packets have (x1, x2, x3,….xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

max(x1,x2,…xk) - min(x1,x2,…xk)

where max denotes the highest value amongst the elements and min denotes the least value amongst the elements. Can you figure out the minimum 
unfairness and print it?

Input Format
The first line contains an integer N.
The second line contains an integer K. N lines follow each integer containing the candy in the ith packet.

Output Format
A single integer which will be the minimum unfairness.

Constraints
1<=N<=105
1<=K<=N
0<= number of candies in any packet <=109

https://www.hackerrank.com/challenges/angry-children

TEST CASE : 

20
5
4504
1520
5857
4094
4157
3902
822
6643
2422
7288
8245
9948
2822
1784
7802
3142
9739
5629
5413
7232
.
Ans : 1335
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main(){

	int n, k;
	scanf("%d%d", &n, &k);
	int pack[100000];
	for (int i = 0; i < n; i++){
		scanf("%d", &pack[i]);
	}

	qsort(pack, n, sizeof(int), compare);
		int unfair=0;
	for (int i = 0; i <n-k+1; i++){
		if (i == 0)
			unfair = pack[k - 1] - pack[0];
		if (pack[i + k - 1] - pack[i]<unfair)
			unfair = pack[i + k - 1] - pack[i];
		
	}
	printf("%d", unfair);
	return 0;
}