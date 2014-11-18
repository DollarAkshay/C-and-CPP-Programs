
//http://www.codechef.com/MTRX2014/problems/JERRYRUN/

static int t,xt,xj,vt,vj;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&xt,&xj,&vt,&vj);
		if(vt<=vj) puts("not possible");
		else printf("(%d,0)\n",(xj-xt)/(vt-vj)*vt+xt);
	}
	return 0;
}

//Solved - 6th on the Leader Board :)
