#include <stdio.h>

int len = 61;
char map[30][30],n;

int path(int sy, int sx){

	if (sy - 1 >= 0 && sx - 1 >= 0){
		if (map[sy - 1][sx - 1] == 'E')
			return 1;
		else if (map[sy - 1][sx - 1] == 'P'){
			int temp = 1 + path(sy - 1, sx - 1);
			len = temp<len ? temp : len;
		}
	}
	if (sy - 1 >= 0){
		if (map[sy - 1][sx] == 'E')
			return 1;
		else if (map[sy - 1][sx] == 'P'){
			int temp = 1 + path(sy - 1, sx);
			len = temp<len ? temp : len;
		}
	}
	if (sy - 1 >= 0 && sx + 1<n){
		if (map[sy - 1][sx + 1] == 'E')
			return 1;
		else if (map[sy - 1][sx + 1] == 'P'){
			int temp = 1 + path(sy - 1, sx + 1);
			len = temp<len ? temp : len;
		}
	}
	if (sx + 1<n){
		if (map[sy][sx + 1] == 'E')
			return 1;
		else if (map[sy][sx + 1] == 'P'){
			int temp = 1 + path(sy, sx + 1);
			len = temp<len ? temp : len;
		}
	}
	if (sy + 1<n && sx + 1<n){
		if (map[sy + 1][sx + 1] == 'E')
			return 1;
		else if (map[sy + 1][sx + 1] == 'P'){
			int temp = 1 + path(sy + 1, sx + 1);
			len = temp<len ? temp : len;
		}
	}
	if (sy + 1<n){
		if (map[sy + 1][sx] == 'E')
			return 1;
		else if (map[sy + 1][sx] == 'P'){
			int temp = 1 + path(sy + 1, sx);
			len = temp<len ? temp : len;
		}
	}
	if (sy + 1<n && sx - 1<n){
		if (map[sy + 1][sx - 1] == 'E')
			return 1;
		else if (map[sy + 1][sx - 1] == 'P'){
			int temp = 1 + path(sy + 1, sx - 1);
			len = temp<len ? temp : len;
		}
	}
	if (sx - 1<n){
		if (map[sy][sx - 1] == 'E')
			return 1;
		else if (map[sy][sx - 1] == 'P'){
			int temp = 1 + path(sy, sx - 1);
			len = temp<len ? temp : len;
		}
	}
	return 0;
}

int main()
{

	int i, j;
	int sx, sy, ex, ey;
	//Reading Input
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	for (j = 0; j<n; j++){
		scanf("%c", &map[i][j]);
		if (map[i][j] == 'S'){
			sy = i;
			sx = j;
		}
		else if (map[i][j] == 'E'){
			ey = i;
			ex = j;
		}
	}
	printf("%d", path(sy, sx));
}
