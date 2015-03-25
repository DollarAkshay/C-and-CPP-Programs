unsigned long int n, g, j,i;
char binary[33];

void D_B(){

	int i = 0;
	while (i < 32){
		binary[31-i]= (n>>i)%2?'1':'0';
		i++;
	}
	binary[32] = 0;

}


int main(t){
	scanf("%d", &t);
	while (t--){
		scanf("%llu", &n);
		D_B();
		for (i = 0; i<64; i++){
			if ((n >> i) % 4 == 1){
				n ^= (3 << i);
				D_B();
				break;
			}
		}
		for (j = 0; j<i; j++, i--){
			printf("%d %d\n",n>>i,n>>j);
			int l = (n >> i) % 2, r = (n >> j) % 2 == 0;
			n = l ? n | (1 << j) : n&~(1 << j);
			D_B();
			n = r ? n | (1 << i) : n&~(1 << i);
			D_B();
		}
		printf("%llu\n", n);
	}
}


