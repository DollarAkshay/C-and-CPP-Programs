
//http://www.codechef.com/NOV14/problems/RBTREE

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

int main(){

	int q, x, y,r,b;
	char type[3];
	int flip = 0;
	scanf("%d", &q);
	REP(tc,q){
		scanf("%s",type);
		b = r = 0;
		if (type[1] != 'i'){
			scanf("%d%d", &x, &y);
			while (x != y){
				if (x > y){
					(int)log2(x) % 2 ? r++ : b++;
					x /= 2;
				}
				else {
					(int)log2(y) % 2 ? r++ : b++;
					y /= 2;
				}
			}
			(int)log2(y) % 2 ? r++ : b++;
			if (flip){
				r = r^b;
				b = r^b;
				r = r^b;
			}

			printf("%d\n", type[1] == 'b' ? b : r);
		}
		else{
			flip = !flip;
		}

	}
	return 0;
}

//Solved