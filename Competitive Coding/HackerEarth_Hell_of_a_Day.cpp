//http://www.hackerearth.com/problem/algorithm/day-5-recursion/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b)  for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int t, n;
	vector<int> o, e;
	scanf("%d", &t);
	REP(i, t){
		scanf("%d", &n);
		n % 2 ? o.push_back(n) : e.push_back(n);
	}
	sort(e.begin(), e.end());
	sort(o.begin(), o.end());

	REP(i, e.size())
		printf("%d ", e[i]);
	cout << endl;
	FORD(i, o.size() - 1, 0)
		printf("%d ", o[i]);

	return 0;
}

//Solved
