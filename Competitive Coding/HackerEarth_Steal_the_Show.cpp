/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/codejunk/algorithm/steal-the-show/

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
#define mp(x) make_pair(x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

int a[100000];

int main(){
	
	int ceo, l, r,n;
	scanf("%d%d%d", &ceo, &r, &l);
	vector<int> mem;
	scanf("%d", &n);
	REP(i, n){
		int x;
		scanf("%d", &x);
		mem.pb(x);
	}
	SORT(mem,n);
	a[0] = l;
	a[n + 2] = r;
	a[(n + 3) / 2] = ceo;

	int k = 0;
	REP(i, n + 3){
		if (i != 0 && i != n + 2 && i != (n + 3) / 2)
			a[i] = mem[k++];
	}
	
	int ans = 0;
	REP(i, n + 2)
		ans += abs(a[i] - a[i + 1]);
	printf("%d", ans);


	return 0;
}

//Solved - Bad Problem -- Algo Not Correct