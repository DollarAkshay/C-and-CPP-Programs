/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//https://code.google.com/codejam/contest/11254486/dashboard#s=p1

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

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

char s1[20],s2[20];

int res1 = -1, res2 = -1;

bool check(int n1, int n2, int off) {

	if (n1<0 || n2<0)
		return false;

	int len = strlen(s1);

	FORD(k, off, 0) {
		if(s1[k]!='?' && s1[k]!=(n1%10+'0'))
			return false;
		n1 /= 10;
	}

	FORD(k, off, 0) {
		if (s2[k]!='?' && s2[k]!=(n2%10+'0'))
			return false;
		n2 /= 10;
	}

	return true;
}

int intlen(int n) {
	int res = 0;
	while (n>0) {
		res++;
		n /= 10;
	}
	return res;
}

void bruteforce(int tc) {

	ll int diff = INT64_MAX;
	char t1[20], t2[20];
	int len = strlen(s1);


	strcpy(t1, s1);
	strcpy(t2, s2);

	vector<int> pos1, pos2;

	REP(i, len) {
		if (t1[i]=='?')
			pos1.push_back(i);
	}

	REP(i, len) {
		if (t2[i]=='?')
			pos2.push_back(i);
	}

	int lim1 = pow(10, pos1.size());
	int lim2 = pow(10, pos2.size());

	REP(i, lim1) {

		int ti = i;
		FORD(k, pos1.size()-1, 0) {
			t1[pos1[k]] = ti%10 +'0';
			ti /= 10;
		}

		REP(j, lim2) {

			int tj = j;
			FORD(k, pos2.size()-1, 0) {
				t2[pos2[k]] = tj%10 +'0';
				tj /= 10;
			}
			
			ll int num1 = atoll(t1), num2 = atoll(t2);

			if (abs(num1-num2)<diff) {
				res1 = num1;
				res2 = num2;
				diff = abs(num1-num2);
			}
		}

	}

	fprintf(out, "BRUT #%d: %0*d %0*d\n", tc+1, len, res1, len, res2);

}

int main() {

	int t;
	fscanf(in, "%d", &t);
	REP(tc, t) {

		fscanf(in, "%s %s\n", s1, s2);
		int len = strlen(s1);
		int n1 = 0, n2 = 0;

		REP(i, len+1) {
			n1 *= 10;
			n2 *= 10;

			if (s1[i]=='?' && s2[i]=='?') {
				if (n1>n2) {
					n1 += 0;
					n2 += 9;
				}
				else if (n2>n1) {
					n2 += 0;
					n1 += 9;
				}
				else {
					n1 += 0;
					n2 += 0;
				}
			}
			else if (s1[i]=='?' || s2[i]=='?') {
				if (n1>n2) {
					n1 += s1[i]=='?'?0:s1[i]-'0';
					n2 += s2[i]=='?'?9:s2[i]-'0';
				}
				else if (n2>n1) {
					n1 += s1[i]=='?'?9:s1[i]-'0';
					n2 += s2[i]=='?'?0:s2[i]-'0';
				}
				else {
					n1 += s1[i]=='?'?s2[i]-'0':s1[i]-'0';
					n2 += s1[i]=='?'?s2[i]-'0':s1[i]-'0';
				}
			}
			else {
				n1 += s1[i]-'0';
				n2 += s2[i]-'0';
			}
			if (n2>n1) {
				FOR(k, 1, i) {
					int po10 = pow(10, k);
					if (s2[i-k]=='?' && (n2/po10)>0) {
						int diff1 = abs(n1-(n2-po10)), diff2 = abs(n1-n2);

						if (check(n1, n2-po10, i) && diff1<=diff2)
							n2 -= po10;
					}
				}
				FOR(k, 1, i) {
					int po10 = pow(10, k);
					if (s1[i-k]=='?' && (n1/po10)%10!=9) {
						int diff1 = abs(n2-(n1+po10)), diff2 = abs(n1-n2);
						if (check(n1+po10, n2, i) && diff1<diff2)
							n1 += po10;
					}
				}

			}
			if (n1>n2) {
				FOR(k, 1, i) {
					int po10 = pow(10, k);
					if (s1[i-k]=='?' && (n1/po10)>0) {
						int diff1 = abs(n2-(n1-po10)), diff2 = abs(n1-n2);
						if (check(n1-po10, n2, i) && diff1<=diff2)
							n1 -= po10;
					}
				}
				FOR(k, 1, i) {
					int po10 = pow(10, k);
					if (s2[i-k]=='?' && (n2/po10)%10!=9) {
						int diff1 = abs(n1-(n2+po10)), diff2 = abs(n1-n2);
						if (check(n1, n2+po10, i) && diff1<diff2)
							n2 += po10;
					}
				}
			}
		}
		bruteforce(tc);
		if (res1!=n1 && res2!=n2) {
			printf("OOPS\n");
		}
		fprintf(out, "Case #%d: %0*d %0*d\n", tc+1, len, n1, len, n2);

	}
	fclose(in);
	fclose(out);
	sp;
	return 0;
}

//