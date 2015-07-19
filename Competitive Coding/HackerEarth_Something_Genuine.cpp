/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/july-clash-15/algorithm/something-genuine/

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

int a[200000], v[200001];
int uniq = 0, dir = 1;


void remove(int pos){

	v[a[pos]]--;
	if (v[a[pos]]==0)
		uniq--;

}

void add(int pos){

	v[a[pos]]++;
	if (v[a[pos]]==1)
		uniq++;

}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", &a[i]);

	
	int l = 0, r = 0;
	
	ll ans = 0;

	while (l<n){
		if (dir == 1){
			while (r<n){
				add(r);
				ans = (ans+ (ll int)uniq*uniq)%MOD;
				r++;
			}
			remove(l);
			l++;
			r--;
			dir = -1;
		}
		else{
			while (r>=l){
				ans = (ans+ (ll int)uniq*uniq)%MOD;
				remove(r);
				r--;
			}
			l++;
			r=l;
			dir = 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

//Partially Solved ~ TLE