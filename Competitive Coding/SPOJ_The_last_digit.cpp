/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/LASTDIG/

#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(i,n) FOR(i,0,(int)n-1)

vector<int> cy[10];

void pre(){
	FOR(i, 0, 9){
		int v[10];
		int p=i;
		memset(v,0,40);
		while (v[p]==0){
			v[p]=1;
			cy[i].push_back(p);
			p*=i;
			p%=10;
		}
	}
}
int main(){
	pre();
	int t,b,e;
	scanf("%d",&t);
	REP(tc,t){
		scanf("%d%d",&b,&e);
		printf("%d\n", e==0?1:cy[b%10][(e-1)%cy[b%10].size()]);
	}
	return 0;
}

//Solved