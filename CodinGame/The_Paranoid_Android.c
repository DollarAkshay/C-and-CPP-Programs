#define s(a,b) scanf("%d%d",&a,&b)
d, w, r, a, b, c, d, g, x, y, e[15]; main(h){
	s(h, w); s(r, d); s(c, b); s(a, g);
	scanf("%d%d%d%d%d%d%d%d", &h, &w, &r, &d, &c, &b, &a, &g);
	for (e[g] = c; g--; s(a, b), e[a] = b); while (scanf("%d%d %s", &y, &x, &d))puts(e[y]<x&&d || e[y]>x&&!d ? "BLOCK" : "WAIT", d -= 76);
}