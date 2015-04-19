/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/


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

int a[10];

int main(){


	int n, t;
	scanf("%d", &t);
	REP(tt, t){
		ll int limit, tot=0, sum = 0;
		scanf("%d", &n);
		limit = pow(n, n);
		REP(i, n) a[i] = 1;

		while (limit--){
			a[0]++;
			int i = 0;
			while (a[i] > n){
				a[i] = 1;
				a[++i]++;
			}
			int check = 1;
			REP(i, n){
				if (a[i] == a[i + 1]){
					check = 0;
					break;
				}
			}
			if (check){
				tot++;
				int c[11], max = 0, p = 0;
				MS0(c);
				FORD(i, n - 1, 0){
					if (++c[a[i]] > max)
						max = c[a[i]];
				}
				FOR(i, 1, n){
					if (c[i] == max)
						p++;
				}
				sum += p;
			}
		}
		double prob;
		if (n == 1) 
			prob = 1;
		else 
			prob = (double)sum / tot;
		printf("%.6llf\n",prob);

	}
	return 0;
}

//