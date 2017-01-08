
//You have to find the number of divisors of a number.

main(c){
	long int n, l, i;
	scanf("%ld", &n);
	l=sqrt(n);
	c = 0;
	for(i = 1; i <= l; i++)
			n%i ? 0 : n / i>l ? c += 2 : c++;
	printf("%d\n", c);
}