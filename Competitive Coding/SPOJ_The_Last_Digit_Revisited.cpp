/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/LASTDIG2/

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define ll long long

vector<int> cy[10];

void pre(){
	FOR(i, 0, 9){
		int v[10];
		int p = i;
		memset(v, 0, 40);
		while (v[p]==0){
			v[p] = 1;
			cy[i].push_back(p);
			p *= i;
			p %= 10;
		}
	}
}
int main(){
	pre();
	ll int t, b, e;
	scanf("%lld", &t);
	REP(tc, t){
		char s[1001];
		scanf("%s %lld", s, &e);
		b = s[strlen(s)-1]-'0';
		printf("%d\n", e==0?1:cy[b][(e-1)%cy[b].size()]);
	}
	return 0;
}

//Solved