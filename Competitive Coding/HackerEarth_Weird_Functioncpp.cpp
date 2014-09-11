/*

Chandu is working on Weird function these days.A weird function is defined as :
W(a, b) = MW(a) + MW(a + 1) + MW(a + 2)... + MW(b)
(a and b both inclusive)
where a and b are integers and MW is mini weird function, which is defined as :
MW(i) = p^i + q^i + ...
where p and q(less than or equal to i) are all possible integers such that 
gcd(p, i) = p, gcd(q, i) = q ... and so on.

For example :
MW(10) = 1 ^ 10 + 2 ^ 10 + 5 ^ 10 + 10 ^ 10
where gcd(1, 10) = 1, gcd(2, 10) = 2, gcd(5, 10) = 5, gcd(10, 10) = 10

Your task is to find W(a, b) for given a and b.

Input :
First line of input contains an integer t, which is the number of test cases.
Each test case contains a single line containing two integers a and b.

Output:
Print W(a, b) for each test case modulo 10 ^ 9 + 7.

Constraints:
1 <= a, b <= 10 ^ 4
1 <= t <= 10 ^ 5

Sample Input :
2
2 2
2 3

Sample Output :
5
33

*/


#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int arr[10001] = { 0 };
#define mod 1000000007;
long long int po(long long int a, long long int i)
{
	long long int r = 1;
	while (i>0)

	{
		if (i % 2 == 1)
			r = (r*a) % mod;
		a = a*a;
		a = a%mod;
		i = i / 2;
	}
	return r%mod;
}
void MW(){
	for (int i = 1; i <=10000; i++){
		arr[i]=1;
		for (int j = 2; j <= i; j++)
			if (i%j == 0){
				arr[i]+=po(j,i);
				arr[i]%=mod;
			}
	}
}
int main()
{
	MW();
	int i;
	for (int j = 1; j < 100; j++)
		printf("%d ", arr[j]);
	scanf("%d", &i);
}






