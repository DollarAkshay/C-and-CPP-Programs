//http://www.hackerearth.com/problem/algorithm/day-3-1-d-arrays/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MSN(x,n) memset(x,n,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int t, n, max;
	int a[100000];
	pair<int, int> num[10];
	scanf("%d", &t);
	REP(i, t){
		MSN(num, -1);
		scanf("%d", &n);
		REP(j, n){
			scanf("%d", &a[j]);
			int x = a[j];
			num[x].first == -1 ? num[x].first = j : num[x].second = j;
		}
		max = 0;
		REP(j, 10){
			int diff = num[j].second - num[j].first;
			if (diff > max)
				max = diff;
		}
		cout << max + 1 << endl;
	}
	return 0;
}

//Solved
