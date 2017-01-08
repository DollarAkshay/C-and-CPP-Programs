
//http://www.hackerearth.com/code4maaya/algorithm/golf-on-the-beach/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include<assert.h>
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

int ele[500][500];

void peaks(int p, int q, int k){

	int i, j, x, y;

	for (i = 0; i <= p - k; i++){
		for (j = 0; j <= q - k; j++){

			int max = -1, c = 0;
			for (x = i; x<k + i; x++){
				for (y = j; y<k + j; y++){
					if (ele[x][y]>max){
						c = 1;
						max = ele[x][y];
					}
					else if (ele[x][y] == max)
						c++;
				}
			}
			printf("%d", max);
			if (c>1)
				printf("(%d)", c);
			printf(" ");

		}
		printf("\n");
	}

}



int main(){

	int t, p, q, k;
	scanf("%d", &t);
	REP(tc, t){
		printf("Case %d:\n", tc + 1);
		scanf("%d%d%d", &p, &q, &k);
		REP(i, p)
			REP(j, q)
			scanf("%d", &ele[i][j]);
		peaks(p, q, k);
		printf("\n");

	}
	return 0;
}

//Solved