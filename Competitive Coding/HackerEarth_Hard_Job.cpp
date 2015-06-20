/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//

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

int a[500000], ind[500000],n;

void pop(int x, int pos, char c){
	
	if (c == 'l'){
		FORD(i, pos, 1){
			a[i] = a[i - 1];
			ind[a[i]] = i;
		}
		a[0] = x;
		ind[x] = 0;
	}
	else{
		FOR(i, pos, n - 1){
			a[i] = a[i + 1];
			ind[a[i]] = i;
		}
		a[n - 1] = x;
		ind[x] = n - 1;
	}
}

int main(){

	REP(i, 101)
		printf("%d\n", i);
	sp;
}

//