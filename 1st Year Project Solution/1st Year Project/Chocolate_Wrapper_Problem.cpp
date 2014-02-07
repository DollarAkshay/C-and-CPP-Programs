/*Little Bob loves chocolates and goes to the store with a $N bill with $C being the price of each chocolate.
In addition, the store offers a discount: for every M wrappers he gives the store, he’ll get one chocolate for free.
How many chocolates does Bob get to eat?

Input Format:
The first line contains the number of test cases T (<=1000). 
Each of the next T lines contains three integers N, C and M

Output Format:
Print the total number of chocolates Bob eats.

https://www.hackerrank.com/challenges/chocolate-feast
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int x=0;

	scanf("%d", &x);
	const int t = x;
	int n[1000], m[1000], c[1000];
	for (int i = 0; i<t; i++){
		scanf("%d%d%d", &n[i], &c[i], &m[i]);
	}

	for (int i = 0; i<t; i++){
		int choco, wrap = 0, eaten = 0;
		choco = n[i] / c[i];
		wrap = wrap + choco;
		eaten = choco + eaten;
		choco = 0;
		while (m[i] <= wrap){
			choco = wrap / m[i];
			wrap = wrap - choco*m[i] + choco;
			eaten = eaten + choco;
		}

		printf("%d\n", eaten);
	}
	_getch();
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}