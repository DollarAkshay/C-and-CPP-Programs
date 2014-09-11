/*
Little Arihant has always wanted to be the best Pokemon trainer in this world. And he thinks he has achieved his goal, so he wants to quickly go and meet Professor Oak and verify this fact. But like all Pokemon trainers, he has a weird habit, too. He catches Pokemons which can go through evolution to become a better one. After roaming in the Pokeworld for days, he has finally managed to catch k such Pokemons.

The way he can make a Pokemon go through evolution is NOT by making them fight battles, but by using an evolution stone. Since he has k Pokemons, he naturally needs k evolution stones for every one of them, as well.

Now it takes little Arihant one complete day, to use the evolution stone on one Pokemon. And for each Pokemon, he knows how many days will they take to evolute after the evolution stone has been used on them.

He will go to meet Professor Oak, the very next day, once all his Pokemons have gone through evolution. He can select the order of applying evolution stones as he likes, so he wants to do it in such a way that he gets to meet Professor Oak as soon as possible!

Input Format:
The input has two lines. The first line will contain an integer k, which denotes the number of Pokemons. Then, a line with k integers follows, where the i-th integer denotes the number of days it takes for the i-th Pokemon to evolve.

Output Format:
You need to print the earliest day when little Arihant can go meet Professor Oak.

Constraints:
The days are numbered 1, 2, 3, 4, 5, 6...
1 ≤ k ≤ 10^5.
1 ≤ Number of days ≤ 10^6.

Sample Input (Plaintext Link)
2
3 1

Sample Output (Plaintext Link)
5
*/



#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

int comp(const void * a, const void * b){
	return (*(int*)b - *(int*)a);
}

int main(){
	int a[10000], rem = 0, i, k;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
		scanf("%d", &a[i]);
	qsort(a, k, sizeof(int), comp);
	for (i = 0; i < k; i++){
		rem = ++a[i]> rem ? a[i] : rem;
		rem--;
	}
	printf("%d", k + rem + 1);
	_getch();
}

