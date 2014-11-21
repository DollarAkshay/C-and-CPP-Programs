
//http://codeforces.com/contest/489/problem/C

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

int low[101],i=0;

void calc(int n, int sum){

	MS0(low);
	i = 0;
	int d;
	while (n--){
		d = sum>9?9:sum;
		if (d){
			low[i++] = d;
			sum -= d;
		}
		else{
			low[i - 1]--;
			low[i++] = 1;
		}
	}
	i--;
	for (int k = i; k >= 0; k--)
		printf("%d", low[k]);
	printf(" ");
	SORT(low, i + 1);
	for (int k = i; k >= 0; k--)
		printf("%d", low[k]);
	printf("\n");
}


int main(){

	int n, s;
	scanf("%d%d", &n, &s);
	if (n * 9 < s){
		puts("-1 -1");
	}
	else if (s == 0){
		puts(n == 1 ? "0 0" : "-1 -1");
	}
	else{
		calc(n, s);
	}
	return 0;
}

//Partially Solved