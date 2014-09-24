#include <iostream>
#define sp system("pause")

using namespace std;


int main(){

#define N 100
	int a[N],i;
	for (i = 0; i < N; i++)
		a[i] = i + 1;
	for (i = 0; i < N; i+=N/10)
		cout << " " << a[i];
	cout << endl;
	sp;
	return 0;
}