
//http://www.hackerearth.com/problem/algorithm/chandu-and-his-playing-area/

main(){
	long int n;
	scanf("%d");
	while (scanf("%ld", &n) > 0)
		n % 2 ? n-- : n, printf("%ld\n", n*n >> 4);
}

//Solved