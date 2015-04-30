/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-number-list/

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

int f[500001];
int s[500001];

void calc(int n){

	int pow = 1;
	f[0] = s[0] = 1;
	FOR(i, 1, n){
		f[i] = pow;
		s[i] = ((ll int)f[i] + s[i - 1]) % MOD;
		pow = ((ll int)pow * 2) % MOD;
	}

}


int main(){

	int q, n;
	int a[500001];
	scanf("%d %d", &n, &q);
	REP(i, n)
		scanf("%d", &a[i]);
	SORT(a, n);

	calc(n);

	REP(i, q){
		char op;
		int x;
		getchar();
		scanf("%c %d", &op, &x);

		int l = 0, h = n - 1, mid;
		while (l <= h){
			mid = (l + h) / 2;
			if (a[mid] == x)
				break;
			else if (a[mid]<x)
				l = mid + 1;
			else
				h = mid - 1;
		}
		while (a[mid]<x)
			mid++;
		if (a[mid] == x){
			if (op == '='){
				ll int t1 = mid-1, t2 = mid + 1, ans = f[mid + 1];
				while (a[t1] == x)
					ans = (ans + f[(t2--) + 1]) % MOD;
				while (a[t2] == x)
					ans = (ans + f[(t2++) + 1]) % MOD;
				printf("%d\n", ans);
			}
			else if (op == '<')
				printf("%d\n", s[mid]);
			else
				printf("%d\n", (s[n] - s[mid + 1]) % MOD);
		}
		else{
			if (op == '=')
				printf("0\n");
			else if (op == '<')
				printf("%d\n", s[mid]);
			else
				printf("%d\n", (s[n] - s[mid]) % MOD);
		}

	}
	return 0;
}

//