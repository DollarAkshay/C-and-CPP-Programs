#include<stdio.h>
#include<string.h>

int main() {

	int count = 0;
	char words[100][20];

	FILE *f = fopen("data.txt", "r");

	while (fscanf(f, "%s", words[count])>0) {

		if (strcmp(words[count], "Quora")==0) {
			printf("%s", words[count-1]);
			break;
		}
		else
			count++;

	}

	return 0;

}