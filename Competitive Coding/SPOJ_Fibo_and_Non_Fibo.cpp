/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/POWFIB/

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

int fib[10000001], nonfib[10000001];

void pre(){
	
	fib[1] = fib[2] = 1;
	int j = 1;
	FOR(i, 3, 10000000){
		fib[i] = (fib[i-1] + fib[i-2])%MOD;
		FOR(k, fib[i-1]+1, fib[i]-1){
			if (j>10000000)
				break;
			nonfib[j++] = k;
		}
	}
}

int fastexpo(ll int b,int e){

	if (e==0)
		return 1;
	if (e==1)
		return b;

	if (e%2==0)
		return fastexpo(b*b%MOD, e/2)%MOD;
	else
		return (b*fastexpo(b*b%MOD, (e-1)/2))%MOD;
}




int main(){

	pre();
	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		printf("%d\n", fastexpo(nonfib[n], fib[n]));
	}
	sp;
	return 0;
}

//Solved