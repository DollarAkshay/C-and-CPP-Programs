//http://www.hackerearth.com/problem/algorithm/the-best-internet-browser-3/

#include <stdio.h>
#include <string.h>

int main(){

	int t, i, vov = 0, l;
	char url[201];
	scanf("%d", &t);
	while (t--){
		scanf("%s", url);
		l = strlen(url);
		for (i = 4; url[i + 4]; i++){
			char c = url[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				vov++;
		}
		printf("%d/%d\n", l - 4 - vov, l);
		vov = 0;
	}
}

//Solved
