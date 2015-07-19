/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/EGYPIZZA/

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

int p[4];

int main(){

	p[0] = 1;
	int n;
	scanf("%d", &n);
	REP(i, n){
		int a, b;
		scanf("%d/%d", &a, &b);
		if (a==1 && b==4)
			p[3]++;
		else if (a==1 && b==2)
			p[2]++;
		else
			p[1]++;
	}
	
	int full = min(p[1], p[3]);
	p[1] -= full;
	p[3] -= full;
	p[0] += full;

	p[0] += p[3]/4;
	p[3] %= 4;

	p[0] += p[2]/2;
	p[2] %= 2;

	

	if (p[3]>=2){
		p[3] -= 2;
		p[2]++;
	}

	p[0] += p[2]/2;
	p[2] %= 2;

	if (p[2]&&p[3]){
		p[3]--;
		p[2]--;
		p[1]++;
	}

	int ans = 0;
	REP(i, 4)
		ans += p[i];

	printf("%d", ans);


	return 0;
}

//Solved