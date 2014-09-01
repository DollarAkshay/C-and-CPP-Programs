
#include <stdio.h>


long long int freq[19] =
{ 0, 4, 64, 784, 8704, 92224, 953344, 9720064, 98320384, 989922304,
9939533824, 99637202944, 997823217664, 9986939305984, 99921635835904,
999529815015424, 9997178890092544, 99983073340555264, 999898440043331584 };

int primes[] = { 0, 0, 0, 1, 2, 2, 3, 3, 4, 4 };

int digits[20], len = 0;

void digitize(long int n){

	while (n){
		digits[len++] = n % 10;
		n /= 10;
	}
}

void printDigits(){
	for (int i = 0; i<len; i++){
		printf("%d, ", digits[i]);
	}
	printf("\n");
}

int checkPrimes(long int n){
	while (n){
		int d = n % 10;
		if (d == 2 || d == 3 || d == 5 || d == 7){
			return 1;
		}
		n /= 10;
	}
	return 0;
}

int main()
{
	long int n, magic = 0;
	int t, i;
	scanf("%d", &t);
	while (t--){
		scanf("%ld", &n);
		digitize(n);
		for (i = len - 1; i >= 0; i--){
			if (i<len - 1 && (digits[i + 1] == 2 || digits[i + 1] == 3 || digits[i + 1] == 5 || digits[i + 1] == 7)){
				magic = magic + n % ((long int)pow(10, (double)i + 1));
				break;
			}
			magic = magic + primes[digits[i]] * pow(10, (double)i) +
				freq[i] * (digits[i] - primes[digits[i]]);
		}
		printf("%ld\n", magic + checkPrimes(n));
		magic = 0;
		for (i = 0; i<20; i++)
			digits[i] = 0;
		len = 0;
	}
}