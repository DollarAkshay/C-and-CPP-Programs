#include <iostream>
#include <stdio.h>
#include <math.h>



using namespace std;

_int64 mod = 1000000007;
_int64 tr = 10000000000;
_int64 fib[10000];

_int64 f(int n){
	if (fib[n])
		return fib[n];
	if (n <= 0)
		return 1;
	else{
		fib[n] = f(--n) + f(n--);
		fib[n] %= tr;
	}
	return fib[n];
}


int main(){

	fib[0] = 1;

	for (int i = 0; i <100; i++)
		printf("i = %d Res = %I64d\n", i, f(i)%mod);
	system("PAUSE");
	return 0;

}