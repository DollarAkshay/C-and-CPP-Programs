#include <stdio.h>
#include <string.h>

int main()
{
	int n, i;
	char p[1000], t[100000], r[1000];
	scanf("%d", &n);
	while (n--){
		scanf("%s %s", p, t);
		strcpy(r, p);
		strrev(r);
		if (strstr(t, p) || strstr(t, r)) printf("YES");
		else printf("NO");
	}