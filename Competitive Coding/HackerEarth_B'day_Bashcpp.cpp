/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/acet03/algorithm/bday-bash/

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


int main(){

	ll int t, n;
	scanf("%lld", &t);
	REP(tc, t){
		ll int sum=0,a[3];
		vector<ll int> cake;
		scanf("%lld %lld %lld %lld", &n, &a[0], &a[1], &a[2]);
		REP(i, 3){
			if (a[i])
				cake.pb(a[i]*100/pow(2, i));
		}
		REP(i, cake.size())
			sum += cake[i];
		if (n<sum){
			printf("No\n");
		}
		else{
			int give = true;
			while (give){
				give = false;
				if ()
			}
		}
	}
	return 0;
}

//