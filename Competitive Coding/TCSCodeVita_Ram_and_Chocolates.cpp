/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.tcscodevita.com/CodevitaV5/problemstart.jsp

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

int a[100];

int main(){

	int n;
	scanf("%d", &n);

	int sum = 0;
	REP(i, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int base = (n*(n-1)/2)*3;
	if ((sum-base)%n==0) {
		int off = (sum-base)/n;
		int steps = 0;
		REP(i, n) {
			if (a[i] < (off + 3*i)) {
				FOR(j, i+1, n-1) {
					if (a[j] > (off + 3*j)) {
						int trans = min((off + 3*i)-a[i], a[j]-(off + 3*j));
						a[i] += trans;
						a[j] -= trans;
						steps++;
						if (a[i] ==  (off + 3*i))
							break;
					}
				}
			}
			else if (a[i] > (off + 3*i)) {
				FOR(j, i+1, n-1) {
					if (a[j] < (off + 3*j)) {
						int trans = min( a[i]-(off + 3*i), (off + 3*j)-a[j] );
						a[i] -= trans;
						a[j] += trans;
						steps++;
						if (a[i] ==  (off + 3*i))
							break;
					}
				}
			}
		}
		printf("Yes %d\n", steps);
	}
	else {
		printf("No\n");
	}
	sp;
	return 0;
}

//