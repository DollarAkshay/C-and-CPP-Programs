

//https://www.hackerrank.com/contests/codeomania/challenges/reversed-number


r,n;main(a,b){for(scanf("%d%d",&a,&b);a<=b;printf("%d\n",r),r=0)for(n=a++;n;n/=10)r=r*10+n%10;}


//95 Characters

// Anta's Solution
//a;t;main(x){scanf("%d%d",&t,&x);for(a=t-x&&main(x-1);x;x/=10)a=a*10+x%10;printf("%d\n",a);}

