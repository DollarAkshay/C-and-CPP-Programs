main(l,h,n,m){
	int a[99];scanf("%d",&n);m=n;h=n-1;
	while (m--)scanf("%d", &a[m]);
	while (l<=h){m=(l+h)/2;
		if (a[m]==a[0]){printf("%d", n-m);break;}
		a[m]>a[0]?(l=m+1):(h=m-1);}
	l>h?printf("ERROR"):0;}



