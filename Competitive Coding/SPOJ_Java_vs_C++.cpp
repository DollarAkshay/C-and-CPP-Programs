/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//http://www.spoj.com/problems/JAVAC/

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
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007

char s[1001];

int main(){

	while (scanf("%s",s)>0){
		bool error = 0,j=0,c=0;
		string res="";
		int len = strlen(s);
		REP(i, len){
			if (isupper(s[i])){
				if (i && isalpha(s[i-1]) && (i==len-1 || isalpha(s[i+1]))){
					res += '_';
					res += tolower(s[i]);
					c = 1;
				}
				else{
					error = 1;
					break;
				}
			}
			else if (s[i]=='_'){
				if (i && islower(s[i-1]) && islower(s[i+1])){
					i++;
					res += toupper(s[i]);
					j = 1;
				}
				else{
					error = 1;
					break;
				}
			}
			else
				res += s[i];
		}
		if (error || (j&&c) )
			printf("Error!\n");
		else
			printf("%s\n", res.c_str());
	}
	return 0;
}

//Solved