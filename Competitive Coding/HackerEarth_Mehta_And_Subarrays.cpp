//http://www.hackerearth.com/october-sky-1/algorithm/mehta-and-subarrays/

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

ll int a[1000000];
ll int s[1000000];
int main(){

	ll int n, pos, len, count = 1, i, j;
	scanf("%lld", &n);
	REP(i, n){
		scanf("%lld", &a[i]);
		s[i] = i ? s[i - 1] + a[i] : a[0];
	}
	pos = -1;
	FORD(i, n - 1, 0){
		if (s[i] >= 0){
			pos = i;
			len = i + 1;
			break;
		}
	}
	if (pos == -1){
		printf("-1");
	}
	else{
		int sum = s[pos];
		for (i = pos + 1, j = 0; i<n; i++, j++){
			sum += a[i];
			sum -= a[j];
			if (sum >= 0)
				count++;
		}
		printf("%d %d", len, count);
	}
	return 0;
}

//Partially Solved 70/100