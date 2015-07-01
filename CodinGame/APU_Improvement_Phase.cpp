/*~~~~~~~~~~~~~~~~~~*
*                  *
* $Dollar Akshay$  *
*                  *
*~~~~~~~~~~~~~~~~~~*/

//

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
#include <vector>

using namespace std;

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define DB(s,x) fprintf(stderr,s,x)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

struct point{
	int x, y;
	point(){}
	point(int px, int py){
		x = px;
		y = py;
	}
	bool operator <(const point &n)const{
		return (x < n.x) || (x == n.x && y < n.y);
	}

	bool operator ==(point &n){
		return x == n.x && y == n.y;
	}
	bool operator !=(const point &n)const{
		return x != n.x || y != n.y;
	}
};

int w, h;
char s[31][31];

int links[30][30][30][30];
int added=0, link = 0;
point dir[4] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

void addLinks(point u,int l){


	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = u.x + dir[i].x, y = u.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] > '0' &&  links[u.y][u.x][y][x]<2){
			links[u.y][u.x][y][x]+=l;
			links[y][x][u.y][u.x]+=l;
			s[u.y][u.x]-=l;
			s[y][x]-=l;
			added++;
			printf("%d %d %d %d %d\n", u.x, u.y, x, y,l);
		}
	}


}


void addLinks2(point u, int l){


	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = u.x + dir[i].x, y = u.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] > '1' &&  links[u.y][u.x][y][x]<2){
			links[u.y][u.x][y][x] += l;
			links[y][x][u.y][u.x] += l;
			s[u.y][u.x] -= l;
			s[y][x] -= l;
			added++;
			printf("%d %d %d %d %d\n", u.x, u.y, x, y, l);
		}
	}


}

int getNeighbours(point p){

	int res = 0;
	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = p.x + dir[i].x, y = p.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] > '0'){
			res++;
		}
	}
	return res;

}

int getLinksToNeighbours(point p){

	int res = 0;
	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = p.x + dir[i].x, y = p.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] >= '0'){
			res += links[p.y][p.x][y][x];
		}
	}
	return res;

}

int getNeighbourTotalValue(point p){

	int res = 0;
	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = p.x + dir[i].x, y = p.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] > '0'){
			res += s[y][x] - '0';
		}
	}
	return res;

}

int has1Neighbour(point p){

	int res = 0;
	REP(i, 4){
		int dx = dir[i].x, dy = dir[i].y;
		int x = p.x + dir[i].x, y = p.y + dir[i].y;
		while (x >= 0 && x<w && y >= 0 && y<h && s[y][x] == '.'){
			y += dy;
			x += dx;
		}
		if (s[y][x] == '1'){
			return 1;
		}
	}
	return 0;

}

void attach1(int x, int n,int l){

	vector<point> remov;
	REP(i, h){
		REP(j, w){
			if (s[i][j] == '0' + x && getNeighbours({ j, i }) == n)
				remov.push_back({ j, i });
		}
	}

	REP(i, remov.size()){
		int rx = remov[i].x, ry = remov[i].y;
		addLinks(remov[i],l);
	}
}

void attach2(int x, int val, int l){

	vector<point> remov;
	REP(i, h){
		REP(j, w){
			if (s[i][j] == '0' + x && getNeighbourTotalValue({ j, i }) == val)
				remov.push_back({ j, i });
		}
	}

	REP(i, remov.size()){
		int rx = remov[i].x, ry = remov[i].y;
		addLinks(remov[i], l);
	}
}




void attach3(int x,int n, int li, int l){

	vector<point> remov;
	REP(i, h){
		REP(j, w){
			if (s[i][j] == '0' + x && getLinksToNeighbours({ j, i }) == li && getNeighbours({ j, i })==n )
				remov.push_back({ j, i });
		}
	}


	REP(i, remov.size()){
		DB("Attach 3 = %d,", remov[i].x);
		DB("%d has a value of ", remov[i].y);
		DB("%c\n", s[remov[i].y][remov[i].x]);
		int rx = remov[i].x, ry = remov[i].y;
		addLinks(remov[i], l);
	}
}

void attach4(){

	vector<point> remov;
	REP(i, h){
		REP(j, w){
			if (s[i][j] == '1' &&  has1Neighbour({ j, i }) && getNeighbours({ j, i }) == 2)
				remov.push_back({ j, i });
		}
	}


	REP(i, remov.size()){
		DB("Attach 3 = %d,", remov[i].x);
		DB("%d has a value of ", remov[i].y);
		DB("%c\n", s[remov[i].y][remov[i].x]);
		int rx = remov[i].x, ry = remov[i].y;
		addLinks2(remov[i], 1);
	}
}

int main(){


	scanf("%d%d", &w, &h);
	REP(i, h){
		scanf("%s", s[i]);
		REP(j, w){
			if (s[i][j] > '0')
				link += s[i][j] - '0';
		}
		DB("%s\n", s[i]);
	}
	DB("Links needed = %d\n", link);


	while (added<link/2){
		FORD(i,4,1)
			attach1(i*2,i,2);
		attach1(7, 4,1);
		attach1(5, 3,1);
		attach1(3, 2,1);
		attach1(1, 1, 1);

		FORD(i, 8, 1)
			attach2(i, i, 1);

		attach3(1, 1, 4, 1);
		attach3(2, 2, 4, 1);
		attach3(3, 3, 4, 1);
		attach3(4, 4, 4, 1);
		int b = added;
		while (1){
			attach4();
			if (b == added)
				break;
			else
				b = added;
		}
		attach1(2, 2, 1);

		
	}

	return 0;
}

//