#include <stdio.h>
#include<string.h>
#include<conio.h>

int main()
{
	int T, i, j, k, countup = 0, countlo = 0;
	char S[100];
	scanf("%d", &T);
	if (T>=1 && T<=10)
	{
		while (T--)
		{
			countup = 0;
			countlo = 0;
			scanf("%s", S);
			for (i = 0; i<strlen(S); i++)
			{
				if (isupper(S[i]))
					countup++;
				else if (islower(S[i]))
					countlo++;
			}
			if (countup==0 && countlo==0)
			{
				printf("Invalid Input\n");
				continue;
			}
			if (countup<countlo)
			{
				printf("%d\n", countup);
				continue;
			}
			else if (countup>countlo)
			{
				printf("%d\n", countlo);
			}
		}
	}
	else
	{
		printf("Invalid Test\n");
	}
	getch();
}