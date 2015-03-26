#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX 100

using namespace std;

void prims(int n,int adj[MAX][MAX]){

	int visit[MAX], i, j, c = 0, u, v, total = 0;

	for (i = 1; i <= n; i++)
		visit[i] = 0;

	visit[1] = 1;
	c++;

	cout << "\n\n Edges of the minimum spanning tree are : ";

	while (c < n){
		int min = 999;
		for (i = 1; i <= n; i++){
			if (visit[i]){
				for (j = 1; j <= n; j++){
					if (visit[j] == 0 && adj[i][j] && adj[i][j] < min){
						min = adj[i][j];
						u = i;
						v = j;
					}
				}
			}
		}
		cout << "{" << u << "," << v << "},";
		visit[v] = 1;
		total += min;
		c++;
	}
	cout << "\nMinimum cost : " << total;
}

int main(){

	int i,j,n, adj[MAX][MAX];
	
	printf("Enter the number of nodes : ");
	cin >> n;

	cout << "Enter adjacency matrix :\n";
	for (i = 1; i <=n; i++) 
		for (j = 1; j <=n; j++) 
			cin >> adj[i][j];
	prims(n, adj);

	_getch();
	return 0;
}