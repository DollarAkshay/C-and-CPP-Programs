/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/HPYNOS/

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



int squareSum(int n){

	int res = 0;
	while (n){
		res += (n%10)*(n%10);
		n /= 10;
	}
	return res;

}

int main(){

	int n;
	scanf("%d", &n);
	
	int c = 0;
	map<int, int> m;

	while (1){
		m[n] = 1;
		n = squareSum(n);
		c++;
		if (m.count(n)>0){
			printf("-1\n");
			break;
		}
		if (n==1){
			printf("%d\n",c);
			break;
		}
	}
	sp;
	return 0;
}

//Solved