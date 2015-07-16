/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/CANTON/

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int binary_search(int n){

	int hi = 4472, lo = 1 , mid , res;
	while (hi>=lo){
		mid = (lo+hi)/2;
		int maxn = mid*(mid+1)/2;
		if (maxn>=n)
			res = mid;
		if (maxn>n)
			hi = mid-1;
		else if (maxn<n)
			lo = mid + 1;
		else
			break;
	}
	return res;
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		int row = binary_search(n);
		int maxn = row*(row+1)/2;
		int a,b;
		a = 1 + maxn%n;
		b = row - maxn%n;

		if (row%2==0){
			int t = a;
			a = b;
			b = t;
		}

		printf("TERM %d IS %d/%d\n", n, a, b);
	}
	sp;
	return 0;
}

//Solved