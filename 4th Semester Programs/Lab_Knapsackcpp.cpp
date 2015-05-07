#include<iostream>
#include<algorithm>
#include<conio.h>

using namespace std;

void knapsack(int n, int m, int w[], int p[]){

	int i, j, v[10][10], x[10];
	for (i = 0; i <= n; i++){
		for (j = 0; j <= m; j++){
			if (i == 0 || j == 0)
				v[i][j] = 0;
			else if (w[i]>j)
				v[i][j] = v[i - 1][j];
			else
				v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
		}
	}
	for (i = 0; i <= n; i++){
		for (j = 0; j <= m; j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}

	cout<<"\nMaximum profit"<<v[n][m];

	for (i = 1; i <= n; i++)
		x[i] = 0;

	i = n;
	j = m;
	while (i != 0 && j != 0){
		if (v[i][j] != v[i - 1][j]){
			x[i] = 1;
			j -= w[i];
		}
		i--;
	}
	cout << "Objects selected are :";
	for (i = 1; i <= n; i++){
		if (x[i] == 1)
			cout << i << ", ";
	}
}


void main(){

	int i, w[10], p[10], n, m; 
	cout << "Enter the number of items : ";
	cin >> n;
	cout << "enter the capacity of knapsack : ";
	cin >> m;
	cout << "Enter the weight of each item : ";
	for (i = 1; i <= n; i++)
		cin >> w[i];
	cout << "Enter the profit of each item : ";
	for (i = 1; i <= n; i++)
		cin >> p[i];
	knapsack(n, m, w, p);
	_getch();
}
