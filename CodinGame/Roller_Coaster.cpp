/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/15634301d88f7d5b66a751fcfc4fc08ce7bd9c0

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
#include <map>
#include <stack>
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007
struct point{
	int x, y;
};


int nx[10000];
int e[10000];

int main(){

	int l, c, n;
	ll int tot=0, paisa = 0;
	int q[10000],front=0,rear;
	scanf("%d%d%d", &l, &c, &n);
	REP(i, n){
		scanf("%d", &q[i]);
		tot += q[i];
		nx[i] = -1;
	}

	REP(i, c){
		if (nx[front] >= 0){
			paisa += e[front];
			front = nx[front];
		}
		else{
			int fools = 0,start = front;
			while (fools < tot && fools + q[front] <= l){
				fools += q[front];
				front = (front + 1) % n;
			}
			e[start] = fools;
			paisa += e[start];
			nx[start] = front;
		}
	}
	printf("%lld\n", paisa);
	return 0;
}

//Solved