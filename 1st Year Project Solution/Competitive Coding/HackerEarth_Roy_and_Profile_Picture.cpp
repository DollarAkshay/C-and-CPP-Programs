http://www.hackerearth.com/problem/algorithm/roy-and-profile-picture/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,n-1)
#define ll long long


int main(){
	int l, n, w, h;
	scanf("%d%d", &l, &n);
	REP(i, n){
		scanf("%d%d", &w, &h);
		if (w<l || h<l)
			cout << "UPLOAD ANOTHER\n";
		else if (w == h)
			cout << "ACCEPTED\n";
		else
			cout << "CROP IT\n";

	}
	return 0;
}

//Solved