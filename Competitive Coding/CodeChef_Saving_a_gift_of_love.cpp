/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/LTIME22/problems/ASHIGIFT

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

struct clan {
	ll int x;
	ll int grp;
	ll int pop;
};

struct food{
	ll int x;
	ll int ppl;
};

vector<food> f;
vector<clan> c;

int main(){

	ll int t, X,B,C;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%lld", &X);
		scanf("%lld", &B);
		ll int max=0,min = 0,ans;
		f.clear();
		c.clear();
		REP(i, B){
			ll int x, y;
			food t;
			scanf("%lld%lld", &x, &y);
			min += y;
			t = { x, y };
			f.push_back(t);
		}
		ans = min;
		scanf("%lld", &C);
		REP(i, C){
			ll int x, y,z;
			clan t;
			scanf("%lld%lld%lld", &x, &y,&z);
			t = { x, y, z };
			c.push_back(t);
		}
		c.push_back({ X + 1, 0, 0 });

		for (int i = 0,j = 0; i < B; ){
			if (f[i].x < c[j].x){
				min -= f[i].ppl;
				i++;
			}
			else{
				if (j < C && min >= c[j].grp){
					min += c[j].pop;
					if (c[j].grp>max)
						max = c[j].grp;
				}
				j++;
			}
		}
		ans = ans - min + 1<max ? max : ans - min + 1;
		printf("%lld\n", ans);
	}
	sp;
	return 0;
}

//Partially Solved