//http://www.hackerearth.com/problem/algorithm/day-4-basic-mathematics/

main(t, n){
	scanf("%d", &t);
	while (scanf("%d", &n)>0){
		n = ceil((sqrt(1 + 8 * n) - 1) / 2);
		puts(n % 3 ? (n % 3 - 1 ? "BS" : "LB") : "SL");
	}
}

//Solved