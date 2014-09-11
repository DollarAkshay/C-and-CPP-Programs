/*Serena is interested in only red and yellow roses. She is arranging flowers in some fashion to be presented at her friend's birthday. Her friend loves only red and yellow roses(but mostly red ones). The flowers can be arranged only in the following three ways: 
1) red
2) red, yellow
3) red, yellow, yellow
This sequence may be repeated endlessly but if it goes somewhere wrong then she won't go to the party. As she is getting late for the party, Serena gives this job to her flower vendor giving all the instructions. However, the vendor is suffering from alzheimer disease and forgets all the arrangement and the required color of the roses(he just remembers that only roses were required). Due to lack of memory, vendor decides to create different sequences of roses so that Serena can choose the appropriate one. Since Serena is short of time, help her in making correct choice from the given sequence of roses.

Constraints: The bouquet can have 1 to 10^5 (both inclusive) number of roses.

Input: The first line contains an integer T denoting the number of test cases. The second line contains a sequence of characters representing color for the roses for example, 'Y' for yellow roses, 'R' for red roses, 'W' for white roses and so on...

Output: Print “YES” if the sequence is valid and “NO” if it is invalid.*/

#include<stdio.h>
#include<string.h>
 
int main(){

	int n, i, j, y = 0;
	char s[100000];
	scanf("%d", &n);
	//No of Test Cases
	for (i = 0; i < n; i++){

		scanf("%s", s);
		int len = strlen(s);
		if (s[0] != 'R')
			printf("NO\n");
		else{
			for (j = 0; j < len; j++){
				if (s[j] != 'R' && s[j] != 'Y'){
					printf("NO\n");
					break;
				}
				else if (s[j] == 'Y'){
					if (++y>2){
						printf("NO\n");
						break;
					}
				}
				else
					y = 0;

			}
			if (j == len)
				printf("YES\n");
			y = 0;
			memset(s, 0, len);
		}
	}
}

