//http://www.hackerearth.com/problem/algorithm/saxie-and-strings/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t, i, j = 0;
	char s[101], r[101];
	scanf("%d", &t);
	while (t--){
		scanf("%s", s);
		int len = strlen(s);
		for (i = len - 1, j = 0; i + 1; i--, j++)
			r[j] = s[i];
		if (strcmp(s, r))
			puts("NO");
		else
			puts("YES");
		memset(s, 0, len);
		memset(r, 0, len);
	}
}

//Solved
