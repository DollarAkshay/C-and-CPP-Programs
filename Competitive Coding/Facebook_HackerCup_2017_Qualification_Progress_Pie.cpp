/*~~~~~~~~~~~~~~~~~~*
 *                  *
 * Dollar Akshay$  *
 *                  *
 *~~~~~~~~~~~~~~~~~~*/

//https://www.facebook.com/hackercup/problem/1254819954559001/

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
#define MS(x,n) memset(x,n,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007
#define PI 3.14159265



int main(){

    int t;

    FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");

    fscanf(fin, "%d", &t);
    REP(tc, t){
        int p, x, y;
        fscanf(fin, "%d %d %d", &p, &x, &y);
        
        double degrees = fmod(p*3.6 + 270, 360);

        double point_angle = atan2( y-50, x-50) * 180 / PI;
        
        if(point_angle < 0)
            point_angle = -point_angle;
        else
            point_angle = 360 - point_angle;

        double point_radius = sqrt( (x-50)*(x-50) + (y-50)*(y-50) );  

        if (point_radius < 50 && point_angle <= degrees)
            fprintf(fout, "Case #%d: black\n", tc+1);
        else
            fprintf(fout, "Case #%d: white\n", tc+1);
        
    }
    return 0;
}

//