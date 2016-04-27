/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/GSS1/

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

struct node {
	int l, r;
	ll int minval, maxval, bestval;
};

node SegTree[131073];
ll int a[50005], sum[50005];

ll int rangeMaxQuerry(int node, int querryl, int querryr) {

	int nodel = SegTree[node].l, noder = SegTree[node].r;

	if (nodel>=querryl && noder<=querryr)
		return SegTree[node].bestval;
	else if (noder<querryl || nodel>querryr)
		return INT32_MIN;
	else {
		return max(rangeMaxQuerry(node*2+1, querryl, querryr),
				   rangeMaxQuerry(node*2+2, querryl, querryr));
	}

}

void constructTreeRange(int node, int l, int r) {

	SegTree[node].l = l;
	SegTree[node].r = r;

	if (l<r){
		int mid = (l+r)/2;
		constructTreeRange(node*2+1, l, mid);
		constructTreeRange(node*2+2, mid+1, r);
	}
}

ll int constructMaxTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].maxval = sum[l];
	}
	else {
		SegTree[node].maxval = max(constructMaxTree(node*2 + 1) , constructMaxTree(node*2 + 2));
	}
	return SegTree[node].maxval;

}

ll int constructMinTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].minval = sum[l];
	}
	else {
		SegTree[node].minval = min(constructMinTree(node*2 + 1), constructMinTree(node*2 + 2));
	}
	return SegTree[node].minval;

}

ll int constructBestTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].bestval = a[l];
	}
	else {
		ll int leftbest = constructBestTree(node*2+1);
		ll int rightbest = constructBestTree(node*2+2);
		SegTree[node].bestval = max(SegTree[node*2+2].maxval-SegTree[node*2+1].minval, 
									max(leftbest, rightbest));
	}
	return SegTree[node].bestval;

}

int main(){

	int n, q;
	bool neg=0;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%lld", &a[i]);
		sum[i] = i?sum[i-1]+a[i]:a[i];
		if (sum[i]<0)
			neg = 1;
	}

	constructTreeRange(0, 0, n-1);
	constructMaxTree(0);
	constructMinTree(0);
	constructBestTree(0);

	scanf("%d", &q);
	REP(i, q) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n",  + (neg?rangeMaxQuerry(0, l-1, r-1):sum[r-1]-sum[l-1]+a[l-1]));
	}
	
	sp;
	return 0;
}

//Not Solved :/