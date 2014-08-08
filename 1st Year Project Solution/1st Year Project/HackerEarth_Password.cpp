
/*
Password

Danny has a possible list of passwords of Manny's facebook account.All passwords length is odd.
But Danny knows that Manny is a big fan of palindromes. So, his password and reverse of his password
both should be in the list.
You have to print the length of Manny's password and it's middle character.

Note : The solution will be unique.

INPUT
The first line of input contains the integer N, the number of possible passwords.
Each of the following N lines contains a single word, its length being an odd number greater
than 2 and lesser than 14. All characters are lowercase letters of the English alphabet.

OUTPUT
The first and only line of output must contain the length of the correct password and its
central letter.

CONSTRAINTS
1 ≤ N ≤ 100

Sample Input :
4
abc
def
feg
cba
	   
Sample Output :
3 b

*/



#include<stdio.h>
#include<string.h>
#include<conio.h>


int palindrome(char s1[], char s2[], int l){
	int i, j;
	for (i = 0, j = l - 1; i < l; i++, j--){
		if (s1[i] != s2[j])
			return 0;
	}
	return 1;
}




void main(){
	int n, i, j, len;
	char pass[100][14];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s", pass[i]);
		len = strlen(pass[i]);
		for (j = 0; j < i; j++){
			if (len != strlen(pass[j]))
				continue;
			if (palindrome(pass[i], pass[j], len)){
				printf("%d %s %c", len, pass[i], pass[i][(len - 1) / 2]);
				i = n;
				break;
			}
		}
	}
	_getch();
}



