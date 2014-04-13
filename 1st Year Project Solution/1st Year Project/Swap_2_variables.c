main(){
	int a = 10, b = 5;
	printf("a=%d   b=%d\n",a,b);
	a-=(b=(a+=b)-b);
	printf("a=%d   b=%d", a, b);
}

