//https://www.codingame.com/ide/14832725ac3d4398a50f9d8d8129f20bd82cc29

main(a,b,x,y){for(scanf("%d%d%d%d",&a,&b,&x,&y);putchar(b>y?y++,83:b<y?y--,78:13);puts(a>x?"E":a<x?"W":""));}