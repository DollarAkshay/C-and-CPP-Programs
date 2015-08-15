/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerrank.com/contests/codeagon/challenges/sherlock-and-subarray-queries

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
#define gc getchar

void scanint(int &x){
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

int n, m;
int a[100000];
int segTree[1000000];

void constructTree(int low, int high, int pos){

	if (low==high){
		segTree[pos] = a[low];
		return;
	}
	int mid = (low+high)/2;
	constructTree(low, mid, 2*pos+1);
	constructTree(mid+1, high, 2*pos+2);
	segTree[pos] = max( segTree[2*pos+1], segTree[2*pos+2]);
}

int maxQuerry(int qlow, int qhigh, int low, int high, int pos){

	if (qlow<=low &&  qhigh>=high)
		return segTree[pos];
	if (qlow>high || qhigh<low)
		return 0;
	int mid = (low+high)/2;
	return max(maxQuerry(qlow, qhigh, low, mid, 2*pos+1), maxQuerry(qlow, qhigh, mid+1, high, 2*pos+2));
}

int occMAX(int l, int r){

	if (l==r)
		return 1;

	int mid = (l+r)/2;
	int lmax = maxQuerry(l, mid, 0, n-1, 0);
	int rmax = maxQuerry(mid+1, r, 0, n-1, 0);
	if (lmax>rmax)
		return occMAX(l, mid);
	else if (rmax>lmax)
		return occMAX(mid+1, r);
	else
		return occMAX(l, mid) + occMAX(mid+1, r);

}

int main(){

	
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanint(a[i]);
	constructTree(0, n-1, 0);
	REP(i, m){
		int l, r;
		scanint(l); 
		scanint(r);
		printf("%d\n", occMAX(l-1, r-1));
	}
	return 0;
}

//Almost Solved ~TLE