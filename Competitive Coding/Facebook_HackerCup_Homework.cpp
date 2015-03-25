/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.facebook.com/hackercup/problems.php?pid=582396081891255&round=344496159068801

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
#define MAX 10000005

char p[MAX];
int f[MAX];

void calcPrimes(){

	MS1(p);
	MS0(f);
	p[0] = p[1] = 0;
	int lim = sqrt(MAX);
	ll int i, j;
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j < MAX; j += i)
				if (p[j])
					p[j] = 0;
		}
	}
}


void pre(){
	calcPrimes();
	FOR(i, 2, MAX - 1){
		if (!p[i]){
			int n = i,j;
			for (j = 2; n != 1; j++){
				if (p[j] && n%j == 0){
					f[i]++;
					while (n%j == 0)
						n /= j;
					if (p[n]){
						f[i]++;
						break;
					}
				}
			}
		}
		else{
			f[i] = 1;
		}
	}
}


int main(){

	clock_t time = clock();
	pre();
	time = clock() - time;
	FILE *fp = fopen("op.txt", "w");
	//printf("Time taken for pre calculation : %f\n", (float)time / CLOCKS_PER_SEC);
	ll int t,a,b,k;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld%lld", &a,&b,&k);
		if (k > 8){
			printf("Case #%lld: %lld\n", tc + 1, 0);
			fprintf(fp,"Case #%lld: %lld\n", tc + 1, 0);
		}
		else{
			int c = 0;
			FOR(i, a, b) 
				if (f[i] == k) 
					c++;
			printf("Case #%lld: %lld\n", tc + 1, c);
			fprintf(fp,"Case #%lld: %lld\n", tc + 1, c);
		}
	}
	fclose(fp);
	sp;
	return 0;
}

//