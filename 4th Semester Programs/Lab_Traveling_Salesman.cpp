#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
#define max 100
#define infinity 999999

int v[max], c[max][max],tour[max], optimal = infinity,n;

void tsprec(int curtour[], int u, int k, int cost){

	int i;
	v[u] = 1;
	curtour[k++] = u;
	if (k == n && cost + c[u][0] < optimal){
		optimal = cost + c[u][0];
		for (i = 0; i < n; i++)
			tour[i] = curtour[i];
	}
	else{
		for (i = 0; i < n; i++){
			if (v[i] == 0)
				tsprec(curtour, i, k, cost + c[u][i]);
		}
	}
	v[u] = 0;

}

int tspnn(int tour[], int start, int n){

	int cost = 0, i, k = 0;
	tour[k] = start;
	v[start] = 1;
	while (k<n - 1){
		int u = -1, min = infinity;
		for (i = 0; i<n; i++){
			if (v[i] != 1 && c[tour[k]][i]<min){
				min = c[tour[k]][i];
				u = i;
			}
		}
		tour[++k] = u;
		v[u] = 1;
		cost += min;
	}
	cost += c[tour[k]][start];
	return cost;
}


int main(){

	int i, j;
	int curtour[max], aproxcost;

	cout<<"Travelling Salesman Problem using Brute-Force and Nearest-Neighbour approximation algorithms\n";
	cout<<"\nEnter number of cities : ";
	cin>>n;
	cout<<"Enter cost matrix :\n"<<endl;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>c[i][j];
			c[i][j] = c[i][j] == 0 ? infinity : c[i][j];
		}
	}

	tsprec(curtour,0,0,0);
	cout<<"\nMinimum cost using Brute-Force : "<<optimal<<endl;
	cout<<"Tour : ";
	for(i=0;i<n;i++)
		cout<<tour[i]<<" -> ";
	cout<<"0\n";
	_getch();

	
	aproxcost = tspnn(curtour, 0, n);
	cout << "\nMinimum cost using Nearest Neighbour : " << aproxcost << endl;
	cout<<"Tour : ";
	for(i=0;i<n;i++)
		cout<<curtour[i]<<" -> ";
	cout<<"0\n";
	
	double relative_err=(double)(aproxcost-optimal)/optimal;
	cout<<"\nThe relative error : "<<relative_err<<endl;
	
	_getch();
	return 0;
}


/*
OUTPUT :
----------------------------
Travelling Salesman Problem using Brute-Force and Nearest-Neighbour approximatio
n algorithms

Enter number of cities to traverse : 11
Enter cost matrix

0   29  20  21  16  31  100 12  4   31  18
29  0   15  29  28  40  72  21  29  41  12
20  15  0   15  14  25  81  9   23  27  13
21  29  15  0   4   12  92  12  25  13  25
16  28  14  4   0   16  94  9   20  16  22
31  40  25  12  16  0   95  24  36  3   37
100 72  81  92  94  95  0   90  101 99  84
12  21  9   12  9   24  90  0   15  25  13
4   29  23  25  20  36  101 15  0   35  18
31  41  27  13  16  3   99  25  35  0   38
18  12  13  25  22  37  84  13  18  38  0

Minimum cost using Brute-Force : 253
Tour : 0 -> 7 -> 4 -> 3 -> 9 -> 5 -> 2 -> 6 -> 1 -> 10 -> 8 -> 0

Minimum cost using Nearest Neighbour : 299
Tour : 0 -> 8 -> 7 -> 2 -> 10 -> 1 -> 4 -> 3 -> 5 -> 9 -> 6 -> 0
The relative error = 0.181818


*/



