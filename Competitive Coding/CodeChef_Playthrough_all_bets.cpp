
//http://www.codechef.com/TCFST15/problems/KRISH365/

#include <stdio.h>

int main(){

	int n, a, b;
	long long int min = 0, bal = 0;
	scanf("%d", &n);
	while (n--){
		scanf("%d%d", &a, &b);
		bal -= a;
		if (bal < min)
			min = bal;
		bal += b;
	}
	printf("%lld\n", -min);
	return 0;
}

//Solved