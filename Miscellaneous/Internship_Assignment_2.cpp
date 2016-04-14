
/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

// 

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ll long long

int n, m;
ll int DP[10000][10000];
int a[10000][10000];

ll int solve(int i, int j) {

	if (j>=m || i>=n)			// Terminating Condition if i and j go out of bounds
		return 0;

	if (DP[i][j]>0)				// If the value is already calculated then return the value
		return DP[i][j];


	if (i==n-1 && j==m-1)		// If it is the bottom most right corner then return that value
		DP[i][j] = a[i][j];
	else
		DP[i][j] = a[i][j] + max(solve(i+1, j), solve(i, j+1));		// Else find the maximum of the right and down values


	return DP[i][j];

}

int main() {

	int t;
	printf("Enter no of Testcases : ");
	scanf("%d", &t);
	FOR(tc, 1, t) {
		printf("\nEnter size of the table : ");
		scanf("%d %d", &n, &m);

		printf("\nEnter the Matrix :\n");
		FOR(i, 0, n-1)
			FOR(j, 0, m-1)
				scanf("%d", &a[i][j]);


		printf("\nAns = %lld\n", solve(0, 0));

		FOR(i, 0, n-1)
			FOR(j, 0, m-1)
			DP[i][j] = 0;

	}
	printf("\n");
	sp;
	return 0;
}

//Solved O(m*n)  
