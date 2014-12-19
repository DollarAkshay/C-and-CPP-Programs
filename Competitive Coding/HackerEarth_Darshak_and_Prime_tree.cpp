/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.hackerearth.com/tcetcyphers-5/algorithm/chef-and-prime-tree/

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

char p[5000001];

void seiv(){
	MS1(p);
	long int i, j;
	p[0] = p[1] = 0;
	int lim = sqrt(5000001);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<5000001; j += i){
				if (p[j])
					p[j] = 0;
			}
		}
	}
}

int main(){

	seiv();
	int t, x, y;
	scanf("%d", &t);
	REP(tc, t){
		scanf("%d%d", &x, &y);
		int good = 0;
		while (x != y){
			if (x>y){
				good += p[x] ? -x : x;
				x /= 2;
			}
			else{
				good += p[y] ? -y : y;
				y /= 2;
			}
		}
		good += p[x] ? -x : x;
		printf("%d\n", good);
	}
	return 0;
}

//Solved