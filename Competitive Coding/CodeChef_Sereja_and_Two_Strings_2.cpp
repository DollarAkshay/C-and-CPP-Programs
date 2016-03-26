/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codechef.com/MARCH16/problems/SEATSTR2

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
#include <functional>

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
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007


set<string> unqperm;


void swap(string &a, int i, int j) {

	char c = a[i];
	a[i] = a[j];
	a[j] = c;

}

bool isAnagram(string s1, string s2) {


	int f1[255], f2[255];
	int l1 = s1.length(), l2 = s2.length();

	if (l1!=l2)
		return false;

	MS0(f1);
	MS0(f2);
	

	REP(i, l1) {
		f1[s1[i]]++;
		f2[s2[i]]++;
	}


	REP(i, 255) {
		if (f1[i] != f2[i]) {
			return false;
		}
	}

	return true;

}

bool isSimiliarBF(string a, string b) {

	int n = a.size();

	REP(ia, n) {
		FOR(ja, ia, n-1) {

			swap(a, ia, ja);
			REP(ib, n) {
				FOR(jb, ib, n-1) {
					swap(b, ib, jb);
					if (a==b)
						return true;
					swap(b, ib, jb);
				}
			}
			swap(a, ia, ja);
		}
	}

	return false;

}

bool isSimiliar(string a, string b) {

	if (!isAnagram(a, b))
		return false;

	int n = a.size(), mist = 0;
	vector<int> pts;

	REP(i, n) {
		if (a[i]!=b[i]) {
			if (++mist > 4)
				break;
			pts.push_back(i);
		}
	}

	if (mist<=3) {
		return true;
	}
	else if (mist == 4) {

		if ((a[pts[0]]==b[pts[1]] && b[pts[0]]==a[pts[1]]) ||
			(a[pts[0]]==b[pts[2]] && b[pts[0]]==a[pts[2]]) ||
			(a[pts[0]]==b[pts[3]] && b[pts[0]]==a[pts[3]]))
			return true;
		else
			return false;

	}
	else {
		return false;
	}
}

int noofSwaps(string a, string b) {

	int n = a.size(), mist = 0;
	vector<int> pts;

	REP(i, n) {
		if (a[i]!=b[i]) {
			if (++mist > 4)
				break;
			pts.push_back(i);
		}
	}

	if (mist==0) {
		return 0;
	}
	else if (mist==2) {
		return 1;
	}
	else if (mist==3 || mist==4) {
		return 2;
	}
	else {
		sp;
		return 3;
	}
}

void generateStringPermutation(string s, int start, int end) {

	if (start==end) {
		unqperm.insert(s);
	}
	else {
		FOR(i, start, end) {
			swap(s, start, i);
			generateStringPermutation(s, start+1, end);
			swap(s, start, i);
		}
	}
}

int bruteForce(string s) {

	unqperm.clear();
	generateStringPermutation(s, 0, s.size()-1);

	int res = 0;

	for (auto it = unqperm.begin(); it!=unqperm.end(); it++) {
		for (auto jt = unqperm.begin(); jt!=unqperm.end(); jt++) {
			if (isSimiliar(*it, *jt)) 
				res++;
		}
	}

	return res;
}

ll int fact(int n) {

	ll int res = 1;
	FOR(i, 2, n)
		res *= i;
	return res;

}

ll int similiarPerms(string s) {

	string orig = s;

	set<string> sim;

	set<string> swaptyp[3];
	int n = s.size();
	

	REP(i1, n) {
		REP(j1, n) {
			swap(s, i1, j1);
			REP(i2, n) {
				REP(j2, n) {
					swap(s, i2, j2);
					sim.insert(s);
					swaptyp[noofSwaps(orig, s)].insert(s);
					swap(s, i2, j2);
				}
			}
			swap(s, i1, j1);
		}
	}

	printf("\nSwap 0 = %3d\nSwap 1 = %3d\nSwap 2 = %3d\n", swaptyp[0].size(), swaptyp[1].size(), swaptyp[2].size() );

	return sim.size();

}

ll int algo(string s) {


	int n = s.size();

	ll int res = fact(n);
	res = res*(1 + n*(n-1)/2 + (n*(n-1)/2)*(n*n-n-2)/2);
	return res;


}

ll int simG(ll int n) {

	return (24 - 14*n + 21*n*n - 10*n*n*n + 3*n*n*n*n)/24;

}


int main(){

	int t;

	scanf("%d", &t);
	REP(tc, t){
		string s;
		cin>>s;

		printf("No of Similiar Perms = %d\n", similiarPerms(s));

		ll int bf = bruteForce(s), al = algo(s);

		printf("# %2d BF = %lld\n", tc+1, bf);
		printf("# %2d Alg = %lld\n\n", tc+1, al);
		
	}

	sp;
	return 0;
}

//