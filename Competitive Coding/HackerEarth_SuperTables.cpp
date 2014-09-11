/*
Supertables

Little Timmy is exceptionally good at math tables, so his maths teacher decided to make things
a bit more interesting. His teacher takes two numbers A and B and merges the tables of A and B
in sorted order (ascending order), removing the duplicates and thus creates supertable of A and B
and asks Little Timmy the Nth number in the supertable.
Given A, B and N, calculate the Nth number in the supertable of A and B.

Input
First line contains number of test cases T . Each test case contains three integers A , B and N .

Output
For each test case print the Nth number of the supertable.

Constraints:
1<=T<=300000
1<=A, B<=1000
1<=N<=1000000000

Sample Input:
4
3 5 2
3 5 3
2 3 4
2 3 6

Sample Output :
5
6
6
9

*/

#include<stdio.h>

long int gcd(long int a, long int b){

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}

}

int main(){

	long int a, b, n, t, k = 0, f;
	long long int x, y;
	scanf("%ld", &t);
	while (t--){
		scanf("%ld%ld%ld", &a, &b, &n);
		if (a%b == 0)
			printf("%ld\n", b*n);
		else if (b%a == 0)
			printf("%ld\n", a*n);
		else{

			long int lcm = a*b / gcd(a, b);
			long int no = lcm / a + lcm / b - 1;
			x = y = lcm*(n / no);
			n %= no;
			if (!x)
				x = a, y = b;
			else
				n++;
			for (k = 0; k <n; k++){
				if (x<y){
					x += a; f = 1;
				}
				else if (x>y){
					y += b; f = 0;
				}
				else{
					x += a; y += b;
				}
			}
			printf("%lld\n", f ? x - a : y - b);
		}
	}
}

//Solved