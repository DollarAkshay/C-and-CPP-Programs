/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/flavored-june/algorithm/xorcum-set/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
#define gc getchar_unlocked
struct Edge{ int v, w; };

int a[100000],xorcum[100000];

vector<pair<int, int>> f;

void incre(int n){

	int size = f.size(),found=0;
	REP(i, size){
		if (f[i].first == n){
			found = 1;
			f[i].second++;
			break;
		}
	}
	if (!found){
		f.push_back(make_pair(n, 1));
	}
}

int main(){

	int n;
	scanf("%d", &n);
	REP(i, n){
		scanf("%d", &a[i]);
		xorcum[i+1] = xorcum[i]^a[i];
	}
	FOR(i, 0, n){
		FOR(j, i + 1, n)
			incre(xorcum[i] ^ xorcum[j]);
	}
	int maxf=0, no=-1,size = f.size();
	REP(i, size){
		if (f[i].second > maxf){
			maxf = f[i].second;
			no = f[i].first;
		}
		else if (f[i].second == maxf && f[i].first < no){
			no = f[i].first;
		}
	}
	printf("%d %d", no, maxf);
	
	return 0;
}

//