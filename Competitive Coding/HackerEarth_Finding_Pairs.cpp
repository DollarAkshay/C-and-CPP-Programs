#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define ll long long

int main(){
	int t, n, x,ans;
	vector<pair<int, int>> v;
	scanf("%d", &t);
	REP(i, t){
		scanf("%d", &n);
		ans = n;
		REP(j, n){
			scanf("%d", &x);
			int exists = 0;
			int s = v.size();
			REP(k,s){
				if (v[k].first == x){
					v[k].second++;
					exists = 1;
					break;
				}
			}
			if (!exists)
				v.push_back(make_pair(x, 1));
		}
		int s = v.size();
		REP(j,s){
			if (v[j].second > 1)
				ans += (v[j].second)*(v[j].second - 1) / 2;
		}
		printf("%d\n", ans);
		v.clear();
	}
	system("pause");
	return 0;
}
