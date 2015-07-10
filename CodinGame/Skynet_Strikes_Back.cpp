/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1525658dd27416899528ee223672344e5fe3f0a

#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define SORTR(a) sort(a.rbegin(),a.rend())
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007
#define DB(s,x) fprintf(stderr,s,x);

using namespace std;

struct block{
	int dv;
	int di;
	int i;

	block(){}
	block(int a, int b, int c){
		dv = a;
		di = b;
		i = c;
	}
};

bool comp(block l, block r){
	return (l.dv>r.dv) || (l.dv==r.dv && l.di<r.di);
}

int v[500], d[500], isGate[500], isNode[500], gate, n;
int graph[500][500];

vector<int> node;

int getGatewayLinkCount(int s){

	int c = 0;
	REP(i,n){
		if (isGate[i] && graph[s][i])
			c++;
	}

	return c;

}

void bfs(int s){

	int u;
	queue<int> q;

	MS0(v);
	MS0(d);

	v[s] = 1;
	q.push(s);

	if (isNode[s])
		d[s] = getGatewayLinkCount(s);
	else
		d[s]=0;

	while (!q.empty()){
		u = q.front();
		q.pop();
		REP(i, n){
			if (!v[i] && graph[u][i] && !isGate[i]){
				v[i] = v[u] + 1;
				d[i] = d[u] + getGatewayLinkCount(i);
				q.push(i);
			}
		}
	}

}

int removeLinkFrom(int u){

	int v=0;
	REP(i, n){
		if (isGate[i] && graph[u][i]){
			v = i;
			break;
		}
	}

	graph[u][v] = 0;
	graph[v][u] = 0;
	
	return v;
}



int main(){

	int e, g, agent;
	scanf("%d%d%d", &n, &e, &g);
	DB("%d ", n); DB("%d ", e); DB("%d\n",g)
	REP(i, e){
		int u, v;
		scanf("%d%d", &u, &v);
		DB("%d ",u);
		DB("%d\n",v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	REP(i, g){
		int x;
		scanf("%d", &x);
		DB("%d ",x);
		isGate[x] = 1;
		REP(i, n){
			if (isNode[i]==0 && graph[x][i]){
				node.pb(i);
				isNode[i] = 1;
			}
		}
	}


	while (1){
		scanf("%d", &agent);
		if (getGatewayLinkCount(agent)>0)
			printf("%d %d\n", agent, removeLinkFrom(agent));
		else{
			bfs(agent);
			vector<block> ranks;
			REP(i, node.size()){
				if (d[node[i]])
					ranks.pb(block(d[node[i]]-v[node[i]]+1,v[node[i]]-1,node[i]) );
			}
			sort(begin(ranks), end(ranks), comp);
			printf("%d %d\n", ranks[0].i, removeLinkFrom(ranks[0].i));
		}
	}
	return 0;
}

//Solved