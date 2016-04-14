/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

// Program to Simulate a Tower of Hanoi Game

#include<GL/glut.h>
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
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MIN_HEAP priority_queue<int, vector<int>, greater<int> >

int n, totoal_swaps;

MIN_HEAP A, B, C;


// Function to Display the Towers using ASCI Art
void printTowers() {

	MIN_HEAP _A = A, _B = B, _C = C;	//Make copies of the original Piority Queue

	int vA[10], vB[10], vC[10];

	memset(vA, 0, sizeof(vA));
	memset(vB, 0, sizeof(vB));
	memset(vC, 0, sizeof(vC));

	// Convert the Priority Queues into Ascending Order Arrays
	while (!_A.empty()) {
		vA[n - _A.size()+1] = _A.top();			
		_A.pop();
	}

	while (!_B.empty()) {
		vB[n - _B.size()+1] = _B.top();
		_B.pop();
	}

	while (!_C.empty()) {
		vC[n - _C.size()+1] = _C.top();
		_C.pop();
	}


	// Printing the Towers
	REP(i, n+1) {

		// Tower A
		FOR(j, -1, 2*n+2) {
			if (j==n)
				printf("|");
			else if (j>=n-vA[i] && j<=n+vA[i])
				printf("*");
			else
				printf(" ");
		}
		printf("  ");

		// Tower B
		FOR(j, -1, 2*n+2) {
			if (j==n)
				printf("|");
			else if (j>=n-vB[i] && j<=n+vB[i])
				printf("*");
			else
				printf(" ");
		}
		printf("  ");

		// Tower C
		FOR(j, -1, 2*n+2) {
			if (j==n)
				printf("|");
			else if (j>=n-vC[i] && j<=n+vC[i])
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}


	FOR(j, -1, 2*n+2) {
		if (j==n)
			printf("A");
		else
			printf("-");
	}
	printf("  ");

	FOR(j, -1, 2*n+2) {
		if (j==n)
			printf("B");
		else
			printf("-");
	} 
	printf("  ");

	FOR(j, -1, 2*n+2) {
		if (j==n)
			printf("C");
		else
			printf("-");
	}
	printf("\n\n");

}


// Recursive Function to Solve Tower of Hanoi Problem
void solve(MIN_HEAP &src, MIN_HEAP &dest, MIN_HEAP &buff, int count) {

	if (count>0) {

		solve(src, buff, dest, count-1);	// Shift N-1 disks from the Source to the Buffer

		int disk = src.top();
		src.pop();
		dest.push(disk);					// Shift the remaining disk on the Source to the Destination
		totoal_swaps++;						// Variable to Keep Track of the totla number of swaps

		printTowers();						// Display the state of all the towers after the Swap occurs
		solve(buff, dest, src, count-1);	// Shift back all the N-1 disks from the Buffer to the Destination
	}

}

int main(){

	printf("+----------------------------------------------------------------------------+\n");
	printf("|     _____                               __   _   _                   _     |\n");
	printf("|    |_   _|____      _____ _ __    ___  / _| | | | | __ _ _ __   ___ (_)    |\n");
	printf("|      | |/ _ \\ \\ /\\ / / _ \\ '__|  / _ \\| |_  | |_| |/ _` | '_ \\ / _ \\| |    |\n");
	printf("|      | | (_) \\      /  __/ |    | (_) |  _| |  _  | (_| | | | | (_) | |    |\n");
	printf("|      |_|\\___/ \\_/\\_/ \\___|_|     \\___/|_|   |_| |_|\\__,_|_| |_|\\___/|_|    |\n");
	printf("|                                                                            |\n");
	printf("+----------------------------------------------------------------------------+\n");
                                                                                                                  

	printf("\n\n Enter size of the Tower : ");
	scanf("%d", &n);
	printf("\n");

	FORD(i, n, 1)
		A.push(i);					// Populating the tower A with Disks of sizes  1 to n

	printTowers();				// Display the Initial configuration
	solve(A, B, C, n);	

	printf("Solved in %d swaps\n", totoal_swaps);

	sp;
	return 0;

}

//