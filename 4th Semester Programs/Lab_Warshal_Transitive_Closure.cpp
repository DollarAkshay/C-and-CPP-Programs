#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;


void warshal(int n,int R[100][100]){
	
	int k,i,j;
	
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				R[i][j] = (R[i][j]) | (R[k][j]&R[i][k]);
									 
	
}

int main(int argc, char** argv) {
	
	int i,j,n,adj[100][100];
	
	cout<<"Enter the number of nodes :";
	cin>>n;
	cout<<"Enter the adjacency matrix : \n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>adj[i][j];
			
	warshal(n,adj);
	
	cout<<"The Transitive Cosure is : \n";		
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<adj[i][j]<<" ";	
		cout<<endl;
	}
	
	_getch();
	return 0;
}
