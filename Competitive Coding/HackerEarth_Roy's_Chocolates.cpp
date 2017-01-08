
//http://www.hackerearth.com/november-clash/approximate/roys-chocolates/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
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

int compareints(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int find(int n, int a[], int size){
	REP(i, size){
		if (a[i] == n){
			a[i] = 0;
			return 1;
		}
	}
	return 0;
}

int main(){

	int n, m, fr[1000000], temp[1000000], next, found = 0;
	scanf("%d%d", &n, &m);
	REP(i, m){
		scanf("%d", &fr[i]);
		fr[i]--;
	}
	if (m == 1 && n == 1){
		printf("%d 0", fr[0] + 1);
		found = 1;
	}
	else if (m == 1){
		printf("%d %d", fr[0] + 1, n);
		found = 1;
	}
	else if (m == 2){
		printf("%d %d", fr[0] + 1, fr[1] - fr[0]);
		found = 1;
	}
	else{
		REP(i, m){
			FOR(j, 1, n - 1){
				copy(fr, fr + m, temp);
				next = fr[i];
				int loop = 0;
				while (bsearch(&next, fr, m, sizeof (int), compareints) && loop<m){
					loop++;
					next = (next + j) % n;
				}
				if (loop == m){
					printf("%d %d\n", fr[i] + 1, j);
					found = 1;
					i = m + 1;
					j = n;
				}
			}
		}
	}
	if (!found){
		printf("impossible\n");
	}
	return 0;
}

//Partially Solved 9/15