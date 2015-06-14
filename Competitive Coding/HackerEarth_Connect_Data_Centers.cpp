/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.hackerearth.com/game-of-codes-1/algorithm/arrange-servers/

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

vector<pair<int, int>> edge;
vector<pair<int, int>> conn;

int s, a[20],pos[20];

int cost(){

	REP(i, s)
		pos[a[i]] = i;
	int wire = 0;

	REP(i, edge.size())
		wire += abs(pos[edge[i].first] - pos[edge[i].second]);

	return wire;

}



int main(){

	int t;
	scanf("%d%d", &s, &t);

	REP(i,s)
		conn.push_back(make_pair(0, i));
	
	REP(i, t){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edge.push_back(make_pair(u, v));
		conn[u ].first++;
		conn[v ].first++;
	}

	sort(begin(conn), begin(conn) + s);



	int dir = 0;
	for (int i=0, j=s-1,k=0; i <= j;){
		if (dir==0)
			a[i++] = conn[k++].second;
		else
			a[j--] = conn[k++].second;
		dir = !dir;
	}


	printf("%d\n", cost());
	sp;
	return 0;
}

//DintSubmit - Might Work