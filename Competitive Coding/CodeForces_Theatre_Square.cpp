
//http://codeforces.com/problemset/problem/1/A

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	long long int n, m, a;
	scanf("%I64d%I64d%I64d", &n, &m, &a);
	long long int ans;
	if (n%a == 0)
		ans = n / a;
	else
		ans = n / a + 1;

	if (m%a == 0)
		ans = ans*m / a;
	else
		ans = ans*(m / a + 1);
	printf("%I64d",ans);
	return 0;
}

//Solved