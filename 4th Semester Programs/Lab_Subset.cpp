#include<iostream>

#include<conio.h>

using namespace std;

int w[20], x[20], scount = 0, d;

void subset(int s, int k,int n){

	int i;
	x[k] = 1;
	if (s + w[k] == d){
		scount++;
		cout << "Subset #" << scount << " : ";
		for (i = 1; i <= k; i++){
			if (x[i] == 1)
				cout << w[i]<<", ";
		}
		cout << endl;
	}
	else if (s + w[k]<= d && k<=n)
		subset(s + w[k], k + 1,n);
	if (k <= n){
		x[k] = 0;
		subset(s, k + 1, n);
	}
	
}

void main(){

	int sum = 0, i, n;
	cout << "Enter value of n : ";
	cin >> n;
	cout << "Enter the elements : ";
	for (i = 1; i <= n; i++)
		cin >> w[i];
	cout << "Enter the value to find : ";
	cin >> d;
	for (i = 1; i <= n; i++)
		x[i] = 0;
	for (i = 1; i <= n; i++)
		sum = sum + w[i];
	if (d>sum)
		cout << "No solution\n";
	else{
		subset(0, 1,n);
		if (scount == 0)
			cout << "no solution\n";
	}
	_getch();

}