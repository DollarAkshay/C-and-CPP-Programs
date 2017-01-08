
//http://www.hackerearth.com/problem/algorithm/project-team/

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

int a[100];
int sum[50];

int main(){

	int t, n,max,min;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n) cin >> a[i];
		SORT(a, n);
		max = 0;
		min = 20000;
		REP(i, n){
			sum[i] = a[i] + a[n - 1 - i];
			min = sum[i] < min ? sum[i] : min;
			max = sum[i] > max ? sum[i] : max;
		}
		cout << max - min << endl;
	}
	return 0;
}

//Solved