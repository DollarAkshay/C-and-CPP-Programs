/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/MARCH16/problems/CHNGSS

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
#include <functional>

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

int q;

int findcell(int i, int j) {

	int hi = 50, lo = 1, mid,  x, res=25;

	while (hi>=lo) {
		mid = (hi+lo)/2;
		if (q>=500000)
			return 25;
		printf("1 %d %d %d %d %d %d\n", i+1, i+1, j+1, j+1, mid, hi);
		q++;
		fflush(stdout);
		scanf("%d", &x);
		if (x==0)
			hi = mid-1;
		else {
			lo = mid+1;
			res = mid;
		}
	}

	return res;

}

int main(){

	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);

	ll int avg;
	printf("2 %d %d %d %d\n", 1, n, 1, m);
	c--;
	q++;
	fflush(stdout);
	scanf("%lld", &avg);
	avg /= (m*n);

	vector<int> a[500];
	REP(i, n) {
		REP(j, m)
			a[i].push_back(avg);
	}

	REP(i, c) {
		if (i>=m*n)
			break;
		int sum;
		printf("2 %d %d %d %d\n", i/m +1, i/m +1, i%m +1, i%m +1);
		q++;
		fflush(stdout);
		scanf("%d", &sum);
		a[i/m][i%m] = sum;

	}

	while (q<500000 && c<m*n) {
		a[c/m][c%m] = findcell(c/m, c%m);
		c++;
	}

	printf("3\n");
	fflush(stdout);
	REP(i, n) {
		REP(j, m) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
		fflush(stdout);
	}
	sp;
	return 0;

}

//