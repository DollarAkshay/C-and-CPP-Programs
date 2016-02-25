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
#include <functional>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(format,...) fprintf(stderr,format, ##__VA_ARGS__)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int a[100000];

int main(){

	int n = 5;

	FOR(i, 1, n) {
		FOR(j, 1, n-i)
			printf(" ");
		FOR(j, 1, i)
			printf("*");
		printf("\n");
	}
	printf("\n");


	FOR(i, 1, n) {
		FOR(j, 1, i*2-1)
			printf("* ");
		FOR(j, 1, n*2 - i*2)
			printf("  ");

		FOR(j, 1, 2*n - i*2)
			printf("  ");
		FOR(j, 1, i*2-1)
			printf("* ");
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n) {

		FOR(j, 1, 2*n-1) {
			if (i%2) {
				if (j%2 && (j<=i || j>=2*n-i))
					printf("* ");
				else
					printf("  ");
			}
			else {
				if (j%2==0 && (j<=i || j>=2*n-i))
					printf("* ");
				else
					printf("  ");
			}
		}
		printf("\n");
	}
	FORD(i, n-1, 1) {

		FOR(j, 1, 2*n-1) {
			if (i%2) {
				if (j%2 && (j<=i || j>=2*n-i))
					printf("* ");
				else
					printf("  ");
			}
			else {
				if (j%2==0 && (j<=i || j>=2*n-i))
					printf("* ");
				else
					printf("  ");
			}
		}
		printf("\n");
	}
	printf("\n");


	FOR(i, 1, n) {
		FOR(j, 1, 2*n-1) {
			if (i%2) {
				if (j%2 && (j>=i && j<=2*n-i))
					printf("*");
				else
					printf(" ");
			}
			else {
				if (j%2==0 && (j>=i && j<=2*n-i))
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	FORD(i, n-1, 1) {
		FOR(j, 1, 2*n-1) {
			if (i%2) {
				if (j%2 && (j>=i && j<=2*n-i))
					printf("*");
				else
					printf(" ");
			}
			else {
				if (j%2==0 && (j>=i && j<=2*n-i))
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n) {
		FOR(j, 1, 2*n-1) {
			if (j>=n-i+1 && j<=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	FORD(i, n-1, 1) {
		FOR(j, 1, 2*n-1) {
			if (j>=n-i+1 && j<=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n) {
		FOR(j, 1, i)
			printf("  ");
		FOR(j, 1, i)
			printf("* ");
		printf("\n");
	}
	FORD(i, n-1, 1) {
		FOR(j, 1, i)
			printf("  ");
		FOR(j, 1, i)
			printf("* ");
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n) {
		FOR(j, 1, 2*n-1) {
			if (j<=n-i+1 || j>=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	FORD(i, n-1, 1) {
		FOR(j, 1, 2*n-1) {
			if (j<=n-i+1 || j>=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n-1) {
		FOR(j, 1, 2*n-1) {
			if (j>=i && j<=2*n-i)
				printf("* ");
			else
				printf("  ");
		}
		FOR(j, 2, 2*n-1) {
			if (j>=i && j<=2*n-i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	FOR(i, 1, n) {
		FOR(j, 1, n-1) 
			printf("  ");
		
		FOR(j, 1, 2*n-1) {
			if (j>=i && j<=2*n-i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");

	FOR(i, 1, n) {
		FOR(j, 1, 2*n-1) {
			if (j>=n-i+1 && j<=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}

	FORD(i, n, 1) {
		FOR(j, 1, 2*n-1) {
			if (j>n-i+1 && j<n+i-1)
				printf("  ");
			else
				printf("* ");
		}
		printf("\n");
	}
	FOR(i, 2, n) {
		FOR(j, 1, 2*n-1) {
			if (j>n-i+1 && j<n+i-1)
				printf("  ");
			else
				printf("* ");
		}
		printf("\n");
	}
	

	FORD(i, n, 1) {
		FOR(j, 1, 2*n-1) {
			if (j>=n-i+1 && j<=n+i-1)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("\n");

	int r = 3;

	FOR(j, 0, r*2*n)
		printf("* ");
	printf("\n");
	FOR(i, 1, n) {
		FOR(j, 0, r*2*n-1) {
			if (j%(2*n)==i || j%(2*n)==2*n-i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	FORD(i, n-1, 1) {
		FOR(j, 0, r*2*n-1) {
			if (j%(2*n)==i || j%(2*n)==2*n-i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
	}
	FOR(j, 0, r*2*n)
		printf("* ");
	printf("\n");

	printf("\n");
	sp;
	return 0;
}

//