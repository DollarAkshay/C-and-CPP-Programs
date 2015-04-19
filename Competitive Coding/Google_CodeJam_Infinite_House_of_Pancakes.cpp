/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/6224486/dashboard#s=p1

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

int main(){

	FILE *fp = fopen("Problem_2_Small_2.txt", "w");
	int t, n,mx;
	int p[1001];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		MS0(p);
		REP(i, n){
			int x;
			scanf("%d", &x);
			p[x]++;
			mx = max(mx, x);
		}
		int special = 0,time=0;
		FORD(i,1000,1){
			if (p[i] && p[i]+ (float)special < (float)i/2 ){
				
				special += p[i];
				if (i % 2 == 0){
					p[i / 2] += 2 * p[i];
					p[i] = 0;
				}
				else{
					int a = i/2, b = (i+1)/2;
					p[a] += p[i];
					p[b] += p[i];
					p[i] = 0;
				}
			}
			else if(p[i]){
				time = i;
				break;
			}
		}
		int ans = time + special;
		fprintf(fp,"Case #%d: %d\n", tc + 1, time + special);
		//printf("Case #%d: %d\n", tc + 1, ans);
	}
	fclose(fp);
	sp;
	return 0;
}

//