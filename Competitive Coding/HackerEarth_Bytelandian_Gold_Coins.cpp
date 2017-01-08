http://www.spoj.com/problems/COINS/

#include <stdio.h>

long long int a[50000000];

long long int exchange(long int n){
	long long int r = 0, m, t;
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
	long long int n;
	while (scanf("%lld", &n) != EOF){
		if (n>11)
			printf("%lld\n", exchange(n));
		else
			printf("%lld\n", n);

	}

}



//Solved