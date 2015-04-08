/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/problem/algorithm/equivalent-strings-2-2/

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


char A[100001], B[100001];

int equivalence(int a, int b, int l){

	char rela[256],relb[256];;
	MS0(rela);
	MS0(relb);
	REP(i,l){
		if (rela[A[a+i]] == 0 && relb[B[b+i]] == 0){
			rela[A[a + i]] = B[b + i];
			relb[B[b + i]] = A[a + i];
		}
		else if (rela[A[a + i]] && rela[A[a + i]] != B[b + i]){
			return 0;
		}
		else if (relb[B[b + i]] && relb[B[b + i]] != A[a + i]){
			return 0;
		}
	}
	return 1;
}

int main(){

	int t, q;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%s", A);
		scanf("%s", B);
		scanf("%d", &q);
		REP(qq, q){
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			i--; j--;
			puts(equivalence(i, j, k) ? "yes" : "no");
		}
	}
	return 0;
}

//Partially Solved