#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define sp system("pause")
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,n) FOR(i,0,(int)n-1)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,1,sizeof(x))
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define MOD 1000000007

char bits[8000];
int k = 0;

void getbits(char c){
	FORD(i, 6, 0)
		bits[k++] = ((c&(1<<i))>>i) + '0';
	
}

void encode(){

	REP(i, k){
		char c = bits[i], len = 1;
		while (c==bits[i+1]){
			len++;
			i++;
		}

		if (c == '1')
			printf("0 ");
		else
			printf("00 ");

		REP(j, len)
			printf("0");
		if (i<k-1)
			printf(" ");
	}

}

int main()
{
    char m[100];
	scanf("%[^\n]s", m);
	int len = strlen(m);
	REP(i,len)
		getbits(m[i]);
	encode();
	return 0;
}