/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

int a[70][70];
int b[70][70];
int c[70][70];

int main(){

	int t, n;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		int ans = -1;
		REP(i, n){
			REP(j, n){
				scanf("%d", &a[i][j]);
				b[i][j] = i ? b[i - 1][j] ^ a[i][j] : a[i][j];
				ans = max(ans, b[i][j]);
				c[i][j] = j ? c[i][j - 1] ^ a[i][j] : a[i][j];
				ans = max(ans, c[i][j]);
			}
		}
		REP(j, n){
			REP(i, n){
				b[i][j] = j ? b[i][j-1] ^ b[i][j] : b[i][j];
				ans = max(ans, b[i][j]);
				c[i][j] = i ? c[i-i][j] ^ c[i][j] : c[i][j];
				ans = max(ans, c[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

//