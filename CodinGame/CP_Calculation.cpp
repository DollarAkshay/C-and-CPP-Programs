/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//This is to calculate CP for a contest


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int n, range = 10;

int calcPoints(int r){

	double CP = pow(n, ((double)n - r + 1) / n);
	return round(CP);
}


int main(){


	FILE *f = fopen("res.txt", "w");
	
	
	printf("Enter N the number of participants that have a score of more than 0% : ");
	cin >> n;


		printf("  Rank Range   |  Points Range \n");
	for (int i = 1; i <= n; i += n / range)
		printf(" %4d to %4d  |  %4d to %4d \n", i, i + n / 10, calcPoints(i), calcPoints(i+n/10));

	printf("\n\n");
	sp;

	return 0;
}

//