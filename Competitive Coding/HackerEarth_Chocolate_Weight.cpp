/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codestellar-3/algorithm/choclate-weight/

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

int compareints(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}



int main(){

	int m, n, a[100000];
	a[0] = 0;
	scanf("%d", &n);
	assert(n <= 100000);
	REP(i, n)
		scanf("%d", &a[i + 1]);

	scanf("%d", &m);
	REP(q, m){
		int x, found = 0;
		scanf("%d", &x);
		FOR(i, 1, n){
			REP(j, n + 1){
				if (x == a[i] + a[j] && i != j){
					found = 1;
					break;
				}
			}
		}
		puts(found ? "I Like You" : "I Hate You");
	}
	return 0;
}

//Solved