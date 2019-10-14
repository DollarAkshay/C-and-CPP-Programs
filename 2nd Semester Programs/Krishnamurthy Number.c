// 145 = 1! + 4! + 5!
#include<stdio.h>
#include<stdlib.h>
int main() 
{
 int i,n,a,r,c=0,s;
 printf(" Please,Enter a number : "); 
 scanf("%d",&n);
 if(n==0)
 {
  printf("\n %d is not a Krishnamurthy Number.",n);
  exit(0);
 }
 a=n; 
 while(n>0)
 {
  r=n%10;
  s=1;
  for(i=r;i>=1;i--)
   s=s*i;
  c=c+s;
  n=n/10;
 }
 if(c==a)
  printf("\n %d is a Krishnamurthy Number.",a);
 else
  printf("\n %d is not a Krishnamurthy Number.",a);
 return 0;
}
