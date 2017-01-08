
//https://www.hackerrank.com/challenges/leibniz

main(n){double a,x;scanf("%d");for(;a=scanf("%d",&n)>0;printf("%.15f\n",a))while(x=1.0/(2*--n+1),n)a+=n%2?-x:x;}

//112 Characters

