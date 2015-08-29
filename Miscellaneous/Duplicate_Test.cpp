/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//

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



int main(){

	FILE *f1 = fopen("HackerRank_Full.txt", "r");
	FILE *f2 = fopen("HackerRank_Win.txt", "r");
	FILE *f3 = fopen("HackerRank_Win_sorted.txt", "w");
	
	string s;
	map<string, int> hash;
	int i = 1;
	vector<pair<int, string>> hash2;

	while(fscanf(f1,"%s" , s.c_str())>0){
		if (hash.count(s.c_str())==0)
			hash[s.c_str()] = i++;
		else
			printf("'%s' already exists\n", s.c_str());
	}

	while (fscanf(f2, "%s", s.c_str())>0) {
		hash2.push_back( mp(hash[s.c_str()], s.c_str()) );
	}
	SORT(hash2, hash2.size());
	REP(i, hash2.size())
		fprintf(f3, "%s\n", hash2[i].second.c_str());

	fclose(f1);
	fclose(f2);
	fclose(f3);

	sp;
	return 0;
}

//