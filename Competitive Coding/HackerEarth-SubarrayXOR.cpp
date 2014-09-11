/*
Subarray XOR
Little Deepu since his breakup has been obsessed with XOR, so now he passes his time by calculating XOR of various numbers.
To help Little Deepu pass his time, his friend Rahul gives him an array of N numbers and asks him to calculate XOR of a range of numbers, from ath numbert to bth number(both a and b inclusive and are 0 - based).

Input
The first line contains T, the number of test cases.
First line of each test case contains N, the number of elements in the array
Next line contains N integers, where ith integer is the ith element of the array
The line after that contains Q, the number of XOR queries to be performed on the array
Next Q lines each contain a and b, the range of indices for which XOR is to be calculated.

Output
For each query a, b you need to print
array[a] XOR array[a + 1] XOR ... XOR array[b]

Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 100000
1 ≤ array[i] ≤ 1000000
1 ≤ Q ≤ 50000

Sample Input:
1
3
2 3 2
2
0 2
1 2

Sample Output:
3
1

*/


#include<conio.h>

#include<stdio.h>

int main(){

	long int array[100000], XOR[100000];
	long int t, n,q,a,b,res;
	scanf("%ld", &t);
	while (t--){
		scanf("%ld",&n);
		for (int i = 0; i < n; i++){
			scanf("%ld", &array[i]);
			if (i == 0)
				XOR[i] = array[i];
			else
				XOR[i] = XOR[i - 1] ^ array[i];
		}
		scanf("%ld", &q);
		for (int i = 0; i < q; i++){
			scanf("%ld %ld", &a, &b);
			int x = a>0 ? XOR[a - 1] : 0;
			int y = XOR[b];
			printf("%ld\n",x^y);
		}
	}
}

// Solved