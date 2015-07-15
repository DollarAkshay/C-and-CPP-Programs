/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/148336711054a6e0efd78e43572a33a717f17de

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
#define DB(s,x) fprintf(stderr,s,x);
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

int main(){
	unsigned int x, size;
	bitset<64> b;

	scanf("%d", &size);

	for (int i = 0; i < size / 16; i++){
		scanf("%x", &x);
		REP(j, 32){
			b[63 - i * 32 - j] = x % 2;
			x /= 2;
		}
	}
	/*
	for (int i = 0; i < size / 16; i++)
		b[i] = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			b[(i+j) / 32] ^= (   a[i/32] >> (i%32)   &   a[j/32+size/32] >> (j%32)   &   1) << (i+j)%32;

	for (int i = 0; i < size / 16; i++)
		cout << hex << b[i] << " ";

		*/
	return 0;
}
//