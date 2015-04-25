#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
#define max 100
#define infinity 999
int tspdp(int c[][max],int tour[],int star,int n);
int tspnn(int c[][max],int tour[],int start,int n);

int main(){
	int n;
	int i,j,c[max][max];
	int tour[max],cost1, cost2;
	cout<<"Travelling Salesman Problem Using Dynamic Programming and nearest neighbour approximation algorithms\n";
	cout<<"\nEnter number of cities to traverse : ";
	cin>>n;
	cout<<"Enter cost matrix\n"<<endl;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>c[i][j];
			if(c[i][j]==0)
				c[i][j]=999;
		}
	}

	for(i=0;i<n;i++)
		tour[i]=i;
	cost1=tspdp(c,tour,0,n);
	cout<<"\nMinimum cost using dynamic programming : "<<cost1<<endl;
	cout<<"Tour: ";
	for(i=0;i<n;i++)
		cout<<(char)(tour[i]+'A')<<" -> ";
	cout<<"A\n";
	_getch();

	
	cost2=tspnn(c,tour,0,n);
	cout<<"\nMinimum cost using approximation algorithm - nearest neighbour : "<<cost2<<endl;
	cout<<"Tour : ";
	for(i=0;i<n;i++)
		cout<<(char)(tour[i]+'A')<<" -> ";
	cout<<"A\n";
	
	double relative_err=(double)(cost2-cost1)/cost1;
	cout<<"The relative error = "<<relative_err<<endl;
	
	getch();
	return 0;
}

int tspdp(int c[][max],int tour[],int start,int n){
	
	int i,j,temp[max],mintour[max];
	int mincost,ccost;
	if(start==n-2)
		return c[tour[n-2]][tour[n-1]]+c[tour[n-1]][0];
	mincost=infinity;
	for(i=start+1;i<n;i++)
	{
		for(j=0;j<n;j++)
		temp[j]=tour[j];
		temp[start+1]=tour[i];
		temp[i]=tour[start+1];
		if(c[tour[start]][tour[i]]+(ccost=tspdp(c,temp,start+1,n))<mincost)
		{
		mincost=c[tour[start]][tour[i]]+ccost;
		
		for(int k=0;k<n;k++)
		mintour[k]=temp[k];
		}
	}
	for(i=0;i<n;i++)
		tour[i]=mintour[i];
		
	return mincost;
}



int tspnn(int c[][max],int tour[],int start,int n){
	
	int cost = 0,v[max],i,j,k=0;
	tour[k]=start;
	v[start]=1;
	while(k<n-1){
		int u=-1,min=infinity;
		for(i=0;i<n;i++){
			if(v[i]!=1 && c[tour[k]][i]<min){
				min=c[tour[k]][i];
				u=i;
			}	
		}
		tour[++k]=u;
		v[u]=1;
		cost+=min;
	}
	cost+=c[tour[k]][start];
	return cost;
}
