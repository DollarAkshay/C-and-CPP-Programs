/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.codechef.com/COOK52/problems/MOSTDIST

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
#define gc getchar
struct Edge{ int v, w; };

struct point{
	int x, y;
	bool valid;
};

void scanint(register int &x)
{
	register int c = gc();
	x = 0;
	for (; (c<48 || c>57); c = gc());
	for (; c>47 && c<58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}

vector<point> p;

int main(){

	register int t,x,y,ans=0,n;
	char c;
	scanint(t);
	REP(tc, t){
		c = gc();
		if (c == '-'){
			scanint(n);
			if (ans)
				n ^= ans;
			p[n-1].valid = false;
		}
		else{
			scanint(x);
			scanint(y);
			if (ans){
				x ^= ans;
				y ^= ans;
			}
			if (c == '+'){
				p.push_back({ x, y, true });
			}
			else{
				register int max = 0, pts = p.size();
				REP(i, pts){
					if (p[i].valid){
						register int dist = abs(x - p[i].x) + abs(y - p[i].y);
						if (dist > max)
							max = dist;
					}
				}
				ans = max;
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}

// ~TLE