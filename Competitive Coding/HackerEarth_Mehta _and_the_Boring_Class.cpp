
//http://www.hackerearth.com/october-sky-1/algorithm/mehta-and-the-boring-class/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

ll int p[1000001];
ll int f[1000001];
ll int s[1000001];


void seiv(){
	MS1(p);
	long int i, j;
	p[0] = p[1] = 0;
	int lim = sqrt(1000001);
	for (i = 2; i <= lim; i++){
		if (p[i]){
			for (j = i*i; j<1000001; j += i){
				if (p[j])
					p[j] = 0;
			}
		}
	}
}


void preCompute(){

	// F(x) from 1 to 1000000
	f[1] = 1;
	s[1] = 1;
	FOR(i, 2, 100000){
		int x = i, ans = 0;
		if (p[i]){
			f[i] = 1;
		}
		else{
			FOR(j, 2, i){
				if (p[j] && x%j == 0){
					while (x%j == 0){
						x /= j;
						ans++;
					}
					if (x == 1){
						f[i] = ans;
						break;
					}
				}
			}
		}
		s[i] = s[i - 1] + f[i];
	}

}

int main(){

	seiv();
	preCompute();
	ll int t, a, b;
	scanf("%lld", &t);
	REP(tc, t){
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", s[b] - s[a] + f[a]);
	}
	return 0;
}

//Partially Solved