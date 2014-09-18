#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define ll long long
#define MOD 1000000007


int main(){

	int t, n, k, r = 0;
	bool del;
	int f[100000];
	scanf("%d", &t);
	REP(i, t){
		del = false;
		r = 0;
		scanf("%d%d", &n, &k);
		REP(j, n)
			scanf("%d", &f[j]);
		while (r<k){
			REP(j, n - 1){
				if (f[j] == -1)
					continue;
				int next = f[j + 1];
				if (next == -1){
					int k = j + 2;
					while (f[k] == -1)
						k++;
					next = f[k];
				}
				//printf("Comparing %d and %d when r = %d\n", f[j], next,r);
				if (f[j]<next){
					//cout << "Deleting " << f[j]<<endl;
					f[j] = -1;
					del = true;
					r++;
					break;
				}
			}
			if (del == false){
				n--;
				r++;
			}
			del = false;
		}
		REP(j, n)
		if (f[j] != -1)
			printf("%d ", f[j]);
		cout << endl;

	}
	return 0;
}

//Partially Solved : 10/100
//Time Limit Exceded