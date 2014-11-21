
//http://codeforces.com/contest/489/problem/B

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

int b[100], g[100];


int main(){

	int n, m,pairs=0;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &b[i]);
	scanf("%d", &m);
	REP(i, m)
		scanf("%d", &g[i]);
	SORT(b, n);
	SORT(g, m);

	for (int i = 0, j = 0; i < n &&  j < m;){
		if (abs(b[i] - g[j]) <= 1){
			pairs++;
			i++; 
			j++;
		}
		else if(g[j]<b[i]){
			j++;
		}
		else{
			i++;
		}
	}
	cout << pairs << endl;
	return 0;
}

//