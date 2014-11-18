
//http://www.hackerearth.com/programming-basics-part-2/algorithm/penny-and-averages-15-points/

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

	int t, n, x;
	ll int ans;
	scanf("%d", &t);
	REP(tc, t){
		ans = 1;
		n = 0;
		while (1){
			scanf("%d", &x);
			if (x == -1)
				break;
			else{
				ans *= x;
				n++;
			}
		}
		printf("%.3f\n", ans / (double)n);
	}
	return 0;
}

//Solved