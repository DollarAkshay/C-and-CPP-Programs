/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/challenges/pairs

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
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int a[100000];

int main(){

	int n, k,i,j;
	scanf("%d%d", &n, &k);
	REP(i, n) scanf("%d", &a[i]);
	int c = 0;
	SORT(a, n);
	for (i = 0, j = 1; j < n;){
		int diff = a[j] - a[i];
		if (diff < k){
			j++;
		}
		else if (diff == k){
			c++;
			i++;
			j++;
		}
		else{
			i++;
		}
	}
	cout << c;
	return 0;
}

//Solved ~ Fast and Efficient 