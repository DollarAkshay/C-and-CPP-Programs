/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/magic-lines-september-2015/challenges/common-child-magic-lines

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int c[5005][5005];

string a, b;
int m, n;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	cin>>a;
	cin>>b;
	//cout<<a<<b<<endl;
	m = a.length();
	n = b.length();
	for (int i = 0; i<=m; i++) c[i][0] = 0;
	for (int i = 0; i<=n; i++) c[0][i] = 0;

	for (int i = 1; i<=m; i++) {
		for (int j = 1; j<=n; j++) {
			if (a[i-1]==b[j-1]) c[i][j] = c[i-1][j-1]+1;
			else c[i][j] = max(c[i][j-1], c[i-1][j]);
			//cout<<c[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<c[m][n]<<endl;

	return 0;
}

//Solved