#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int n, r;
int all[99][99], max[99][99], need[99][99];
int res[99], avail[99];

void safe() {

	int i, j, k, flag=1,f[99], availcpy[99];
	vector<int> p;

	for (i = 1; i<=n; i++) {
		availcpy[i] = avail[i];								/*Make a copy of the available matrix*/
		f[i] = 0;
	}
	while (flag && p.size()<n) {
		flag = 0;
		for (i = 1; i<=n; i++) {
			for (k=0,j = 1; !f[i] & j<=r; j++) {			
				if (need[i][j]<=availcpy[j]) 
					k++;									/*counts the number of resources that can be allocated*/
			}
			if (k==r) {										/*If all the resources can be allocated complete the Process*/
				f[i] = flag = 1;							
				p.push_back(i);
				for (j = 1; j<=r; j++) 
					availcpy[j] += all[i][j];				/*Process i is completed. So collect all its allocated resources*/
			}
		}
	}

	if (flag) {
		cout<<"\nSafe State\nProcess order :";
		for (i = 0; i<p.size(); cout<<" "<<p[i++]);
		cout<<"\n";
	}
	else {
		cout<<"\nNot Safe State.";
	}
}

void req() {
	
	int can=1,i, p, nr[99];
	cout<<"\nProcess number : ";
	cin>>p;
	cout<<"New Request : ";
	for (i = 1; i<=r; i++) {
		cin>>nr[i];
		can = nr[i]<=avail[i] && nr[i]<=need[p][i]?1:0;		/*If the new request is more than the available or t=more than what the process needs then you cannot allocate it. Invalid request*/
	}
	if (can) {
		cout<<"Request within Limits\n";
		for (i = 1; i<=r; i++) {
			all[p][i] += nr[i];
			avail[i] -= nr[i];
			need[p][i] -= nr[i];							/*If the new request is within limits then subtract it from the need and available matrix*/
		}
		safe();
	}
	else {
		cout<<"Invalid Request\n";
	}
}


int main() {

	int i, j;
	cout<<"\nNo of processes : ";
	cin>>n;
	cout<<"\nNo. of resources : ";
	cin>>r;

	cout<<"\nAllocation Matrix : \n";
	for (i = 1; i<=n; i++) {
		for (j = 1; j<=r; j++) {
			cin>>all[i][j];
			avail[j] -= all[i][j];
		}
	}

	cout<<"\nMax Matrix : \n";
	for (i = 1; i<=n; i++) {
		for (j = 1; j<=r; j++) {
			cin>>max[i][j];
			need[i][j] = max[i][j] - all[i][j];
		}
	}

	cout<<"\nTotal Resources : ";
	for (i = 1; i<=r; i++) {
		cin>>res[i];
		avail[i] += res[i];
	}

	safe();

	while (1) {
		int ch;
		cout<<"\n1.New Request\n2.Exit\nEnter your choice : ";
		cin>>ch;
		if (ch==1)
			req();
		else
			break;
	}
	return 0;

}