main(a, b){
	scanf("%d");
	while (scanf("%d%d", &a, &b)>0)
		printf("%d\n", floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}