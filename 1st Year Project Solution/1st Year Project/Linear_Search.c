main(){
	int key,i,n,a[99];
	printf("Array Size : ");
	scanf("%d",&n);
	printf("Array : ");
	for (i=0;i<n;scanf("%d",&a[i++]));
	printf("Key : ");
	scanf("%d", &key);
	for (i=0;a[i++]!=key&&i<n;);
	i!=n?printf("Key at %d", i):printf("Not Found");
	_getch();
}



