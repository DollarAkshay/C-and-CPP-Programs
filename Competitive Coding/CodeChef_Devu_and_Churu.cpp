/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/AUG15/problems/DCGAME

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

int a[1000000];
vector<pii> res;
vector<pii> cumsum;

void submax(int l, int r){

	if (l>r)
		return;

	pii e = mp(0,-1);
	FOR(i, l, r){
		if (a[i]>e.first){
			e.first = a[i];
			e.second = i;
		}
	}
	res.pb(mp(e.first, (e.second-l+1)*(r-e.second+1)));
	submax(l, e.second-1);
	submax(e.second+1, r);
}

int eq_binary_search(int l, int h, int key){

	int res = -1;
	while (l<=h){
		int m = (l+h)/2;
		if (cumsum[m].first==key){
			res = m;
			break;
		}
		else if (cumsum[m].first>key)
			h = m-1;
		else
			l = m+1;
	}
	return res;

}

int gt_binary_search(int l, int h, int key){

	int res = -1;
	while (l<=h){
		int m = (l+h)/2;
		if (cumsum[m].first>key){
			res = m;
			h = m-1;
		}
		else
			l = m+1;
	}
	return res;

}

int lt_binary_search(int l, int h, int key){

	int res = -1;
	while (l<=h){
		int m = (l+h)/2;
		if (cumsum[m].first<key){
			res = m;
			l = m+1;
		}
		else
			h = m-1;
	}
	return res;

}

int main(){

	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%d", &a[i]);
	submax(0, n-1);
	SORT(res, res.size());
	REP(i, res.size()){
		int cz = cumsum.size();
		if (cz==0)
			cumsum.pb(mp(res[i].first, res[i].second));
		else if (res[i].first == cumsum[cz-1].first)
			cumsum[cz-1].second += res[i].second;
		else
			cumsum.pb(mp(res[i].first, cumsum[cz-1].second+res[i].second));
	}

	REP(i, m){
		char c, p;
		int k, mov;
		getchar();
		scanf("%c %d %c", &c, &k, &p);
		if (c=='='){
			int pos = eq_binary_search(0, cumsum.size()-1, k);
			if (pos<0)
				mov = 0;
			else{
				mov = cumsum[pos].second;
				if (pos)
					mov -= cumsum[pos-1].second;
			}
			mov%2?printf("%c", p=='D'?'D':'C'):printf("%c", p=='D'?'C':'D');
		}
		else if (c=='>'){
			int pos = gt_binary_search(0, cumsum.size()-1, k)-1;
			if (pos<0)
				mov = 0;
			else
				mov = cumsum[cumsum.size()-1].second - cumsum[pos].second;
			mov%2?printf("%c", p=='D'?'D':'C'):printf("%c", p=='D'?'C':'D');
		}
		else {
			int pos = lt_binary_search(0, cumsum.size()-1, k);
			if (pos<0)
				mov = 0;
			else
				mov = cumsum[pos].second;
			mov%2?printf("%c", p=='D'?'D':'C'):printf("%c", p=='D'?'C':'D');
		}
	}
	sp;
	return 0;
}

//Solved