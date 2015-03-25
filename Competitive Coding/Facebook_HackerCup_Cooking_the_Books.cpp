/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460

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

	FILE *f = fopen("myfile.txt", "w");

	int t, n;
	int dig[100];
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d", &n);
		if (n){
			int min = n, max = n, len = 0;

			while (max){
				dig[len] = max % 10;
				max /= 10;
				len++;
			}

			max = n;
			REP(i, len){
				FOR(j, i, len - 1){

					//Swap
					int t = dig[i];
					dig[i] = dig[j];
					dig[j] = t;

					t = 0;
					FORD(k, len - 1, 0) t = t * 10 + dig[k];

					int lt = 0,copy_t=t;
					while (copy_t){
						copy_t /= 10;
						lt++;
					}
					max = t > max && lt==len? t : max;
					min = t < min && lt==len? t : min;

					//Swap Back
					t = dig[i];
					dig[i] = dig[j];
					dig[j] = t;
				}
			}
			fprintf(f, "Case #%d: %d %d\n",tc+1, min, max);
			printf("%d %d\n", min, max);
		}
		else{
			fprintf(f, "Case #%d: 0 0\n",tc+1);
			printf("0 0\n");
		}
	}
	fclose(f);
	sp;
	return 0;
}

//