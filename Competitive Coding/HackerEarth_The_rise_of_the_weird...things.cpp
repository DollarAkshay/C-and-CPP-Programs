/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/july-easy-15/algorithm/the-rise-of-the-weird-things-1/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

int main(){

	int n, a[100000];
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i]);
	SORT(a, n);

	int p1 = 0, p2 = 0;
	REP(i, n){
		if (a[i] % 2 == 0){
			printf("%d ", a[i]);
			p1 += a[i];
		}
	}
	printf("%d ", p1);
	REP(i, n){
		if (a[i] % 2){
			printf("%d ", a[i]);
			p2 += a[i];
		}
	}
	printf("%d ", p2);
	return 0;
}

//Solved