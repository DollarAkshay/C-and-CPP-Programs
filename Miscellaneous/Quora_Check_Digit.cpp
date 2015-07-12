#include <iostream>
using namespace std;

int a[] = { 2, 3, 5, 7 };

long long int check(long long int n){

	long long int i = 0, s = 0;
	while (n){
		s += n%10*a[i++%4];
		n /= 10;
	}
	return s;
}

int main() {

	long long int n;
	cin>>n;
	while (n>9){
		long long int t = n;
		n = check(n);
		if (t==n)
			break;
	}
	cout<<"Answer = "<<n;
	return 0;
}