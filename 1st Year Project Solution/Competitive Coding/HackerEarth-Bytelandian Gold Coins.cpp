/*
In Byteland they have a very strange monetary system. Each Bytelandian gold coin has an integer
number written on it. A coin n can be exchanged in a bank into three coins:n/2, n/3 and n/4.
But these numbers are all rounded down (the banks have to make a profit).
You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1.
But you can not buy Bytelandian coins. You have one gold coin. What is the maximum amount of
American dollars you can get for it?
Input
The input will contain several test cases (not more than 10). Each testcase is a single line
with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

Output
For each test case output a single line, containing the maximum amount of American dollars
you can make.

Sample Input :
12
2

Sample Output :
13
2

Explanation You can change 12 into 6, 4 and 3, and then change these into $6+$4+$3 = $13.
If you try changing the coin 2 into 3 smaller coins, you will get 1, 0 and 0, and later you
can get no more than $1 out of them. It is better just to change the 2 coin directly into $2.
*/

#include <stdio.h>

long int a[50000000];

long int exchange(long int n){
	long int r = 0, m, t;
	for (int i = 2; i <= 4; i++){
		m = n / i;
		if (m<50000000 && a[m])
			r += a[m];
		else if (m>11){
			t = exchange(m);
			r += t;
			if (m<50000000)
				a[m] = t;
		}
		else{
			a[m] = m;
			r += m;
		}
	}
	return r;
}

int main()
{
	long int n;
	while (scanf("%ld", &n) != EOF){
		if (n>11)
			printf("%ld\n", exchange(n));
		else
			printf("%ld\n", n);

	}

}


//Solved