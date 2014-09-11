char s[9999], w[998][998], a, t[999]; i, j, k, n[998];
main(){
	gets(s);
	while ((a=s[i++]))
		isalnum(a)?w[j][k++]=a:w[j][0] ?j++,k=0:0;

	for (i=0;w[i][0];i++){
		for (j = i; w[j][0]; j++){
			if (!strcmp(w[i], w[j])){
				if (++n[i] > 1) {
					k = j;
 					while (++k<999)
						strcpy(w[k - 1], w[k]);
					j--;
				}
			}
		}for (k = i; k >0; k--){
					if (n[k] > n[k - 1]) {
						j = n[k];
						n[k] = n[k - 1];
						n[k - 1] = j;
						strcpy(t, w[k]);
						strcpy(w[k], w[k - 1]);
						strcpy(w[k - 1], t);
					}}}
	for (i=0;w[i][0];i++)
		printf("%s = %d\n",w[i],n[i]);
	_getch();
}