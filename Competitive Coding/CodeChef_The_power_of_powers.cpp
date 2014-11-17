
//http://www.codechef.com/CDSM2014/problems/PPOW/

#include <stdio.h>
#define gc getchar_unlocked

int num[4001];

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int powSum(int a, int n){

	int carry = 0, prod, lim = 0, i, sum = 0;
	num[0] = 1;
	while (n--){
		for (i = 0; i <= lim || carry>0; i++){
			prod = num[i] * a + carry;
			carry = prod / 10;
			num[i] = prod % 10;
		}
		lim = i - 1;
	}
	lim++;
	while (lim--) {
		sum += num[lim];
		num[lim] = 0;
	}
	return sum;

}


int main()
{
	int t, a, n;
	scanf("%d", &t);
	for (int i = 0; i<t; i++){
		num[0] = 1;
		scanint(a);
		scanint(n);
		printf("Case %d: %d\n", i + 1, powSum(a, n));
	}
	return 0;
}

// ~ TLE