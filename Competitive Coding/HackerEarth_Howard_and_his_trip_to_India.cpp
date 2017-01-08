
//http://www.hackerearth.com/programming-basics-part-2/algorithm/howard-and-his-trip-to-india25-points-2/

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

int main(){

	int t, n, ja[30],cu[30];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		REP(i, n) scanf("%d", &ja[i]);
		REP(i, n) scanf("%d", &cu[i]);
		SORT(ja, n);
		SORT(cu, n);
		int count = 0;
		for (int i = 0, j = 0; i < n && j < n;){
			if (ja[i] <= cu[j]){
				count++;
				i++;
				j++;
			}
			else
				j++;
		}
		cout << count << endl;
	}
	return 0;
}

//Solved