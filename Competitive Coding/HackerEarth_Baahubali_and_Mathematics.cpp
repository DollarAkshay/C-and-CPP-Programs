/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/cm1508/algorithm/bahubali-and-mathematics/

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

int a[10][10];
int v[10][10];

void mark(pii a,int n) {

	REP(i, n) {
		v[i][a.second]=1;
		v[a.first][i]=1;
	}
}

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		MS0(v);
		scanf("%d", &n);
		REP(i, n) 
			REP(j, n) 
				scanf("%d", &a[i][j]);

		int hash = 0;

		REP(k, n) {

			int ml = -10000000;
			pii mlpos = mp(-1, -1);
			REP(i, n) {
				int least = 10000000, lpos = -1;
				int vert = 1000000;
				REP(j, n) {
					if (a[i][j]<least && !v[i][j]) {
						least = a[i][j];
						lpos = j;
						vert = 1000000;
					}
					if (a[i][j]==least && !v[i][j]) {

						int vl = 1000;
						REP(gg, n) {
							if (a[gg][j]<vl) {
								vl = a[gg][j];
							}
						}
						if (vl<vert) {
							least = a[i][j];
							lpos = j;
							vert = vl;
						}
					}
				}
				if (least>ml && lpos!=-1) {
					ml = least;
					mlpos.first = i;
					mlpos.second = lpos;
				}
			}
			mark(mlpos,n);
			hash += ml;
		}
		printf("%d\n", hash);

	}
	return 0;
}

//