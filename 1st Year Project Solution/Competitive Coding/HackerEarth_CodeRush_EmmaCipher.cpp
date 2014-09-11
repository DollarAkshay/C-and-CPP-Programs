#include <stdio.h>
#include <string.h>

int freq[28];
char str[10000];

char low(){
	int min = 10000;
	char c = -1;
	for (int i = 0; i < 28; i++){
		if (freq[i] < min && freq[i]){
			min = freq[i];
			c = i;
		}
	}
	freq[c] = 0;
	if (c>1)
		c += 63;
	else if (c == 1)
		c = '.';
	else if (c == 0)
		c = ' ';

	return c;
}

char high(){
	int max = 0;
	char c = -1;
	for (int i = 27; i >= 0; i--){
		if (freq[i] > max){
			max = freq[i];
			c = i;
		}
	}
	freq[c] = 0;
	if (c>1)
		c += 63;
	else if (c == 1)
		c = '.';
	else if (c == 0)
		c = ' ';
	return c;
}

int cipher(){
	char l = low();
	char h = high();
	if (l < 0 || h < 0)
		return 0;
	for (int i = 0; str[i]; i++){
		if (str[i] == h)
			str[i] = l;
		else if (str[i] == l)
			str[i] = h;
	}
	return 1;
}

int main()
{
	int t, i;

	scanf("%d", &t);
	getchar();
	while (t--){

		for (i = 0;; i++){
			scanf("%c", &str[i]);
			if (str[i] == '\n' || str[i] == 10){
				break;
			}
		}
		str[i] = '\0';
		printf("%s\n", str);
		for (i = 0; str[i]; i++){
			if (str[i] == ' ')
				freq[0]++;
			else if (str[i] == '.')
				freq[1]++;
			else
				freq[str[i] - 63]++;
		}
		while (cipher());
		printf("%s\n", str);
		str[0] = '\0';
	}
	return 0;
}
