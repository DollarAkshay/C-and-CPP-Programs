/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/NSTEPS/

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

int dx[] = { 1, 1, 1, -1 };
int dy[] = { 1, -1, 1, 1 };


int main(){

	int t;
	scanf("%d", &t);
	REP(tc, t){
		int x, y;
		scanf("%d%d", &x, &y);
		int mindiv = min(x/2, y/2);
		int cx = 2*mindiv, cy = 2*mindiv, n = 4*mindiv, found = 0;

		if (cx==x && cy==y){
			found = 1;
			printf("%d\n", n);
		}
		else{
			REP(i, 4){
				cx += dx[i];
				cy += dy[i];
				n++;
				if (cx==x && cy==y){
					found = 1;
					printf("%d\n", n);
					break;
				}
			}
		}
		if (!found)
			printf("No Number\n");
	}
	sp;
	return 0;
}

//Solved