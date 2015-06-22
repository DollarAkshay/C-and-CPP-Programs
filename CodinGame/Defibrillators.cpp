/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * $Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.codingame.com/ide/1500798534ae2080d70455e4476342630defd6b

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
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
#define DB(s,x) fprintf(stderr,s,x);



void readCord(double *n){
	
	char str[1000];
	scanf("%[^;\n]s", str);
	str[(strchr(str, ',') - str)] = '.';
	*n = stod(str);
}

double dist(double lon, double lat,double dlon,double dlat){

	double x = (lon - dlon)*cos((lat + dlat) / 2);
	double y = lat - dlat;
	return sqrt(x*x + y*y)*6371;

}

int main(){

	double ulon, ulat,min = 1e9;
	int n,dum1;
	char dum2[1000],name[1000],ans[1000];

	readCord(&ulon); getchar();
	readCord(&ulat); getchar();
	scanf("%d", &n);
	REP(i, n){
		double x, y;
		scanf("%d", &dum1);getchar();
		scanf("%[^\n;]s", name);getchar();
		scanf("%[^\n;]s", dum2);getchar();
		scanf("%[^\n;]s", dum2);getchar();
		readCord(&x);getchar();
		readCord(&y);
		double d = dist(ulon, ulat, x,y);
		if (d < min){
			min = d;
			strcpy(ans, name);
		}
	}
	printf("%s\n", ans);
}

//