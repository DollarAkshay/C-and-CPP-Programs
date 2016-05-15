#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

	for (i = 0; i<fs; i++) { 
		cout<<f[i];
	}
	cout<<"\n Generator :"; 
	for (i = 0; i<gs; i++) { cout<<g[i]; }
	//Append 0's 
	int rs=gs-1; 
	cout<<"\n Number of 0's to be appended: "<<rs; 
	for (i=fs;i<fs+rs;i++) { 
		f[i]=0; 
	} 
	int temp[20]; 
	for (i = 0; i<20; i++) { 
		temp[i] = f[i]; 
	}
	cout<<"\n Message after appending O's :";
	for (i = 0; i<fs+rs; i++) { 
		cout<<temp[i]; 
	}

	Division(temp, g, fs, gs); 
	cout<<"Remainder is "<<temp<<endl; 
	cout<<"\nThe transmitted message is";

}