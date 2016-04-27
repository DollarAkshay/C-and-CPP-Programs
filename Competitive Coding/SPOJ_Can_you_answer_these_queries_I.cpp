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
	int minval, maxval, bestval;
};

node SegTree[131073];
int a[50000], sum[50000];

int rangeMaxQuerry(int node, int querryl, int querryr) {

	int nodel = SegTree[node].l, noder = SegTree[node].r;

	if (nodel>=querryl && noder<=querryr)
		return SegTree[node].bestval;
	else if (noder<querryl || nodel>querryr)
		return INT16_MIN;
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


int constructMaxTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].maxval = sum[l];
	}
	else {
		SegTree[node].maxval = max(constructMaxTree(node*2 + 1) , constructMaxTree(node*2 + 2));
	}
	return SegTree[node].maxval;

}

int constructMinTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].minval = sum[l];
	}
	else {
		SegTree[node].minval = min(constructMinTree(node*2 + 1), constructMinTree(node*2 + 2));
	}
	return SegTree[node].minval;

}

int constructBestTree(int node) {

	int l = SegTree[node].l, r = SegTree[node].r;

	if (l==r) {
		SegTree[node].bestval = sum[l];
	}
	else {
		int leftbest = constructBestTree(node*2+1);
		int rightbest = constructBestTree(node*2+2);
		SegTree[node].bestval = max(SegTree[node*2+2].maxval-SegTree[node*2+1].minval, 
									max(leftbest, rightbest));
	}
	return SegTree[node].bestval;

}

int main(){

	int n, q;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		sum[i] = i?sum[i-1]+a[i]:a[i];
	}

	constructTreeRange(0, 0, n-1);
	constructMaxTree(0);
	constructMinTree(0);
	constructBestTree(0);

	scanf("%d", &q);
	REP(i, q) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", rangeMaxQuerry(0, l-1, r-1));
	}
	
	sp;
	return 0;
}

//Solved :D First ever Segment Tree Problem Solved :D